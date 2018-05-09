// X3D_Text
#ifndef __X3D_Text
#define __X3D_Text
#include "x3d_solid.h"


class X3D_Text : public X3D_Solid{
   X3D_Text (const X3D_Text & );
   X3D_Text operator = (const X3D_Text &);

 protected:
   X3D_String text;
   float length, max_extent;
  virtual X3D_String X3D_Shape_XML()const;
   X3D_String Name() const {return "Text";}
 public:
   X3D_Text();
   X3D_Text(const X3D_String & parm1);

  //Accessor functions
   X3D_String get_text() const {return text;}
   void  set_text(const X3D_String& param0){ text = param0;}

  // You must implement
   virtual X3D_String ToString() const;
   //virtual X3D_String ToXML() const;

};

#endif