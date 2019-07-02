//=========================================================================
// HW#: HW7P2 dgraph.cpp
// Your name: Alejandro Aquino
// Compiler:  g++
// File type: implementation file
//=========================================================================
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "dgraph.h"

//Purpose: initialize dgraphs variables
dgraph::dgraph()
{
  countUsed = 0;
  for(int i=0;i<SIZE;i++)
    {
      Gtable[i].vertexName = ' ';
      Gtable[i].outDegree = 0;
      Gtable[i].visit = 0;
    }
}

//Purpose: nothing since the destructor is called on llist function
dgraph::~dgraph()
{
  //Nothing  
}

//Purpose: read from the input file table.txt and fill GTable
void dgraph::fillTable()
{
  ifstream fin;
  fin.open("table.txt"); //used to open .txt file
  char X,x;

  while(fin >> Gtable[countUsed].vertexName)//reads name
   {
     fin >> Gtable[countUsed].outDegree; //reads degree

       for(int i=0;i<Gtable[countUsed].outDegree;i++)
	 {
	   fin >> x;
	   (Gtable[countUsed].adjacentOnes).addRear(x);
	   // this uses a slist function from HW3
	 }//end of for loop
     
     countUsed++;// increment the countUsed
   }//end of while
 
  fin.close(); //the file is closed after while loop
}

//Purpose: displays in an easy to read format
void dgraph::displayGraph()
{
  for(int i=0;i<countUsed;i++)
    {
      if(!Gtable[i].adjacentOnes.isEmpty())
	{ //displays name,degree, and slist files
	  cout << "*****************" << endl;
	  cout << "Graph Name: "<< Gtable[i].vertexName << endl;
	  cout << "Graph Degree: " << Gtable[i].outDegree << endl;
	  cout << "Graph Visit: " << Gtable[i+1].visit << endl;
	  (Gtable[i].adjacentOnes).displayAll();
	  cout << "*****************" << endl;
	}

      else//if not found it displays empty
	{ 
	 cout << "*****************" << endl;
	 cout << "----The graph " << Gtable[i].vertexName <<" is [EMPTY]----" << endl;
	 cout << "******************" << endl;
	}
    }//end of for loop
}

//Purpose: // returns the out degree of a given vertex - may throw BadVertex
int dgraph::findOutDegree(char d)
{
  //goes through the loop to find degree
  for(int i=0;i<countUsed;i++)
    {
      if(Gtable[i].vertexName == d)
	return Gtable[i].outDegree; //returns if successfully found
    }//end of for loop

  return -1;//used if not found in the loop
}

//Purpose: returns the adjacency list of a given vertex - may throw BadVertexx
slist dgraph::findAdjacency(char a)
{
  //goes through the foor loop to find adjacent ones of the vertex name.
  for(int i=0;i<countUsed;i++)
    {
      if(Gtable[i].vertexName == a)
	return Gtable[i].adjacentOnes;
    }//end of for loop
  slist temp;
  return temp;

}

//Purpose: enters depending on the given visit number for a given vertex
void dgraph::visit(int vis, char ch)
{
  for(int i=0;i<countUsed;i++)
    {
      //will check to see if vertex matches
      if(Gtable[i].vertexName == ch)
	{
	  //then it will assign a value to visit
	  Gtable[i].visit = vis;
	}
    }
}

//Purpose: to let the user know if the given vertex was visited
bool dgraph::isMarked(char mark)
{
  for(int i=0;i<countUsed;i++)
    {
      if(Gtable[i].vertexName == mark)
	{
	  if(Gtable[i].visit != 0)
	    {
	      return true;
	    }
	  else
	    {
	      return false;
	    }
	}//end of if

    }//end of for loop

  //if it doesnt exist then displaying error
  cout << mark << " was not found." << endl;
}

//Purpose: to display only vertex name and visits
void dgraph::displayGraphVertices()
{
  for(int i=1;i<countUsed;i++)
    {
      //nested for loop
      for(int k=0;k<countUsed;k++)
	{
	  if(Gtable[k].visit == i)
	    {
	      cout << "***************************" << endl;
	      cout << "Vertex Name: " << Gtable[k].vertexName << endl;
	      cout << "Vertex Number of Visits: " << Gtable[k].visit << endl;
	      cout << "***************************" << endl;
	    }
	}
    }//end of for loop

}