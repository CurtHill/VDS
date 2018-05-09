// Tree
#ifndef __Tree
#define __Tree
#include <vcl.h>
#include <assert.h>
#include "stack.h"
#include "visual_data_structure.h"


class Tree;
class TreeIterator;
class ListNode{
   friend class Tree;
   friend class TreeIterator;
    float data;
    int order;
    ListNode * next;
    ListNode(){}
    ListNode(float d, int i):next(NULL),order(i),data(d){}
    unsigned Counter();
    };

class TreeNode{
   friend class Tree;
   friend class TreeIterator;

    String key;
    float data;
    int order;
    TreeNode * smaller, * larger;
    ListNode * equal;

    TreeNode():smaller(NULL),larger(NULL),equal(NULL){}
    TreeNode(const String & k, float d, int i):
        key(k), data(d), order(i),
        smaller(NULL), larger(NULL), equal(NULL){}
    String ToString();
};


class Tree {

  friend class TreeIterator;
   int my_size;
   Tree (const Tree & ){assert(false);}
   Tree & operator =(Tree & t){assert(false); return *this;}
 protected:
   TreeNode * root;
   TreeIterator * current;
   unsigned id;

   TreeNode * start(TreeIterator *);
   bool end(TreeIterator *);
   void equal_add(ListNode * & anchor, float d, int i);
   void trav(TreeNode * root,float &  sum, int & depth, int & count);


 public:
   Tree();

   bool add(const String & k, float d, int i);
   unsigned find(const String & k, float & d, int & i);
   int size(){return my_size;}
   int traverse(float & sum, int & depth);
   void Register(VDS & vds);
   void snapshot(VDS & v, char * filename, bool list=false);
};

struct TreeData {
    float data;
    int order;
    };

class TreeIterator{
    friend class Tree;
    Tree * base;
    stack <TreeNode *> saved;
   void IsChanged();
 public:
   TreeIterator();
   bool start(Tree *);
   unsigned next(String &,TreeData * &);
   bool more();
};


#endif
