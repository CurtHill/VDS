#include "PtrStatus.h"
#include <assert.h>



X3D_String __fastcall PtrStatus::ToString() const {
 X3D_String result;
 switch(data){
   case PSFirstUnused:
     result  = "FirstUnused";
     break;
   case PSNotSeen:
     result  = "NotSeen";
     break;
   case PSValidWithID:
     result  = "ValidWithID";
     break;
   case PSDropped:
     result  = "Dropped";
     break;
   case PSValid:
     result  = "Valid";
     break;
   case PSReused:
     result  = "Reused";
     break;
   case PSLastUnused:
     result  = "LastUnused";
     break;
   default:
     result  = X3D_String("Invalid")
     #ifdef CB4
       + "("+int(data)+")";
       #endif
	 #ifdef CB10
	   + "("+int(data)+")";
	   #endif
	 #ifdef DEV
	   << "(" << int(data) << ")";
	   #endif
	 #ifdef VS
	   + "("+int(data)+")";
	   #endif
  } // switch
 result = result
 #ifdef CB4
	 + " (" + size + ")";
   #endif
 #ifdef CB10
	 + " (" + size + ")";
   #endif
 #ifdef DEV
	 << " (" << size << ")";
   #endif
 #ifdef VS
	 + " (" + size + ")";
   #endif

 return result;
}

PtrStatus::PtrStatus(){
  data = PSNotSeen;
  size = 0;
}

PtrStatus::PtrStatus(const PtrStatus & that){
  data = that.data;
  size = that.size;
}

PtrStatus::PtrStatus(PtrStatus_enum t, size_t length){
  data = t;
  size = length;
}

PtrStatus __fastcall PtrStatus::operator ++(int){
  PtrStatus temp = *this;
  if(data < PSFirstUnused){
	  data = PSFirstUnused;
	  return temp;
	  }
  if(data >= PSLastUnused){
	  data = PSLastUnused;
	  return temp;
	  }
  switch(sizeof(PtrStatus)) {
	case 1:{
	  union{char c;
		PtrStatus_enum t;} u;
	  u.t = data;
	  u.c++;
	  data = u.t;}
	  break;
	case 2:{
	  union{short c;
		PtrStatus_enum t;} u;
	  u.t = data;
	  u.c++;
	  data = u.t;}
	  break;
	case 4:{
	  union{int c;
		PtrStatus_enum t;} u;
	  u.t = data;
	  u.c++;
	  data = u.t;}
	  break;
	default:
	  assert(false);
  }// switch
 return temp;
}

PtrStatus __fastcall PtrStatus::operator --(int){
  PtrStatus temp = *this;
  if(data < PSFirstUnused){
	  data = PSFirstUnused;
	  return temp;
	  }
  if(data >= PSLastUnused){
	  data = PSLastUnused;
	  return temp;
	  }
  switch(sizeof(PtrStatus)) {
	case 1:{
	  union{char c;
		PtrStatus_enum t;} u;
	  u.t = data;
	  u.c--;
	  data = u.t;}
	  break;
	case 2:{
	  union{short c;
		PtrStatus_enum t;} u;
	  u.t = data;
	  u.c--;
	  data = u.t;}
	  break;
	case 4:{
	  union{int c;
		PtrStatus_enum t;} u;
	  u.t = data;
	  u.c--;
	  data = u.t;}
	  break;
	default:
	  assert(false);
  }// switch
 return temp;
}

PtrStatus __fastcall PtrStatus::operator ++(){
 (*this)++;
 return *this;
}

PtrStatus __fastcall PtrStatus::operator --(){
 (*this)--;
 return *this;
}


