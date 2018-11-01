/*********************************************************************
** Program name: doodle
** Author: John Casillas, Corbin Stripling, Tristan Santiago 
** Date: 2/18/2018
** Description: This is main. Here we prompt the menus, create the board,
** and carry on with general gameplay.
*********************************************************************/
#include "critter.cpp"
#include "ant.cpp"
#include "doodlebug.cpp"
#include "inputValidation.cpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

using std::vector;
using std::random_shuffle;

/***************************************************************
* Function: fillWithNull
* Description: Fills 20x20 grid with null pointers
* ************************************************************/
void fillWithNull(Critter* grid[][20], int numRows);

/***************************************************************
* Function: initializeGrid
* Description: Initializes 20x20 grid with 100 Ants and 5 Doodlebugs
* ************************************************************/
void initializeGrid(Critter* grid[][20], int numRows);

/***************************************************************
* Function: printGrid
* Description: Prints values of 20x20 grid
* ************************************************************/
void printGrid(Critter* grid[][20], int numRows);

/***************************************************************
* Function: advanceTime
* Description: Goes through 20x20 grid. Each non NULL pointer is placed in
*              a vector randomVec. randomVec is shuffled into random order
*              and then iterated through. All Critters move (if
*              appropriate), then all Critters breed (if appropriate),
*              then all Doodlebugs starve(if appropriate). Any Critters
*              that have died are then deleted.
* ************************************************************/
void advanceTime(Critter* grid[][20], int numRows);

int main()
{
    string cont;
    bool finished = false;							// Variable used to determine whether or not to continue the program or exit.
    bool gameOver = false;							// Variable used to determine whether or not to continue the program or exit.
    int validInput, valid;							// Variables used for user input validation.
    double again;										// Variable used to determine whether or not the user wants to re-run the simulation.
    double steps;										// Variable used to determine the number of steps for the simulation.
    Critter* world[20][20];						// Create a 20x20 array of Critter pointers for the game board.
	srand(time(NULL));      						// Seed random number generator
	//Functions function;
    initializeGrid(world,20);						// Fill grid with Critters and NULL pointers
    do
    {
    	while(gameOver == false)
    	{
			cout << "\nHow many steps would you like the simulation to take? ";
			cin >> steps;
			// Run input validation.
			valid = integerValidation(steps);
			cin.ignore();
    		int i = 0;
    		do
    		{
			    // Print the game board.
			    printGrid(world, 20);

			    // Make Critters take steps.
			    advanceTime(world, 20);
			    i++;
			    cout << "End of step " << i << endl;
			    if (i < valid)
			    {
				cout << "Press ENTER key to continue...";
				cin.get();
			    }
			    else
			    {
			    	cout << "Simulation completed." << endl;
			    }
		    }	while(i < valid);	// End of do-while loop.

    // Ask user if they would like to run the simulation again.
    cout << "\nWould you like to play again?" << endl;
    cout << "--------------------------------\n";
    cout << "1. Play again." << endl;
    cout << "2. Quit." << endl;
    cin >> again;
    // Run input validation.
    validInput = menuValidation(again);
        switch(validInput)
        {
        	case 1:cout << "You entered one. Playing again.";
        	finished = true;
        	break;

        	case 2:cout << "You entered two. Quitting.";
        	finished = false;
        	gameOver = true;
        	break;
        }	// End of switch statement.
	}
} while(finished != false);

return 0;
}	// Main

void fillWithNull(Critter* grid[][20], int numRows)
{

    for(int i = 0; i < numRows; i++)
    {
    	for(int j = 0; j < 20; j++)
    	{
          grid[i][j] = NULL;
    	}
    }
}

