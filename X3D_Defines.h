// X3D_Defines
#ifndef __X3D_Defines
#define __X3D_Defines

#include <math.h>


// One of these should come in from compiler system
//#define CB4
//#define CB10
//#define DEV
//#define VS

#ifdef CB4
 #define X3D_String AnsiString
 #include <vcl.h>
 #endif

#ifdef CB10
 // This is ASCII string
 #define X3D_String AnsiString
 #include <vcl.h>
 #endif

 #ifdef DEV
 #define X3D_String wxString
 #include <wx/string.h>
 #endif

#ifdef VS
 #define X3D_String string
 #include <string>
 using namespace std;
 #define M_PI 3.14159265358979
 #endif

 #endif
