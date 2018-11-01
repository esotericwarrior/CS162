/*********************************************************************
** Program name:  Langton's Ant Game
** Author:  Tristan Santiago
** Date: 1/19/2018
** Description: main.cpp is the driver for the program
*********************************************************************/
#include <iostream>
#include "inputValidation.cpp"  // To validate the switches
#include "direction.cpp"        // Tracks the direction of the ant
#include <cstdlib>              // Needed for the rand() function
#include <ctime>                // Needed to access computer clock to seed a random number

using namespace std;

// Although my menus are a part of the main function, they are the only part of the main function.
// I have re-used them from Lab1, making them reusable. I also made my input validation reusable.
int main()
{
    int numRows, numCols, steps, row, col, choice, validInput;
    char ranStart;
    bool trueCheck1 = true;
    bool trueCheck2 = true;
    bool finished = false;
    
    // Begins do while loop to ultimately prompt user to begin game over again
    do
    {
    // Outputs menu for user, so they can choose from a menu.
    cout << "\n\nHello and welcome to the ant game.\n\n";
    cout << "Here are your options:\n";
    cout << "--------------------------------------\n";
    cout << "1. Begin game.\n";
    cout << "2. Quit game.\n";
    cout << "--------------------------------------\n";
    cout << "Enter your choice: \n";
    cin >> choice;

    // Sends user input to the validation function to ensure it's either 1 or 2.
    validInput = inputValidation(choice);
    switch(validInput)
    {
        case 1:cout << "You entered 1. Game start.\n";
            // Breaks switch statement, continuing onto next menu.
            break;
        case 2:cout << "You entered 2. Quitting...\n";
            // Quits Program.
            return 0;
            break;
        default: cout << "You did not enter 1 or 2.\n";
    }

    // Clears Screen. https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
    cout <<"\033[2J\033[1;1H";
    // Second menu on choosing board size
    cout << "---------------------\n";
    cout << "Please select your board size.\n";
    cout << "Here are your options:\n";
    cout << "--------------------------------------\n";
    cout << "1. Create my own board.\n";
    cout << "2. Create a board for me.\n";
    cout << "--------------------------------------\n";
    cout << "Enter your choice: \n";
    cin >> choice;

    validInput = inputValidation(choice);
    switch(validInput)
    {
    case 1:cout << "You entered 1. You will choose your board dimensions." << endl;
        // Begins more data validation on entering valid input or not
        while (trueCheck1 == true)
        {
            cout << "Enter the number of rows you want for the board: ";
            // user enters rows first
            cin >> numRows;
            if (numRows > 0)
            {
                trueCheck1 = false; // ends While loop
            }
            else    // if input is bad (not bigger than 0), makes user input again
            {
                cout << "The number of rows must be greater than 0! Try again! " << endl;
                cin.clear();
                cin.ignore();
            }
        }
        trueCheck1 = true; // switch bool back to true for next while loop
        while (trueCheck1 == true)
        {
            cout << "Enter the number of columns you want for the board: ";
            // enter columns next
            cin >> numCols;
            if (numCols > 0)
            {
                trueCheck1 = false;
            }
            else
            {
                cout << "The number of columns must be greater than 0! Try again! " << endl;
                cin.clear();
                cin.ignore();
            }
        }   // breaks out of switch
            break;
        // If user wishes to have us create a board, create 10x10 board
    case 2:cout << "You entered 2. Creating a board for you.\n";
            numRows = 10;
            numCols = 10;
            break;
        default: cout << "You did not enter 1 or 2.\n";
        }
        // Change bool to true for next statement.
        trueCheck1 = true;
        // Same data validation as rows and columns input
        while (trueCheck1 == true)
        {
            cout << "Enter the number of steps that you want the ant to take, as long as the number is greater than zero: ";
            cin >> steps;
            if (steps > 0)
            {
                trueCheck1 = false;
            }
            else
            {
                cout << "The number of steps must be greater than 0! Try again! " << endl;
                cin.clear();
                cin.ignore();
            }
        }
        // Updates bool to true again.
        trueCheck1 = true;
        // this menu asks user if they want to choose an Ant starting location, or randomize it.
        cout <<"\033[2J\033[1;1H";
        cout << "Now that you've chosen your board size and decided step count,\n";
        cout << "where would you like your ant to start?\n";
        cout << "--------------------------------------\n";
        cout << "1. I will choose my starting location.\n";
        cout << "2. Choose a random starting location for me.\n";
        cout << "--------------------------------------\n";
        cin >> choice;

        validInput = inputValidation(choice);
        switch(validInput)
            {
            case 1:cout << "You entered 1. You will enter your starting location:\n";
                while (trueCheck1 == true)
                {
                    cout << "Enter the row number (starting at row 1) in which you would like the ant to start at: ";
                    cin >> row;
                    // similar data validation as above, except here it ensures the user does not try to enter
                    // a number outside of the board.
                    if (row <= numRows && row > 0)
                    {
                        row = row - 1;
                        trueCheck1 = false;
                    }
                    else
                    {
                        cout << "Starting row position must be within the given number of rows! " << endl;
                        cin.clear();
                        cin.ignore();
                    }
                }
                while (trueCheck1 == false)
                {
                    cout << "Enter the column number (starting at column 1) in which you would like the ant to start at: ";
                    cin >> col;
                    if (col <= numCols && col > 0)
                    {
                        col = col - 1;
                        trueCheck1 = true;
                    }
                    else
                    {
                        cout << "Starting column position must be within the given number of columns! " << endl;
                        cin.clear();
                        cin.ignore();
                    }
                }
                trueCheck2 = false;
                break;
            case 2:cout << "You entered 2. Surprise!\n";
                while(trueCheck2 == true)
                {
                     srand(time(0));  //  generate random row/column numbers if user wishes to use random starting location for ant
                     row = (rand()% numRows);
                     col = (rand()% numCols);
                     trueCheck2 = false;
                }
                     break;
                default: cout << "You broke me. DX\n";
            }
    // calls the function that, using the data collected, begins running the simulation
    directionFunction(numRows, numCols, steps, row, col);
    
        // Clears screen and prompts user whether they'd like to play again or not
        cout <<"\033[2J\033[1;1H";
        cout << "\nWould you like to run the simulation again?" << endl;
        cout << "-------------------------------------------\n";
        cout << "1. Play again." << endl;
        cout << "2. Quit." << endl;
        cin >> choice;
        
        validInput = inputValidation(choice);
        
        switch(choice)
        {
        case 1:cout << "You entered one. Playing again.";
        finished = true;
        break;
        
        case 2:cout << "You entered two. Quitting.";
        finished = false;
        break;
        }
    } while(finished != false);

    return 0;
}
