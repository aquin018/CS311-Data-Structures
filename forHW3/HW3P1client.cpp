//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P1 llist
//Your name: Alejandro Aquino
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "llist.h"

void caseOne()
{
  cout << "CASE 1:------------------- " << endl;
  llist L;   // this is my list
  int x;  // to hold a removed element
  
  //1 check empty and report the result  
  cout << "Step 1:" << endl;
  if(L.isEmpty() == true)
    cout << "[The list is empty]" << endl;

  cout << endl;

  //2 display the list  
  cout << "Step 2:" << endl;
  L.displayAll();
  cout << endl;
  //3 add 4 integers 1,2,3,4    
  cout << "Step 3:" << endl;
  L.addRear(1);
  L.addRear(2);
  L.addRear(3);
  L.addRear(4);
  cout << "integers have been added." << endl;
  cout << endl;

  //4 display the list  
  cout << "Step 4:" << endl;
  L.displayAll();
  cout << endl;

  //5 remove from front twice (and display the elements removed)
  cout << "Step 5:" << endl;
  L.deleteFront(x);
  cout <<"The element " << x << " has been deleted from the front list."<< endl;
  L.deleteFront(x);
  cout <<"The element " << x << " has been deleted from the front list."<< endl;  cout << endl;

  //6 display the list
  cout << "Step 6:" << endl;
  L.displayAll();
  cout << endl;

  //7 check empty and report the result 
  cout << "Step 7:" << endl;
  if(L.isEmpty() == false)
    {
      cout << "The list is not empty." << endl;
      cout << "Results: ";
      L.displayAll();
    }
  cout << endl;

  //8 remove from the rear twice (display the element removed)
  cout << "Step 8:" << endl;
  L.deleteRear(x);
  cout <<"The element " << x << " has been deleted from the rear list."<< endl;
  L.deleteRear(x);
  cout <<"The element " << x << " has been deleted from the rear list."<< endl;
  cout << endl;

  //9 check empty again and report the result
   cout << "Step 9:" << endl; 
   if(L.isEmpty() == false)
     {
       cout << "The list is not empty." << endl;
       cout << "Results: ";
       L.displayAll();
     }
   cout << endl;

}//end of case 1 
 
void caseTwo()
{ 
  cout << "Case 2: -----------------------" << endl;
  llist L2;  // another list
  int x;   // to hold the removed element 
  int c = 1;  // displayed step number

  // 1.add to front once   (element 5)
  cout << "Step :" << c << endl; c++;
  L2.addFront(5);
  cout << "added element 5 in front list" << endl;
  cout << endl;
  // 2.add to front again  (element 4)
  cout << "Step :" << c << endl; c++;
  L2.addFront(4);
  cout << "added element 4 in front list" << endl;
  cout << endl;
  // 3.delete Front
  cout << "Step :" << c << endl; c++;
  L2.deleteFront(x);
  cout << "deleted front element" << endl;
  cout << endl;
  // 4.add to rear 3 times (elements 6,8,9)
  cout << "Step :" << c << endl; c++;
  L2.addRear(6);
  L2.addRear(8);
  L2.addRear(9);
  cout << "added rear elements 6,8,9" << endl;
  cout << endl;
  // 5. display all
  cout << "Step :" << c << endl; c++;
  L2.displayAll();
  cout << endl;   
  // 6.add before the 1st  (element 4) . 4 5 6 8 9
  cout << "Step :" << c << endl; c++;
  L2.addbeforeIth(1,4);
  cout << "added element 4 before 1st" << endl;
  cout << endl;  
  // 7.add before the 4th  (element 7) . 4 5 6 7 8 9
  cout << "Step :" << c << endl; c++;
  L2.addbeforeIth(4,7);
  cout << "added element 7 before 4th" << endl;
  cout << endl; 
  // 8.add before the 7th  (element 10) . 4 5 6 7 8 9 10
  cout << "Step :" << c << endl; c++;
  L2.addbeforeIth(6,10);
  cout << "added element 10 before 7th" << endl;
  cout << endl;
  
  // 9.add before the 9th  (element 12) . error (out of range)
  cout << "Step :" << c << endl; c++;
  try
    {
     L2.addbeforeIth(9,12);
    } 
  catch(llist::OutOfRange)
    {
      cerr << "Error: Since it could not be inserted element 12 before "
           << "9th element. It is out of range." << endl;
      cerr << endl;
    }
  // 10.add before the 0th (element 0) . error (out of range)
  cout << "Step :" << c << endl; c++;
  try
    {
      L2.addbeforeIth(0,0);
    } 
  catch(llist::OutOfRange)
    {
      cerr << "Error: Since it could not be inserted element 0 before "
           << "0th element. It is out of range." << endl;
      cerr << endl;
    }
  // 11.displayAll
  cout << "Step :" << c << endl; c++;
  L2.displayAll();
  cout << endl; 
  // 12.delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
  cout << "Step :" << c << endl; c++;
  L2.deleteIth(1,x);
  cout << "deleted element " << x << endl;
  cout << endl;
  
  // 13.delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9 
  cout << "Step :" << c << endl; c++;
  L2.deleteIth(5,x);
  cout << "deleted element " << x << endl;
  cout << endl;

  // 14.delete Ith I==3 (indicate the element removed)  - 5 6 8 9
  cout << "Step :" << c << endl; c++;
  L2.deleteIth(3,x);
  cout << "deleted element " << x << endl;
  cout << endl;
  
  // 15.delete Ith I==5 . error (out of range)
  cout << "Step :" << c << endl; c++;
  try 
    {
      L2.deleteIth(5,x);
    }
  catch(llist::OutOfRange)
    {
      cerr << "Error: Could not remove 5th index element. Out of range" << endl;
    }
  // 16.delete Ith I==0 . error (out of range)
  cout << "Step :" << c << endl; c++;
  try 
    {
      L2.deleteIth(0,x);
    }
  catch(llist::OutOfRange)
    {
      cerr << "Error: Could not remove 0 index element. Out of range" << endl;
    }
  // 17.displayAll
  cout << "Step :" << c << endl; c++;
  L2.displayAll();
  cout << endl;

  // 18.delete from rear until it is empty (indicate the elements removed)
  cout << "Step :" << c << endl; c++;
  
  //deletes until there is no nodes left.
  while(!L2.isEmpty())
    {
      L2.deleteFront(x);
      cout << "Deleted " << x << endl;
    }
  cout << endl;

  // 19.displayAll  
  cout << "Step :" << c << endl; c++;
  L2.displayAll();
  cout << endl; 

  
}//end of case 2

