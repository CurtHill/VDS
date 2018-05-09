//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CurtTreeIterator.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
CurtTreeIterator::CurtTreeIterator()
  :container(NULL)
    {}

CurtTreeIterator::~CurtTreeIterator(){
 while(!stk.isempty())
   stk.pop();
}

bool CurtTreeIterator::start(CurtTree * ptr){
  if(container)
    return false;
  if(!ptr->start(this))
    return false;
  container = ptr;
  zing_to_bottom(ptr->root);
  return true;
}

bool CurtTreeIterator::next(AnsiString & n, AnsiString & z, AnsiString & c, bool & i){
 if(stk.isempty())
   return false;
 CurtNode * ptr = stk.pop();
 n = ptr->name;
 z = ptr->zip;
 c = ptr->crime;
 i = ptr->inPrison;
 zing_to_bottom(ptr->larger);
 return true;
}

void CurtTreeIterator::zing_to_bottom(CurtNode * ptr){
 while(ptr){
   stk.push(ptr);
   ptr = ptr->smaller;
   }
}

void CurtTreeIterator::changed(){
 // abort the iteration
 container->done();
 container = NULL;
}
