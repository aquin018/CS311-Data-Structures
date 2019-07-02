//=========================================================================
// HW#: HW7 hw7Client.cpp
// Your name: Alejandro Aquino
// Compiler:  g++
// File type: client file
//=========================================================================

#include <iostream>
using namespace std;
#include "dgraph.h"

int main()
{
  int visitNum = 1;
  int verPop;
  char let = 'A';
  char verLet;
  int degree;

  dgraph dgh;
  stack vtx;

  //this fills the table 
  cout << "The table is filling up.." << endl;
  dgh.fillTable();

  //then this function displays the graph
  cout << "Displaying graph..." << endl;
  dgh.displayGraph();

  //marking/visit A
  cout << "...Marking DFS by starting with A..." << endl;
  dgh.visit(visitNum, let);
  visitNum++;

  //THis will display the stack which is empty
  cout << "Displaying the stack..." << endl;
  vtx.displayAll();
  
  while(!vtx.isEmpty())
    {
      vtx.pop(verPop);
      cout << "The vertex name is " << verPop <<endl; 
      
    }

  //will output the vertex name and visits
  cout << "Displaying the graph" << endl;
  dgh.displayGraphVertices();
  
  return 0;

}
