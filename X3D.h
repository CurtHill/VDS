// X3D - Container for X3D style Scene graph
#ifndef __X3D
#define __X3D

#include <fstream>
#include <vector>
using namespace std;
#include "X3D_Sphere.h"
#include "X3D_Box.h"
#include "X3D_Text.h"
#include "X3D_Cone.h"
#include "X3D_Cylinder.h"
#include "X3D_Group.h"
#include "X3D_Block.h"
#include "X3D_Arrow.h"

class X3D {

 protected:
   vector<X3D_SolidPtr> solids;
   static X3D_String prefix, suffix;

 public:
   X3D();
   ~X3D();

  //Accessor functions
  void Add(X3D_SolidPtr p){solids.push_back(p);}
  X3D_SolidPtr Get(unsigned i);
  unsigned SaveToFile(const char * fn);
  unsigned Size() const {return solids.size();}
  void Clear();
  X3D_String ToString() const;
};

#endif
