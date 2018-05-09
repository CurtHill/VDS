// X3D_Color
#ifndef __X3D_Color
#define __X3D_Color

#include "X3D_Defines.h"

#define X3D_COLOR_FUZZ 0.01
class X3D_Color {

 protected:
   float red;
   float green;
   float blue;
 public:
   X3D_Color();
   X3D_Color (const X3D_Color & );

   X3D_Color operator = (const X3D_Color &);
   X3D_Color(float parm1, float parm2, float parm3);

  //Accessor functions
   float get_red() const {return red;}
   void  set_red(const float& param0){ red = param0>=0&&param0<=1?param0:0;}
   float get_green() const {return green;}
   void  set_green(const float& param0){ green = param0>=0&&param0<=1?param0:0;}
   float get_blue() const {return blue;}
   void  set_blue(const float& param0){ blue = param0>=0&&param0<=1?param0:0;}
   bool operator == (const X3D_Color & that)const;
   bool operator != (const X3D_Color & that)const{
        return !(*this == that);}

  // You must implement
   X3D_String ToString() const;

};

#endif