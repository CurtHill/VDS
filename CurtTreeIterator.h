//---------------------------------------------------------------------------
#ifndef CurtTreeIteratorH
#define CurtTreeIteratorH
#include "CurtTree.h"
#include "stack.h"
//---------------------------------------------------------------------------
class CurtTreeIterator{
  friend class CurtTree;
   void changed();
   stack <CurtNode *> stk;
   CurtTree * container;
   void zing_to_bottom(CurtNode *);
 public:
   CurtTreeIterator();
   ~CurtTreeIterator();
   bool start(CurtTree *);
   bool more(){return !stk.isempty();}
   bool next(AnsiString & n, AnsiString & z, AnsiString & c, bool & i);
};
#endif
