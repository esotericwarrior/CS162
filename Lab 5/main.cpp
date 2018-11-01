/********************************************************************
* Program name: recurs                                              *
* Author: Tristan Santiago                                          *
* Date: February 10, 2018                                           *
* Description: This program uses three recursive functions. The     *
* prints a string in reverse. The second calculates the sum of an   *
* array of integers. The third calculates the triangular number of  *
* an integer N.                                                     *
********************************************************************/
#include <iostream>
#include "inputValidation.cpp"
#include "functions.cpp"

using namespace std;

int main()
{
    bool gameOver = false; // Whether or not the user wants to keep playing or not
    int arrInCheck, arrCheck, arrIn, triNum, check, choice, valid, arrSize = 1;
    int *arrayValue = new int [arrSize];
    // While user hasn't chosen to quit...
    while(gameOver == false)
    {
        cout << "\n\t\tI always knew I'd be able to use cursive.\n\n" << endl;
        cout << "Recursive Functions Game                           " << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Please choose a function to run.                   " << endl;
        cout << "1. Print a string in reverse.                      " << endl;
        cout << "2. Array sum.                                      " << endl;
        cout << "3. Triangle Sum.                                   " << endl;
        cout << "4. Quit Game.                                      " << endl;
        cout << "---------------------------------------------------" << endl;
        cin >> choice;
        // Validates so user can only enter 1 - 4
        valid = menu4Validation(choice);
        // 1 is string reversal
        if(valid == 1)
        {
            string str;
            cin.clear();    // Clear the cin error flags
            cin.ignore();   // Skips to the next newline (the menu choice was throwing this off before)
            cout << "Please enter a string." << endl;
            // Grabs user input, maintaining spaces
            getline(cin, str);
            // Sends to be reversed
            firstRecursive(str);
        }
        // 2 is Summing the numbers in an array
        else if(valid == 2)
        {
            cout << "Please enter a number greater than 1 and less than 20 for the size of your array." << endl;
            cin >> arrCheck;
            arrSize = integerValidation(arrCheck);          // Validate user input to be an int greater than 0 and less than 20
            for (int i = 0; i < arrSize; i++)               // Take user input and create an array
            {
                cout << "Please enter an integer to go into array." << endl;
                cin >> *(arrayValue + i);                               // Currently sending array to secondRecursive
            }
            secondRecursive(arrayValue, arrSize);
            cout << "Sum: " << secondRecursive(arrayValue, arrSize) << endl;

        }
        // 3 is triangle numbers
        else if(valid == 3)
        {
            cout << "Please enter an integer greater than 1 and less than 20." << endl;
            cin >> check;
            triNum = integerValidation(check);
            cout <<"The triangle of "<< triNum <<" is " << thirdRecursive(triNum) << endl;//printing triangle number
        }
        // 4 marks gameOver as true, and exits while loop/game as a result
        else if(valid == 4)
        {
            gameOver = true;
            //exit(0);
        }
    } // gameOver while loop
// Unallocate array
delete [] arrayValue;
return 0;
} // main