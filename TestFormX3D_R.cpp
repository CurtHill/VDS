//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TestFormX3D_R.h"
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
void __fastcall TForm1::SaveConsole(TObject *Sender)
{
  if(SaveDialog1->Execute()){
    Memo1->Lines->SaveToFile(SaveDialog1->FileName);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Clarify(TObject *Sender)
{
 Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Test1(TObject *Sender)
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
void __fastcall TForm1::Solids1Click(TObject *Sender)
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
//---------------------------------------------------------------------------

void __fastcall TForm1::Scene1Click(TObject *Sender)
{
 Memo1->Clear();
 DoScene(true);
}

void __fastcall TForm1::DoScene(bool display){
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
 X3D_Text * ptr3 = new X3D_Text(L"Hello There!");
 ptr3->set_translate(X3D_Coordinate(-.5,-2.5,0));
 ptr3->set_color(X3D_Color(0.5,0,0.9));
 scene.Add(ptr3);
 ptr3 = new X3D_Text(L"Hello There!");
 ptr3->set_translate(X3D_Coordinate(-.5,-2.5,20));
 ptr3->set_color(X3D_Color(0.5,0,0.9));
 scene.Add(ptr3);
 ptr3 = new X3D_Text(L"Hello There!");
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
 X3D_Cone * ptr6 = new X3D_Cone();
 ptr6->set_translate(X3D_Coordinate(1,-2.5,1));
 ptr6->set_color(X3D_Color(.3,.5,0.7));
 ptr6->set_rotation(X3D_Coordinate(0,1.8,3.14159));
 scene.Add(ptr6);
 ptr6 = new X3D_Cone();
 ptr6->set_translate(X3D_Coordinate(1,-2.5,21));
 ptr6->set_color(X3D_Color(.3,.5,0.7));
 ptr6->set_rotation(X3D_Coordinate(0,1.8,3.14159));
 scene.Add(ptr6);
 ptr6 = new X3D_Cone();
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
 AddAxes(scene);

 if(display){
	Memo1->Lines->Add(String("Number of items ")+scene.Size());
	int result = scene.SaveToFile("Test");
	Memo1->Lines->Add(AnsiString("Test.x3d was written, objects written: ")+result);
	}
}

void __fastcall TForm1::AddAxes(X3D & scene){
 const int max_axis = 200;
 // Axis X displays
 const float size = .05;
 X3D_Sphere * ptr2;
 for(int i = 1;i<max_axis;i++){
   ptr2 = new X3D_Sphere(size);
   ptr2->set_translate(X3D_Coordinate(i,0,0));
   ptr2->set_color(X3D_Color(1,0,0));
   scene.Add(ptr2);
   ptr2 = new X3D_Sphere(size);
   ptr2->set_translate(X3D_Coordinate(-i,0,0));
   ptr2->set_color(X3D_Color(1,0.2,0.2));
   scene.Add(ptr2);
 }
 // Axis Y displays
 for(int i = 1;i<max_axis;i++){
   ptr2 = new X3D_Sphere(size);
   ptr2->set_translate(X3D_Coordinate(0,i,0));
   ptr2->set_color(X3D_Color(0,1,0));
   scene.Add(ptr2);
   ptr2 = new X3D_Sphere(size);
   ptr2->set_translate(X3D_Coordinate(0,-i,0));
   ptr2->set_color(X3D_Color(0.2,1,0.2));
   scene.Add(ptr2);
 }
 // Axis Z displays
 for(int i = 1;i<max_axis;i++){
   ptr2 = new X3D_Sphere(size);
   ptr2->set_translate(X3D_Coordinate(0,0,i));
   ptr2->set_color(X3D_Color(0,0,1));
   scene.Add(ptr2);
   ptr2 = new X3D_Sphere(size);
   ptr2->set_translate(X3D_Coordinate(0,0,-i));
   ptr2->set_color(X3D_Color(0.2,0.2,1));
   scene.Add(ptr2);
 }
}


//---------------------------------------------------------------------------

void __fastcall TForm1::Groupie(TObject *Sender)
{
 Memo1->Clear();
 DoGroup(true);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DoGroup(bool display){
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
	int result = scene.SaveToFile("Test2");
	Memo1->Lines->Add(AnsiString("Test2.x3d was written, objects written: ")+result);
	}

}

void __fastcall TForm1::DoBlock(bool display){
 X3D scene;
 X3D_Text * tptr;
 //X3D_Box * bptr;
 //X3D_Group * gptr;
 //X3D_Cylinder * cyptr;
 X3D_Cone * coptr;
 X3D_Block * blptr;


 AddAxes(scene);

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



 X3D_Arrow * aptr;
 blptr = new X3D_Block();
 blptr->set_translate(X3D_Coordinate(-8,-4,-18));
 scene.Add(blptr);
 tptr = new X3D_Text("Z");
 tptr->set_color(X3D_Color(1,1,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("Z2");
 tptr->set_color(X3D_Color(0.2,1,1));
 blptr->Add(tptr);
 aptr = new X3D_Arrow(X3D_Coordinate(-4,0,0),X3D_Coordinate(-1.5,0,0));
 blptr->Add(aptr);
 aptr = new X3D_Arrow(X3D_Coordinate(-8,-4,-18),X3D_Coordinate(1,4,-22));
 //blptr->Add(aptr);
 scene.Add(aptr);
 blptr->Adjust();

 /*
 gptr = new X3D_Group();
 gptr->set_translate(X3D_Coordinate(-4,-4,-28));
 scene.Add(gptr);
 tptr = new X3D_Text("Unrotated");
 gptr->Add(tptr);
 X3D_Group * g2ptr = new X3D_Group();
 gptr->Add(g2ptr);
 tptr = new X3D_Text("Rotated");
 g2ptr->Add(tptr);
 g2ptr->set_rotation(X3D_Coordinate(0,0,.3));
 */
 if(display){
	int result = scene.SaveToFile("Block");
	Memo1->Lines->Add(AnsiString("Block.x3d was written, objects written: ")+result);
	}
}


void __fastcall TForm1::BlockTest(TObject *Sender)
{
 Memo1->Clear();
 DoBlock(true);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Aligner(TObject *Sender)
{
 DoAlign(true);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DoAlign(bool display)
{
 // Create a line of several blocks - Aligned in X
 X3D scene;
 X3D_Text * tptr;
 X3D_Block * blptr;
 X3D_Arrow * aptr;
 X3D_Box * boxptr;
 //AddAxes(scene);
 /*
 blptr = new X3D_Block();
 blptr->set_translate(X3D_Coordinate(1,12,-18));
 scene.Add(blptr);
 tptr = new X3D_Text("W: First Line, which is really large");
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
 aptr = new X3D_Arrow(X3D_Coordinate(-17,0,0),X3D_Coordinate(-9.5,0,0));
 blptr->Add(aptr);
 aptr = new X3D_Arrow(X3D_Coordinate(9,0,0),X3D_Coordinate(12,0,0));
 blptr->Add(aptr);
 aptr = new X3D_Arrow(X3D_Coordinate(15,-1,0),X3D_Coordinate(9,-1,0));
 blptr->Add(aptr);
 blptr->Adjust();

 blptr->LeftJustify();
 */
 blptr = new X3D_Block();
 blptr->set_translate(X3D_Coordinate(1,1,-18));
 boxptr = dynamic_cast<X3D_Box *>(blptr->get_solid(0));
 boxptr->set_size(X3D_Coordinate(16,3,1));
 scene.Add(blptr);
 tptr = new X3D_Text("X: 1");
 tptr->set_color(X3D_Color(1,0,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("X: 2");
 tptr->set_color(X3D_Color(0,1,0));
 blptr->Add(tptr);
 // up and down
 aptr = new X3D_Arrow(X3D_Coordinate(0,8,0),X3D_Coordinate(0,2,0));
 aptr->set_color(X3D_Color(.2,.9,.7));
 blptr->Add(aptr);
 aptr = new X3D_Arrow(X3D_Coordinate(4,2,0),X3D_Coordinate(4,8,0));
 blptr->Add(aptr);
 aptr = new X3D_Arrow(X3D_Coordinate(5,2,0),X3D_Coordinate(5,8,0),false);
 blptr->Add(aptr);

 aptr = new X3D_Arrow(X3D_Coordinate(-4,0,0),X3D_Coordinate(-1,0,0));
 //blptr->Add(aptr);
 aptr = new X3D_Arrow(X3D_Coordinate(4,0,0),X3D_Coordinate(12,0,0));
 blptr->Add(aptr);
 aptr = new X3D_Arrow(X3D_Coordinate(9,-1,0),X3D_Coordinate(3,-1,0));
 blptr->Add(aptr);
 aptr = new X3D_Arrow(X3D_Coordinate(1,1,1),X3D_Coordinate(2,2,2));
 aptr->set_transparency(0.5);
 blptr->Add(aptr);

 X3D_Group * blkptr = new X3D_Group();
 blptr->Add(blkptr);
 blkptr->set_translate(X3D_Coordinate(1.5,1.5,1.5));
 X3D_Cylinder * cylptr = new X3D_Cylinder(X3D_Coordinate(1,1,1), X3D_Coordinate(2,2,2), .05);
 cylptr->set_color(X3D_Color(0,0,0));
 blkptr->Add(cylptr);


 blptr->Adjust();

 /*
 blptr = new X3D_Block();
 blptr->set_translate(X3D_Coordinate(1,-3,-18));
 scene.Add(blptr);
 tptr = new X3D_Text("Y first");
 tptr->set_color(X3D_Color(1,0,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("Y Second");
 tptr->set_color(X3D_Color(0,1,0));
 blptr->Add(tptr);
 blptr->Adjust();

 */
 if(display){
    int result = scene.SaveToFile("Align");
    Memo1->Lines->Add(AnsiString("Align.x3d was written, objects written: ")+result);
	ofstream outf("Align.lst");
	outf << scene.ToString().c_str();
	}

 /*
 scene.Clear();
 AddAxes(scene);

 blptr = new X3D_Block();
 blptr->set_translate(X3D_Coordinate(1,6,-18));
 scene.Add(blptr);
 tptr = new X3D_Text("W: First Line, which is really large");
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
 blptr->set_translate(X3D_Coordinate(1,2,-18));
 scene.Add(blptr);
 tptr = new X3D_Text("X: 1");
 tptr->set_color(X3D_Color(1,0,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("X: 2");
 tptr->set_color(X3D_Color(0,1,0));
 blptr->Add(tptr);
 blptr->Adjust();

 blptr = new X3D_Block();
 blptr->set_translate(X3D_Coordinate(1,-2,-18));
 scene.Add(blptr);
 tptr = new X3D_Text("Y first");
 tptr->set_color(X3D_Color(1,0,1));
 blptr->Add(tptr);
 tptr = new X3D_Text("Y Second");
 tptr->set_color(X3D_Color(0,1,0));
 blptr->Add(tptr);
 blptr->Adjust();

 if(display){
	int result = scene.SaveToFile("Align2");
	Memo1->Lines->Add(AnsiString("Align2.x3d was written, objects written: ")+result);
	ofstream outf("Align2.lst");
	outf << scene.ToString().c_str();
	}

  */

}

void __fastcall TForm1::MemoryGroup(TObject *Sender)
{
 const int max = 10000000;
 Application->MessageBox(L"Memory test is about to begin - enable the memory monitor",L"Get Ready",MB_OK);
 Memo1->Lines->Add("Memory test begins");
 for(int i = 0;i<max;i++)
   DoGroup(false);
 Memo1->Lines->Add("Second Memory test complete");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Contain(TObject *Sender)
{
  DoContain(true);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DoContain(bool display){
 // Create a line of several blocks - Aligned in X
 X3D scene;
 X3D_Text * tptr;
 X3D_Group * gptr;
 X3D_Block * blptr;
 X3D_Arrow * aptr;
 //bX3D_Box * boxptr;

 aptr = new X3D_Arrow(X3D_Coordinate(-6,8,-10),X3D_Coordinate(0,6,-10));
 scene.Add(aptr);

 gptr = new X3D_Group();
 gptr->set_translate(X3D_Coordinate(-6,2,-10));
 scene.Add(gptr);
 tptr = new X3D_Text("One text group");
 gptr->Add(tptr);

 gptr = new X3D_Group();
 gptr->set_translate(X3D_Coordinate(-5,-2,-10));
 scene.Add(gptr);
 tptr = new X3D_Text("Group containing a block etc.");
 gptr->Add(tptr);
 blptr = new X3D_Block(X3D_Coordinate(0,-2,0));
 gptr->Add(blptr);
 tptr = new X3D_Text("Block's text.");
 tptr->set_translate(X3D_Coordinate(0,-1,0));
 blptr->Add(tptr);
 aptr = new X3D_Arrow(X3D_Coordinate(-8,0,0),X3D_Coordinate(0,0,0));
 blptr->Add(aptr);
 blptr->Adjust();
/*
 blptr = new X3D_Block(X3D_Coordinate(0,-2,0));
 scene.Add(blptr);
 tptr = new X3D_Text("Block's text.");
 tptr->set_translate(X3D_Coordinate(0,-1,0));
 blptr->Add(tptr);
 aptr = new X3D_Arrow(X3D_Coordinate(-8,0,0),X3D_Coordinate(0,0,0));
 blptr->Add(aptr);
 blptr->Adjust();
*/

 if(display){
	int result = scene.SaveToFile("Contain");
	Memo1->Lines->Add(AnsiString("Contain.x3d was written, objects written: ")+result);
	ofstream outf("Contain.lst");
	outf << scene.ToString().c_str();
	}

}

