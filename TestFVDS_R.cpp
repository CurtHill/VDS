//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TestFVDS_R.h"
#include "LinkedList.h"
#include "circle_list.h"
#include "vds_memory.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Closer(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Clarify(TObject *Sender)
{
 Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Saver(TObject *Sender)
{
  if(SaveDialog1->Execute())
	Memo1->Lines->SaveToFile(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TForm1::DoAdd(CurtTree & badguys, AnsiString line){
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

void __fastcall TForm1::ListBuilder(TObject *Sender)
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
