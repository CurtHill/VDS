// X3D_Box
#include "X3D_Box.h"


X3D_Box::X3D_Box():X3D_Solid(){}

X3D_Box::X3D_Box (const X3D_Box & that):X3D_Solid(){
  size = that.size;
}

X3D_Box:: X3D_Box(X3D_Coordinate parm1):
       X3D_Solid(),
       size(parm1)
       {}

X3D_Box X3D_Box::operator =  (const X3D_Box & that){
  X3D_Solid::operator = (that);
  size = that.size;
  return *this;
}

X3D_String X3D_Box::ToString() const{
  X3D_String temp = X3D_Solid::ToString();
  #ifdef CB4
    temp = temp + ", sizes (" + size.ToString()+") ";
     #endif
  #ifdef VS
    temp = temp + ", sizes (" + size.ToString()+") ";
     #endif
  #ifdef DEV
    temp = temp << ", sizes (" << size.ToString()<<") ";
    #endif
  return temp;
}


X3D_String X3D_Box::X3D_Shape_XML()const{
  X3D_String temp = "";
  temp = temp
  #ifdef CB4
       + "<Box size=\"" + size.ToString() + "\"/>\n";
     #endif
  #ifdef CB10
	   + "<Box size=\"" + size.ToString() + "\"/>\n";
	 #endif
  #ifdef VS
       + "<Box size=\"" + size.ToString() + "\"/>\n";
     #endif
  #ifdef DEV
       << "<Box size=\"" << size.ToString() << "\"/>\n";
    #endif
  return temp;
}
