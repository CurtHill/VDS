// X3D_Coordinate
#ifndef __X3D_Coordinate
#define __X3D_Coordinate


#include "X3D_Defines.h"

#define X3D_COORDINATE_FUZZ 0.001


class X3D_Coordinate {

 protected:
   float x;
   float y;
   float z;
 public:
   X3D_Coordinate();
   X3D_Coordinate (const X3D_Coordinate & );

   X3D_Coordinate operator = (const X3D_Coordinate &);
   X3D_Coordinate operator += (const X3D_Coordinate &);
   X3D_Coordinate operator -= (const X3D_Coordinate &);
   X3D_Coordinate(float parm1, float parm2, float parm3);

   X3D_Coordinate operator + (const X3D_Coordinate & that)const;
   X3D_Coordinate operator - (const X3D_Coordinate & that)const;

  //Accessor functions
   float get_x() const {return x;}
   void  set_x(const float& param0){ x = param0;}
   float get_y() const {return y;}
   void  set_y(const float& param0){ y = param0;}
   float get_z() const {return z;}
   void  set_z(const float& param0){ z = param0;}
   bool operator == (const X3D_Coordinate & that)const;
   bool operator != (const X3D_Coordinate & that)const{
        return !(*this == that);}

   float Distance(X3D_Coordinate);
   X3D_Coordinate Mid(X3D_Coordinate);
   X3D_Coordinate Angle(X3D_Coordinate);
   X3D_String ToString() const;

};

#endif
