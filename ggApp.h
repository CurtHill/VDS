//---------------------------------------------------------------------------
//
// Name:        Project1App.h
// Author:      curt.hill
// Created:     12/19/2013 1:56:56 PM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __PROJECT1FRMApp_h__
#define __PROJECT1FRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class Project1FrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