void initializeGrid(Critter* grid[][20], int numRows)
{

    // This function sets each element of the board to NULL.
    fillWithNull(grid, numRows);

    // Randomly place 100 ants.
    int antCount = 0;
    // Initialize a while-loop that continues to execute until 100 ants have been successfully placed.
    while (antCount < 100)
    {

        int i = rand() % 20;					// Generate a random position from 20 columns.
        int j = rand() % 20;					// And also generate a random position from 20 rows.
        // To determine our random placement for the ant on the game board.
        // If the spot is NULL, then it is empty, since we initialized the entire array to NULL beforehand.
        if (grid[i][j] == NULL)         		// Then only place an ant in an empty spot.
        {
        	grid[i][j] = new Ant(i, j);			// Create an ant at the specified random location.
            antCount++;							// Increment the ant count, so that we make sure we're placing 100 ants.
        }
    }   // End while

    // Randomly place 5 doodlebugs.
    int doodleCount = 0;
    // Initialize a while-loop that continues to execute until 5 doodlebugs have been successfully placed.
    while(doodleCount < 5)
    {
        int i = rand() % 20;					// Generate a random position from 20 columns.
        int j = rand() % 20;					// And also generate a random position from 20 rows.
        // To determine our random placement for the doodlebug on the game board.
        // If the spot is NULL, then it is empty, since we initialized the entire array to NULL beforehand.
        if (grid[i][j] == NULL)         		// Then only place a doodlebug in an empty spot.
        {
        	grid[i][j] = new Doodlebug(i,j);	// Create a doodlebug at the specified random location.
            doodleCount++;
        }
    }   // End while
}

/************************************************************************************************
*						void printGrid(Critter* grid[][20], int numRows)						*
* This function is responsibile for printing the game board before the simulation starts and	*
* throughout the simulation.																	*
************************************************************************************************/
void printGrid(Critter* grid[][20], int numRows)
{
    // Begin cycling through the entire game board.
    for(int i = 0; i < numRows; i++)
    {
    	for(int j = 0; j < 20; j++)
    	{
    		// If the space is NULL, it is empty and unoccupied. Therefore, we print an empty string.
    		if(grid[i][j] == NULL)
    		{
    			cout << " ";
    		}
    		// If the space is currently occupied by an ant, we want to print an O, symbolizing the ant.
    		else if((*grid[i][j]).getSpecies() == "Ant")
    		{
    			cout << " O";
    		}
    		// If the space is currently occupied by a doodlebug, we want to print an X, symbolizing the doodlebug.
    		else if((*grid[i][j]).getSpecies() == "Doodlebug")
    		{
    			cout << " X";
    		}
    	}
  cout << endl;
	}
}

void advanceTime(Critter* grid[][20], int numRows)
{
	vector<Critter*> randVec;

    //Fill vector with Critter pointers
    for(int i = 0; i < numRows; i++)
    {
    	for(int j = 0; j < 20; j++)
    	{
        	if(grid[i][j] != NULL)
        	{
        		randVec.push_back(grid[i][j]);
        	}
    	}
    }

     //Randomly shuffle order of Critter pointers http://www.cplusplus.com/reference/algorithm/random_shuffle/
     random_shuffle(randVec.begin(), randVec.end());

    // Iterate through vector and call move on each living Critter
    for(int i = 0; i < randVec.size(); i++){

    	if (!randVec[i]->hasDied())
    	{
        	randVec[i]->move(grid, 20);
    	}
    }

     // Randomly shuffle order of Critter pointers
     random_shuffle(randVec.begin(), randVec.end());

    // Iterate through vector and call breed on each living Critter
    for(int i = 0; i < randVec.size(); i++)
    {
    	if(!randVec[i]->hasDied())
    	{
        	randVec[i]->breed(grid, 20);
    	}

    }

     // Iterate through vector and call starve on Doodlebugs.
     for(int i = 0; i < randVec.size(); i++){

      if (randVec[i]->getSpecies() == "Doodlebug")
    	{
        	randVec[i]->starve(grid, 20);
    	}
    }

     // Delete eaten Ants and starved Doodlebugs.
     // (These were already removed from the grid by
     // Doodlebug::move and Doodlebug::starve).
     for(int i = 0; i < randVec.size(); i++){

      if (randVec[i]->hasDied())
    	{
        	delete randVec[i];
        	randVec[i] = NULL;
    	}
    }
}
