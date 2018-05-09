// Visual_Data_Structure
#include "Visual_Data_Structure.h"
#ifdef CB4
 #include "\projects\objects\exec_obj\exec_obj.h"
 #endif
#include <assert.h>
#include "vds_memory.h"

// the memory variables must be initialized
VDS::VDS():max_string_length(1),registering(false){
 VDS_Memory::Clear();
 VDS_Memory::stop = false;
 VDS_Memory::resume();
}

VDS::~VDS(){
 VDS_Memory::stop = true;
}

unsigned VDS::start_registration(unsigned length){
  VDS_Memory::pause();
  Pointer_Based_Object pbo;
  pbo.set_length(length);
  pbos.push_back(pbo);
  registering = true;
  VDS_Memory::resume();
  return pbos.size()-1;
}

bool VDS::add_pointer(unsigned id, void * source, void * ptr, X3D_String name, unsigned dest_id){
  assert(registering);
  if(id >= pbos.size()){
     return false;
     }
  if(dest_id == SELFID)
    dest_id = id;
  else if(dest_id >= pbos.size())
     return false;
  VDS_Memory::pause();
  unsigned start, end;
  start = unsigned(source);
  end = unsigned(ptr);
  if(end-start >= pbos[id].get_length()){
    VDS_Memory::resume();
    return false;
    }
  Visual_Pointer vp(end-start, dest_id,name);
  pbos[id].add_pointer(vp);
  VDS_Memory::resume();
  return true;
}

bool VDS::add_display(unsigned id, void * source, void * item, Display_Type dt, X3D_String name){
  assert(registering);
  if(id >= pbos.size())
     return false;
  unsigned start, end;
  //Pointer_Based_Object pb = pbos[id];
  start = unsigned(source);
  end = unsigned(item);
  if(end-start >= pbos[id].get_length())
    return false;
  VDS_Memory::pause();
  Visual_Display dp(end-start, dt, name);
  pbos[id].add_display(dp);

  VDS_Memory::resume(); // Last thing before return
  return true;
}

X3D_String VDS::ToString() const{

  X3D_String line = X3D_String("A VDS\n Number of PBOs: ")
  #ifdef CB4
     +  pbos.size() +
     #endif
  #ifdef CB10
	 +  pbos.size() +
	 #endif
  #ifdef DEV
	 << pbos.size() <<
	 #endif
  #ifdef VS
	 +  to_string(pbos.size()) +
	 #endif
   "\n\npbos vector:";
  for(unsigned i = 0;i<pbos.size();i++)
	line = line
	#ifdef CB4
	   + "\n["+ i +"] " +
	   #endif
	#ifdef CB10
	   + "\n["+ i +"] " +
	   #endif
	#ifdef VS
	   + "\n["+ to_string(i) +"] " +
	   #endif
	#ifdef DEV
	   << "\n[" << i << "] " <<
	   #endif
	   pbos[i].ToString("   ");
  // The map objects
  line = line
  #ifdef CB4
	   + "\n\nobjects map: ";
	   #endif
  #ifdef CB10
	   + "\n\nobjects map: ";
	   #endif
	#ifdef VS
	   + "\n\nobjects map: ";
	   #endif
	#ifdef DEV
	   << "\n\nobjects map:\n ";
	   #endif
  map<unsigned,VDS_Pair>::const_iterator map_it;
  X3D_String temp;
  for(map_it = objects.begin(); map_it != objects.end(); map_it++){
	  line = line
	  #ifdef CB4
		 + "\n ["+map_it->first+"]  (" + map_it->second.x3d_index + "," + map_it->second.pbos_index + ")";
	   #endif
	  #ifdef CB10
		 + "\n ["+map_it->first+"]  (" + map_it->second.x3d_index + "," + map_it->second.pbos_index + ")";
	   #endif
	  #ifdef VS
		 + "\n\nobjects map: ";
	   #endif
	  #ifdef DEV
		 << "\n\nobjects map:\n ";
	   #endif
	} // map iterator

  return line;
}

