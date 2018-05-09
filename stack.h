/* stacks using lists
   This is very old.
   Updated 2016/1/14 to make a style checker more happy with it.
*/
#ifndef _Curt_Stack_H
#define _Curt_Stack_H

#include <assert.h>
// This was the problem - used to be Windows.h to enable MessageBoxW
#include <vcl.h>

template <class T>
 class stack {
  // private data
  typedef struct sttype { // the typedef if private, allows us
	  sttype* next;        // to wrap a struct around the type
	  T package;
		} stack_type;

  stack_type * top;
  stack(const stack&);
  stack& operator = (const stack&);

 public:
  stack();     // default constructor
  ~stack();
  void push(T);
  T pop();
  T get_top(){return top->package;}
  bool isempty();
}; // end of class prototypes

template <class T>
  stack<T>::stack() {
	  top = NULL; // null
	 }

template <class T>
  stack<T>::stack(const stack<T>& old) {
	 assert(0);
         top = NULL;
	 }

template <class T>
  stack<T>& stack<T>::operator = (const stack<T>& old) {
	 assert(0);
         top = NULL;
	 }

template <class T>
  stack<T>::~stack() {
	  stack_type* temp;
	  while(top != NULL) {
		 temp = top;
		 top = top->next;
		 delete temp;
		 }
	  top = NULL; 	 
	 }

template <class T>
  void stack<T> :: push(T item) {
	  stack_type* temp;
        try {
	      temp = new stack_type;
            }
		catch(...){
		#ifdef CB10
		  Application->MessageBox(L"Could not allocate a new stack unit",L"This is bad!",MB_OK);
		#else
		  Application->MessageBox("Could not allocate a new stack unit","This is bad!",MB_OK);
		  #endif
			return;
			}
	  temp->package = item;
	  temp->next = top;
	  top = temp;
	 }

template <class T>
  T stack<T>::pop() {
	  T temp;
	  stack_type* s;
	  assert(top!=NULL);

	  temp = top->package;
	  s = top;
	  top = top->next;
	  delete s;
	  return(temp);
	 }

template <class T>
  bool stack<T>::isempty() {
	  return(top==NULL);
	 }
#endif
