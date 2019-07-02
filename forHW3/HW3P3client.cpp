//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P3 slist
//Your name: Alejandro Aquino
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;
#include <iostream>
#include "slist.h"

//PURPOSE: This function simply tests the copy constructor of the slist class
//and adds 6 to a the rear of copiedList and displays the list
//PARAMETER: list passed by value becomes copiedList
void CopyTest(slist copiedList)
{
  cout << "in copy test" << endl;
  slist List(copiedList); // makes a copy
  cout << "Adding 6 to the rear" << endl;
  List.addRear(6);//adds 6 to the rear
  cout << "finished" << endl;
  List.displayAll();
}


//PURPOSE of the Program: to test the overloading operation by making a copy
// of one class
//Algorithm/Design: to test copytest first, then to continue down by creating a
// linked list and making copies 
int main()
{
  slist L1, L2;
  int temp;
  int counter = 1;

 //1.Create a 5 element list with  1,2,3,4,5 (L1)
  cout << "Step: " <<  counter << endl; counter++;
  L1.addFront(1);
  L1.addRear(2);
  L1.addRear(3);
  L1.addRear(4);
  L1.addRear(5);
  cout << "Created 1 to the front." <<endl;
  cout << "Created 2,3,4,5 to the rear." << endl;
  cout << endl;

  //2.Pass the list to a client function called CopyTest to 
  //test your copy constructor.
  cout << "Step: " << counter << endl; counter++;
  CopyTest(L1);
  cout << "-- After copytest --- " << endl;
  cout << endl;

  //3.Display L1 (this should still be a 5 element list)
  cout << "Step: " << counter << endl; counter++;
  cout << "Displaying L1:" << endl;
  L1.displayAll();
  cout << endl;

  cout << "-- Testing operator overloading ---" << endl;
  
  //4.Do L1 = L1;
  cout << "Step: " << counter << endl; counter++;
  cout << "Did L1=L1;" << endl;
  L1=L1;
  cout << endl;

  //5.Display L1    (this should still be 1 2 3 4 5)
  cout << "Step: " << counter << endl; counter++;
  cout << "Displaying L1:" << endl;
  L1.displayAll();
  cout << endl;
  
 
  //6.Create a 4 element list L2 with 7,8,9,10.
  cout << "Step: " << counter << endl; counter++;
  L2.addFront(7);
  L2.addRear(8);
  L2.addRear(9);
  L2.addRear(10);
  cout << "Created 7,8,9,10 into L2" << endl;
  cout << endl;

  //7.Display L2
  cout << "Step: " << counter << endl; counter++;
  cout << "Displaying L2:" << endl;
  L2.displayAll();
  cout << endl;
  
  //8.Do L2 = L1;  (L2 becomes 5 elements 1,2,3,4,5)
  cout << "Step: " << counter << endl; counter++;
  L2 = L1;
  cout << "Did L2 = L1" << endl;
  cout << endl;

  //9.Display L2.
  cout << "Step: " << counter << endl; counter++;
  cout << "Displaying L2:" << endl;
  L2.displayAll();
  cout << endl;
  
  //10.Remove a rear node from L1. (This should not affect L2).
  cout << "Step: " << counter << endl; counter++;
  L1.deleteRear(temp);
  cout << "Deleted Rear node from L1." << endl;
  cout << endl;

  //11.Display L1.   (L1 is 1,2,3,4)
  cout << "Step: " << counter << endl; counter++;
  cout << "Displaying L1:" << endl;
  L1.displayAll();
  cout << endl;
   
  //12.Display L1 again. (4 elements . just to make sure)
  cout << "Step: " << counter << endl; counter++;
  cout << "Displaying L1:" << endl;
  L1.displayAll();
  cout << endl;

  //13.Display L2 again. (still 5 elements 1,2,3,4,5)
  cout << "Step: " << counter << endl; counter++;
  cout << "Displaying L2:" <<endl;
  L2.displayAll();
  cout << endl;
    
 }//end of program

