///-----------------------------------------------------------------
///
/// @file      Project1Frm.cpp
/// @author    curt.hill
/// Created:   12/19/2013 1:56:57 PM
/// @section   DESCRIPTION
///            Test the X3D and VDS classes. The original is all on CBuilder, 
///            but this should work if DEV is defined.
///------------------------------------------------------------------

#include "ggFrm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// Project1Frm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Project1Frm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(Project1Frm::OnClose)
	EVT_SIZE(Project1Frm::Project1FrmSize)
	EVT_BUTTON(ID_WXBUTTON3,Project1Frm::WxButton3Click0)
	EVT_BUTTON(ID_WXBUTTON2,Project1Frm::WxButton2Click0)
	EVT_BUTTON(ID_WXBUTTON1,Project1Frm::WxButton1Click0)
	EVT_BUTTON(ID_CLEARBUTTON,Project1Frm::WxButton3Click)
	EVT_BUTTON(ID_ABOUTBUTTON,Project1Frm::WxButton2Click)
	EVT_BUTTON(ID_EXITBUTTON,Project1Frm::WxButton1Click)
END_EVENT_TABLE()
////Event Table End

Project1Frm::Project1Frm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

Project1Frm::~Project1Frm()
{
}

void Project1Frm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxButton3 = new wxButton(this, ID_WXBUTTON3, _("VDS TEst"), wxPoint(208, 30), wxSize(85, 38), 0, wxDefaultValidator, _("WxButton3"));

	WxButton2 = new wxButton(this, ID_WXBUTTON2, _("X3D Test2"), wxPoint(121, 28), wxSize(76, 40), 0, wxDefaultValidator, _("WxButton2"));

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("X3D Test1"), wxPoint(28, 27), wxSize(82, 42), 0, wxDefaultValidator, _("WxButton1"));

	ClearButton = new wxButton(this, ID_CLEARBUTTON, _("Clear"), wxPoint(453, 3), wxSize(75, 25), 0, wxDefaultValidator, _("ClearButton"));

	AboutButton = new wxButton(this, ID_ABOUTBUTTON, _("About"), wxPoint(453, 31), wxSize(75, 25), 0, wxDefaultValidator, _("AboutButton"));

	ExitButton = new wxButton(this, ID_EXITBUTTON, _("Exit"), wxPoint(453, 61), wxSize(75, 25), 0, wxDefaultValidator, _("ExitButton"));

	Memo1 = new wxTextCtrl(this, ID_MEMO1, wxEmptyString, wxPoint(1, 88), wxSize(525, 234), wxTE_MULTILINE, wxDefaultValidator, _("Memo1"));
	Memo1->SetMaxLength(0);
	Memo1->SetFocus();
	Memo1->SetInsertionPointEnd();

	SetTitle(_("X3D Test"));
	SetIcon(wxNullIcon);
	SetSize(8,8,547,366);
	Center();
	
	////GUI Items Creation End
}

void Project1Frm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * WxButton3Click
 */
void Project1Frm::WxButton3Click(wxCommandEvent& event)
{
	Memo1->Clear();
}

/*
 * WxButton2Click
 */
void Project1Frm::WxButton2Click(wxCommandEvent& event)
{
	MessageBoxW(NULL, L"This program does something. Copyright (c) 2015 by someone",L"About this program",MB_OK);
}

/*
 * WxButton1Click
 */
void Project1Frm::WxButton1Click(wxCommandEvent& event)
{
	Destroy();
}

/*
 * Project1FrmSize
 */
void Project1Frm::Project1FrmSize(wxSizeEvent& event)
{
 //int xedge = GetSystemMetrics(SM_CXEDGE);
 //int yedge = GetSystemMetrics(SM_CYEDGE);
 int buttonHeight = 0; // Set this to put buttons at bottom
 int menuHeight = GetSystemMetrics(SM_CYMENU)+1;
 int ytitle = GetSystemMetrics(SM_CYMIN);
 int margins = GetSystemMetrics(SM_CXFIXEDFRAME);
 int xborder = GetSystemMetrics(SM_CXFRAME);
 int yborder = GetSystemMetrics(SM_CYFRAME);
 // Resize the Memo
 int width, height, top, left;
 GetSize(&width,&height);
 Memo1->GetPosition(&left,&top);
 int newWidth = width - (left + 2*yborder);// + 2*margins);
 int newHeight = height - (top + ytitle
                         // + menuHeight
                          + buttonHeight);
 Memo1->SetSize(left,top,newWidth,newHeight);
 // Move the buttons
 int bwidth,bheight;
 AboutButton->GetSize(&bwidth, &bheight);
 AboutButton->GetPosition(&left,&top);
 AboutButton->SetSize(width-bwidth-yborder*2,top,bwidth,bheight);
 ClearButton->GetSize(&bwidth, &bheight);
 ClearButton->GetPosition(&left,&top);
 ClearButton->SetSize(width-bwidth-yborder*2,top,bwidth,bheight);
 ExitButton->GetSize(&bwidth, &bheight);
 ExitButton->GetPosition(&left,&top);
 ExitButton->SetSize(width-bwidth-yborder*2,top,bwidth,bheight);
}

/*
 * WxButton1Click0
 */
