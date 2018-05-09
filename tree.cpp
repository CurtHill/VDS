// Tree
#include "Tree.h"

unsigned ListNode::Counter(){
  unsigned count = 1;
  ListNode * ptr = next;
  while(ptr != NULL){
    count++;
    ptr = ptr->next;
    }
  return count;
}

String TreeNode::ToString(){
    return key + " " + data + " " + order;
}


Tree::Tree():
           root(NULL),my_size(0),current(NULL)
           {}

void Tree::equal_add(ListNode * & anchor, float d, int i){
 if(anchor == NULL){
   anchor = new ListNode(d,i);
   return;
   }
 equal_add(anchor->next,d,i);
}


 void Tree::Register(VDS & vds){
 // Pointed at node types
 ListNode list;
 unsigned id1 = vds.start_registration(sizeof(ListNode));
 bool ptr = vds.add_pointer(id1, &list, &list.next,"next");
 bool str = vds.add_display(id1, &list, &list.data,DTFloat, "data") &&
            vds.add_display(id1, &list, &list.order, DTInteger, "order");
 assert(ptr  && str);
 TreeNode tree;
 unsigned id2 = vds.start_registration(sizeof(TreeNode));

 bool ptr1 = vds.add_pointer(id2, &tree, &tree.smaller,"smaller"); // &&
 bool ptr2 = vds.add_pointer(id2, &tree, &tree.larger,"larger"); // &&
 bool ptr3 = vds.add_pointer(id2, &tree, &tree.equal,"equal",id1);
 str = vds.add_display(id2, &tree, &tree.key,DTStringObject, "key") &&
       vds.add_display(id2, &tree, &tree.data,DTFloat, "data") &&
       vds.add_display(id2, &tree, &tree.order, DTInteger, "order");
 assert(ptr && str);
 id = id2;
}

void Tree::snapshot(VDS & v, char * filename, bool list){
  v.snapshot(root,id,filename,list,true);
}



bool Tree::add(const String & k, float d, int i){
    if(current){
        current->IsChanged();
        current = NULL;
        }
    if(root == NULL){
        root = new TreeNode(k,d,i);
        my_size++;
        return true;
        }
    // Search for the item
    TreeNode * ptr = root, * trailer = NULL;
    // Search for the NULL that will be changed
    while(ptr){
        if(ptr->key == k){
          equal_add(ptr->equal,d,i);
          return true;
          }
        trailer = ptr;
        if(ptr->key > k)
            ptr = ptr->smaller;
        else
            ptr = ptr->larger;
    }   // end of while
    ptr = trailer;
    trailer = new TreeNode(k,d,i);
    if(ptr->key > k)
      ptr->smaller = trailer;
    else
      ptr->larger = trailer;
    my_size++;
    return true;
}

unsigned Tree::find(const String & k, float & d, int & i){
    if(root == NULL)
      return 0;
    TreeNode * ptr = root;
    while(ptr){
      if(ptr->key == k){
        d = ptr->data;
        i = ptr->order;
        unsigned count = 1;
        if (ptr->equal != NULL)
           count += ptr->equal->Counter();
        return count;
        }
      if(ptr->key < k)
        ptr = ptr->larger;
      else
        ptr = ptr->smaller;
      } // while
    return 0;
}

TreeNode * Tree::start(TreeIterator * c){
    if(current || root == NULL)
      return NULL;
    current = c;
    return root;
}


bool Tree::end(TreeIterator * c){
    if(current == c){
      current = NULL;
      return true;
    }
    return false;
}



TreeIterator::TreeIterator():base(NULL){}

bool TreeIterator::start(Tree * the_tree){
  if(the_tree == NULL)
    return false;
  if(base){ // in an iteration
    base->end(this);
    base = NULL;
    }
  TreeNode * root = the_tree->start(this);
  while(!(saved.isempty()))
    saved.pop();
  if(root){ // success
      base = the_tree;
      while(root){
         saved.push(root);
         root = root->smaller;
        }    
      return true;
      }
    return false;
 // Dead code
 //return false;
}


unsigned TreeIterator::next(String & str,TreeData * & ptr){
  if(saved.isempty()){
    if(base){
      base->end(this);
      base = NULL;
      }
    return 0;
    }
  TreeNode * current = saved.pop();
  ptr = new TreeData[1000];
  // Stuff the items into the too-large array
  unsigned count=1;
  str = current->key;
  ptr[0].data = current -> data;
  ptr[0].order = current -> order;

  ListNode * ep = current->equal;
  while(ep && count < 1000){
     ptr[count].data = ep->data;
     ptr[count++].order = ep->order;
     ep = ep->next;
    }
  current = current->larger;
  while(current != NULL){
      saved.push(current);
      current = current->smaller;
      }
  return count;
}

bool TreeIterator::more(){
    bool moore = !(saved.isempty());
    if(base && !moore){
      base->end(this);
      base = NULL;
      }    
    return moore;           
}

void TreeIterator::IsChanged(){
  // Abort the iteration
  base = NULL;
  while(!(saved.isempty()))
    saved.pop();  
}

int Tree::traverse(float & sum, int & depth){
    sum = 0.0;
    depth = 0;
    int count = 0;
    trav(root, sum, depth, count);
    return count;
}

void Tree::trav(TreeNode * ptr,float &  sum, int & depth, int & count){
   if(ptr == NULL)
     return;
   sum += ptr->data;
   count++;
   int old_depth = depth;
   depth = 0;
   trav(ptr->smaller, sum, depth, count);
   int small_depth = depth;
   depth = 0;
   trav(ptr->larger, sum, depth, count);     
   if(depth > small_depth)
     depth += old_depth+1;
   else
     depth = old_depth+small_depth+1;   
}   
