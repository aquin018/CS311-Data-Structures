//=========================================================
//  HW#: HW2P1
//  Name: ALejandro Aquino
//  Compiler: g++ compiler
//  File Type: Binsearch main program
//=========================================================
//Purpose: the purpose is to ask the user to enter a number
//it will then look for the number if it exists.

//Algorithm: this program will ask the user to enter a number. 
//And will check to see if the number exists using binary search algorithm.

#include <iostream>
using namespace std;

int binarySearch(int L[], int findthis, int first, int last); //function

int main()
{
  int L[10]={1,3,5,7,9,11,13,15,17,19};//fills array 
  int n;
  int myfirst = 0; 
  int mylast = 9; //  set up initial indices 
  int myList;
  int resultloc;

  cout << "Enter an number to look for: "; //ask user to enter number
  cin >> n;

  resultloc = binarySearch(L, n, myfirst, mylast); //calls function
 
  if(resultloc == -1)
    { //if it returns -1 then it was not found.
      cout << "Find "<< n << " fails to be found." << endl;
      exit(1);
    }
  else
    { //other than that it returns the found number
       cout << "Found " << n << " in position " << resultloc + 1 << endl;
    }
 
  return 0;
}

//function tries to find the number in the array
int binarySearch(int L[], int findthis, int first, int last)
{
  int middle = ((first+last)/2);  // note that if first == last, 
                                  // there is only one element left
  if(last>=first)
   {                            
   if (findthis == L[middle]) return middle;  // found x at location middle
   else if (findthis < L[middle]) last  = middle - 1; // go to first half
   else if (findthis > L[middle]) first = middle + 1; // go to second half   
   }
  else
    return -1; //returns -1 if not found in the filled array.

  return binarySearch(L, findthis, first, last); // recursive call
}
