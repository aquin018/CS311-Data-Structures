//=======================================================
// HW#: HW1P2 vector stack
// Your name: Alejandro Aquino
// Compiler:  g++ 
// File type: header file vstack.h
//=======================================================

#ifndef VStack_H
#define VStack_H
#include <iostream>
#include <vector> //declares vector
using namespace std;

typedef int el_t;  //used to declare el_t

class stack
{ 
  
 private: // to be hidden from the client
  
  vector<el_t> el;       // el is a vector of el_t's
    
 public: // prototypes to be used by the client
  // Note that no parameter variables are given
  
  // exception handling classes  
  class Overflow{};   // thrown when the stack overflows
  class Underflow{};  // thrown when the stack underflows
  
  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (pass by ref)
  void pop(el_t&);
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: will give back an element (pass by reference)
  void topElem(el_t&);

  //PURPOSE: returns true if stack is empty, else false
  bool isEmpty();
  //PURPOSE: always returns false since vectors don't have a max size
  bool isFull();
  //PURPOSE: displays the elements
  void displayAll();
  //PURPOSE: pops all elements from the stack to make it empty
  //if it is not empty
  void clearIt();
  
};  

// Note: semicolon is needed at the end of the header file

#endif
