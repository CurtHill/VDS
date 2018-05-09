//---------------------------------------------------------------------------

#ifndef LinkedListH
#define LinkedListH
#include "LinkedNode.h"
#include "visual_data_structure.h"
//---------------------------------------------------------------------------
class LinkedList{
  private:
	LinkedNode * root;


	LinkedList(const LinkedList &);
	LinkedList & operator = (const LinkedList &);

  public:
	LinkedList();
	~LinkedList();
	bool add(int,X3D_String);
	bool remove(int);
	X3D_String find(int)const;
	int count();
        unsigned register_class(VDS & v);
        bool snapshot(VDS & v, unsigned id, char * filename, bool list=false, bool view=false);
};
#endif
