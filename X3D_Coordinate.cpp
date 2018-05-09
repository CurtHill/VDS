// X3D_Coordinate
#include "X3D_Coordinate.h"


X3D_Coordinate::X3D_Coordinate(): 
           x(0),
           y(0),
           z(0){}

X3D_Coordinate::X3D_Coordinate (const X3D_Coordinate & that){
  x = that.x;
  y = that.y;
  z = that.z;
}

X3D_Coordinate:: X3D_Coordinate(float parm1, float parm2, float parm3):
       x(parm1),
       y(parm2),
       z(parm3)
       {}

X3D_Coordinate X3D_Coordinate::operator =  (const X3D_Coordinate & that){
  x = that.x;
  y = that.y;
  z = that.z;
  return *this;
}

X3D_Coordinate X3D_Coordinate::operator +=  (const X3D_Coordinate & that){
  x += that.x;
  y += that.y;
  z += that.z;
  return *this;
}

X3D_Coordinate X3D_Coordinate::operator -=  (const X3D_Coordinate & that){
  x -= that.x;
  y -= that.y;
  z -= that.z;
  return *this;
}

X3D_String X3D_Coordinate::ToString() const{
  return
  #ifdef CB4
     AnsiString("")+x+" "+y+" "+z;
     #endif
  #ifdef CB10
	 String("")+x+" "+y+" "+z;
	 #endif
  #ifdef VS
     to_string(x)+" "+to_string(y)+" "+to_string(z);
     #endif
  #ifdef DEV
    wxString("")<<x<<" "<<y<<" "<<z;
     #endif
}

X3D_Coordinate X3D_Coordinate::operator + (const X3D_Coordinate & that)const{
  X3D_Coordinate temp;
  temp.x = x+that.x;
  temp.y = y+that.y;
  temp.z = z+that.z;
  return temp;
}

X3D_Coordinate X3D_Coordinate::operator - (const X3D_Coordinate & that)const{
  X3D_Coordinate temp;
  temp.x = x-that.x;
  temp.y = y-that.y;
  temp.z = z-that.z;
  return temp;
}



bool X3D_Coordinate::operator == (const X3D_Coordinate & that)const{
 return
       fabs(x-that.x)<X3D_COORDINATE_FUZZ &&
       fabs(y-that.y)<X3D_COORDINATE_FUZZ &&
       fabs(z-that.z)<X3D_COORDINATE_FUZZ;
}

float X3D_Coordinate::Distance(X3D_Coordinate that){
 return sqrt(fabs(x-that.x)*fabs(x-that.x) +
             fabs(y-that.y)*fabs(y-that.y) +
             fabs(z-that.z)*fabs(z-that.z));
}

X3D_Coordinate X3D_Coordinate::Mid(X3D_Coordinate that){
 X3D_Coordinate result((x+that.x)/2,(y+that.y)/2,(z+that.z)/2);
 return result;
}

X3D_Coordinate X3D_Coordinate::Angle(X3D_Coordinate that){
 float delta_x = x-that.x;
 float delta_y = y-that.y;
 float delta_z = z-that.z;
 float th_x=0,th_y=0,th_z=0;
 if(!(delta_z==0&&delta_y==0))
   th_x = atan2(delta_y,delta_z) + M_PI/2;
 if(!(delta_z==0&&delta_x==0))
   th_y =atan2(delta_z,delta_x) + M_PI/2;
 if(!(delta_x==0&&delta_y==0))
   th_z = atan2(delta_y,delta_x) + M_PI/2;
 // Zero things close to zero
 if(th_x<1E-8 && th_x>-1E-8)
   th_x = 0;
 if(th_y<1E-8 && th_y>-1E-8)
   th_y = 0;
 if(th_z<1E-8 && th_z>-1E-8)
   th_z = 0;
 return X3D_Coordinate(th_x,th_y,th_z);
}
