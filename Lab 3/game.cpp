/********************************************************************
** Program name: warGame                                            *
** Author: Tristan Santiago                                         *
** Date: January 28, 2018                                           *
** Description: game.cpp contains the overwhelming majority of the  *
** program. It displays the main menu, asks the user for the        *
** specifics used to create the dice object that will be used for   *
** the game, and asks the user to determine how many rounds will be *
** played.                                                          *
********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "die.cpp"
#include "loadDie.cpp"
#include "game.hpp"
#include "inputValidation.cpp" // Homemade input validation file.

int roundCount = 1;                 // Initialize roundCounter to 1
int validate, inputCheck, choice;   // These 3 variables are used for data validation.
std::string roundWinner;            // Keeps track of who's won each round.

// Default Dice object constructor
Game::Game()
{
    dice1 = dice2 = NULL;
}

// Display Menu first asks the user if they'd like to play or not.
int Game::displayMenu()
{
    // Prompt user to enter choice.
    cout << "--------------------------------------\n";
    cout << "Welcome to War. Want to play?\n";
    cout << "Here are your options:\n";
    cout << "--------------------------------------\n";
    cout << "1. Yes, I want to play.\n";
    cout << "2. No thanks, I'd rather quit.\n";
    cout << "--------------------------------------\n";
    cout << "Enter your choice: \n";
    cin >> inputCheck;
    cout <<"\033[2J\033[1;1H"; // screen clear
    choice = menuValidation(inputCheck); // Data validation for either 1 or 2 only
// Assign value of validate to choice.
    switch(choice)
        {
            case 1:cout << "You entered 1. Game start!\n" << endl;
            // Carries onto the input function
            input();
            break;
            case 2:cout << "You entered 2. Bye!" << endl;
            // Exits program.
            exit(0);
            break;
        }
}

// Set Rounds asks the user for how many rounds they'd like to play. Can't be more than 90.
void Game::setRounds()
{
    // Prompt the user to determine the number of rounds for the game.
    cout <<"\033[2J\033[1;1H";  // Clear screen
    cout << "---------------------------------------\n";
    cout << "How many rounds would you like to play?\n";
    cout << "                    **Max of 90 Rounds.\n";
    cout << "---------------------------------------\n";
    cin >> inputCheck;

    numRounds = integerValidation(inputCheck);  // Assign value of validate to rounds.

    cout << "\nYou've chosen to play " << numRounds << " rounds." << endl;
}

    // Input is where sides/type of dice are chosen. This is also where the dice objects are created.
    void Game::input()
    {

        // Declare variables
        int response;
        int sides;

        // Denerate distinct random numbers using system time.
        srand(time(NULL));


        // Prompt user to enter the number of sides
        std::cout << "How many sides for the die of Player 1?\n";
        std::cin >> validate;
        // Data validate to ensure side # is between 1 and 90
        sides = integerValidation(validate);

        std::cout << "Use loaded die for Player 1?\n";
        std::cout << "1. Use Loaded Dice.\n";
        std::cout << "2. No, use a Normal Dice.\n";
        std::cin >> validate;
        // Data validate for 1 or 2 only
        response = menuValidation(validate);

        if (response == 1)
            // Create player one's loaded dice object
            dice1 = new LoadedDie(sides);
        else
            // Create normal dice object
            dice1 = new Die(sides);

        // Prompt user to enter the number of sides
        std::cout << "How many sides for the die of Player 2?\n";
        std::cin >> validate;
        // Data validate to ensure side # is between 1 and 90
        sides = integerValidation(validate);

        std::cout << "Use loaded die for Player 2?\n";
        std::cout << "1. Use Loaded Dice.\n";
        std::cout << "2. No, use a Normal Dice.\n";
        std::cin >> validate;
        // Data validate for 1 or 2 only
        response = menuValidation(validate);

        // Creating player 2's dice.
        if (response == 1)
            dice2 = new LoadedDie(sides);
        else
            dice2 = new Die(sides);

        cout <<"\033[2J\033[1;1H";

            // Ask user how many rounds they want to play.
            setRounds();
    }

    // Generates random numbers per the user's input, using the dice objects,
    // and then stores that into an array.
    void Game::play()
    {
        for (int i = 0; i < numRounds; i++)
        {
            rounds[i][0] = dice1->roll(); // Player1's dice
            rounds[i][1] = dice2->roll(); // Player2's dice
        }
    }

    // This results function shows scores and the general output of the game.
    void Game::results()
    {
        int points1 = 0, points2 = 0; // Initialize points to zero

        std::cout << "Number of rounds played: " << numRounds << std::endl;

        // Calls the objects getters to display the given dice's type and how many sides it has.
        std::cout << "Player 1 uses " << dice1->getDieType() << " die with " << dice1->getNumSides() << " sides." << std::endl;

        std::cout << "Player 2 uses " << dice2->getDieType() << " die with " << dice2->getNumSides() << " sides." << std::endl;

        // Couting the game results
        std::cout << "\n\tPlayer 1 \t Player 2 \t  Round Winner \t" << std::endl;
        std::cout << "\t-------- \t -------- \t   ------------ \t" << std::endl;

        // This for statement dishes out points to round victors, as well as updates the string to cout
        for (int i = 0; i < numRounds; i++)
        {
            if (rounds[i][0] > rounds[i][1])
            {
                roundWinner = "Player 1";
                points1++;
            }
            else if (rounds[i][0] < rounds[i][1])
            {
                roundWinner = "Player 2";
                points2++;
            }
            else
            {
                roundWinner = "Draw";
            }

            // The repeating rows of data. Begins with Rd# which shows Round Number.
            std::cout << "Rd#" << roundCount << "          " << rounds[i][0] << "                 " << rounds[i][1] << "           " << roundWinner << std::endl;
            roundCount++;

        }
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "Player 1 wins " << points1 << " rounds." << std::endl;
        std::cout << "Player 2 wins " << points2 << " rounds." << std::endl;

        // Overall winner
        if (points1 > points2)
            std::cout << "Player 1 wins !";
        else if (points2 > points1)
            std::cout << "Player 2 wins !";
        else
            std::cout << "Its a draw !!";

    // Deletes objects to prevent memory leaks.
    delete dice1;
    delete dice2;
    }
    // Default destructor.
    Game::~Game()
    {
    }