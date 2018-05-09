//---------------------------------------------------------------------------
#ifndef CurtTreeH
#define CurtTreeH
#include "CurtNode.h"
//#include "CurtTreeIterator.h"
//---------------------------------------------------------------------------
//class TreeStat{

//};
class CurtTree{
 //friend class CurtTreeIterator;
  CurtNode* root;
  bool Get(CurtNode * ptr,AnsiString n, AnsiString & z, AnsiString & c, bool & i);
  bool Remove(CurtNode * & ptr,AnsiString data);
  void Remove(CurtNode * & ptr);
  void killer(CurtNode * r);
  int Count(CurtNode * r,AnsiString crime) const;
  int DepthSum(CurtNode * r,int depth);
  bool start(CurtTreeIterator *);
  void done();

 public:
  CurtTree ():root(NULL){}
  ~CurtTree ();

  bool Insert(AnsiString name, AnsiString zip, AnsiString crime, bool inPrison);
  bool Remove(AnsiString data);
  bool Get(AnsiString n, AnsiString & z, AnsiString & c, bool & i);
  int Count(AnsiString crime)const;
  double AvgDepth();
  void snapshot(VDS & v, unsigned id, char * filename, bool list=false, bool view=false);
  unsigned register_class(VDS & v);
 };
#endif
