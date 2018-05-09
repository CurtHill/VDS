//---------------------------------------------------------------------------
#ifndef CurtNodeH
#define CurtNodeH
#include "visual_data_structure.h"


class CurtNode {
 friend class CurtTree;
 friend class CurtTreeIterator;
  CurtNode * smaller, * larger;
  AnsiString name;
  AnsiString zip;
  AnsiString crime;
  bool inPrison;

  CurtNode();
  CurtNode(AnsiString name, AnsiString zip, AnsiString crime, bool inPrison);
  bool operator == (const CurtNode &);
  bool operator < (const CurtNode &);
  bool operator > (const CurtNode & that){
    return !(*this == that || *this < that);
    }
  bool operator >= (const CurtNode & that){
    return !(*this < that);
    }
  bool operator <= (const CurtNode & that){
    return *this == that || *this < that;}
  bool operator != (const CurtNode & that){
    return !(*this == that);
    }
};
//---------------------------------------------------------------------------
#endif