bool VDS::snapshot(void * pointer, unsigned id, const char * filename, bool list, bool viewer){
  unsigned ptr = unsigned(pointer);
  registering = false;
  unsigned level = 1;
  VDS_Memory::pause();
  if(PointerValid(ptr)){
	 Visual_Pointer vp(ptr,id,"");
	 Display_Pointer(vp,level);
	 Adjust();
	 x3d.SaveToFile(filename);
	 if(list){
	   char fn[1000];
	   strcpy(fn,filename);
	   strcat(fn,".lst");
	   ofstream outf(fn);
	   outf << ToString().c_str();
	   }
	 #ifdef CB4
	 if(viewer){
	   exec_obj xo;
	   xo.set_timeout(10);
	   xo.set_minimize(false);
	   char fn[500];
	   strcpy(fn,filename);
	   strcat(fn,".x3d");
	   xo.execute_registered(fn);
	   }
	  #endif
	 objects.clear();
	 x3d.Clear();
	 VDS_Memory::resume();
	 return true;
	}
  char fn[1000];
  strcpy(fn,filename);
  strcat(fn,".err");
  ofstream outf(fn);
  outf << "The address given for the snapshot was invalid: " << ptr
	   << "\n";
  VDS_Memory::resume();
  return false;
}

bool VDS::PointerValid(unsigned ptr) const {
 enum PtrStatus_enum status = VDS_Memory::Status(ptr);
 return status == PSValidWithID || status == PSValid;
}


// Add the visual display to the block
void VDS::Process_Display(X3D_Block * bptr, const Visual_Display & vd, const Visual_Pointer & vp){
 assert(!registering);
 Display_Type type = vd.get_type();
 void * ptr = (void *)(vd.get_location() + vp.get_pointer());
 X3D_String str = vd.get_name()+": ";
 int * ip;
 float * fp;
 double * dp;
 char * cp;
 X3D_String * sp;
 switch(type){
   case DTInteger:
	 ip = (int *)ptr;
	 #ifdef CB4
	  str += *ip;
	  #endif
	 #ifdef CB10
	  str += *ip;
	  #endif
	 #ifdef VS
	  str += to_string(*ip);
	  #endif
	 #ifdef DEV
	  str = str << *ip;
	  #endif
	 break;
   case DTFloat:
	 fp =  (float *) ptr;
	 #ifdef CB4
	   str += *fp;
	  #endif
	 #ifdef CB10
	   str += *fp;
	  #endif
	 #ifdef VS
	   str += to_string(*fp);
	  #endif
	 #ifdef DEV
	   str = str << *fp;
	  #endif
	 break;
   case DTDouble:
	 dp = (double *) ptr;
	 #ifdef CB4
	  str += *dp;
	  #endif
	 #ifdef CB10
	  str += *dp;
	  #endif
	 #ifdef VS
	  str += to_string(*dp);
	  #endif
	 #ifdef DEV
	  str = str << *dp;
	  #endif
	 break;
   case DTString:
	 cp = (char *) ptr;
	 #ifdef CB4
	  str += *cp;
	  #endif
	 #ifdef CB10
	  str += *cp;
	  #endif
	 #ifdef VS
	  str += *cp;
	  #endif
	 #ifdef DEV
	  str = str << *cp;
	  #endif
	 break;
   case DTStringObject:
	 sp = (X3D_String *) ptr;
	 #ifdef CB4
	   str += *sp;
	  #endif
	 #ifdef CB10
	   str += *sp;
	  #endif
	 #ifdef VS
	   str += *sp;
	  #endif
	 #ifdef DEV
	   str = str << *sp;
	  #endif
	 break;
   default:
	 break;
   }
  X3D_Text * tp = new X3D_Text (str);
  bptr->Add(tp);
  if(unsigned(str.Length()) > max_string_length)
	max_string_length = str.Length();
}

void VDS::Process_Pointer(X3D_Block * bptr, Visual_Pointer ptr, const Visual_Pointer & source, unsigned & level){
 // First do display
 assert(!registering);
 unsigned location = ptr.get_pointer()+source.get_pointer();
 X3D_String str = ptr.get_name()+": ";
 int * ip = (int *)location;
 void * vp = (void *)*ip;
 str
 #ifdef CB4
  +=
  #endif
 #ifdef CB10
  +=
  #endif
 #ifdef VS
  +=
   #endif
 #ifdef DEV
   = str <<
   #endif
 Convert_Pointer((unsigned)vp);
 // Ready to recursively check?
 // Does it already exist and is it valid
 unsigned address = unsigned(vp);
 map<unsigned,VDS_Pair>::iterator it;
 it = objects.find(address);
 if(PointerValid(address) && it==objects.end()){
	ptr.set_pointer(address);
	Display_Pointer(ptr,level); //+bptr->get_size());
	}
 bptr->Add(new X3D_Text(str));
}


