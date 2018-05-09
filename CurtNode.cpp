//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CurtNode.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
CurtNode::CurtNode(){
 smaller = NULL;
 larger = NULL;
}

CurtNode::CurtNode(AnsiString n, AnsiString z, AnsiString c, bool i){
 smaller = NULL;
 larger = NULL;
 name = n;
 zip = z;
 crime = c;
 inPrison = i;
}

