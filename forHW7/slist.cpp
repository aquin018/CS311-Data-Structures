//==================================================================
// HW#3: HW3P2 slist
// Your name: Alejandro Aquino
// Compiler:  g++
// File type: implementation file for slist
//==================================================================

#include <iostream>
#include "slist.h"
using namespace std;

//Purpose: to intialize all of llist inherited objects
slist::slist()
{
  Front = NULL;
  Rear = NULL;
  Count=0;
  
}

//Purpose: to create a new linked list or copy
//Parameter: will pass an object to make a copy
slist::slist(const slist& original)
{
  el_t t=0;
  //First make sure this-> and otherOne are not the same object.
  //To do this, compare the pointers to the objects.
  if(&original != this) // if not the same
    {
      //this-> object has to be emptied first.
      while(!this->isEmpty())
        this->deleteRear(t);

      //this-> object has to be built up by allocating new cells(**)
      Node *p; //local pointer for original 
      p = original.Front;
      while(p!=NULL) //This uses a loop which repeats until you reach the end
                     //of otherOne
        {
          this->addRear(p->Elem);
          p=p->Next;
        }
    }//end of if

}

//Purpose: used to overload the operator allowing to make a copy of
//linked list
//Parameter: will pass a copy slist object
slist& slist::operator=(const slist& otherOne)
{
  el_t t=0;
  //First make sure this-> and otherOne are not the same object.
  //To do this, compare the pointers to the objects.
  if(&otherOne != this) // if not the same
    {
      //this-> object has to be emptied first.
      while(!this->isEmpty())
	this->deleteRear(t);

      //this-> object has to be built up by allocating new cells(**)
      Node *p; //local pointer for otherOne
      p = otherOne.Front;
      while(p!=NULL) //This uses a loop which repeats until you reach the end
               	     //of otherOne
	{
	  this->addRear(p->Elem);
	  p=p->Next;
	}
    }//end of if
  return *this; //returns the result unconditionally
}

//Purpose: will compare size and elements to check if two objects
//are the same. Using const at the end so that it won't be 
//changed (Extra Credit)
//Parameter: pass a copy object of slist
bool slist::operator==(const slist& list2) const
{
  //compares size for list2
  if(this->Count != list2.Count)
    return false;

  //p and q are local pointers for putting both values front
  Node *p=this->Front;
  Node *q=list2.Front;
  
  while(p!=NULL)
    {
      //compares element by element
      if(p->Elem != q->Elem)
	{
	  return false;
	}
      p=p->Next;
      q=q->Next;
    }

  return true;
}
//Purpose: to search through the list until
//Parameter: will use pass by value to find key position
//key is found and returns the position
int slist::search(el_t key)
{
  //p is a local pointer for finding key 
  Node *p= new Node;
  p = Front;
  int find = 0;
  int i=1;
    while(p!=NULL)
      {
	//if it is found then it will return key position
	if(p->Elem == key)
	  {
	    find = i;
	    return find;
	  }
	i++;
	p=p->Next;
      }
    return find;
}

//Purpose: go to the Ith place and the replace the element (swap)
//Parameters: will pass a an elem and <I> postion to the function
void slist::replace(el_t elem, int I)
{
  //exception Error
  if(I<1 || I>Count)
    {
      throw OutOfRange();
    }
  else if(I == 1)
    {
      Front->Elem = elem;
    }
  else if(I == Count)
    {
      Rear->Elem = elem;
    }
  else
    {
      //p is a local pointer that will point to next pointer
      //to replace an element
      Node *p = new Node;
      p=Front;
      for(int i=1; i<I;i++)
	{
	  p=p->Next;
	}
      p->Elem = elem;
    }
}