X3D_String VDS::Convert_Pointer(unsigned ptr)const{
  if(ptr==0)
	return X3D_String("NULL");
  char loc[64];
  itoa(ptr,loc,16);
  if(!PointerValid(ptr))
	 strcat(loc," - Invalid Pointer");
  return X3D_String(loc);
}


/*
  Take a pointer and generate a group that represents the object pointed at
  Use the template of type to find the displayables as part of that object.
  Recursively process the pointers within it.
*/
void VDS::Display_Pointer(const Visual_Pointer & vp, unsigned & level){
  unsigned type = vp.get_type();
  assert(type<=pbos.size());
  Pointer_Based_Object pbo = pbos[type];
  unsigned ptrs = pbo.pointer_count();
  unsigned disps = pbo.display_count();
  //unsigned lines = 1 + ptrs + disps;
  unsigned address = vp.get_pointer();
  VDS_Pair pair;
  pair.x3d_index = x3d.Size();
  pair.pbos_index = type;
  objects[address] = pair;
  unsigned size =   pbos[vp.get_type()].pointer_count() + pbos[vp.get_type()].display_count();
  X3D_Block * bptr = new X3D_Block();
  bptr->set_translate(X3D_Coordinate(0,level*size,-8));
  X3D_Box * boxptr = dynamic_cast<X3D_Box *>(bptr->get_solid(0));
  if(boxptr != NULL){
	switch(type%7){
	  case 0:
		boxptr->set_color(X3D_Color(0,0.5,0));
		break;
	  case 1:
		boxptr->set_color(X3D_Color(0, 0,0.5));
		break;
	  case 2:
		boxptr->set_color(X3D_Color(0.5,0,0));
		break;
	  case 3:  // Who uses more than 3 types of objects?
		boxptr->set_color(X3D_Color(0,0.5,0.5));
		break;
	  case 4:
		boxptr->set_color(X3D_Color(0.5,0.5,0));
		break;
	  case 5:
		boxptr->set_color(X3D_Color(0.5,0,0.5));
		break;
	  case 6:
		boxptr->set_color(X3D_Color(0,5.5,0.5));
		break;
	  }
	}
  x3d.Add(bptr);
  unsigned original = level;
  bptr->Add(new X3D_Text("("+Convert_Pointer(address)+")"));
  for(unsigned i = 0;i<disps;i++){
	Visual_Display vd = pbo.get_display(i);
	Process_Display(bptr,vd,vp);
	}
  for(unsigned i = 0;i<ptrs;i++){
	Visual_Pointer ptr = pbo.get_pointer(i);
	Process_Pointer(bptr,ptr,vp,++level);
	}
  if(original == 1){ // Add a marker for the first one
	X3D_Arrow * ptr = new X3D_Arrow(X3D_Coordinate(-8,0,0),X3D_Coordinate(-5,0,0));
	bptr->Add(ptr);
	}
}

