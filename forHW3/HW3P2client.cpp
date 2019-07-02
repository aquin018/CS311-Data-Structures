//=========================================================
//HW#: HW3P2 slist
//Your name: Alejandro Aquino
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "slist.h"

//PURPOSE of the program: to test out slist.h and list.cpp
//using inheritance of llist
int main()
{ 
  slist L;  // the list 
  int foundPos; // to hold the found position 
  int counter = 1; // used to display test line number
try
  {
    //  1)add to front once (element 4)
    cout << "Step: " << counter << endl; counter++;
    L.addFront(4);
    cout << "Added element 4 to the front. " <<endl;
    cout << "----------------------------------" << endl;
    cout << endl;

    //  2)add to rear 3 times (elements 6,7,8)
    cout << "Step: " << counter << endl; counter++;
    L.addRear(6);
    L.addRear(7);
    L.addRear(8);
    cout << "Added elements 6,7,8 to the rear." << endl;
    cout << "----------------------------------" << endl;
    cout << endl;

    //  3)displayAll    - 4 6 7 8
    cout << "Step: " << counter << endl; counter++;
    L.displayAll();
    cout << "----------------------------------" << endl;
    cout << endl;

    //  4)search for 6, report the result  - found in pos 2
    cout << "Step: " << counter << endl; counter++;
    foundPos = L.search(6);
    if(foundPos!=0)
      {
        cout << "found 6 in position #" << foundPos << " in the list" << endl;
      }
    else
      {
	cout << "6 Not Found" << endl;
      }
    cout << "----------------------------------" << endl;
    cout << endl;

    //  5)replace the 6 with 0 using the search result
    cout << "Step: " << counter << endl; counter++;
    if(foundPos!=0)
      {
	cout << "replaced 6 with 0" << endl;
	L.replace(0,foundPos);
      }
    else 
      {
	cout << "6 could not be replace: not in the list." << endl;
      }
    cout << "----------------------------------" << endl;
    cout << endl;

    //  6)search for 8 and report the result . found in pos 4
    cout << "Step: " << counter << endl; counter++;
    foundPos = L.search(8);
    if(foundPos!=0)
      {
        cout << "found 8 in position #" << foundPos << " in the list" << endl;
      }
    else
      {
        cout << "6 Not Found" << endl;
      }
    cout << "----------------------------------" << endl;
    cout << endl;

    //  7)replace the 8 with 2 using the search result
    cout << "Step: " << counter << endl; counter++;
    if(foundPos!=0)
      {
        cout << "replaced 8 with 2" << endl;
        L.replace(2,foundPos);
      }
    else
      {
        cout << "8 could not be replace: not in the list." << endl;
      }
    cout << "----------------------------------" << endl;
    cout << endl;

    //  8)displayAll                       - 4 0 7 2
    cout << "Step: " << counter << endl; counter++;
    L.displayAll();
    cout << "----------------------------------" << endl;
    cout << endl;

    //  9)search for 5 and report the result   - not found
    cout << "Step: " << counter << endl; counter++;
    foundPos = L.search(5);
    if(foundPos!=0)
      {
        cout << "found " << foundPos << " in the list" << endl;
      }
    else
      {
        cout << "5 could not be found in the list." << endl;
      }
    cout << "----------------------------------" << endl;
    cout << endl;

    // 10) replace postion 7 with 10
    cout << "Step: " << counter << endl; counter++;
    L.replace(10,foundPos);
    cout << "----------------------------------" << endl;
    cout << endl;
    }//end of try
   
 //will catch an error if it is out of range from the I value position.
  catch(slist::OutOfRange)
    { cerr << "ERROR: Bad position was given" << endl;
      cerr << "----------------------------------" << endl;
    }

}//end of program
