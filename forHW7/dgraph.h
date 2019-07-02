
//=========================================================================
// HW#: HW7P2 dgraph.h
// Your name: Alejandro Aquino
// Compiler:  g++
// File type: header file
//=========================================================================
#include <iostream>
#include <string>
#include "slist.h"
#include "stack.h"

using namespace std;

//-----  globally setting up an alias ---------------------
const int SIZE = 20;   // for the size of the graph table

// this will be in each GTable slot
struct Gvertex
{
  char vertexName;      //the vertex Name
  int outDegree;	//the Out degree
  slist adjacentOnes;   //the adjecent vertices in an slist
  int visit;            // This will hold the visit number in HW7 
};

class dgraph
{

private:
  Gvertex Gtable[SIZE];  // a table representing a dgraph
  int countUsed; // how many slots of the Gtable are actually used

public:

  class BadVertex {};  // thrown when the vertex is not in the graph
 
  dgraph();    // initialize vertexName (blank) and visit numbers (0)
               // initialize countUsed to be 0
  ~dgraph();   // do we have to delete all nodes of slists in table??
	       // Question: If we do not do this, will the llist destructor
               // be called automatically??? Try it.

  //Purpose:read from the input file table.txt and fill GTable
  void fillTable();  

  //Purpose: displays in an easy to read format 
  void displayGraph(); 

  //Purpose: returns the out degree of a given vertex - may throw BadVertex
  int findOutDegree(char d);  
	
  //Purpose: returns the adjacency list of a given vertex - may throw BadVertex
  slist findAdjacency(char a);

  //Purpose: enters depending on the given visit number for a given vertex.
  void visit(int vis, char ch);
  
  //Purpose: to let the user know if the given vertex was visited 
  bool isMarked(char mark); 

  //Purpose: to display only vertex name and visits
  void displayGraphVertices();
};


