// Pointer_Based_Object
#ifndef __Pointer_Based_Object_
#define __Pointer_Based_Object_
#ifdef CB4
  #include <vcl.h>
  #endif
#include <vector>
using namespace std;
#include "Visual_Display.h"
#include "Visual_Pointer.h"

class Pointer_Based_Object {

 protected:
   unsigned id;
   unsigned length;
   vector<Visual_Pointer> pointers;
   vector<Visual_Display> displays;

 public:
   Pointer_Based_Object();
   Pointer_Based_Object (const Pointer_Based_Object & );

   Pointer_Based_Object operator = (const Pointer_Based_Object &);

  //Accessor functions
   void add_pointer(Visual_Pointer vp){pointers.push_back(vp);}
   Visual_Pointer get_pointer(unsigned)const;
   unsigned pointer_count() const {return pointers.size();}
   unsigned get_length() const {return length;}
   void  set_length(const unsigned& param0){ length = param0;}
   void add_display(const Visual_Display& param0){ displays.push_back(param0);}
   Visual_Display get_display(unsigned index) const;
   unsigned display_count() const {return displays.size();}
   // Comparisons
   bool operator < (const Pointer_Based_Object & that)const;
   bool operator <= (const Pointer_Based_Object & that)const{
        return (*this < that) || (*this == that);}
   bool operator > (const Pointer_Based_Object & that)const{
        return !((*this < that) || (*this == that));}
   bool operator >= (const Pointer_Based_Object & that)const{
        return (!(*this < that) || (*this == that));}
   bool operator == (const Pointer_Based_Object & that)const;
   bool operator != (const Pointer_Based_Object & that)const{
        return !(*this == that);}

  // You must implement
   X3D_String ToString(X3D_String indent = "")const;

};

#endif
