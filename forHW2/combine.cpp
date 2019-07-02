//=========================================================
//  HW#: HW2P2
//  Name: Alejandro Aquino
//  Compiler: g++ compiler
//  File Type: combine merge program
//=========================================================
//Purpose: to organize integers in order so it will output in order.

//Algorithm: will ask user to enter integers and 
// will order them in order.

#include <iostream>
#include <vector>
using namespace std;

void Combine(vector<int> A,  vector<int> B, vector<int>& R,int count);

int main()
{
  //declaring integers
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int num;
  int count=0;
  int half,half2;

  //asks the user to enter how many elements
  cout << "How many integers will you enter: ";
  cin >> count;
  half=count/2;
  half2=count/2;

  //enters half of user entered
  cout << "Enter first " << half << " integers in order: " << endl;
  while(half!=0)
    {
      cout << "Enter here: ";
      cin >> num;
      L1.push_back(num);
      half--;
    }
  
  //enter half of user entered
  cout << "Enter last " << half2 << " integers in order:" << endl;
  while(half2!=0)
    {
      cout << "Enter here: ";
      cin >> num;
      L2.push_back(num);
      half2--;
    }
  //calls combine function
  Combine(L1,L2,L3,count);

  //outputs elements
  cout << "The combination of L1 and L2 are: ";
  for(int i=0;i<count;i++)
    cout << L3[i] << " "; 

  cout << endl;
  return 0;
}

void Combine(vector<int> A,  vector<int> B, vector<int>& R, int count)
{
  int ia = 0; // index for A
  int ib = 0; // index for B
  int ir = 0; // index for R
  int ABsize=(A.size() + B.size()); // size for A and B

  //Until you run out of elements in A or run out of elements in B:
  while(R.size() < ABsize)
    {

      //checks to see one of elements are empty
      if(ia== A.size())
	{
	  R.push_back(B[ib]);
	  ib++;
	}
      else if(ib== B.size())
	{
	  R.push_back(A[ia]);
          ia++;
	}
      else
	//if not it does the merge process in else conditional statement
	{
         if(A[ia] < B[ib])//compares two intgers
          {
	   R.push_back(A[ia]); //push backs them to R vector
           ia = ia + 1; // get the A element
          }
	 else 
	  {                   
	   R.push_back(B[ib]); //push backs them to R vector
           ib = ib + 1; // get the B element
          }

        } 
    }
  
}
