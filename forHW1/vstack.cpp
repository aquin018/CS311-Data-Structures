//=========================================================
//HW#: HW1P2 vstack
//Your name: Alejandro Aquino
//Complier:  g++
//File type: stack implementation file
//=========================================================
#ifndef VStack_CPP
#define VStack_CPP

using namespace std;  
#include <iostream>
#include <vector>
#include "vstack.h"

//PURPOSE:  Constructor does not have anything to do
stack::stack()
{ } // indicate an empty stack 
  
//PURPOSE:  Destructor does not have to do anything since this is a vector.
stack::~stack()
{ }// nothing to do
  
//PURPOSE:  checks top and returns true if empty, false otherwise.
bool stack::isEmpty()
{ if(el.size() == 0 )return true; else return false; }
    
//PURPOSE: always returns false but vectors shrink and increase.
bool stack::isFull()
{return false; }
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
 void stack::push(el_t elem)
{ 
  if(isFull())
    throw Overflow(); //throws error overflow
  else
    el.push_back(elem); // pushes element
}
 
 //PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
 //  Otherwise, removes an element from el and gives it back.
 //PARAMETER: provide a holder (elem) for the element popped (pass by ref)
 void stack::pop(el_t& elem)
{ if(isEmpty()) 
    throw Underflow(); //throw an error underflow
  else 
   {
     elem = el[el.size()-1]; //returns the last element
     el.pop_back();   //deletes the last element and decrements
   }
 }
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
 void stack::topElem(el_t& elem)
 { if(isEmpty()) 
     throw Underflow();
   else 
     { 
       elem = el.back(); //returns last element from vector
     } 
 }
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
 void stack::displayAll()
 {  if (isEmpty()) cout << ".[ empty ]." << endl;
   else for (int i=el.size()-1; i>=0; i--)
     { cout << el[i] << endl; }
   cout << "--------------" << endl;
 }
 
 
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
 void stack::clearIt()
 {
   int t; //local variable for popping all elements
   while(!isEmpty()) //if it not empty then it goes 
     pop(t);         //in the while loop to pop all elements 

 }
 
#endif
