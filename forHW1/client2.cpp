//INSTRUCTION
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: Alejandro Aquino
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "queue.h"

//Purpose of the program: to indicate a queue data structure using 
//string array. It will also display an overflow message.  
//Algorithm: is to print out A B C and continue to print until it overflows 

int main()
{
  //declaring string and queue objects
  string SElement;
  queue SQueue;

  //displays message
  cout << "Here it is in order:" << endl;
   SQueue.displayAll();

  try
    {
    //stop after 25 size it stops the while loop
     while(SQueue.getSize()<25)
       {
	 //adds and removes and then displays all
	  SQueue.add("A");
	  SQueue.add("B");
	  SQueue.add("C");
	  SQueue.remove(SElement);
	  SQueue.displayAll();
     
       }
  
    }
  catch(queue::Overflow)
    { // displays error mesage
      cerr << "Overflow: The operands got full." << endl;
	exit(1);
    }
    return 0;
}
