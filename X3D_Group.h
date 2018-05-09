// X3D_Group
#ifndef __X3D_Group
#define __X3D_Group
#include <vector>
using namespace std;
#include "x3d_solid.h"


class X3D_Group : public X3D_Solid{
  virtual X3D_Group operator = (const X3D_Group &); 
   X3D_Group (const X3D_Group & );

 protected:
   vector<X3D_SolidPtr> items;

  virtual X3D_String X3D_Shape_XML()const;
   X3D_String Name() const {return "Group";}
 public:
   X3D_Group();
   virtual ~X3D_Group();
   virtual void Clear();

   X3D_SolidPtr get_solid(unsigned);
  //Accessor functions
  int get_size() const {return items.size();}

  // Add to group
  void __fastcall Add(X3D_SolidPtr p){items.push_back(p);}
  void __fastcall set_color(X3D_Color);

  // You must implement
   virtual X3D_String ToString() const;
   virtual X3D_String ToXML() const;

};

#endif