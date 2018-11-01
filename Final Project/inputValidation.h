#pragma once
/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: the header file for the input validation
*********************************************************************/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#ifndef INPUTVALIDAITON_HPP
#define INPUTVALIDAITON_HPP

double inputValidation(double validate);  // Function prototype
int intValidation();
int intValidationPositive();

int choiceValidation(int);

#endif

double menuValidation(double validate) // make sure numbers coming in are initialized as doubles
{
	//int validate;
	while (1) //Begins infinite loop that will only break if an integer of 1 or 2. https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
	{
		if (cin.fail()) //if not an integer:
		{
			cin.clear(); // clears the error flag on cin. https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
			cin.ignore(100, '\n'); // skips to the next newline, and skips 100 characters
			cout << "Please enter an integer, either 1 or 2." << endl; // asks for input again
			cin >> validate;
			// cout << "Not an integer catch: " << validate << endl; -- test cout
		}
		if (!cin.fail() && (validate == 1 || validate == 2)) 	// If valid input:
		{   // cout << validate << endl; -- test cout
			return validate;									// then break loop.
			break;
		}

		else // if an integer, but not a 2 or 3:
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a 1 or a 2." << endl;
			cin >> validate;
			// cout << "Not correct integer catch: " << validate << endl; -- test cout
		}
	}
}

double menu4Validation(double validate) // make sure numbers coming in are initialized as doubles
{
	//int validate;
	while (1) //Begins infinite loop that will only break if an integer of 1 or 2. https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
	{
		if (cin.fail()) // if not an integer:
		{
			cin.clear(); // clears the error flag on cin. https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
			cin.ignore(100, '\n'); // skips to the next newline, and skips 100 characters
			cout << "Please enter a valid option." << endl; // asks for input again
			cin >> validate;
			// cout << "Not an integer catch: " << validate << endl; -- test cout
		}
		if (!cin.fail() && (validate == 1 || validate == 2 || validate == 3 || validate == 4)) 	// If valid input:
																								// if(!cin.fail() && (0 < validate < 5)) 	// If valid input:
		{   // cout << validate << endl; -- test cout
			return validate;									// then break loop.
			break;
		}

		else // if an integer, but not a valid option
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid option." << endl;
			cin >> validate;
			// cout << "Not correct integer catch: " << validate << endl; -- test cout
		}
	}
}

double menu5Validation(double validate) // make sure numbers coming in are initialized as doubles
{
	//int validate;
	while (1) //Begins infinite loop that will only break if an integer of 1 or 2. https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
	{
		if (cin.fail()) // if not an integer:
		{
			cin.clear(); // clears the error flag on cin. https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
			cin.ignore(100, '\n'); // skips to the next newline, and skips 100 characters
			cout << "Please enter a valid option." << endl; // asks for input again
			cin >> validate;
			// cout << "Not an integer catch: " << validate << endl; -- test cout
		}
		if (!cin.fail() && (validate == 1 || validate == 2 || validate == 3 || validate == 4 || validate == 5)) 	// If valid input:
																													// if(!cin.fail() && (0 < validate < 5)) 	// If valid input:
		{   // cout << validate << endl; -- test cout
			return validate;									// then break loop.
			break;
		}

		else // if an integer, but not a valid option
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid option." << endl;
			cin >> validate;
			// cout << "Not correct integer catch: " << validate << endl; -- test cout
		}
	}
}

double inputValidation(double validate)
{
	//int validate;
	while (1) //Begins infinite loop that will only break if an integer of 1 or 2. https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
	{
		if (cin.fail()) //if not an integer:
		{
			cin.clear(); // clears the error flag on cin. https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
			cin.ignore(100, '\n'); // skips to the next newline, and skips 100 characters
			cout << "Please enter an integer, either 1 or 2 or 3." << endl; // asks for input again
			cin >> validate;
			// cout << "Not an integer catch: " << validate << endl; -- test cout
		}
		if (!cin.fail() && (validate == 1 || validate == 2 || validate == 3)) 	// If valid input:
		{   // cout << validate << endl; -- test cout
			return validate;									// then break loop.
			break;
		}

		else // if an integer, but not a 2 or 3:
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a 1 or a 2 or a 3." << endl;
			cin >> validate;
			// cout << "Not correct integer catch: " << validate << endl; -- test cout
		}
	}
}

//****************************************************************************************************
// Takes a string as a parameter and converts to an integer. Checks for the validity of the integer  *
// and returns it. If the integer is invalid, the user is prompted again continuously.               *
//****************************************************************************************************

int intValidation()
{
	std::string str;
	int newStr;
	bool intCheck = false;

	while (!intCheck)
	{
		std::cin >> str;
		std::stringstream stream(str);

		if (stream >> newStr)
		{
			std::string remainingStr;
			std::getline(stream, remainingStr);

			if (remainingStr == "")
			{
				intCheck = true;
			}
			else
			{
				std::cout << "Not an integer! Try again." << std::endl;
			}
		}
		else
		{
			std::cout << "Not an integer! Try again." << std::endl;
		}
	}
	return newStr;

	//Source: http://www.cplusplus.com/forum/beginner/13044/#msg62827
}

int intValidationPositive()
{
	std::string str;
	int newStr;
	bool intCheck = false;

	while (!intCheck)
	{
		std::cin >> str;
		std::stringstream stream(str);

		if (stream >> newStr)
		{
			std::string remainingStr;
			std::getline(stream, remainingStr);

			if (remainingStr == "")
			{
				if (newStr > 0)
				{
					intCheck = true;
				}
				else
				{
					std::cout << "Please enter a value greater than zero." << std::endl;
				}
			}
			else
			{
				std::cout << "Invalid Input! Try again." << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid Input! Try again." << std::endl;
		}
	}
	return newStr;

	//Source: http://www.cplusplus.com/forum/beginner/13044/#msg62827
}

//****************************************************************************************************
// Takes a string as a parameter and converts to an integer. Checks for the validity of the integer  *
// and returns it. If the integer is invalid, the user is prompted again continuously. Finally,      *
// checks that a user inputs a valid number for the amount of options displayed on the menu.         *
//****************************************************************************************************

int choiceValidation(int choices)
{
	std::string str;
	int newStr;
	bool intCheck = false;

	while (!intCheck)
	{
		std::cin >> str;
		std::stringstream stream(str);

		if (stream >> newStr)
		{
			std::string remainingStr;
			std::getline(stream, remainingStr);

			if (remainingStr == "")
			{
				if ((newStr <= 0) || (newStr > choices))
					std::cout << "Not a valid option. Try again." << std::endl;
				else
					intCheck = true;
			}
			else
			{
				std::cout << "Not an integer! Try again." << std::endl;
			}
		}
		else
		{
			std::cout << "Not an integer! Try again." << std::endl;
		}
	}
	return newStr;
}