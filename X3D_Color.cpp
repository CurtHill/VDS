// X3D_Color
#include "X3D_Color.h"


X3D_Color::X3D_Color():
           red(0.5),
           green(0.5),
           blue(0.5){}

X3D_Color::X3D_Color (const X3D_Color & that){
  red = that.red;
  green = that.green;
  blue = that.blue;
}

X3D_Color:: X3D_Color(float parm1, float parm2, float parm3) {
 red = parm1>=0&&parm1<=1?parm1:0;
 green = parm2>=0&&parm2<=1?parm2:0;
 blue = parm3>=0&&parm3<=1?parm3:0;
}

X3D_Color X3D_Color::operator =  (const X3D_Color & that){
  red = that.red;
  green = that.green;
  blue = that.blue;
  return *this;
}

bool X3D_Color::operator == (const X3D_Color & that)const{
 return
       fabs(red-that.red)<X3D_COLOR_FUZZ &&
       fabs(green-that.green)<X3D_COLOR_FUZZ &&
       fabs(blue-that.blue)<X3D_COLOR_FUZZ;
}

X3D_String X3D_Color::ToString()const{
  return
  #ifdef CB4
     AnsiString("")+red+" "+green+" "+blue;
     #endif
  #ifdef CB10
	 String("")+red+" "+green+" "+blue;
	 #endif
  #ifdef VS
     to_string(red)+" "+to_string(green)+" "+to_string(blue);
     #endif
  #ifdef DEV
     wxString("")<<red<<" "<<green<<" "<<blue;
     #endif
}
