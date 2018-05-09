// X3D_Block
#include "X3D_Block.h"
#include <assert.h>

X3D_Block::X3D_Block():X3D_Group(){
 X3D_Box * bp = new X3D_Box(X3D_Coordinate(1,2,1));
 X3D_Group::Add(bp);
 bp->set_transparency(.7);
 bp->set_color(X3D_Color(0,0,0));
}

X3D_Block::X3D_Block(X3D_Coordinate parm1){
 set_translate(parm1);
 X3D_Box * bp = new X3D_Box(X3D_Coordinate(1,2,1));
 X3D_Group::Add(bp);
 bp->set_transparency(.7);
 bp->set_color(X3D_Color(0,0,0));
}

X3D_Block::X3D_Block (const X3D_Block & that):X3D_Group(){}

X3D_Block::~X3D_Block(){
 X3D_Group::Clear();
}


void __fastcall X3D_Block::Add(X3D_SolidPtr p){
  // Only examine text items
  float width;
  X3D_Box * boxptr = dynamic_cast<X3D_Box *>(items[0]);
  assert (boxptr);
  X3D_Text * tptr = dynamic_cast<X3D_Text *>(p);
  if(tptr){
    X3D_String s = tptr->get_text();
    width = s.
     #ifdef CB4
        Length();
        #endif
	 #ifdef CB10
		Length();
		#endif
	 #ifdef VS
		Length();
		#endif
	 #ifdef DEV
		length();
		 #endif
	X3D_Coordinate size = boxptr->get_size();
	if(width/2 > size.get_x()){
	  size.set_x(width/2.0);
	  boxptr->set_size(size);
	  }

	p->set_scale(X3D_Coordinate(.9,.9,.9));
	}
  X3D_Group::Add(p);
  //adjust(); // Done to whole block not individually
}

void __fastcall X3D_Block::LeftJustify(){
 // Text starts at center - indent to left
 unsigned lines = items.size();
 X3D_Box * boxptr = dynamic_cast<X3D_Box *>(items[0]);
 assert(boxptr);
 for(unsigned i = 1;i<lines;i++){
   X3D_Text * ptr = dynamic_cast<X3D_Text *>(items[i]);
   if(ptr) { // it is a text item
	 X3D_Coordinate coord = ptr->get_translate();
	 X3D_Coordinate sizes = boxptr->get_size();
	 coord.set_x(-sizes.get_x()/2 + 0.25);
	 coord.set_y(-float(i) + sizes.get_y()/1.85);
	 ptr->set_translate(coord);
	 }
  }
}

bool __fastcall X3D_Block::Close(float a,float b){
 return fabs(a-b) < .2;
}

void __fastcall X3D_Block::ArrowAdjust(X3D_Box * bptr, X3D_Arrow * aptr){
  // Adjust an arrow so that the right or left edge is close to box edge
  X3D_Cylinder * cptr = dynamic_cast<X3D_Cylinder *>(aptr->get_solid(0));
  assert(cptr);
  X3D_Coordinate rot = cptr->get_rotation(); // This should be the cylinder
  float yrot = rot.get_y(), zrot = rot.get_z();
  if(!(Close(yrot,4.7123) && Close(zrot,4.7123) || Close(yrot,1.570) && Close(zrot,1.570)))
	return; // only deal with horizontals
  float left, right = bptr->get_size().get_x()/2;
  left = -right;
  float arrow_length = cptr->get_height();
  float arrow_x = aptr->get_translate().get_x();
  float box_width = bptr->get_size().get_x();
  float pos = arrow_length/2 + box_width/2;
  rot = aptr->get_translate();
  Append_Commentary(X3D_String("Arrow coord was: ")+rot.ToString());
  if(rot.get_x() < 0)
	rot.set_x(-pos-.5);
  else
	rot.set_x(pos+.5);
  Append_Commentary(X3D_String("Arrow adjusted to: ")+rot.ToString());
  aptr->set_translate(rot);
}

// Reset the sizes of things
void __fastcall X3D_Block::Adjust(){
 unsigned lines = 1;
 unsigned width = 5;
 X3D_Box * bptr = dynamic_cast<X3D_Box *>(items[0]);
 assert(bptr);
 // First find the maximum size of the text in this box
 for(unsigned i = 0;i<items.size();i++){
   X3D_Text * ptr = dynamic_cast<X3D_Text *>(items[i]);
   if(ptr) { // it is a text item
	 lines++;
	 X3D_String t = ptr->get_text();
	 unsigned len = t
		 #ifdef CB4
			.Length();
			#endif
		 #ifdef CB10
			.Length();
			#endif
		 #ifdef VS
			.Length();
			#endif
		 #ifdef DEV
			.length();
			#endif
	 if(len > width)
	   width = len;
	 }
   X3D_Arrow * aptr = dynamic_cast<X3D_Arrow *>(items[i]);
   if(aptr)
	 ArrowAdjust(bptr,aptr);
  }
 width += 1;
 // Now we have maximum width and length - resize box
 // Never make it smaller
 bptr->Append_Commentary(X3D_String("Width: ")
	#ifdef CB4
	   +
	   #endif
	#ifdef CB10
	   +
	   #endif
	#ifdef VS
	   +
	   #endif
	#ifdef DEV
	   <<
	   #endif
	width);
 X3D_Coordinate loc = bptr->get_translate();
 X3D_Coordinate sizes = bptr->get_size();
 if(width*0.5 > sizes.get_x())
   sizes.set_x(width*0.5);
 if(lines*0.85 > sizes.get_y())
   sizes.set_y(lines*0.85);
 if(1 > sizes.get_z())
   sizes.set_z(1);

 bptr->set_size(sizes);

 LeftJustify();

}


