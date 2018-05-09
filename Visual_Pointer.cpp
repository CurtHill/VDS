// Visual_Pointer
#include "Visual_Pointer.h"


Visual_Pointer::Visual_Pointer(){}

Visual_Pointer::Visual_Pointer (const Visual_Pointer & that){
  pointer = that.pointer;
  type = that.type;
  name = that.name;
}

Visual_Pointer Visual_Pointer::operator =  (const Visual_Pointer & that){
  pointer = that.pointer;
  type = that.type;
  name = that.name;
  return *this;
}

X3D_String Visual_Pointer::ToString(X3D_String indent)const{
  return X3D_String ("\n")
   #ifdef CB4
      + indent + "Visual Pointer. Pointer offset: " +
      + pointer + ", PBO type: " + type + ", name: " +
      #endif
   #ifdef CB10
	  + indent + "Visual Pointer. Pointer offset: " +
	  + pointer + ", PBO type: " + type + ", name: " +
	  #endif
   #ifdef DEV
	  << indent << "Visual Pointer. Pointer offset: " <<
	  << pointer << ", PBO type: " << type << ", name: " <<
	  #endif
   #ifdef VS
	  + indent + "Visual Pointer. Pointer offset: " +
	  + pointer + ", PBO type: " + type + ", name: " +
	  #endif
  name;
}




