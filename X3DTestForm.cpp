/*
  Put your title here
  Author Curt Hill

  Start your change log here.
*/
#include <vcl.h>
#pragma hdrstop

#include "x3dTestForm.h"


#include "\projects\objects\about\curt_about.h"
#include "\projects\objects\userlog\userlog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------

const AnsiString version = "1.0";
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Activator(TObject *Sender)
{
 // Some generalities that may come in handy
 int count = ParamCount();
 Memo1->Lines->Add(String("Numberof parameters: ")+count);
 // ParamStr(0) is path and exec file name
 myPath = ParamStr(0);
 group = false;
 exit = false;
 block = false;
 if(count) {
   for(int i = 0;i<=count;i++) {
     AnsiString st = ParamStr(i);
     Memo1->Lines->Add(String()+i+": "+st);
     if(st[1] == '-' || st[1] == '/'){
        // a commandline directive
        switch(st[2]){
          case 'b':
          case 'B':
            block = true;
            break;
          case 'g':
          case 'G':
            group = true;
            break;
          case 'x':
          case 'X':
            exit = true;
            break;
          }

        }
     else {
        // Probably a file name
     }
   } // for processing parameters
 } // if checking for parameters
 Memo1->Lines->Add("Program: "+myPath);
 int pos = myPath.LastDelimiter("\\");
 myPath = myPath.SubString(1,pos);
 Memo1->Lines->Add("Originating directory: "+myPath);
 if(block){
   Memo1->Clear();
   DoBlock(true);
   }
 if(group){
   Memo1->Clear();
   DoGroup(true);
   }
 if(exit)
   AllDone(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::AllDone(TObject *Sender)
{
// Do you need to save anything?
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AboutMe(TObject *Sender)
{
 CurtAbout->Copyright(1999,2017);
 CurtAbout->Version(version);
 CurtAbout->Description("This program demonstrates Genericness. I tried to make this comment so long that it would wrap and cause problems.");
 CurtAbout->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Contribute(TObject *Sender)
{
Application->MessageBox("I did not create this program to make money, nor is my financial security dependent on your sending something. Anything you send will will be appreciated, even if it will not make a difference in my budget, since I do have a good position. However, if you use this program and find it useful, then a contribution for the sake of conscience is appropriate. Since I do move occasionally, Google \"Curt Hill\" and see where I may be residing these days. Thanks for the thought.","Is this program valuable?",MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Warrant(TObject *Sender)
{
Application->MessageBox("The program is unconditionally unwarranted. In particular, since you paid nothing, if this thing wrecks your computer, your car, your stock portfolio or your relationships you have absolutely no legal rights for compensation. Is that clear enough?","You got to be kidding!",MB_OK);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::UserLogger(TObject *Sender)
{
  UserLogParms ulp;
  // Customize these three as needed
  ulp.displaymsg = "Please enter your comments and be as specific as possible.";
  ulp.filename = "App.log";
  ulp.specific_info = ""; // This one is program generated

  UserLogWindow->Tag = int(&ulp);
  UserLogWindow->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Sizing(TObject *Sender)
{
 //int xedge = GetSystemMetrics(SM_CXEDGE);
 //int yedge = GetSystemMetrics(SM_CYEDGE);
 int buttonHeight = 0; // Set this to put buttons at bottom
 int menuHeight = GetSystemMetrics(SM_CYMENU)+1;
 int ytitle = GetSystemMetrics(SM_CYMIN);
 int margins = GetSystemMetrics(SM_CXFIXEDFRAME);
 int xborder = GetSystemMetrics(SM_CXFRAME);
 //int yborder = GetSystemMetrics(SM_CYFRAME);
 // Resize the window
 Memo1->Width = Width - (Memo1->Left + xborder*2 + 2*margins);
 Memo1->Height = Height - (Memo1->Top + ytitle
                          + menuHeight + 2*margins + buttonHeight);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Clarify(TObject *Sender)
{
 Memo1->Clear();
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::SaveConsole(TObject *Sender)
{
  if(SaveDialog1->Execute()){
    Memo1->Lines->SaveToFile(SaveDialog1->FileName);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DisplayAPIError(String context){
   DWORD err = GetLastError();
   char * msg2 = new char [9000];
   FormatMessage(
      FORMAT_MESSAGE_FROM_SYSTEM,
      NULL,
      err,
      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
      (LPTSTR) msg2, 9000, NULL);
   context += msg2;
   Application->MessageBox(context.c_str(),"Error",MB_OK);
   delete [] msg2;
}


void __fastcall TMainForm::Test1(TObject *Sender)
{
 Memo1->Clear();
 Memo1->Lines->Add("Starting simple Color tests");
 int passed=0, failed=0;
 X3D_Color red(1,0,0), gray(.5,.5,.5),black(0,0,0),blah,outbound(4,-1,12), odd(1,0,0.5);
 if(red != black){
   passed++;
   }
 else {
   Memo1->Lines->Add("Failed color != test");
   failed++;
   }
 blah = gray;
 if(gray == blah){
   passed++;
   }
 else {
   Memo1->Lines->Add("Failed assignment or == test");
   failed++;
   }
 if(outbound == black){
   passed++;
   }
 else {
   Memo1->Lines->Add("Failed out of bounds in three float constructor");
   failed++;
   }
 blah.set_red(.5);
 blah.set_green(.5);
 blah.set_blue(.5);
 if(blah == gray){
   passed++;
   }
 else {
   Memo1->Lines->Add("Failed set colors");
   failed++;
   }
 blah.set_red(12);
 blah.set_green(-0.001);
 blah.set_blue(-12);
 if(blah == black){
   passed++;
   }
 else {
   Memo1->Lines->Add("Failed out of bounds set colors");
   failed++;
   }
 if(odd.ToString() == "1 0 0.5"){
   passed++;
   }
 else {
   Memo1->Lines->Add("Failed Color ToString");
   failed++;
   }

 Memo1->Lines->Add("Starting simple Coordinate tests");
 X3D_Coordinate c0(0,0,0), c1(0,1,2), c2(3,2,1), c3, c4, c5(10,15,20);
 if(c0 == c3){
   passed++;
   }
 else {
   Memo1->Lines->Add("Default Coordinate was not zero or == failed");
   failed++;
   }

 if(c1 != c2){
   passed++;
   }
 else {
   Memo1->Lines->Add("Coordinate != failed");
   failed++;
   }
 c4=c3;
 if(c4 == c3) {
   passed++;
   }
 else {
   Memo1->Lines->Add("Assignment for Coordinate failed");
   failed++;
   }
 c4 = c1+c5;
 if(c4.get_x()==10 && c4.get_y()==16 && c4.get_z()==22){
   passed++;
   }
 else {
   Memo1->Lines->Add("+ operator for Coordinate failed");
   failed++;
   }
 c4 = c5-c1;
 if(c4.get_x()==10 && c4.get_y()==14 && c4.get_z()==18){
   passed++;
   }
 else {
   Memo1->Lines->Add("- operator for Coordinate failed");
   failed++;
   }
 c4 = c1;
 c4+=c5;
 if(c4.get_x()==10 && c4.get_y()==16 && c4.get_z()==22){
   passed++;
   }
 else {
   Memo1->Lines->Add("+= operator for Coordinate failed");
   failed++;
   }
 c4 = c5;
 c4 -= c1;
 if(c4.get_x()==10 && c4.get_y()==14 && c4.get_z()==18){
   passed++;
   }
 else {
   Memo1->Lines->Add("-= operator for Coordinate failed");
   failed++;
   }
 if(c4.ToString() == "10 14 18") {
   passed++;
   }
 else {
   Memo1->Lines->Add("ToString for Coordinate failed: "+c4.ToString());
   failed++;
   }

 Memo1->Lines->Add(String("Tests completed: Passed: ")+passed+", failed: "+failed);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Test2(TObject *Sender)
{
 Memo1->Clear();
 Memo1->Lines->Add("Starting Sphere tests");
 X3D_Sphere s1, s2(3);
 s2.set_translate(X3D_Coordinate(2.5,5,3));
 s2.set_scale(X3D_Coordinate(4,1,2.5));
 Memo1->Lines->Add(s2.ToString());
 Memo1->Lines->Add(s2.ToXML());
 X3D_Box b1, b2(X3D_Coordinate(3,2,4));
 b2.set_translate(X3D_Coordinate(2.5,5,3));
 b2.set_scale(X3D_Coordinate(4,1,2.5));
 b2.set_rotation(X3D_Coordinate(0,.15,0));
 Memo1->Lines->Add(b2.ToString());
 Memo1->Lines->Add(b2.ToXML());
}
//-----------------------------
void __fastcall TMainForm::GenScene(TObject *Sender)
{
 Memo1->Clear();
 DoScene(true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DoScene(bool display){
 X3D scene;
 X3D_Box * ptr = new X3D_Box(X3D_Coordinate(2,1,3));
 ptr->set_translate(X3D_Coordinate(-2,-1,-1));
 ptr->set_color(X3D_Color(0.9,.1,.3));
 scene.Add(ptr);
 ptr = new X3D_Box(X3D_Coordinate(6,1,2));
 ptr->set_translate(X3D_Coordinate(-2,2,-2));
 ptr->set_color(X3D_Color(0.4,0.19,.3));
 scene.Add(ptr);
 ptr = new X3D_Box(X3D_Coordinate(6,1,1));
 ptr->set_translate(X3D_Coordinate(-2,2,22));
 ptr->set_color(X3D_Color(0,0.9,.3));
 scene.Add(ptr);
 ptr = new X3D_Box(X3D_Coordinate(6,1,4));
 ptr->set_translate(X3D_Coordinate(-2,2,-22));
 ptr->set_color(X3D_Color(0,0.9,.3));
 scene.Add(ptr);
 X3D_Sphere * ptr2 = new X3D_Sphere(.8);
 ptr2->set_translate(X3D_Coordinate(-.5,.5,0));
 ptr2->set_color(X3D_Color(0,0,0.9));
 ptr2->set_transparency(.4);
 scene.Add(ptr2);
 ptr2 = new X3D_Sphere(.8);
 ptr2->set_translate(X3D_Coordinate(-.5,.5,20));
 ptr2->set_color(X3D_Color(0,0,0.9));
 ptr2->set_transparency(.4);
 scene.Add(ptr2);
 ptr2 = new X3D_Sphere(.8);
 ptr2->set_translate(X3D_Coordinate(-.5,.5,40));
 ptr2->set_color(X3D_Color(0,0,0.9));
 ptr2->set_transparency(.4);
 scene.Add(ptr2);
 X3D_Text * ptr3 = new X3D_Text("Hello There!");
 ptr3->set_translate(X3D_Coordinate(-.5,-2.5,0));
 ptr3->set_color(X3D_Color(0.5,0,0.9));
 scene.Add(ptr3);
 ptr3 = new X3D_Text("Hello There!");
 ptr3->set_translate(X3D_Coordinate(-.5,-2.5,20));
 ptr3->set_color(X3D_Color(0.5,0,0.9));
 scene.Add(ptr3);
 ptr3 = new X3D_Text("Hello There!");
 ptr3->set_translate(X3D_Coordinate(-.5,-2.5,40));
 ptr3->set_color(X3D_Color(0.5,0,0.9));
 scene.Add(ptr3);
 X3D_Cone * ptr4 = new X3D_Cone(2, .4);
 ptr4->set_translate(X3D_Coordinate(1,-2.5,1));
 ptr4->set_color(X3D_Color(0,.5,0.7));
 scene.Add(ptr4);
 ptr4 = new X3D_Cone(2, .4);
 ptr4->set_translate(X3D_Coordinate(1,-2.5,41));
 ptr4->set_color(X3D_Color(0,.5,0.7));
 scene.Add(ptr4);
 ptr4 = new X3D_Cone(2, .4);
 ptr4->set_translate(X3D_Coordinate(1,-2.5,61));
 ptr4->set_color(X3D_Color(0,.5,0.7));
 scene.Add(ptr4);
 X3D_Cone * ptr6 = new X3D_Cone(*ptr4);
 ptr6->set_translate(X3D_Coordinate(1,-2.5,1));
 ptr6->set_color(X3D_Color(.3,.5,0.7));
 ptr6->set_rotation(X3D_Coordinate(0,1.8,3.14159));
 scene.Add(ptr6);
 ptr6 = new X3D_Cone(*ptr4);
 ptr6->set_translate(X3D_Coordinate(1,-2.5,21));
 ptr6->set_color(X3D_Color(.3,.5,0.7));
 ptr6->set_rotation(X3D_Coordinate(0,1.8,3.14159));
 scene.Add(ptr6);
 ptr6 = new X3D_Cone(*ptr4);
 ptr6->set_translate(X3D_Coordinate(1,-2.5,41));
 ptr6->set_color(X3D_Color(.3,.5,0.7));
 ptr6->set_rotation(X3D_Coordinate(0,1.8,3.14159));
 scene.Add(ptr6);
 X3D_Cylinder * ptr5 = new X3D_Cylinder(2, .3);
 ptr5->set_translate(X3D_Coordinate(2,2.5,1));
 ptr5->set_color(X3D_Color(0.1,.5,0.7));
 scene.Add(ptr5);
 ptr5 = new X3D_Cylinder(2, .3);
 ptr5->set_translate(X3D_Coordinate(2,2.5,21));
 ptr5->set_color(X3D_Color(0.1,.5,0.7));
 scene.Add(ptr5);
 ptr5 = new X3D_Cylinder(2, .3);
 ptr5->set_translate(X3D_Coordinate(2,2.5,41));
 ptr5->set_color(X3D_Color(0.1,.5,0.7));
 scene.Add(ptr5);
 const int max_axis = 200;
 // Axis X displays
 for(int i = 1;i<max_axis;i++){
   ptr2 = new X3D_Sphere(.2);
   ptr2->set_translate(X3D_Coordinate(i,0,0));
   ptr2->set_color(X3D_Color(1,0,0));
   scene.Add(ptr2);
   ptr2 = new X3D_Sphere(.2);
   ptr2->set_translate(X3D_Coordinate(-i,0,0));
   ptr2->set_color(X3D_Color(1,0.2,0.2));
   scene.Add(ptr2);
 }
 // Axis Y displays
 for(int i = 1;i<max_axis;i++){
   ptr2 = new X3D_Sphere(.2);
   ptr2->set_translate(X3D_Coordinate(0,i,0));
   ptr2->set_color(X3D_Color(0,1,0));
   scene.Add(ptr2);
   ptr2 = new X3D_Sphere(.2);
   ptr2->set_translate(X3D_Coordinate(0,-i,0));
   ptr2->set_color(X3D_Color(0.2,1,0.2));
   scene.Add(ptr2);
 }
 // Axis Z displays
 for(int i = 1;i<max_axis;i++){
   ptr2 = new X3D_Sphere(.2);
   ptr2->set_translate(X3D_Coordinate(0,0,i));
   ptr2->set_color(X3D_Color(0,0,1));
   scene.Add(ptr2);
   ptr2 = new X3D_Sphere(.2);
   ptr2->set_translate(X3D_Coordinate(0,0,-i));
   ptr2->set_color(X3D_Color(0.2,0.2,1));
   scene.Add(ptr2);
 }


 if(display){
    Memo1->Lines->Add(String("Number of items ")+scene.Size());
    int result = scene.SaveToFile("Test.x3d");
    Memo1->Lines->Add(AnsiString("Test.x3d was written, objects written: ")+result);
    }
}

void __fastcall TMainForm::RepeatMe(TObject *Sender)
{
 const int max = 10000;
 Application->MessageBoxA("Memory test is about to begin - enable the memory monitor","Get Ready",MB_OK);
 Memo1->Lines->Add("Memory test begins");
 for(int i = 0;i<max;i++)
   DoScene(false);
 Memo1->Lines->Add("Memory test complete");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DoGroup(bool display){
 X3D scene;
 X3D_Text * tptr;
 X3D_Box * bptr;
 X3D_Group * gptr;
 X3D_Cylinder * cyptr;
 X3D_Cone * coptr;

 gptr = new X3D_Group;
 gptr->set_translate(X3D_Coordinate(0,0,0));
 gptr->set_transparency(.7);
 scene.Add(gptr);
 bptr = new X3D_Box(X3D_Coordinate(6,1,.5));
 bptr->set_color(X3D_Color(0.2,0,0));
 bptr->set_transparency(.8);
 gptr->Add(bptr);
 tptr = new X3D_Text("Some Text");
 tptr->set_translate(X3D_Coordinate(-3,-.4,0));
 tptr->set_color(X3D_Color(0, 0.9,0));
 gptr->Add(tptr);

 gptr = new X3D_Group;
 gptr->set_translate(X3D_Coordinate(-1,2,3));
 scene.Add(gptr);
 cyptr = new X3D_Cylinder(5,0.15);
 cyptr->set_color(X3D_Color(0,.5,1));
 gptr->Add(cyptr);
 coptr = new X3D_Cone (1,.4);
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

 if(display){
    int result = scene.SaveToFile("Test2.x3d");
    Memo1->Lines->Add(AnsiString("Test2.x3d was written, objects written: ")+result);
    }

}

void __fastcall TMainForm::DoBlock(bool display){
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



 if(display){
    int result = scene.SaveToFile("Test3.x3d");
    Memo1->Lines->Add(AnsiString("Test3.x3d was written, objects written: ")+result);
    }
}



void __fastcall TMainForm::BlockTest(TObject *Sender)
{
 Memo1->Clear();
 DoBlock(true);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Groupie(TObject *Sender)
{
 Memo1->Clear();
 DoGroup(true);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MemoryGroup(TObject *Sender)
{
 const int max = 10000000;
 Application->MessageBoxA("Memory test is about to begin - enable the memory monitor","Get Ready",MB_OK);
 Memo1->Lines->Add("Memory test begins");
 for(int i = 0;i<max;i++)
   DoGroup(false);
 Memo1->Lines->Add("Second Memory test complete");
}
//---------------------------------------------------------------------------

