// X3D_Sphere
#ifndef __X3D_Sphere
#define __X3D_Sphere
#include "x3d_solid.h"

class X3D_Sphere: public X3D_Solid {

   X3D_Sphere (const X3D_Sphere & );
   X3D_Sphere operator = (const X3D_Sphere &);
 protected:
   float radius;
  virtual X3D_String X3D_Shape_XML()const;
  X3D_String Name() const {return "Sphere";}
 public:
   X3D_Sphere();
   X3D_Sphere(float parm1);

  //Accessor functions
   float get_radius() const {return radius;}
   void  set_radius(const float& param0){ radius = param0;}
   virtual X3D_String ToString() const;
   //virtual X3D_String ToXML() const;

};

#endif