void caseThree()
{
  cout << "Case 3:-------------------- " << endl;
  llist L3;
  int x;  // to hold the removed element

  // 1.add before the 0th . error (out of range)
  cout << "Step :" << 1 << endl;;
  try 
    {
      L3.addbeforeIth(0,0);
    }
  catch (llist::OutOfRange)
    {
      cerr << "Error: Since it could not be inserted element 0 before "
           << "0th element. It is out of range." << endl;
      cerr << endl;
    }
  //2.delete front . error (underflow)
  cout << "Step :" << 2 << endl;
  try 
    {
      L3.deleteFront(x);
    }
  catch (llist::Underflow)
    {
      cerr << "Error: Could not delete front element: It is underflow." << endl;
      cerr << endl;
    }
}   //end of case 3

void caseFour()
{

  cout << "Case 4:------------------------ " << endl;
  llist L4;
  int x;  // to hold the removed element

  //   1.delete 2nd . error (out of range)
  cout << "Step :" << 1 << endl;
  try 
    { 
      L4.deleteIth(2,x);
    }
  catch (llist::OutOfRange)
    {
      cerr << "Error: Cannot delete 2nd.  It is out of range." << endl;
      cerr << endl;
    }
  //    2.delete rear . error (underflow)
  cout << "Step :" << 2 << endl;
  try 
    {
      L4.deleteRear(x);
    }
  catch (llist::Underflow)
    {
      cerr << "Error: Could not delete rear element: It is underflow." << endl;
    }
	    
} // end of case 4

//PURPOSE of the Program: to test out the llist files by using test cases.
//Algorithm/Design: 4 test cases are divided into 3 functions and will be tested
int main()
{
  int selection; // this will indicate what the user wants to do
  
  do
    {
      cout << endl << "MENU: These are your options: " << endl << endl;
      cout << "   (1) Case 1  " << endl;
      cout << "   (2) Case 2  " << endl;
      cout << "   (3) Case 3  " << endl;
      cout << "   (4) Case 4 " << endl;
      cout << "    Enter ( 0 ) to quit " << endl;
      cout << "===>";
      
      cin >> selection;
      
      switch(selection)
	{
	case 1: caseOne(); break;
	case 2: caseTwo(); break;
	case 3: caseThree(); break;
	case 4: caseFour(); break;
	}
      if(selection==0)
	{
	  cout << "Exit: GoodBye" << endl;
	}
    }
  while(selection !=0);

}// end of main

