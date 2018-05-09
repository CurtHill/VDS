//---------------------------------------------------------------------------
#ifndef vds_memoryH
#define vds_memoryH
#include "PtrStatus.h"
#include <stdlib.h>
#include <map>
using namespace std;
//---------------------------------------------------------------------------

void * operator new (size_t size);
void operator delete (void *);


class VDS;
class VDS_Memory{
  friend class VDS;
   static bool save,  // methods are called from user code
               stop;  // The VDS destructor has been called - map may not still exist
   static unsigned news,passed,false_removes;     // Statistics
   static map<unsigned, PtrStatus> all_pointers;  // All valid user pointers
   static void add(unsigned  ptr, size_t size);
   static void remove(unsigned  ptr);
   static void pause(){save = false;}
   static void resume(){save = true;}
   static enum PtrStatus_enum Status(unsigned);
   static void Clear(){all_pointers.clear();}
 public:
   static void * vds_new (size_t size);
   static void  vds_delete (void * ptr);
   static unsigned new_used(){ return news;}
   static unsigned new_passed(){ return passed;}
   static X3D_String ToString();
 };
#endif
