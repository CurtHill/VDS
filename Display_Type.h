//---------------------------------------------------------------------------
#ifndef Display_TypeH
#define Display_TypeH
#ifdef CB4
 #include <vcl.h>
 #endif
#include "X3D.h" 
//---------------------------------------------------------------------------

typedef enum {
   DTFirstUnused, DTInteger, DTFloat, DTDouble, DTString, DTStringObject, DTLastUnused
   }
    Display_Type;


X3D_String __fastcall ToString(const Display_Type & val);


#endif
