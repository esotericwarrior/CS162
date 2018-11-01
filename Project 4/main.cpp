/****************************************************************************
* Program Name: dieFight                                                    *
* Author: Tristan Santiago                                                  *
* Date: February 18, 2018                                                   *
* Description: main.cpp only calls everything needed to run the tournament.	*
****************************************************************************/
#include <iostream>
#include "Character.h"
#include "Medusa.h"
#include "Barbarian.h"
#include "Vampire.h"
#include "BlueMen.h"
#include "HarryPotter.h"
#include "Game.h"
#include "Queue.h"
#include "Losers.h"
#include "Tournament.h"
#include "InputValidation.h"
#include "Functions.h"
#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	/*seed random numbers*/
	srand((unsigned)time(0));
	// Create function object.
	Functions functions;
	// Create tournament object.
	Tournament T1;
	// Initialize all necessary variables to be used during runtime.
	int fighters;				// Used to determine number of fighters on each team.
	string choice1;				// Used to store the user's choice during character selection.		
	string choice2;				// Used to store the user's choice for viewing the loser's bracket.
	string name;				// Used to set each character's name.
	int choice;					// Used to store the user's main menu choice.
	int numLosers;				// Used to keep track of how many losers there are during the tournament.
	int valid1, valid2;			// Input validation variables.
	bool gameOver = false;		// Boolean variable used to determine game state.
	int again;					// Variable used to determine whether or not user would like to play again.
	int validInput;				// Input validation variable for whether or not the user wants to play again.

	/********************************************************************
	*							MAIN MENU								*
	********************************************************************/
	do {
		functions.displayMenu();
		cin >> choice;
		valid1 = menu4Validation(choice);
		if (valid1 == 1)
		{
			functions.displayRules();
		}   // if valid1 == 1
		else if (valid1 == 2)
		{
			functions.displayDescriptions();
		}   // if valid1 == 2
		else if (valid1 == 3)
		{
			// Prompt the user to determine the number of fighters for each team.
			cout << "How many players do you want on each team?" << endl;
			//cin >> valid2;
			cin >> fighters;
			// Input validation: **NEEDS WORK**
			valid2 = integerValidation(fighters);
			cout << endl;
			//cout << "Player 1: you will now choose a creature and a name for the " << fighters << " player(s) on Team A." << endl;
			cout << "Player 1: you will now choose a creature and a name for the " << valid2 << " player(s) on Team A." << endl;
			// This loop continues while player 1 is selecting the specified number of fighters for their team.
			//for (int i = 0; i < fighters; i++)
			for (int i = 0; i < valid2; i++)
			{
				do
				{
					//--------------------- PLAYER 1 ----------------------//
					cout << "\nPlayer 1, please choose your class:" << endl;
					cout << "1. Medusa \n";
					cout << "2. Barbarian \n";
					cout << "3. Vampire \n";
					cout << "4. Blue Men \n";
					cout << "5. Harry Potter \n";
					cin >> choice1;
					cin.ignore(1000, '\n');

					if ((choice1 != "1") && (choice1 != "2") && (choice1 != "3") && (choice1 != "4") && (choice1 != "5")) {
						cout << "That is not a choice. Please choose again. \n" << endl;
					}
				} while ((choice1 != "1") && (choice1 != "2") && (choice1 != "3") && (choice1 != "4") && (choice1 != "5"));

				cout << "Please give this player a name: " << endl;
				getline(cin, name);
				T1.setTeamA(choice1, name);     // Adds this character to Team A.
			}
			cout << endl;
			//cout << "Player 2: you will now choose a creature and a name for the " << fighters << " player(s) on Team B." << endl;
			cout << "Player 2: you will now choose a creature and a name for the " << valid2 << " player(s) on Team B." << endl;
			// This loop continues while player 2 is selecting the specified number of fighters for their team.
			//for (int i = 0; i < fighters; i++)
			for (int i = 0; i < valid2; i++)
			{
				do
				{
					//--------------------- PLAYER 2 ----------------------//
					cout << "\nPlayer 2, please choose your class:" << endl;
					cout << "1. Medusa \n";
					cout << "2. Barbarian \n";
					cout << "3. Vampire \n";
					cout << "4. Blue Men \n";
					cout << "5. Harry Potter \n";
					cin >> choice1;
					cin.ignore(1000, '\n');

					if ((choice1 != "1") && (choice1 != "2") && (choice1 != "3") && (choice1 != "4") && (choice1 != "5")) {
						cout << "That is not a choice. Please choose again. \n" << endl;
					}
				} while ((choice1 != "1") && (choice1 != "2") && (choice1 != "3") && (choice1 != "4") && (choice1 != "5"));

				cout << "Please give this player a name: " << endl;
				getline(cin, name);

				T1.setTeamB(choice1, name);     // Adds this character to Team B.

			}
			cout << "\n";

			//print Team A's lineup
			cout << "Here is the lineup of players for Team A : " << endl;

			T1.getTeamA();

			cout << endl;

			cout << "Here is the lineup of players for Team B : " << endl;

			//print Team B's lineup
			T1.getTeamB();

			cout << "\n";
			cout << "Characters have been selected.\n" << endl;

			//start the tournament
			//numLosers = T1.startRound(fighters);
			numLosers = T1.startRound(valid2);

			cout << "\n";

			//display results
			cout << "The results of the tournament are as follows: " << endl;

			//display stats for each team
			cout << "Team A finished with " << T1.getWinsA() << " point(s)." << endl;
			cout << "Team B finished with " << T1.getWinsB() << " point(s)." << endl;

			cout << "\n";

			//display the list of winners
			T1.displayWinners();

			cout << "\n";

			//choice to see losers
			cout << "Would you like to view the loser's bracket? Choose Y or N." << endl;
			cin >> choice2;

			if (choice2 == "y" || choice2 == "Y")
			{
				cout << "The following characters are in the losers bracket: " << endl;
				T1.displayLosers(numLosers);
				cout << "\n\n";
				cout << "\nExiting Program";
				//gameOver = true;
			}

			else if (choice2 == "n" || "N")
			{
				cout << "\nExiting Program";
				//gameOver = true;
			}
			cout << "\nWould you like to play again?" << endl;
			cout << "--------------------------------\n";
			cout << "1. Play again." << endl;
			cout << "2. Quit." << endl;
			cin >> again;

			validInput = menuValidation(again);

			switch (validInput)
			{
			case 1:cout << "\nYou entered one. Playing again.";
				gameOver = false;
				break;

			case 2:cout << "\nYou entered two. Quitting." << endl;
				gameOver = true;
				break;
			}
		}
		else if (valid1 == 4)
		{
			gameOver = true;
			cout << "Exiting Program." << endl;
			exit(0);
		}   // if valid == 4
	} while (gameOver == false);
	return 0;
}

