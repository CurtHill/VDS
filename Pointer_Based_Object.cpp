// Pointer_Based_Object
#include "Pointer_Based_Object.h"
#include <assert.h>

//unsigned Pointer_Based_Object::current_id=ORIGINAL_ID;

Pointer_Based_Object::Pointer_Based_Object():
           length(0){}

Pointer_Based_Object::Pointer_Based_Object (const Pointer_Based_Object & that){
  id = that.id;
  length = that.length;
  pointers = that.pointers;
  displays = that.displays;
}

Pointer_Based_Object  Pointer_Based_Object::operator =  (const Pointer_Based_Object & that){
  id = that.id;
  length = that.length;
  pointers = that.pointers;
  displays = that.displays;
  return *this;
}

bool Pointer_Based_Object::operator < (const Pointer_Based_Object & that)const{
  return id < that.id;
}

bool Pointer_Based_Object::operator == (const Pointer_Based_Object & that)const{
  return id == that.id;
}

X3D_String Pointer_Based_Object::ToString(X3D_String indent)const{
 X3D_String line = X3D_String("Pointer Based Object\n")
  #ifdef CB4
     + indent + "Length: "
     +length+
     "\n" + indent + "Number of pointers: "+pointers.size()+
     "\n" + indent + "Number of displays: "+displays.size() + "\n" + indent +
     #endif
  #ifdef CB10
	 + indent + "Length: "
	 +length+
	 "\n" + indent + "Number of pointers: "+pointers.size()+
	 "\n" + indent + "Number of displays: "+displays.size() + "\n" + indent +
	 #endif
  #ifdef DEV
	 << indent << "Length: "
	 <<length<<
	 "\n" << indent << "Number of pointers: " << pointers.size() <<
	 "\n" << indent << "Number of displays: " << displays.size() << "\n" << indent <<
	 #endif
  "Pointers:";

 X3D_String subindent = indent
 #ifdef CB4
	+ " ";
	#endif
 #ifdef CB10
	+ " ";
	#endif
 #ifdef DEV
	<<  " ";
	#endif
 #ifdef VS
	+ " ";
	#endif

 for(unsigned i=0;i<pointers.size();i++)
   line = line
	 #ifdef CB4
		 + indent +
	   #endif
	 #ifdef CB10
		 + indent +
	   #endif
	 #ifdef DEV
		 <<  indent <<
	   #endif
	 #ifdef VS
		 + indent +
	   #endif
	pointers[i].ToString(subindent);
 line = line
	 #ifdef CB4
		 +  indent +  "\n" + indent +
	   #endif
	 #ifdef CB10
		 +  indent +  "\n" + indent +
	   #endif
	 #ifdef DEV
		 <<  indent <<  "\n" << indent <<
	   #endif
	 #ifdef VS
		 +  indent +  "\n" + indent +
	   #endif
  "Displays:";
 for(unsigned i=0;i<displays.size();i++)
   line = line
	 #ifdef CB4
		 +  indent +
	   #endif
	 #ifdef CB10
		 +  indent +
	   #endif
	 #ifdef DEV
		 <<  indent <<
	   #endif
	 #ifdef VS
		 +  indent +
	   #endif
	displays[i].ToString(subindent);
 return line;
}

Visual_Pointer Pointer_Based_Object::get_pointer(unsigned index)const{
 assert(index < pointers.size());
 return pointers[index];
}

Visual_Display Pointer_Based_Object::get_display(unsigned index) const{
 assert(index < displays.size());
 return displays[index];
}


