// Copyright (C) 2012 gureedo
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "StdAfx.h"
#include "GrymApiBase.h"

//////////////////////////////////////////////////////////////////////////
// CommandBase
//////////////////////////////////////////////////////////////////////////

CommandBase::CommandBase()
{
}

CommandBase::~CommandBase()
{
}

HRESULT WINAPI CommandBase::ICommandAcceleratorQIFunc( void* pv, REFIID /*riid*/, LPVOID* ppv, DWORD /*dw*/ )
{
	CommandBase *pThis = static_cast<CommandBase *>(pv);
	*ppv = NULL;
	if ( pThis->accelerator_ ) {
		*ppv = static_cast<GrymCore::ICommandAccelerator *>(pThis);
		pThis->AddRef();
		return S_OK;
	}
	return E_NOINTERFACE;
}

STDMETHODIMP CommandBase::get_Accelerator( LONG *pVal )
{
	try {
		if ( !pVal ) {
			return E_POINTER;
		}
		*pVal = accelerator_;
		return S_OK;
	} catch (...) {
	}

	return E_FAIL;
}

//////////////////////////////////////////////////////////////////////////
// ControlBase
//////////////////////////////////////////////////////////////////////////

ControlBase::ControlBase()
{
}

ControlBase::~ControlBase()
{
}

STDMETHODIMP ControlBase::get_PlacementCode( BSTR *pVal )
{
	try {
		if ( !pVal ) {
			return E_POINTER;
		}
		*pVal = placement_code_.copy();
		return S_OK;
	} catch (...) {
	}

	return E_FAIL;
}

STDMETHODIMP ControlBase::get_Tag( BSTR *pVal )
{
	try {
		if ( !pVal ) {
			return E_POINTER;
		}
		*pVal = tag_.copy();
		return S_OK;
	} catch (...) {
	}

	return E_FAIL;
}

STDMETHODIMP ControlBase::get_Caption( BSTR *pVal )
{
	try {
		if ( !pVal ) {
			return E_POINTER;
		}
		*pVal = caption_.copy();
		return S_OK;
	} catch (...) {
	}

	return E_FAIL;
}

STDMETHODIMP ControlBase::get_Description( BSTR *pVal )
{
	try {
		if ( !pVal ) {
			return E_POINTER;
		}
		*pVal = description_.copy();
		return S_OK;
	} catch (...) {
	}

	return E_FAIL;
}

STDMETHODIMP ControlBase::get_Icon( IUnknown **pVal )
{
	try {
		if ( !pVal ) {
			return E_POINTER;
		}
		*pVal = IUnknownPtr(icon_).Detach();
		return S_OK;
	} catch (...) {
	}

	return E_FAIL;
}

//////////////////////////////////////////////////////////////////////////
// VisibleCommandBase
//////////////////////////////////////////////////////////////////////////

VisibleCommandBase::VisibleCommandBase()
{
}

VisibleCommandBase::~VisibleCommandBase()
{
}

STDMETHODIMP VisibleCommandBase::get_PlacementCode(BSTR *pVal)
{
	try {
		if ( !pVal ) {
			return E_POINTER;
		}
		*pVal = placement_code_.copy();
		return S_OK;
	} catch (...) {
	}

	return E_FAIL;
}

STDMETHODIMP VisibleCommandBase::get_Tag(BSTR *pVal)
{
	try {
		if ( !pVal ) {
			return E_POINTER;
		}
		*pVal = tag_.copy();
		return S_OK;
	} catch (...) {
	}

	return E_FAIL;
}

STDMETHODIMP VisibleCommandBase::get_Caption(BSTR *pVal)
{
	try {
		if ( !pVal ) {
			return E_POINTER;
		}
		*pVal = caption_.copy();
		return S_OK;
	} catch (...) {
	}

	return E_FAIL;
}

STDMETHODIMP VisibleCommandBase::get_Description(BSTR *pVal)
{
	try {
		if ( !pVal ) {
			return E_POINTER;
		}
		*pVal = description_.copy();
		return S_OK;
	} catch (...) {
	}

	return E_FAIL;
}

STDMETHODIMP VisibleCommandBase::get_Icon( IUnknown **pVal )
{
	try {
		if ( !pVal ) {
			return E_POINTER;
		}
		*pVal = IUnknownPtr(icon_).Detach();
		return S_OK;
	} catch (...) {
	}

	return E_FAIL;
}

//////////////////////////////////////////////////////////////////////////
// VisibleStateCommandBase
//////////////////////////////////////////////////////////////////////////

#if 0
VisibleStateCommandBase::VisibleStateCommandBase( const _bstr_t &placement_code, 
	const _bstr_t &tag, const _bstr_t &caption, const _bstr_t &description, 
	IUnknown *icon, DWORD accelerator )
	: VisibleCommandBase(placement_code, tag, caption, description, icon, accelerator)
{
}

VisibleStateCommandBase::~VisibleStateCommandBase()
{
}

STDMETHODIMP VisibleStateCommandBase::get_Available( VARIANT_BOOL *pVal )
{
	if ( !pVal ) {
		return E_POINTER;
	}
	*pVal = VARIANT_TRUE;
	return S_OK;
}

STDMETHODIMP VisibleStateCommandBase::get_Enabled( VARIANT_BOOL *pVal )
{
	if ( !pVal ) {
		return E_POINTER;
	}
	*pVal = VARIANT_TRUE;
	return S_OK;
}

STDMETHODIMP VisibleStateCommandBase::get_Checked( VARIANT_BOOL *pVal )
{
	if ( !pVal ) {
		return E_POINTER;
	}
	*pVal = VARIANT_FALSE;
	return S_OK;
}
#endif
