//---------------------------------------------------------------------------
#include <vcl.h>
#include <assert.h>

#pragma hdrstop

#include "vds_memory.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
void * operator new (size_t size){
  return VDS_Memory::vds_new(size);
}

void operator delete (void * ptr){
  return VDS_Memory::vds_delete(ptr);
}

bool VDS_Memory::save = false;
bool VDS_Memory::stop = false;
unsigned VDS_Memory::news = 0;
unsigned VDS_Memory::passed = 0;
unsigned VDS_Memory::false_removes = 0;
map<unsigned, PtrStatus> VDS_Memory::all_pointers;

void * VDS_Memory::vds_new (size_t size){
  void * ptr = malloc (size);
  if(save && !stop){
    save = false;
    add(unsigned(ptr),size);
    news++;
    save = true;
    }
  else
    passed++;
  return ptr;
}

void  VDS_Memory::vds_delete (void * ptr){
  if(save && !stop){
    save = false;
    remove(unsigned (ptr));
    save = true;
    }
  free(ptr);
}

void VDS_Memory::add(unsigned ptr, size_t size){
  map<unsigned, PtrStatus>::iterator map_it;
  map_it = all_pointers.find(ptr);
  if(map_it != all_pointers.end()){
    // It currently exists  PSFirstUnused, PSNotSeen, PSValidWithID, PSDropped, PSValid, PSLastUnused
    PtrStatus_enum pse = map_it->second.Value();
    size_t size = map_it->second.GetLength();
    switch(pse){
      case PSDropped:
         map_it->second = PtrStatus(PSReused,size);
         break;
      case PSReused:  // WHat should this be?
         map_it->second = PtrStatus(PSReused,size);
         break;
      default:
         assert(false);
         break;
      } // switch
    }
  else { // time to add it
    all_pointers[ptr] = PtrStatus(PSValid,size);
    }
}

void VDS_Memory::remove(unsigned  ptr){
  map<unsigned, PtrStatus>::iterator map_it;
  map_it = all_pointers.find(ptr);
  if(map_it != all_pointers.end()){
    // It currently exists  PSFirstUnused, PSNotSeen, PSValidWithID, PSDropped, PSValid, PSLastUnused
    switch(map_it->second.Value()){
      case PSValidWithID:
      case PSValid:
         map_it->second = PtrStatus(PSDropped);
      default:
         false_removes++;
         break;
      } // switch
    }
  //else assert(false);
}

X3D_String VDS_Memory::ToString(){
  X3D_String line = X3D_String("All_Pointers\n");
  // The map all_pointers
  map<unsigned, PtrStatus>::const_iterator map_it;
  X3D_String temp;
  char hex[24]="";
  for(map_it = all_pointers.begin(); map_it != all_pointers.end(); map_it++){
      itoa(map_it->first,hex,16);
      line = line
      #ifdef CB4
         + "\n "+map_it->first+"[0x"+hex+"] " + map_it->second.ToString();
       #endif
	  #ifdef CB10
		 + "\n "+map_it->first+"[0x"+hex+"] " + map_it->second.ToString();
	   #endif
	  #ifdef VS
		 + "\n "+map_it->first+"[0x"+hex+"] " + map_it->second.ToString();
	   #endif
	  #ifdef DEV
		 << "\n "<<map_it->first<<"[0x"<<hex<<"] " << map_it->second.ToString();
	   #endif
	} // map iterator
  VDS_Memory::resume();

  return line;
}

 enum PtrStatus_enum VDS_Memory::Status(unsigned address){
  map<unsigned, PtrStatus>::const_iterator map_it;
  map_it = all_pointers.find(address);
  if(map_it != all_pointers.end())
	return map_it->second.Value();
  return PSNotSeen;
 }
