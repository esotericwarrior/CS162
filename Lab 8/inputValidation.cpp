/************************************************************************
** Program name: sort							*
** Author: Tristan Santiago						*
** Date: March 4, 2018							*
** Description: lines 11-39 are case validating.			*
**				lines 42-62 are > 0 integer validating.	*
**				lines 65-105 are row/column validating.	*
************************************************************************/
#include "inputValidation.hpp"
#include <iostream>
using namespace std;

double menuValidation(double validate) // make sure numbers coming in are initialized as doubles
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

double integerValidation(double intValidate)
{
	bool check = true;

	//cout << "Please enter a number greater than one." << endl; // edited to be greater than 1, rather than 0
	//cin >> intValidate;

	while(check == true)
	{
		//if (intValidate > 0 && intValidate < 20)				// greater than 1, not zero, less than 20 for Lab5
		if (intValidate >= 0)
		{
			return intValidate;
			cin.clear();
			cin.ignore();
			check = false;
		}
		else
		{
			cout << "The number must be greater than 0. Try again." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> intValidate;
		}
	}
}

double menu5Validation(double validate) // make sure numbers coming in are initialized as doubles
{
    //int validate;
	    while(1) //Begins infinite loop that will only break if an integer of 1 or 2. https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
	{
		if(cin.fail()) // if not an integer:
			{
				cin.clear(); // clears the error flag on cin. https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
				cin.ignore(100, '\n'); // skips to the next newline, and skips 100 characters
				cout << "Please enter a valid option." << endl; // asks for input again
				cin >> validate;
				// cout << "Not an integer catch: " << validate << endl; -- test cout
			}
		if(!cin.fail() && (validate == 1 || validate == 2 || validate == 3 || validate == 4 || validate == 5))
		// If valid input:
		// if(!cin.fail() && (0 < validate < 5)) 	// If valid input:
		{   // cout << validate << endl; -- test cout
		    return validate;									// then break loop.
		    break;
		}

		else // if an integer, but not a valid option
		{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid option. Please try again." << endl;
				cin >> validate;
				// cout << "Not correct integer catch: " << validate << endl; -- test cout
		}
	}
}

// double arrayValidation(double rowValidate, double colValidate) // expecting rows/columns to be passed here
// {
// 	bool check = true;
// 	int row, col;

// 	while (trueCheck1 == true)
//                 {
//                     cout << "Enter the row number (starting at row 1)" << endl;
//                     cin >> row;
//                     if (row <= rowValidate && row > 0)
//                     {
//                         row = row - 1;
//                         trueCheck1 = false;
//                     }
//                     else
//                     {
//                         cout << "Starting row position must be within the given number of rows! " << endl;
//                         cin.clear();
//                         cin.ignore();
//                     }
//                 }
//                 while (trueCheck1 == false)
//                 {
//                     cout << "Enter the column number (starting at column 1)" << endl;
//                     cin >> col;
//                     if (col <= colValidate && col > 0)
//                     {
//                         col = col - 1;
//                         trueCheck1 = true;
//                     }
//                     else
//                     {
//                         cout << "Starting column position must be within the given number of columns! " << endl;
//                         cin.clear();
//                         cin.ignore();
//                     }
//                 }
//                 trueCheck2 = false;
//                 return row;
//                 return col;
// }
