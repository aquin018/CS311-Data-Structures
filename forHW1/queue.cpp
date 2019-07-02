//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Alejandro Aquino
//Complier:  g++
//File type: Implementation File
//===========================================================

#ifndef Queue_CPP
#define Queue_CPP

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
  //intializes the variables
  el[0]="A";
  el[1]="B";
  el[2]="C";
  count=3;
  rear=2;
  front=0; 
}

//destructor 
queue::~queue()
{
 //nothing to destroy in here
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if(count == 0)  //checks to see if count has nothing
    {
      cout << "Error:the queue is empty." << endl;//displays error message
      return true;
    }
  else
    {
      return false;
    }
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{ 
  if(count == MAX_SIZE) //compares count to max size to see if it's full
    {
      cout << "Error: the queue is full. " << endl;//if true then displays error
      return true;                                 //message
    }
  else
    {
      return false;
    }
 
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if(isFull())
    throw Overflow();//throws an error if it's full

  else
    {
      rear = (rear+1) % MAX_SIZE;
      el[rear] = el[front] + newElem; 
      count++; //increments count
    }
}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  if(isEmpty())
    {
      cout << "[.Empty.]" << endl;
      exit(1);
    }
  else
    {
      string giveback = el[front];
      front = (front + 1) % MAX_SIZE;
      count--; //decrements count
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  if(isEmpty())
    {
      throw Underflow();
    }
  else
    {
      theElem = el[front];
      cout << "The front element is " << theElem << endl;
    }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{ 

  if(isEmpty())
    {
      throw "[ Empty ]"; //cout empty if empty
    }
  else if(rear<front)
    { // prints out in order
      for(int i = front; i<MAX_SIZE; i++) 
	 { 
	   cout << el[i] << " " << endl;;  
	 } 
      for(int i=0; i<front; i++) 
	 { 
	   cout << el[i] << " " <<endl;  
         } 
    }
   else
     {//prints if rear is bigger than front
      for(int i=front;i < count+front;i++)
       {
         cout << el[i] << " " << endl;;
       }
    }    

}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{
  if(isEmpty())
    { //throws and underflow if it is empty
     throw Underflow();
    }

  else if(count==1)
    {
      //does nothing if count is 1
    }
  else
    { 
      //adds and then removes
      add(el[front]);
      remove(el[front]);
    }
}

#endif
