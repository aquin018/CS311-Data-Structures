 //=========================================================
//HW#: HW1P2 vector stack
//Your name: Alejandro Aquino
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "vstack.h"

//Purpose of the program: to allow the client to enter a post expression
//and display the result on the scren.

//Algorithm: the program would check to see if the post expression
//is correct if not then it would display an error but also give result
//depending on the error.

int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result=0; //stores the result 
 
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char 
	  
	  if(expression[i]>47 && expression[i]<58) // compares using ASCII table
	    {
	      item = int(item) - 48; //converts charcter into integer
	      postfixstack.push(item); //calls push function
	      postfixstack.displayAll(); //displays all integers and expressions
	      
	    }
	  
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1); //pops box1 
	      postfixstack.pop(box2); //pops box1
	      //cases for different operators follow:
	      if (item == '-') 
		{
		  result = box2-box1; //subtracts two integers
		}
	      else if(item == '+')
		{
		  result = box2+box1; //adds two integers
		}

	      else if(item == '*') // mulitiplies two intgers
		{
		  result = box2*box1;
		}
	      postfixstack.push(result); //will call push function
	      postfixstack.displayAll(); //will display all
	      
	    }
	  else 
	    {throw "invalid item: enter only operands and operators";}
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) // for a lot of operands and less expression
	{
	  cerr << "Error: There is too much operands. " << endl;
	  exit(1);
	}
      catch (stack::Underflow) // for too few operands
	{
	  cerr << "Error: There are few operands." << endl;
	  exit(1);
	}
      catch (char const* errorcode) // for invalid item
	{
	  cerr << "Invalid item: " << errorcode <<  endl;
	  exit(1);
	}
      // go back to the loop after incrementing i
      i++;
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
 
   postfixstack.pop(box1);

  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
   try
     {
       if(postfixstack.isEmpty()!= true)
	 throw "Incomplete expression was found";
     }
   catch(char const* errorcode2)
     {
       cerr << "Invalid item: " << errorcode2 << endl;
       exit(1);
     }

   cout << "Result:" << box1 << endl;

   return 0;

}// end of the program
