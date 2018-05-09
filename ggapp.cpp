//---------------------------------------------------------------------------
//
// Name:        Project1App.cpp
// Author:      curt.hill
// Created:     12/19/2013 1:56:56 PM
// Description: 
//
//---------------------------------------------------------------------------

#include "GgApp.h"
#include "ggFrm.h"

IMPLEMENT_APP(Project1FrmApp)

bool Project1FrmApp::OnInit()
{
    Project1Frm* frame = new Project1Frm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int Project1FrmApp::OnExit()
{
	return 0;
}
