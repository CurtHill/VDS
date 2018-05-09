//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Circle_List.h"
#include "X3D.h"
#include <assert.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)


/*
 * Insertion of element at beginning
 */

void circle_list::add(int value){
    if (last == NULL){
     last = new cnode;
     last->info = value;
     last->next = last;
     return;
    }
    cnode * temp;
    temp = new cnode;
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}


/*
 * Deletion of element from the list
 */
void circle_list::delete_element(int value)
{
    cnode * temp = NULL, * s;
    s = last->next;
      /* If List has only one element*/
    if (last->next == last && last->info == value) {
        last = NULL;
        if(temp)
          delete temp;
        return;
    }
    if (s->info == value){  /*First Element Deletion*/
        temp = s;
        last->next = s->next;
        delete temp;
        return;
    }
    while (s->next != last){
        /*Deletion of Element in between*/
        if (s->next->info == value){
            temp = s->next;
            s->next = temp->next;
            delete temp;
            //cout<<"Element "<<value;
            //cout<<" deleted from the list"<<endl;
            return;
        }
        s = s->next;
    }
    /*Deletion of last element*/
    if (s->next->info == value)
    {
        temp = s->next;
        s->next = last->next;
        delete temp;
        last = s;
        return;
    }
    //cout<<"Element "<<value<<" not found in the list"<<endl;
}

/*
 * Search element in the list
 */

bool circle_list::search_element(int value)
{
    cnode *s;
    int counter = 0;
    s = last->next;
    while (s != last)
    {
        counter++;
        if (s->info == value)
        {
            //cout<<"Element "<<value;
            //cout<<" found at position "<<counter<<endl;
            return true;
        }
        s = s->next;
    }
    if (s->info == value)
    {
        counter++;
        //cout<<"Element "<<value;
        //cout<<" found at position "<<counter<<endl;
        return true;
    }
    //cout<<"Element "<<value<<" not found in the list"<<endl;
    return false;
}


/*
 * Sort Circular Link List
 */

bool circle_list::sort()
{
    cnode *s, *ptr;
    int temp;
    if (last == NULL)
    {
        //cout<<"List is empty, nothing to sort"<<endl;
        return false;
    }
    s = last->next;
    while (s != last)
    {
        ptr = s->next;
        while (ptr != last->next){
            if (ptr != last->next){
                if (s->info > ptr->info){
                    temp = s->info;
                    s->info = ptr->info;
                    ptr->info = temp;
                }
            }
            else
              break;
       ptr = ptr->next;
       }
     s = s->next;
     }
  return true;
}


unsigned circle_list::register_class(VDS & vds){
 cnode ln;
 unsigned id = vds.start_registration(sizeof(cnode));
 bool ptr = vds.add_pointer(id, &ln, &ln.next,"next");
 bool num = vds.add_display(id, &ln, &ln.info, DTInteger,"info");
 assert(ptr && num);

 return id;
}

void circle_list::insert_error(){
 cnode * error;
 for(unsigned i = 0;i<11;i++){
   error = last;
   last = last->next;
   }
 error->next = (cnode *) 5000;  
}

void circle_list::snapshot(VDS & v, unsigned id, char * filename, bool list, bool view){
  v.snapshot(last,id,filename,list,view);
}


circle_iterator::circle_iterator(circle_list * l):list(l),first(NULL){
 first = list->last;
 current = first;
}

bool circle_iterator::next(int & i){
  if(current == NULL)
    return false;
  i = current->info;
  current = current->next;
  if(current == first){
    current = NULL;
    first = NULL;
    list = NULL;
    }
  return true;
}

bool circle_iterator::done(){
  return current == NULL;
}

