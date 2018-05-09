// PtrStatus definition
#ifndef __PtrStatus__
#define __PtrStatus__
#include "x3d_defines.h"

enum PtrStatus_enum {
   PSFirstUnused, PSNotSeen, PSValidWithID, PSDropped, PSValid, PSReused, PSLastUnused};

class PtrStatus  {
  protected:
   enum PtrStatus_enum data;
   size_t size;
  public:
   PtrStatus();
   PtrStatus(PtrStatus_enum, size_t length=0);
   PtrStatus(const PtrStatus & that);


   X3D_String __fastcall ToString() const;

   PtrStatus __fastcall operator ++(int);

   PtrStatus __fastcall operator ++();

   PtrStatus __fastcall operator --(int);

   PtrStatus __fastcall operator --();
   bool operator < (const PtrStatus  & t)const;
   bool operator == (const PtrStatus  & t)const;
   bool operator > (const PtrStatus  & t) const {return !(*this<t || *this==t);}
   bool operator != (const PtrStatus  & t) const {return !(*this==t);}
   bool operator >= (const PtrStatus  & t) const {return !(*this<t);}
   bool operator <= (const PtrStatus  & t) const {return *this<t || *this==t;}
   PtrStatus_enum Value()const{return data;}
   size_t GetLength()const{return size;}
}; // PtrStatus

#endif

