// VDS
#ifndef __Visual_Data_Structure
#define __Visual_Data_Structure
#include <vector>
#include <map>
using namespace std;
#include "X3D.h"
#include "Pointer_Based_Object.h"
#define SELFID 10000
class VDS;

class VDS_Pair{
  friend class VDS;
   unsigned x3d_index;
   unsigned pbos_index;
  public:
   VDS_Pair():x3d_index(9999),pbos_index(9999){}
  };


class VDS {
 private:
   VDS (const VDS& ){} // Prevent copying
   VDS operator = (const VDS &){return *this;} // Prevent assignment

 protected:
   static bool init;
   vector<Pointer_Based_Object> pbos;
   map<unsigned,VDS_Pair> objects; // first unsigned is address, second is pair of x3d index and type(pbos index)
   X3D x3d;
   bool PointerValid(unsigned ptr) const;
   unsigned max_string_length;
   bool registering;
  static bool init_memory(unsigned & high, unsigned & low);

   void Display_Pointer(const Visual_Pointer & vp, unsigned & level);
   void Process_Display(X3D_Block * bptr, const Visual_Display & vd, const Visual_Pointer & vp);
   void Process_Pointer(X3D_Block * bptr, Visual_Pointer ptr, const Visual_Pointer & source, unsigned & level);
   X3D_String Convert_Pointer(unsigned)const;
   void Adjust();
   void ConnectArrows();
   void ArrowBuild(unsigned src, unsigned dest, unsigned level, float length);
 public:
   VDS();
   ~VDS();

  //Accessor functions

   unsigned start_registration(unsigned length);
   void end_registration(){registering = false;}
   bool add_pointer(unsigned id, void * source, void * ptr, X3D_String name, unsigned dest_id=SELFID);
   bool add_display(unsigned id, void * source, void * item, Display_Type dt, X3D_String name);

   bool snapshot(void * pointer, unsigned id, const char * filename, bool list=false, bool viewer=false);
   X3D_String ToString() const;
};

#endif
