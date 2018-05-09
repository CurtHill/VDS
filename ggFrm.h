///-----------------------------------------------------------------
///
/// @file      Project1Frm.h
/// @author    curt.hill
/// Created:   12/19/2013 1:56:57 PM
/// @section   DESCRIPTION
///            Project1Frm class declaration
///
///------------------------------------------------------------------
//#include "visual_data_structure.h"
//#include "linkednode.h"
//#include "linkedlist.h"
#include "x3d.h"
#ifndef __PROJECT1FRM_H__
#define __PROJECT1FRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/button.h>
#include <wx/textctrl.h>
////Header Include End

////Dialog Style Start
#undef Project1Frm_STYLE
#define Project1Frm_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class Project1Frm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		Project1Frm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Project1"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = Project1Frm_STYLE);
		virtual ~Project1Frm();
		void WxButton3Click(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void Project1FrmSize(wxSizeEvent& event);
		void WxButton1Click0(wxCommandEvent& event);
		void WxButton2Click0(wxCommandEvent& event);
		void WxButton3Click0(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *WxButton3;
		wxButton *WxButton2;
		wxButton *WxButton1;
		wxButton *ClearButton;
		wxButton *AboutButton;
		wxButton *ExitButton;
		wxTextCtrl *Memo1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXBUTTON3 = 1007,
			ID_WXBUTTON2 = 1006,
			ID_WXBUTTON1 = 1005,
			ID_CLEARBUTTON = 1004,
			ID_ABOUTBUTTON = 1003,
			ID_EXITBUTTON = 1002,
			ID_MEMO1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		//VDS vds; 
};

#endif
