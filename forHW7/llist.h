//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#3: HW3P1 llist
// Your name: Alejandro Aquino
// Compiler:  g++ 
// File type: header file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be integers

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //Purpose: is to check if the list has no elements, returns true if it is 
  //empty, returns false if it not true.
  bool isEmpty() const;
    
  //Purpose: to display all of the elements in order
  void displayAll() const;

  //Purpose: to add an element to the front
  //Parameter: pass an element to add in the front
  void addFront(el_t);
    
  //Purpose: to add an element to the rear
  //Parameter: pass an element to add in the rear
  void addRear(el_t);

  //Purpose: to delete an element at the front
  //Parameter: will delete an element (pass by reference)
  void deleteFront(el_t&);
    
  //Purpose: to delete an element at the rear
  //Parameter: will delete an element using pass by reference
  void deleteRear(el_t&);
    
  //Purpose: to deletes an element depending on the given value by user entered
  //Parameter: will delete a Ith by using pass by reference
  void deleteIth(int, el_t&);

  //Purpose: to add an element depending before on the given value
  //Parameter: will add before the given Ith pass by value
  void addbeforeIth(int, el_t);
    
};