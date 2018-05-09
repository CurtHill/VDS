// X3D_Cylinder
#include "X3D_Cylinder.h"


X3D_Cylinder::X3D_Cylinder():X3D_Solid(){}

X3D_Cylinder::X3D_Cylinder (const X3D_Cylinder & that):X3D_Solid(){
  radius = that.radius;
  height = that.height;
}

X3D_Cylinder:: X3D_Cylinder(float h, float r):
       X3D_Solid(),
       height(h),
       radius(r)
       {}

X3D_Cylinder::X3D_Cylinder(X3D_Coordinate src, X3D_Coordinate dest, float r){
  height = src.Distance(dest);
  radius = r;
  X3D_Coordinate angle = src.Angle(dest);
  set_rotation(angle);
  //set_translate(src.Mid(dest));
  set_color(X3D_Color(1,0.7,0.7));
  #ifdef CB4
    Append_Commentary(src.ToString()+" "+dest.ToString());
    #endif
}

X3D_Cylinder X3D_Cylinder::operator =  (const X3D_Cylinder & that){
  X3D_Solid::operator = (that);
  radius = that.radius;
  return *this;
}

X3D_String X3D_Cylinder::ToString() const{
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
X3D_String X3D_Cylinder::ToXML() const{
  X3D_String temp = X3D_Solid::XML_Start();
  #ifdef CB4
     temp = temp + "<Cylinder radius=\"" + radius + "\" height=\""+height+"\"/>\n"+ X3D_Solid::XML_End();
     #endif
  #ifdef DEV
     temp = temp << "<Cylinder radius=\"" << radius << "\" height=\""<<height<<"\"/>\n"<< X3D_Solid::XML_End();
    #endif
  return temp;
}
*/

X3D_String X3D_Cylinder::X3D_Shape_XML()const{
  X3D_String temp = "";
  temp = temp
  #ifdef CB4
       + "<Cylinder radius=\"" + radius + "\" height=\""+height+"\"/>\n";
     #endif
  #ifdef CB10
	   + "<Cylinder radius=\"" + radius + "\" height=\""+height+"\"/>\n";
	 #endif
  #ifdef DEV
       << "<Cylinder radius=\"" << radius << "\" height=\""<<height<<"\"/>\n";
    #endif
  return temp;
}
