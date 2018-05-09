//---------------------------------------------------------------------------

#ifndef LinkedNodeH
#define LinkedNodeH
#include "X3D.h"
//---------------------------------------------------------------------------
class LinkedNode{
  private:
	int key;
	X3D_String data;
	LinkedNode * next;
	LinkedNode();
	friend class LinkedList;
};
#endif
