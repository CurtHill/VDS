// X3D_Block - A group containing a box, several lines of text and perhaps arrows
#ifndef __X3D_Block
#define __X3D_Block
#include "x3d_group.h"
#include "X3D_Box.h"
#include "X3D_Text.h"
#include "X3D_Arrow.h"
#include "X3D_Cylinder.h"



/*
  A very specialized Group
  The first item is a box
  The rest are test strings
*/

class X3D_Block : public X3D_Group{

   X3D_Block (const X3D_Block & );

 protected:

   // void __fastcall adjust();
   X3D_String Name() const {return "Block";}
   bool __fastcall Close(float,float);
 public:
   X3D_Block();
   ~X3D_Block();

   X3D_Block(X3D_Coordinate parm1);

  //Accessor functions
   void __fastcall Add(X3D_SolidPtr p);
   void __fastcall Adjust();
   void __fastcall LeftJustify();
   void __fastcall ArrowAdjust(X3D_Box *, X3D_Arrow * );
};

#endif