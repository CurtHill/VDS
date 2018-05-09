//---------------------------------------------------------------------------


#pragma hdrstop

#include "LinkedList.h"
#include "X3D.h"
#include <assert.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)
LinkedList::LinkedList(){
  root = NULL;
}

LinkedList::~LinkedList(){
 LinkedNode * ptr = root, * temp;
 while(ptr){
  temp = ptr;
  ptr = ptr->next;
  delete temp;
  }
 root = NULL;
}

int LinkedList::count(){
 int c = 0;
 LinkedNode * ptr = root;
 while(ptr){
   c++;
   ptr = ptr->next;
  }
 return c;
}

bool LinkedList::add(int k,X3D_String cp){
 LinkedNode * item = new LinkedNode();
 item->key = k;
 item->data = cp;
 // where to put it?
 if(root){
   if(root->key > k){
	 // must go first
	 item->next = root;
	 root = item;
	 return true;
	}
   LinkedNode * ptr = root, * last;
   while(ptr){
	 if(ptr->key < k){
	   last = ptr;
	   ptr = ptr->next;
	   }
	 else if(ptr->key == k){
	   delete item;
	   return false;
	 }
	 else
	   ptr = NULL;
	 }
   item->next = last->next;
   last->next = item;
   return true;
  }
 root = item;
 return true;
}


bool LinkedList::remove(int k){
 if(!root)
   return false; // Case 1 empty list
 LinkedNode * ptr=root, * last=NULL;
 if(root->key == k) {
   // case 1 - Root points at needed item
   root = root->next;
   delete ptr;
   return true;
 }
 while (ptr){
   if(ptr->key == k){
	 last->next = ptr->next;
	 delete ptr;
	 return true;
	 }
   if(ptr->key > k)
	 return false;
   last = ptr;
   ptr = ptr->next;
  }// end of while
 return false;
}

X3D_String LinkedList::find(int k)const{
  LinkedNode * ptr = root;
  while (ptr){
   if(ptr->key < k)
	 ptr = ptr->next;
   else if (ptr->key==k) {
		  X3D_String result = ptr->data;
		  return result;
		}
   else return "";
   }
  return "";
}

unsigned LinkedList::register_class(VDS & vds){
 LinkedNode ln;
 unsigned id = vds.start_registration(sizeof(LinkedNode));
 bool ptr = vds.add_pointer(id, &ln, &ln.next,"next");
 bool num = vds.add_display(id, &ln, &ln.key, DTInteger,"key");
 bool str = vds.add_display(id, &ln, &ln.data, DTStringObject,"data");
 assert(ptr && num && str);

 return id;
}

bool LinkedList::snapshot(VDS & v, unsigned id, char * filename, bool list, bool view){
  return v.snapshot(root,id,filename,list,view);
}
