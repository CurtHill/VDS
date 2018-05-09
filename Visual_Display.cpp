// Visual_Display
#include "Visual_Display.h"


Visual_Display::Visual_Display(){}

Visual_Display::Visual_Display (const Visual_Display & that){
  location = that.location;
  type = that.type;
  name = that.name;
}

Visual_Display:: Visual_Display(unsigned parm1, Display_Type parm2, X3D_String n):
       location(parm1),
       type(parm2),
       name(n)
       {}

Visual_Display Visual_Display::operator =  (const Visual_Display & that){
  location = that.location;
  type = that.type;
  name = that.name;
  return *this;
}

X3D_String Visual_Display::ToString(X3D_String indent)const{
  return X3D_String("\n")
    #ifdef CB4
     + indent +   "Visual Display. Location: " +
     +location+", Type: "+::ToString(type)+", Name: "+
     #endif
	#ifdef CB10
	 + indent +   "Visual Display. Location: " +
	 +location+", Type: "+::ToString(type)+", Name: "+
	 #endif
	#ifdef DEV
	 << indent << "Visual Display. Location: " <<
	 <<location<<", Type: " << ::ToString(type) << ", Name: " <<
	 #endif
	#ifdef VS
	 + indent +   "Visual Display. Location: " +
	 +location+", Type: "+::ToString(type)+", Name: "+
	 #endif
	 name;
}

