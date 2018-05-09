//---------------------------------------------------------------------------
#pragma hdrstop

#include "Display_Type.h"
#include "X3D.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
X3D_String __fastcall ToString(const Display_Type & val){
 switch(val){
   case DTFirstUnused:
     return "FirstUnused";
   case DTInteger:
     return "Integer";
   case DTFloat:
     return "Float";
   case DTDouble:
     return "Double";
   case DTString:
     return "String";
   case DTStringObject:
     return "StringObject";
   case DTLastUnused:
     return "LastUnused";
   default:
     return "Invalid";
  } // switch
}

