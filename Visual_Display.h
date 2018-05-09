// Visual_Display
#ifndef __Visual_Display
#define __Visual_Display
#include "Display_Type.h"
#include "X3D.h"

class Visual_Display {

 protected:
   unsigned location;
   Display_Type type;
   X3D_String name;
 public:
   Visual_Display();
   Visual_Display (const Visual_Display & );

   Visual_Display operator = (const Visual_Display &);
   Visual_Display(unsigned parm1, Display_Type parm2, X3D_String n);

  //Accessor functions
   unsigned get_location() const {return location;}
   void  set_location(const unsigned& param0){ location = param0;}
   Display_Type get_type() const {return type;}
   void  set_type(const Display_Type& param0){ type = param0;}
   X3D_String get_name() const {return name;}

  // You must implement
   X3D_String ToString(X3D_String indent = "")const;

};

#endif
