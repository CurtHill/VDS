// X3D_Box
#ifndef __X3D_Box
#define __X3D_Box
#include "x3d_solid.h"


class X3D_Box : public X3D_Solid{
   X3D_Box (const X3D_Box & );
   X3D_Box operator = (const X3D_Box &);

 protected:
   X3D_Coordinate size;

   virtual X3D_String X3D_Shape_XML()const;
   X3D_String Name() const {return "Box";}
 public:
   X3D_Box();
   X3D_Box(X3D_Coordinate parm1);

  //Accessor functions
   X3D_Coordinate get_size() const {return size;}
   void  set_size(const X3D_Coordinate& param0){ size = param0;}

  // You must implement
   virtual X3D_String ToString() const;
   //virtual X3D_String ToXML() const;

};

#endif