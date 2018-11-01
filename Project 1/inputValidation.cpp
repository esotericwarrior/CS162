/*********************************************************************  
** Program name: Langton's Ant
** Author: Tristan Santiago
** Date:  January 19, 2019
** Description: This is the input validator function. When called, it
** only accepts a 1 or 2. Re-implemented this code from the previous
** lab activity.
*********************************************************************/
#include "inputValidation.hpp"
#include <iostream>
using namespace std;

double inputValidation(double validate)
{   
    //int validate;
	    while(1) //Begins infinite loop that will only break if an integer of 1 or 2. https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
	{
		if(cin.fail()) //if not an integer:
			{
				cin.clear(); // clears the error flag on cin. https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
				cin.ignore(100, '\n'); // skips to the next newline, and skips 100 characters
				cout << "Please enter an integer, either 1 or 2." << endl; // asks for input again
				cin >> validate;
				// cout << "Not an integer catch: " << validate << endl; -- test cout
			}
		if(!cin.fail() && (validate == 1 || validate == 2)) 	// If valid input:
		{   // cout << validate << endl; -- test cout
		    return validate;									// then break loop.
		    break;
		}
		
		else // if an integer, but not a 2 or 3:
		{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please enter a 1 or a 2."<<endl;
				cin >> validate;
				// cout << "Not correct integer catch: " << validate << endl; -- test cout
		}
	}
}