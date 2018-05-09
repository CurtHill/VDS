// Visual_Pointer
#ifndef __Visual_Pointer
#define __Visual_Pointer
#include "Display_Type.h"
#include "X3D.h"


class Visual_Pointer {

 protected:
   unsigned pointer;
   unsigned type;
   X3D_String name;

 public:
   Visual_Pointer();
   Visual_Pointer (const Visual_Pointer & );

   Visual_Pointer operator = (const Visual_Pointer &);
   Visual_Pointer(unsigned parm1, unsigned id,X3D_String n):pointer(parm1),type(id),name(n){}

  //Accessor functions
   unsigned get_pointer() const {return pointer;}
   void set_pointer(unsigned param0){ pointer = param0;}
   unsigned get_type() const {return type;}
   void  set_type(unsigned param0){ type = param0;}
   X3D_String get_name() const {return name;}

  // You must implement
   X3D_String ToString(X3D_String indent = "")const;

};

#endif
