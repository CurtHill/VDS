/*
  VDS Demo
  Author Curt Hill

  Created 4/3/2018
*/
#include <vcl.h>
#pragma hdrstop

#include "mics.h"


#include "\projects\objects\about\curt_about.h"
#include "\projects\objects\userlog\userlog.h"
#include <fstream.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------

const AnsiString version = "0.1";
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
 // Some generalities that may come in handy
 int count = ParamCount();
 Memo1->Lines->Add(String("Numberof parameters: ")+count);
 // ParamStr(0) is path and exec file name
 myPath = ParamStr(0);
 if(count) {
   for(int i = 0;i<=count;i++) {
     AnsiString st = ParamStr(i);
     Memo1->Lines->Add(String()+i+": "+st);
     if(st[1] == '-' || st[1] == '/'){
        // a commandline directive
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
 Memo1->Clear();
 all_data.Register(vds);
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
 CurtAbout->Copyright(1999,2018);
 CurtAbout->Version(version);
 CurtAbout->Description("This program demonstrates Visual Data Structures.");
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
void __fastcall TMainForm::AddFile(TObject *Sender)
{
 if(OpenDialog1->Execute()){
   ifstream inf(OpenDialog1->FileName.c_str());
   int count = 0;
   while(true){
     char name[100];
     float value;
     inf >> name >> value;
     if(!inf)
       break;
     all_data.add(name,value,count++);
     }
   Memo1->Lines->Add(String("Added: ")+count);  
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Finder(TObject *Sender)
{
 String key = Edit1->Text;
 float d;
 int i;
 unsigned count = all_data.find(key,d,i);
 if(count == 0)
   Memo1->Lines->Add("None found");
 else
   Memo1->Lines->Add(String("Found: ")+count);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DoIt(TObject *Sender)
{
 static int val = 1;
 char fn[100] = "demo";
 char num[5];
 itoa(val,num,10);
 strcat(fn,num);

 all_data.snapshot(vds,fn);
 TreeIterator ti;
 ti.start(&all_data);
 String key;
 while(ti.more()){
   struct TreeData * array=NULL;
   unsigned count = ti.next(key,array);
   Memo1->Lines->Add(key);
   for(unsigned i = 0;i<count;i++)
     Memo1->Lines->Add(String(" ")+array[i].data+", "+array[i].order);
   delete [] array;  
   }
}
//---------------------------------------------------------------------------

