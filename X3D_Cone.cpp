// X3D_Cone
#include "X3D_Cone.h"


X3D_Cone::X3D_Cone():X3D_Solid(){}

X3D_Cone::X3D_Cone (const X3D_Cone & that):X3D_Solid(){
  radius = that.radius;
  height = that.height;
}

X3D_Cone:: X3D_Cone(float h, float r):
       X3D_Solid(),
       height(h),
       radius(r)
       {}

X3D_Cone X3D_Cone::operator =  (const X3D_Cone & that){
  X3D_Solid::operator = (that);
  radius = that.radius;
  return *this;
}

X3D_String X3D_Cone::ToString() const{
  X3D_String temp = X3D_Solid::ToString();
  #ifdef CB4
    temp = temp + ", radius (" + radius+") " + ", height (" + height + ") ";
     #endif
  #ifdef DEV
    temp = temp << ", radius (" << radius << ") " << ", height (" << height <<") ";
    #endif
  return temp;
}

/*
X3D_String X3D_Cone::ToXML() const{
  X3D_String temp = X3D_Solid::XML_Start();
  #ifdef CB4
     temp = temp + "<Cone bottomRadius=\"" + radius + "\" height=\""+height+"\"/>\n"+ X3D_Solid::XML_End();
     #endif
  #ifdef DEV
     temp = temp << "<Cone bottomRadius=\"" << radius << "\" height=\""<<height<<"\"/>\n"<< X3D_Solid::XML_End();
    #endif
  return temp;
}
*/

X3D_String X3D_Cone::X3D_Shape_XML()const{
  X3D_String temp = "";
  temp = temp
  #ifdef CB4
       + "<Cone bottomRadius=\"" + radius + "\" height=\""+height+"\"/>";
     #endif
  #ifdef CB10
	   + "<Cone bottomRadius=\"" + radius + "\" height=\""+height+"\"/>";
	 #endif
  #ifdef DEV
       << "<Cone bottomRadius=\"" << radius << "\" height=\""<<height<<"\"/>\n";
    #endif
  return temp;
}
