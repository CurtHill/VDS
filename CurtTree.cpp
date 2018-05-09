//---------------------------------------------------------------------------
#include <vcl.h>
#include <assert.h>
#pragma hdrstop

#include "CurtTree.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

CurtTree::~CurtTree(){
 killer(root);
}

void CurtTree::killer(CurtNode * ptr){
  if(!ptr)
    return;
  killer(ptr->smaller);
  killer(ptr->larger);
  delete ptr;
}

bool CurtTree::Insert(AnsiString n, AnsiString z, AnsiString c, bool i){
 if(root == NULL){
   root = new CurtNode(n,z,c,i);
   return true;
   }
 CurtNode * lead = root, * trail = NULL;
 while(lead) {
   if(lead->name==n)
     return false;
   trail = lead;
   if(lead->name > n)
     lead = lead->smaller;
   else
     lead = lead->larger;
  }
 CurtNode * ptr = new CurtNode(n,z,c,i);
 if(trail->name > n)
    trail->smaller = ptr;
 else
    trail->larger = ptr;
 return true;
}

bool CurtTree::Remove(AnsiString n){
  return Remove(root,n);
  }

void CurtTree::Remove(CurtNode * & stem){
  if(stem == NULL)
    return;
  CurtNode * temp  = stem;
  if(stem->smaller==NULL){
    // smaller is null promote larger
    stem = stem->larger;
    delete temp;
    return;
    }
  if(stem->larger == NULL){
    // larger is null, promote smaller
    stem = stem->smaller;
    delete temp;
    return;
    }
  // Hard one - two descendents
  CurtNode * lead = stem->larger, * trail=NULL;
  while(lead){
    trail = lead;
    lead = lead->smaller;
    }
  // Swap trail with lead
  AnsiString n2 = trail->name;
  AnsiString z = trail->zip;
  AnsiString c = trail->crime;
  bool i = trail->inPrison;
  trail->name = stem->name;
  trail->zip = stem->zip;
  trail->crime = stem->crime;
  trail->inPrison = stem->inPrison;
  stem->name = n2;
  stem->crime = c;
  stem->zip = z;
  stem->inPrison = i;
  // Delete the new leaf/branch
  if(trail->name > n2)
    return Remove(trail->smaller);
  Remove(trail->larger);
}

bool CurtTree::Remove(CurtNode * & ptr,AnsiString n){
 if(!ptr)
   return false;
 if(ptr->name == n){
   Remove(ptr);
   return true;
   }
 CurtNode * lead = ptr, * trail = NULL;
 while(lead) {
   if(lead->name==n){
     if(trail->smaller && trail->smaller->name == n)
       Remove(trail->smaller);
     else
       Remove(trail->larger);
     return true;
     }
   trail = lead;
   if(lead->name > n)
     lead = lead->smaller;
   else
     lead = lead->larger;
  }
 return false;  // did not find it
}

bool CurtTree::Get(CurtNode * ptr,AnsiString n, AnsiString & z, AnsiString & c, bool & i){
  if(!ptr)
    return false;
  if(ptr->name == n){
    z = ptr->zip;
    c = ptr->crime;
    i = ptr->inPrison;
    return true;
    }
  if(ptr->name > n)
    return Get(ptr->smaller,n,z,c,i);
  else
    return Get(ptr->larger,n,z,c,i);
}

bool CurtTree::Get(AnsiString n, AnsiString & z, AnsiString & c, bool & i){
 return Get(root,n,z,c,i);
}

int CurtTree::Count(CurtNode * r,AnsiString crime) const{
  if(!r)
    return 0;
  if(crime == "ALL")
    return Count(r->larger,crime) + 1 + Count(r->smaller,crime);
  if(crime == r->crime)
    return Count(r->larger,crime) + 1 + Count(r->smaller,crime);
  else
    return Count(r->larger,crime) + Count(r->smaller,crime);
}

int CurtTree::Count(AnsiString c)const{
 return Count(root,c);
}

int CurtTree::DepthSum(CurtNode * r,int depth){
 if(r){
   depth++;
   return depth + DepthSum(r->larger,depth)+ DepthSum(r->smaller,depth);
   }
 return 0;
}

double CurtTree::AvgDepth(){
  int sum = DepthSum(root, 0);
  int count = Count(root,"ALL");
  return double(sum)/count;
}

bool CurtTree::start(CurtTreeIterator * p){
  // An iteration is about to start
  if(!root)
   return false;
  return true;
}

void CurtTree::done(){
  //itptr = NULL;
}

unsigned CurtTree::register_class(VDS & vds){
 CurtNode ln;
 unsigned id = vds.start_registration(sizeof(CurtNode));
 bool ptr = vds.add_pointer(id, &ln, &ln.smaller,"smaller") &&
            vds.add_pointer(id, &ln, &ln.larger,"larger");
 bool str = vds.add_display(id, &ln, &ln.name,DTStringObject, "name") &&
            vds.add_display(id, &ln, &ln.zip, DTStringObject, "zip") &&
            vds.add_display(id, &ln, &ln.crime,DTStringObject, "crime");
 assert(ptr  && str);

 return id;
}

void CurtTree::snapshot(VDS & v, unsigned id, char * filename, bool list, bool view){
  v.snapshot(root,id,filename,list,view);
}
