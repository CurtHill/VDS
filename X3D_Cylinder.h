// X3D_Cylinder
#ifndef __X3D_Cylinder
#define __X3D_Cylinder
#include "x3d_solid.h"


class X3D_Cylinder : public X3D_Solid{
   X3D_Cylinder (const X3D_Cylinder & );
   X3D_Cylinder operator = (const X3D_Cylinder &);

 protected:
   float radius, height;
  virtual X3D_String X3D_Shape_XML()const;
  X3D_String Name() const {return "Cylinder";}
 public:
   X3D_Cylinder();
   X3D_Cylinder(float h, float r);
   X3D_Cylinder(X3D_Coordinate src, X3D_Coordinate dest, float r);


  //Accessor functions
   float get_height() const {return height;}
   void  set_height(float param0){ height = param0;}
   float get_radius() const {return radius;}
   void  set_radius(float param0){ radius = param0;}

  // You must implement
   virtual X3D_String ToString() const;
   //virtual X3D_String ToXML() const;

};

#endif