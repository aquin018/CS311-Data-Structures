//=========================================================
//HW#: HW3P3 Overloading Extra Credit
//Your name: Alejandro Aquino
//Complier:  g++
//File type: client program (tester) Extra Credit
//===========================================================

#include <iostream>
#include "slist.h"
using namespace std;

void CompareTwoObjectsTest(slist& list1, slist& list2);

//Purpose: to check each elements using overloading operator==
int main()
{
  int pos;
  int result;
  slist L1, L2;
  
  //1.L1 is empty and L2 is empty   true
  cout << "1. L1 is empty and L2 is empty: ";
  CompareTwoObjectsTest(L1,L2);
  cout << endl;
  
  //2.L1 is empty and L2 has 2 elements   false
  L2.addFront(1);
  L2.addRear(2);
  cout << "L1 is empty and L2 has 2 elements: ";
  CompareTwoObjectsTest(L1,L2);
  cout << endl;
 
  //3.L1 has 2 elements and L2 is empty false
  L1.addFront(1);
  L1.addRear(2);
  L2.deleteRear(result);
  L2.deleteRear(result);
  cout << "L1 has 2 elements and L2 is empty: ";
  CompareTwoObjectsTest(L1,L2);
  cout << endl;

  //4.L1 has 1,2,3 and L2 has 1,2,3 true
  L1.addRear(3);
  L2.addFront(1);
  L2.addRear(2);
  L2.addRear(3);
  cout << "L1 has 1,2,3 and L2 has 1,2,3: ";
  CompareTwoObjectsTest(L1,L2);
  cout << endl;

  //5.L1 has 1,2,3 and L2 has 1,2 false
  L2.deleteRear(result);
  cout << "L1 has 1,2,3 and L2 has 1,2: ";
  CompareTwoObjectsTest(L1,L2);
  cout << endl;

  //6.L1 has 1,2,3 and L2 has 1,2,3,4 false
  L2.addRear(3);
  L2.addRear(4);
  cout << "L1 has 1,2,3 and L2 has 1,2,3,4: ";
  CompareTwoObjectsTest(L1,L2);
  cout << endl;

  //7.L1 has 1,2,3 and L2 has 1,2,4
  L2.deleteIth(3,pos);
  cout << "L1 has 1,2,3 and L2 has 1,2,4: ";
  CompareTwoObjectsTest(L1,L2);
  cout << endl;

  return 0;
}

//Purpose: will use to two objects with their elements
void CompareTwoObjectsTest(slist& list1, slist& list2)
{
  cout << endl;
  cout << "List 1:";
  list1.displayAll();
  cout << "List 2:";
  list2.displayAll();
  if(list1==list2)
    {
      cout << "True" << endl;
    }
  else
    {
      cout << "False" << endl;
    }
}