void Project1Frm::WxButton1Click0(wxCommandEvent& event)
{
 X3D scene;
 X3D_Group * gptr = new X3D_Group;
 gptr->set_translate(X3D_Coordinate(0,0,0));
 gptr->set_transparency(.7);
 scene.Add(gptr);
 X3D_Box * bptr = new X3D_Box(X3D_Coordinate(6,1,.5));
 bptr->set_color(X3D_Color(0.2,0,0));
 bptr->set_transparency(.8);
 gptr->Add(bptr);
 X3D_Text * tptr = new X3D_Text("Some Text");
 tptr->set_translate(X3D_Coordinate(-3,-.4,0));
 tptr->set_color(X3D_Color(0, 0.9,0));
 gptr->Add(tptr);

 gptr = new X3D_Group;
 scene.Add(gptr);
 X3D_Cylinder * cyptr = new X3D_Cylinder(5,0.15);
 cyptr->set_color(X3D_Color(0,.5,1));
 gptr->Add(cyptr);
 X3D_Cone * coptr = new X3D_Cone (1,.4);
 coptr->set_translate(X3D_Coordinate(0,2.5,0));
 coptr->set_color(X3D_Color(0,1,1));
 gptr->Add(coptr);

 X3D_Group * gptr2 = new X3D_Group;
 gptr2->set_translate(X3D_Coordinate(2,2,2));
 gptr2->set_rotation(X3D_Coordinate(0,0,1.6));
 gptr->Add(gptr2);
 cyptr = new X3D_Cylinder(5,0.15);
 cyptr->set_color(X3D_Color(0,.5,1));
 gptr2->Add(cyptr);
 coptr = new X3D_Cone (1,.4);
 coptr->set_translate(X3D_Coordinate(0,2.5,0));
 coptr->set_color(X3D_Color(0,1,1));
 gptr2->Add(coptr);
 tptr = new X3D_Text("Nested Text");
 tptr->set_translate(X3D_Coordinate(-4,-.74,0));
 tptr->set_color(X3D_Color(.5, 0.9,0));
 gptr2->Add(tptr);


// if(display){
    int result = scene.SaveToFile("Test2.x3d");
    Memo1->AppendText(wxString("Test.x3d was written, objects written: ")<<result<<"\n");
//    }



	
}

/*
 * WxButton2Click0
 */
void Project1Frm::WxButton2Click0(wxCommandEvent& event)
{
 X3D scene;
 X3D_Text * tptr;
 X3D_Box * bptr;
 X3D_Group * gptr;
 X3D_Cylinder * cyptr;
 X3D_Cone * coptr;
 X3D_Block * blptr;

 blptr = new X3D_Block();
 blptr->set_translate(X3D_Coordinate(1,-6,-18));
 scene.Add(blptr);
 tptr = new X3D_Text("W: First Line");
 tptr->set_color(X3D_Color(0,1,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("W2");
 tptr->set_color(X3D_Color(0,1,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("W Third");
 tptr->set_color(X3D_Color(1,0,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("W Fourth");
 tptr->set_color(X3D_Color(0,1,1));
 blptr->Add(tptr);
 blptr->Adjust();

 blptr = new X3D_Block();
 blptr->set_translate(X3D_Coordinate(-7,2,-20));
 scene.Add(blptr);
 tptr = new X3D_Text("X First");
 tptr->set_color(X3D_Color(0,1,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("X: Second");
 tptr->set_color(X3D_Color(0.2,1,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("X 3");
 tptr->set_color(X3D_Color(.7,0,1));
 blptr->Add(tptr);
 blptr->Adjust();


 blptr = new X3D_Block();
 blptr->set_translate(X3D_Coordinate(1,4,-22));
 scene.Add(blptr);
 tptr = new X3D_Text("Y: First of a new batch");
 tptr->set_color(X3D_Color(0,1,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("Y: Second");
 tptr->set_color(X3D_Color(0,1,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("Y: Third");
 tptr->set_color(X3D_Color(1,0,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("Y: Fourth");
 tptr->set_color(X3D_Color(1,0,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("Y: Fifth");
 tptr->set_color(X3D_Color(1,0,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("Y: Whoa");
 tptr->set_color(X3D_Color(1,0,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("Y: This one is tall");
 tptr->set_color(X3D_Color(1,1,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("Y: Yuppers");
 tptr->set_color(X3D_Color(1,1,0));
 blptr->Add(tptr);
 coptr = new X3D_Cone(.6,.2);
 coptr->set_color(X3D_Color(0.1,1,.5));
 coptr->set_translate(X3D_Coordinate(0,-1,0));
 blptr->Add(coptr);
 blptr->Adjust();


 blptr = new X3D_Block();
 blptr->set_translate(X3D_Coordinate(-8,-4,-20));
 scene.Add(blptr);
 tptr = new X3D_Text("Z");
 tptr->set_color(X3D_Color(1,1,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("Z2");
 tptr->set_color(X3D_Color(0.2,1,1));
 blptr->Add(tptr);
 blptr->Adjust();



    int result = scene.SaveToFile("Test3.x3d");
    Memo1->AppendText(wxString("Test3.x3d was written, objects written: ")<<result<<"\n");

}

/*
 * WxButton3Click0
 */
void Project1Frm::WxButton3Click0(wxCommandEvent& event)
{
  Memo1->AppendText("Not implemented\n");  
  /*  
	// Here we go
  unsigned low = vds.get_low();
  unsigned high = vds.get_high();
  Memo1->AppendText(wxString("Low: ")<<low<<", high: "<<high<<", range: "<<(high-low)/(1024*1024)<<" M\n");
  
  unsigned id;
  LinkedList list;
  id = list.register_class(vds);
  list.add(2,"Two");
  list.add(12,"Twelve");
  list.add(-6,"Negative six");
  list.add(4,"Four");
  list.snapshot(vds, id, "snapshot1.x3d");
  Memo1->AppendText("Registration and building complete\n");
  */
}
