//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#3: HW3P1 llist
//Your name: Alejandro Aquino
//Complier:  g++ 
//File type: llist implementation file
//=====================================================

using namespace std;

#include <iostream>
#include "llist.h" 

//Purpose:intitalizes Front , Rear and Count
llist::llist()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
}
//- initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The list is empty.

//Purpose: to delete all nodes when this function is called
llist::~llist()
{
  el_t elem;
  while(Count!=0)
    {
     //calls function to delete all Nodes
     deleteFront(elem);  
    }
  cout << "Calling the list destructor." << endl;
}
//- while the list is not empty, call deleteFront repeatedly to delete all nodes
//- Please place a cout in this function "calling the llist desctructor."

//Purpose: to check if count is zero, front and rear are empty.
bool llist::isEmpty() const
{
  if((Front==NULL && Rear ==NULL) && Count==0)
    {
      return true;
    }

  else
    {
     return false;
    }
}
//  - return true if Front and Rear are both pointing to NULL and Count is 0.
//  - (all 3 conditions must be checked)
		
//Purpose: to display all nodes if it is not empty.
void llist::displayAll() const
{
  //checks to see if Nodes are empty
  if(isEmpty())
    cout << "It is [ Empty ]" << endl;

  //if not, then it display all nodes
  else
    {
      Node* curr = Front;
      cout << "[ ";

      while(curr !=NULL)
	{
	  cout << curr -> Elem <<" ";
	  curr = curr -> Next; 
	}
      cout << "]" << endl;
    }
}
//- Special case: if the list is empty, display [ empty ] ).
//- Regular: 
//   displays each element of the list horizontally starting from Front in [ ].

//Purpose: to add an element to the rear node
//Parameter: pass an element to add in the rear node
void llist::addRear(el_t NewNum) 
{
  //if the list is empty
  if(isEmpty())
    {
      Front = new Node;
      Front->Elem = NewNum;
      Front->Next=NULL;
      Rear = Front;
      Count++;
    }
  //if it is not empty, then it will add a new Node
  else
    {
      Node *newN;
      newN = new Node;
      newN -> Elem = NewNum;
      Rear->Next = newN;
      Rear = newN;
      Rear->Next=NULL;
      Count++;
    }
}
/*
2 cases:
  - Special case: if this is going to be the very first node, you must
    create a new node and make Front and Rear point to it. Place NewNum and
    Count is updated.
  - Regular: adds a new node at the rear and puts NewNum in the Elem field
    of this new node. Count is updated.
    Regular case:
    Rear->Next = new Node;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL;
*/
//Purpose: to add an element to the front node 
//Parameter: pass an element to add in the front node
void llist::addFront(el_t NewNum)
{
  //special case: if it is empty
  //this will create a new Node
  if(isEmpty())
    {
      Node *newNode = new Node;
      newNode ->Next = Front;
      newNode ->Elem = NewNum;
      Rear = newNode;
      Front = newNode;
      Count++;
    }
  //Regular case: 
  else
    {
      Node *x;
      x = new Node;
      x->Next = Front;
      Front = x;
      Front->Elem = NewNum;
      Rear=Front;
      Count++;
    }
}

/*
2 cases:
- Special case: if this is going to be the very first node, you must
   create a new node and make Front and Rear point to it. Place NewNum and
   Count is updated.
- Regular: add a new node to the front of the list and 
  Count is updated.
  Regular case:
  Node *x;
  x = new Node;
  x->Next = Front;
  Front = x;
  Front->Elem = NewNum;
*/

