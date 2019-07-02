// =======================================================
// HW#3: HW3P3 slist
// Your name: Alejandro Aquino
// Compiler:  g++
// File type: header file slist
//=======================================================

#include "llist.h"

//inherited llist 
class slist:public llist
{
 public:
  //default contructor
  slist();

  //copy constructor to create a new linked list or copy
  slist(const slist& original);

  //used to overload the operator allowing to make a copy of
  //linked list
  slist& operator=(const slist& otherOne);

  //will compare size and elements to check if two objects
  //are the same (Extra Credit)
  bool operator==(const slist& list2)const;

  // search through the list to see if any node contains the key.
  // If so, return its position (>=1). Otherwise, return 0.
  int search(el_t key);

  // go to the Ith node (if I is between 1 and Count) and
  // replace the element there with the new element.
  // If I was an illegal value, throw OutOfRange
  void replace(el_t elem, int I);
};

