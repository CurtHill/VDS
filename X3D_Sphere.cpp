// X3D_Sphere
#include "X3D_Sphere.h"


X3D_Sphere::X3D_Sphere():X3D_Solid(),
           radius(1){}

X3D_Sphere::X3D_Sphere (const X3D_Sphere & that):X3D_Solid(){
  radius = that.radius;
}

X3D_Sphere:: X3D_Sphere(float parm1):
       X3D_Solid(),
       radius(parm1)
       {}

X3D_Sphere X3D_Sphere::operator =  (const X3D_Sphere & that){
  X3D_Solid::operator = (that);
  radius = that.radius;
  return *this;
}

X3D_String X3D_Sphere::ToString() const{
  X3D_String temp = X3D_Solid::ToString();
  #ifdef CB4
    temp = temp + ", radius " + radius;
     #endif
  #ifdef VS
    temp = temp + ", radius " + radius;
     #endif
  #ifdef DEV
    temp = temp << ", radius " << radius;
    #endif
  return temp;
}

/*
X3D_String X3D_Sphere::ToXML() const{
  X3D_String temp = X3D_Solid::XML_Start();
  #ifdef CB4
     temp = temp + "<Sphere radius=\"" + radius + "\"/>"+ X3D_Solid::XML_End();
     #endif
  #ifdef DEV
     temp = temp << "<Sphere radius=\"" << radius << "\"/>"<< X3D_Solid::XML_End();
    #endif
  return temp;
}
*/

X3D_String X3D_Sphere::X3D_Shape_XML()const{
  X3D_String temp = "";
  temp = temp
  #ifdef CB4
       + "<Sphere radius=\"" + radius + "\"/>\n";
     #endif
  #ifdef CB10
	   + "<Sphere radius=\"" + radius + "\"/>\n";
	 #endif
  #ifdef VS
       + "<Sphere radius=\"" + radius + "\"/>\n";
     #endif
  #ifdef DEV
       << "<Sphere radius=\"" << radius << "\"/>\n";
    #endif
  return temp;
}