//Purpose: to delete an element at the front
//Parameter: will delete an element (pass by reference)
void llist::deleteFront(el_t& OldNum)
{
  //error case: if the Nodes are empty
  if(isEmpty())
    {
      throw Underflow();
    }
  //special case: if theres only one node
  else if(Count==1)//Front->Next==NULL)
    {
      OldNum=Front->Elem;
      delete Front;
      Front=NULL;
      Rear=NULL;
      Count--;
    }
  //regular case
  else
    {
      //p is for local pointer
      OldNum = Front->Elem;
      Node *p;
      p = Front->Next;
      delete Front;

      if(p->Next==NULL)
	Rear=p;

      Front = p;
      Count--;
    }
}
/*
3 cases:
- Error case: if the List is empty, throw Underflow
- Special case: if currently only one Node,
   give back the front node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the front node element through OldNum (pass by reference)
  and also removes the front node.  Count is updated.
  Regular case:
  OldNum = Front->Elem;
  Node *Second;
  Second = Front->Next;
  delete Front;
  Front = Second;
*/

//Purpose: to delete an element at the rear
//Parameter: will delete an element using pass by reference
void llist::deleteRear(el_t& OldNum)
{
  //checks if it empty
  if(isEmpty())
    {
      throw Underflow();
    }
  //if count is 1 then it deletes last elem node
  else if(Count==1)
    {
      OldNum = Rear->Elem;
      delete Rear;
      Front=NULL;
      Rear=NULL;
      Count--;
    }
  //regular cases
  else
    {
      Node *p=Front;
      while(p->Next!=Rear)
	{
	p=p->Next;
	}
      p->Next=NULL;
      OldNum = Rear->Elem;
      delete Rear;
      Rear = p;
      Count--;    
    }
}
/*
 3 cases:
- Error case: if empty, throw Underflow
- Special case: if currently only one node,
   give back the rear node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the rear node element through OldNum (pass by reference)
  and also remove the rear node. Count is updated.
  Regular case:
  OldNum = Rear->Elem;
  Node *p;
  Make p go to the one right before rear (using while)
  delete Rear;
  Rear = p;
*/

//Purpose: to deletes an element depending on the given value by user entered
//Parameter: will delete a Ith by using pass by reference
void llist::deleteIth(int I, el_t& OldNum)
{
  if(I > Count || I < 1)
    {
      throw OutOfRange();
    }
  else if(I==Count)
    {
      deleteRear(OldNum);
    }
  else if(I==1)
    {
      deleteFront(OldNum);
    }
  else
    {
      Node *p=Front;
      for(int K=1;K<I-1;K++)
      	{p=p->Next;}
      
      Node *q = p->Next;
      OldNum = q->Elem;
      p->Next = q->Next;
      delete q;
      Count--;
    }
}
/*
4 cases:
- Error case: 
  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
- Special cases: this should simply call deleteFront when I is 1 or 
  deleteRear when I is Count
- Regular: delete the Ith node (I starts out at 1).  Count is updated.
<see the template loops in the notes to move 2 pointers to the right nodes;
and make sure you indicate the purposes of these local pointers>
*/

//Purpose: to add an element depending before on the given value
//Parameter: will add before the given Ith pass by value
void llist::addbeforeIth(int I, el_t newNum)
{
  if(I > Count+1 || I < 1)
    {
      throw OutOfRange();
    }
  else if(isEmpty())
    {
      throw Underflow();
    }
  else if(I == 1)
    {
      addFront(newNum);
    }
  else if(I == Count+1)
    {
      addRear(newNum);
    }
  else
    {
      //p is a local pointer that will be set to equal  
      //to Front 
      Node *p=Front;
      for(int K=1;K<I-1;K++)
        {p=p->Next;}
    
      //after it is moved the ith node it
      //will then add a node
      Node *newNode = new Node;
      newNode -> Elem = newNum;
      newNode -> Next = p -> Next;
      p -> Next = newNode;
      Count++;
    }
}

/*
4 cases:
-  Error case:
   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
-  Special cases: this should simply call addFront when I is 1 or addRear when
   I is Count+1
-  Regular: add right before the Ith node. Cout if updated.
<see the template loops in the notes to move 2 pointers to the right nodes
and make sure you indicate the purposes of these local pointers>


*/
