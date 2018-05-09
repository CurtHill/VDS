/*
  Put your title here
  Author Curt Hill

  Start your change log here.
*/
#include <vcl.h>
#pragma hdrstop

#include "TestFormVDS.h"
#include "LinkedList.h"
#include "circle_list.h"

#include "\projects\objects\about\curt_about.h"
#include "\projects\objects\userlog\userlog.h"
#include "vds_memory.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------

const AnsiString version = "0.7";
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
 // Some generalities that may come in handy
 int count = ParamCount();
 Memo1->Clear();
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
 CurtAbout->Description("This is the Visual Data Structure test program. ");
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
  ulp.filename = "vds.log";
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
Memo1->Lines->Add(AnsiString("Nothing left in this test"));
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ListBuilder(TObject *Sender)
{
 Memo1->Clear();
 unsigned id;
 //Memo1->Lines->Add(AnsiString("Memory ranges: ")+vds.get_low()+" - "+vds.get_high());
 LinkedList list;
 id = list.register_class(vds);
 list.add(2,"Two");
 list.add(12,"Twelve");
 list.add(-6,"Negative six");
 list.add(4,"Four");
 bool success = list.snapshot(vds, id, "list1", true,ViewBox->Checked);
 if(!success)
    Memo1->Lines->Add("Something failed.");
 else
    Memo1->Lines->Add("Registration and building complete for list1.x3d");
 Memo1->Lines->Add(AnsiString("New calls that were intercepted: ")+VDS_Memory::new_used()+
                   ", passed through: "+VDS_Memory::new_passed());
 Memo1->Lines->Add(AnsiString("Pointer database: ")+VDS_Memory::ToString());

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DoAdd(CurtTree & badguys, AnsiString line){
 // Parse the string
 int pos;
 pos = line.AnsiPos(",");
 if(pos<1)
   return;
 AnsiString name = line.SubString(1,pos-1).Trim();
 line = line.Delete(1,pos);
 pos = line.AnsiPos(",");
 if(pos<1)
   return;
 AnsiString zip = line.SubString(1,pos-1).Trim();
 line = line.Delete(1,pos);
 pos = line.AnsiPos(",");
 if(pos<1)
   return;
 AnsiString crime = line.SubString(1,pos-1).Trim();
 line = line.Delete(1,pos);
 bool inPrison = line[1] == '1';
 // If we got this far add it
 if(!badguys.Insert(name,zip,crime,inPrison)){
   Memo1->Lines->Add(name+" could not be added.");
   }
}



void __fastcall TMainForm::TreeBuild(TObject *Sender)
{
 Memo1->Clear();
 unsigned id;
 CurtTree badguys;
 id = badguys.register_class(vds);
 int count = 0;
 // read in data
 ifstream inf("felons.dat");
   while(inf){
     char ln[1000];
     inf.getline(ln,200);
     AnsiString line = ln;
     if(!inf)
       break;
     count++;
     Memo1->Lines->Add(line);
     if(line.Length()< 3)
       continue;
     line = line.Delete(1,2); // cmd + blank
     DoAdd(badguys,line);
     } // while
 Memo1->Lines->Add(AnsiString("Complete. Added: ")+count);

 badguys.snapshot(vds, id, "felons1",true,ViewBox->Checked);
 Memo1->Lines->Add("Registration and building complete");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BuildCircular(TObject *Sender)
{
 // Build the cicular linked list
 circle_list clist;
 clist.add(12);
 clist.add(-2);
// clist.add(2);
 clist.add(19);
 circle_iterator cit(&clist);
 while(!cit.done()){
    int i;
    bool res = cit.next(i);
    if(!res)
       break;
    Memo1->Lines->Add(String("")+i);
    }
 unsigned id = clist.register_class(vds);
 clist.snapshot(vds, id, "clist1",true,ViewBox->Checked);
 Memo1->Lines->Add("Registration and first build complete");
 ofstream outf("TestFormVDS.lst");
 outf << vds.ToString().c_str() << "\n";
 outf.close();
 clist.sort();
 clist.snapshot(vds, id, "clist2",true,ViewBox->Checked);
 Memo1->Lines->Add("Second build complete");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PointerBad(TObject *Sender)
{
 // Create a circular list and introduce a problem
 circle_list clist;
 clist.add(12);
 clist.add(-2);
 clist.add(2);
 clist.add(19);
 unsigned id = clist.register_class(vds);
 clist.snapshot(vds, id, "clist_good",true,ViewBox->Checked);
 Memo1->Lines->Add("Registration and build of circular list complete");
 clist.insert_error();
 clist.snapshot(vds, id, "clist_bad",false,true);
}
//---------------------------------------------------------------------------

