// X3D_Cone
#ifndef __X3D_Cone
#define __X3D_Cone
#include "x3d_solid.h"


class X3D_Cone : public X3D_Solid{
   X3D_Cone (const X3D_Cone & );
   X3D_Cone operator = (const X3D_Cone &);

 protected:
   float radius, height;
  virtual X3D_String X3D_Shape_XML()const;
  X3D_String Name() const {return "Cone";}
 public:
   X3D_Cone();
   X3D_Cone(float h, float r);

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