void VDS::Adjust(){
 // Find maximum number of lines (maximum height)
 unsigned max_lines = 0;
 for(unsigned i = 0;i<pbos.size();i++){
   unsigned s = pbos[i].display_count()+pbos[i].pointer_count()+1;
   if(s > max_lines)
	 max_lines = s;
   }

 // Find the maximum width of each block
 float max_width = 5;
 for(unsigned i = 0;i<x3d.Size();i++){
   X3D_Block * bptr = dynamic_cast<X3D_Block *>(x3d.Get(i));
   if(bptr == NULL)
	 continue;
   //bptr->Adjust();
   X3D_Box * boxptr = dynamic_cast<X3D_Box *>(bptr->get_solid(0));
   if(boxptr == NULL)
	 continue;

   float width = boxptr->get_size().get_x();
   if(width > max_width)
	 max_width = width;
   }

 // Set the box X location to memory order rather than the logical order
 for(unsigned i = 0;i<x3d.Size();i++){
   X3D_Block * bptr = dynamic_cast<X3D_Block *>(x3d.Get(i));
   if(bptr == NULL)
	 continue;
   X3D_Box * boxptr = dynamic_cast<X3D_Box *>(bptr->get_solid(0));
   if(boxptr == NULL)
	 continue;
   // Set the box widths to be the same
   X3D_Coordinate size = boxptr->get_size();
   size.set_x(max_width);
   boxptr->set_size(size);
   bptr->Adjust();
   }

 map<unsigned,VDS_Pair>::iterator iter;
 unsigned count=0;
 max_lines+=3;
 for(iter=objects.begin();iter!=objects.end();iter++){
   VDS_Pair pair = iter->second;
   unsigned index = pair.x3d_index;
   X3D_SolidPtr solid = x3d.Get(index);
   solid->set_translate(X3D_Coordinate(0,count*max_lines,-12));
   X3D_Block * bptr = dynamic_cast<X3D_Block *>(solid);
   if(bptr)
	  bptr->LeftJustify();
   count++;
   }// end of for
 ConnectArrows();
}

void VDS::ArrowBuild(unsigned src, unsigned dest, unsigned level, float length){
  // only want coordinates for destination
  X3D_Block * bptr = dynamic_cast<X3D_Block *>(x3d.Get(dest));
  if(bptr == NULL)
	 return;
  X3D_Coordinate source, target=bptr->get_translate();
  // We may need to adjust the destination X later
  bptr = dynamic_cast<X3D_Block *>(x3d.Get(src));
  if(bptr == NULL)
	 return;
  X3D_Color color = X3D_Color((30-length)/30.0,1-length/100.0,.5);
  X3D_Box * boxptr = dynamic_cast<X3D_Box *>(bptr->get_solid(0));
  if(boxptr == NULL)
	 return;
  //float height = boxptr->get_size().get_y();
  float width = boxptr->get_size().get_x()/2;
  source=bptr->get_translate();
  target = target-source;
  target.set_x(target.get_x()+width);
  target.set_y(target.get_y()+1);
  source = X3D_Coordinate(width,-float(level-1)*.8,0); // this is relative to block
  X3D_Coordinate next(source);
  next.set_x(next.get_x()+length/3);
  next.set_z(next.get_z());
  X3D_Arrow * arrow = new X3D_Arrow(source, next);
  arrow->set_color(color);
  bptr->Add(arrow);
  // Arrow with out cone up or down
  source = next;
  next = X3D_Coordinate(source.get_x(),target.get_y(),source.get_z());
  arrow = new X3D_Arrow(source, next,false);
  bptr->Add(arrow);
  arrow->set_color(color);
  // Back to destination box
  source = next;
  arrow = new X3D_Arrow(next, target);
  arrow->set_color(color);
  bptr->Add(arrow);
}


void VDS::ConnectArrows(){

 map<unsigned,VDS_Pair>::iterator iter;
 // Iterate through all the blocks
 float length = 2;
 for(iter=objects.begin();iter!=objects.end();iter++){
   //  Find the object type
   VDS_Pair pair = iter->second;
   unsigned src_x3d_index = pair.x3d_index;
   unsigned pbos_index = pair.pbos_index;
   unsigned ds_pointer = iter->first;
   // Get the pointer to the X3d Block
   X3D_Block * bptr = dynamic_cast<X3D_Block *>(x3d.Get(src_x3d_index));
   if(bptr==NULL)
	  continue;
   Pointer_Based_Object p = pbos[pbos_index];
   //  Find each pointer
   for(unsigned i = 0;i<p.pointer_count();i++){
	  Visual_Pointer vp = p.get_pointer(i);
	  unsigned out_ptr = vp.get_pointer();
	  unsigned src = out_ptr + ds_pointer;
	  unsigned dest = *((unsigned *)src);
	  if(!PointerValid(unsigned(dest)))
		 continue;
	  unsigned destptr = *(unsigned *)src;
	  // Find the dest x3d block
	  unsigned dest_x3d  = objects[destptr].x3d_index;
	 // Insert arrows to destination
	  ArrowBuild(src_x3d_index, dest_x3d, p.display_count()+i,length);
	  length += 3.5;
	 }
   }// end of iterating for

}
