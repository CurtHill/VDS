// X3D_Arrow
#include "X3D_Arrow.h"
#include "X3D_Cone.h"
#include "X3D_Cylinder.h"
#include <assert.h>

X3D_Arrow::X3D_Arrow():X3D_Group(){
 X3D_Cone * cop = new X3D_Cone(.5, .2);
 cop->set_color(X3D_Color(1,1,1));
 X3D_Group::Add(cop);
 X3D_Cylinder * cyp = new X3D_Cylinder(2,.125);
 X3D_Group::Add(cyp);
 cyp->set_translate(X3D_Coordinate(0,-1.25,0));
 cyp->set_color(X3D_Color(1,0.7,0.7));
 has_cone = true;
}


// The hard one
// Must start at origin, rotate individually and then move individually
X3D_Arrow::X3D_Arrow(X3D_Coordinate src, X3D_Coordinate dest, bool hascone){
 has_cone = hascone;
 float d = src.Distance(dest);
 X3D_Cylinder * cyp;
 cyp = new X3D_Cylinder(d,.125);
 //cyp = new X3D_Cylinder(src,dest,.125);
 Add(cyp);
 //cyp->set_translate(X3D_Coordinate(0,-1.25,0));
 cyp->set_color(X3D_Color(1,0.7,0.7));

 X3D_Coordinate angle = src.Angle(dest);
 if(has_cone){
   X3D_Cone * cop = new X3D_Cone(.5, .2);
   cop->set_translate(X3D_Coordinate(0,d/2,0));
   cop->set_color(X3D_Color(1,1,1));
   Add(cop);
   cop->set_rotation(angle);
   }
 cyp->set_rotation(angle);
 set_translate(src.Mid(dest));
}

void X3D_Arrow::set_transparency(float t){
  items[0]->set_transparency(t);
  items[1]->set_transparency(t);
}

X3D_Arrow::X3D_Arrow (const X3D_Arrow & that):X3D_Group(){}

X3D_String X3D_Arrow::Name() const {
  return X3D_String("Arrow (")
  #ifdef CB4
    + items.size() +
    #endif
  #ifdef CB10
	+ items.size() +
	#endif
  #ifdef VS
    + items.size() +
    #endif
  #ifdef DEV
    << items.size() <<
    #endif
  ")";
}


