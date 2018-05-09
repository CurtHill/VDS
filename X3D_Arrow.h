// X3D_Arrow - A group containing a cone and cylinder
#ifndef __X3D_Arrow
#define __X3D_Arrow
#include "x3d_group.h"

/*
  A very specialized Group making an Arrow
*/

class X3D_Arrow : public X3D_Group{

   X3D_Arrow();
   X3D_Arrow (const X3D_Arrow & );
 protected:
  bool has_cone;

  X3D_String Name() const;

 public:
   X3D_Arrow(X3D_Coordinate src, X3D_Coordinate dest,bool hascone=true);
   void set_transparency(float t);
};

#endif