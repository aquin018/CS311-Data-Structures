//=========================================================================
// HW#: HW6 hw6Client.cpp
// Your name: Alejandro Aquino
// Compiler:  g++
// File type: client file
//=========================================================================

#include <iostream>
#include <string>
using namespace std;
#include "dgraph.h"

int main()
{ 
  dgraph graph;
  char ch;
  int Dfound;
  slist l1;
  graph.fillTable();
  graph.displayGraph();  
  
  while(true)//this will not stop until user enters 'e' to quit
    {
      cout << "----------------------"<<endl;
      cout << "[Finding Degree]" << endl;
      cout << "To get out of the degree ." << endl;
      cout << "Enter a vertex name or enter 'e' to exit: ";
      cin >> ch; 
 
      if(ch == 'e')
	break;
      else
	{
	  //to check if it exist then it display it
	  if(graph.findOutDegree(ch) == -1)
	    {
	     cout << "[Error: The vertex " << ch << " does not exist.]" << endl;
	     cout << "Error Code: " << graph.findOutDegree(ch) << endl; 
	    }//end of if
	  //
	  else
	    {
	      cout << "[Vertex found!]" << endl;
	      cout << "The degree " << ch << " is " << graph.findOutDegree(ch)
                   << endl;
	    }//end of else
	}//end of else
      
    }//end of while loop

  while(true)//this will not stop until user enters 'e' to quit
    {
      cout << "--------------------" << endl;
      cout << "[Finding adjacent list]" << endl;
      cout << "To get out of the degree ." << endl;
      cout << "Enter a vertex name or enter 'e' to exit: ";
      cin >> ch;

	if(ch == 'e')
	  break;
	//will go to else statement if the user does not enter 'e'
	else
	  {
	   cout << "The adjacent " << ch << " is " << endl;
	   l1 = graph.findAdjacency(ch);
	   l1.displayAll();
	  }//end of else
    }//end of while loop
  //end of try
  
  return 0;
}
