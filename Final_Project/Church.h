/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: This is the Church location. The user is only able to
** scavenge here after dark and with a townmap. It shares the same 
** player as the rest of the locations.
*********************************************************************/

#pragma once
#ifndef CHURCH_HPP
#define CHURCH_HPP

#include "Space.h"
#include "Player.h"
#include "Enums.h"
#include "inputValidation.h"
#include "Menu.h"
#include "Rubble.h"
#include "Door.h"
#include "Ladder.h"
#include "Shelter.h"
#include "Game.h"
#include <vector>
#include <string>
#include <limits>

using namespace game_Enums;

class Church
{
private:
	int rows;
	int columns;
	int i = 0;
	int &night = i;

	vector<vector<Space*>> churchBoard;
	vector<Space*> boardColumn;

	Game* cplayer;
	Space* playerLocation;
	bool playerAlive;
	bool gameState;
public:
	Church();
	//Church(Game* player);
	~Church();
	Game* getsplayer();
	void setPlayer(Game* player);
	void setNight(int &);
	int getNight();
	bool getGameState();
	bool doorOpen = false;					// Boolean used to determine whether or not a door has been opened.

	// Church Functions
	void initializeBoard();
	void printBoard();

	// Player Functions
	void setPlayerLocation(Space*);
	void playerChoose();

	// Movement-related functions
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
};
#endif


//Parameter of game function
Church::Church()
{
	int rows = 3;
	int columns = 4;
	boardColumn.resize(columns, nullptr);
	churchBoard.resize(rows, boardColumn);
	playerAlive = true;
	gameState = true;
}


Game * Church::getsplayer()
{
	return cplayer;
}

void Church::setPlayer(Game* player)
{
	cplayer = player;
}

void Church::setNight(int &n)
{
	night = n;
}

int Church::getNight()
{
	return night;
}

Church::~Church()
{
	for (size_t i = 0; i < churchBoard.size(); i++)
	{
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			delete churchBoard[i][j];
			churchBoard[i][j] = nullptr;
		}
	}
	//delete cplayer;
}

bool Church::getGameState()
{
	return gameState;
}

// Church Functions
void Church::initializeBoard()
{
	// Initialize each space in the Church's matrix.
	for (size_t i = 0; i < churchBoard.size(); i++)
	{
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			/****************************
			*		Create Ladders		*
			****************************/
			if (i == 1 && j == 2)
			{
				churchBoard[i][j] = new Ladder();
				churchBoard[i][j]->setID(i * 10 + j);
				churchBoard[i][j]->setLocation(CHURCH);
			}
			else if (i == 2 && j == 0)
			{
				churchBoard[i][j] = new Ladder();
				churchBoard[i][j]->setID(i * 10 + j);
				churchBoard[i][j]->setLocation(CHURCH);
			}
			/****************************
			*		Create Rubble		*
			****************************/
			else if (i == 0 && j == 0)
			{
				churchBoard[i][j] = new Rubble();
				churchBoard[i][j]->setID(i * 10 + j);
				churchBoard[i][j]->setLocation(CHURCH);
			}
			else if (i == 0 && j == 1)
			{
				churchBoard[i][j] = new Rubble();
				churchBoard[i][j]->setID(i * 10 + j);
				churchBoard[i][j]->setLocation(CHURCH);
			}
			else if (i == 2 && j == 3)
			{
				churchBoard[i][j] = new Rubble();
				churchBoard[i][j]->setID(i * 10 + j);
				churchBoard[i][j]->setLocation(CHURCH);
			}
			/****************************
			*		Create Door			*
			****************************/
			else if (i == 2 && j == 2)
			{
				churchBoard[i][j] = new Door();
				churchBoard[i][j]->setID(i * 10 + j);
				churchBoard[i][j]->setLocation(CHURCH);
			}
			else
			{
				churchBoard[i][j] = new Space();
				churchBoard[i][j]->setID(i * 10 + j);
				churchBoard[i][j]->setLocation(CHURCH);
			}
		}
	}

	// Link all Space's North pointers.
	for (size_t i = 1; i < churchBoard.size(); i++)
	{
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			churchBoard[i][j]->setNorth(churchBoard[i - 1][j]);
		}
	}

	// Link all Space's South pointers.	
	for (size_t i = 0; i < churchBoard.size() - 1; i++)
	{
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			churchBoard[i][j]->setSouth(churchBoard[i + 1][j]);
		}
	}

	// Link all Space's East pointers.
	for (size_t i = 0; i < churchBoard.size(); i++)
	{
		for (size_t j = 0; j < boardColumn.size() - 1; j++)
		{
			churchBoard[i][j]->setEast(churchBoard[i][j + 1]);
		}
	}

	// Link all Space's West pointers.
	for (size_t i = 0; i < churchBoard.size(); i++)
	{
		for (size_t j = 1; j < boardColumn.size(); j++)
		{
			churchBoard[i][j]->setWest(churchBoard[i][j - 1]);
		}
	}

	// Set the player's starting location.
	setPlayerLocation(churchBoard[1][0]);
	churchBoard[1][0]->setPlayerLocatedOn(true);

}

void Church::printBoard()
{
	// http://www.asciiworld.com/-Church-.html
	cout << "\n St. Mary's Church" << endl;
	//cout << "       |   " << endl;
	//   cout << "      __|__ " << endl;
	//   cout << "        |   " << endl;
	//   cout << "       (|)  " << endl;
	//   cout << "       / \\|  " << endl;
	//   cout << "      /   \\  " << endl;
	//   cout << "     /_____\\ " << endl;
	//   cout << "     |  _  | " << endl;
	//   cout << "     | (_) | " << endl;
	//   cout << "     |     | " << endl;
	//cout << "    /       \\" << endl;
	//cout << "   /         \\" << endl;
	//cout << "  /           \\" << endl;
	//cout << " /             \\" << endl;

	cout << "      _|_ " << endl;
	cout << "       |  " << endl;
	cout << "      _|_ " << endl;
	cout << "     //_/\\" << endl;
	cout << "   __|  ||____" << endl;
	cout << "  ////////////\\" << endl;
	cout << " /////////////\\" << endl;

	for (size_t i = 0; i < churchBoard.size(); i++)
	{
		//Top Lines
		for (int count = 0; count < 4; count++)
		{
			cout << " ---";
		}
		if (i == 1)
		{
			cout << "  <--- Upper Level" << "\t| Night: " << getNight();
		}
		if (i == 2)
		{
			cout << "  <--- Ground Floor" << "\t| Time: " << cplayer->getTime() << ":00";
		}
		cout << endl;

		for (size_t j = 0; j < boardColumn.size(); j++)
		{

			if (churchBoard[i][j] != nullptr)
			{
				churchBoard[i][j]->printSpace();
			}
			else
			{
				cout << "nullptr ";
			}
		}
		cout << "|" << endl;
	}
	for (int count = 0; count < 4; count++)
	{
		if (count == 3)
		{
			cout << " ===============" << "  <--- Basement" << "\t\t| Current Health: " << cplayer->getHealth() << endl;
		}
	}	// Prints last bottom line for map
	cout << endl;
}

// Player-related Functions
void Church::setPlayerLocation(Space* playerSpace)
{
	playerLocation = playerSpace;
}

void Church::playerChoose()
{
	do {
	if (playerAlive)	// Check if player is alive.
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (menuChoice5("What do you do?", "Move", "Check your surroundings", "Check your inventory", "Use an item", "Run Home"))	// Prompt user for input.
		{
		case 1:
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			switch (menuChoice4("Which direction do you move?", "North", "South", "East", "West"))	// Prompt user for direction if they choose to move.
			{
			case 1:
				cout << endl;
				moveNorth();
				cout << endl;
				break;
			case 2:
				cout << endl;
				moveSouth();
				cout << endl;
				break;
			case 3:
				cout << endl;
				moveEast();
				cout << endl;
				break;
			case 4:
				cout << endl;
				moveWest();
				cout << endl;
				break;
			default:
				cout << "Which direction do you move? Broke" << endl;
			}

			cout << "You lose one point of health for moving." << endl;
			cplayer->adjustHealth(-1);	// Subtract one health from the player.
			if (cplayer->getTime() >= 24)
			{
				cplayer->resetTime();
				cplayer->adjustTime(1);		// Add time with movement.
			}
			else
			{
				cplayer->adjustTime(1);		// Add time with movement.
			}
			//cplayer->adjustTime(6);		// Add time with movement.
			printBoard();
			//cout << "Current health: " << cplayer->getHealth() << endl << endl;

			if (cplayer->getHealth() <= 0)	// Check if player has died.
			{
				playerAlive = false;
			}
			break;
		case 2:
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			playerLocation->interact(cplayer);
			if (playerLocation->getGameComplete())	// Check if player has completed the game.
			{
				gameState = false;
			}
			cout << endl;
			break;
		case 3:
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cplayer->printInventory();		// Print Inventory.
			break;
		case 4:
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (cplayer->useItem(cplayer->getInventorySelection()) == MAP)	// Use an item. If it's the Map, print the Church.
			{
				printBoard();
			}
			cout << endl;
			break;
		case 5:
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//********************************************
			//*			Set Time for Day Phase			*
			//********************************************/
			cplayer->setDayTime();	// Set time to 6 AM. (0600)
			cout << endl;
			gameState = false;
			cout << endl;
			break;
		default:
			cout << "playerChoose() broke." << endl;
		}
	}
	else
	{
		cout << "GAME OVER" << endl;
		gameState = false;
	}
} while (cplayer->getTime() >= 20 && cplayer->getTime() >= 5); // DO WHILE TEST
if (cplayer->getTime() >= 5)
{
	gameState = false;
}
}

// Move Functions
void Church::moveNorth()
{
	if (playerLocation->getNorth() == churchBoard[0][2])
	{
		cout << "\"Looks like this ladder goes to an upper floor.\"" << endl;
		playerLocation->setPlayerLocatedOn(false);
		playerLocation = playerLocation->getNorth();
		playerLocation->setPlayerLocatedOn(true);
		printBoard();
	}
	else if (playerLocation->getNorth() == churchBoard[1][0])
	{
		cout << "\"This should take me back up to the ground floor.\"" << endl;
		playerLocation->setPlayerLocatedOn(false);
		playerLocation = playerLocation->getNorth();
		playerLocation->setPlayerLocatedOn(true);
		printBoard();
	}
	else if (playerLocation->getNorth() != churchBoard[0][2] || playerLocation->getNorth() != churchBoard[1][0])
	{
		cout << "\"I need to find another way up.\"" << endl;
	}
	else
	{
		cout << "A wall blocks you." << endl;
	}
}

void Church::moveSouth()
{
	if (playerLocation->getSouth() == churchBoard[2][0])
	{
		cout << "\"Looks like this ladder goes down into the basement.\"" << endl;
		playerLocation->setPlayerLocatedOn(false);
		playerLocation = playerLocation->getSouth();
		playerLocation->setPlayerLocatedOn(true);
		//printBoard();
	}
	else if (playerLocation->getSouth() == churchBoard[1][2])
	{
		cout << "\"This should take me back down to the ground floor.\"" << endl;
		playerLocation->setPlayerLocatedOn(false);
		playerLocation = playerLocation->getSouth();
		playerLocation->setPlayerLocatedOn(true);
		//printBoard();
	}
	else if (playerLocation->getSouth() == nullptr)
	{
		cout << "\"There's no way for me to go that way.\"" << endl;
	}
	else if (playerLocation->getSouth() != churchBoard[2][0] || playerLocation->getSouth() == churchBoard[1][2])
	{
		cout << "\"I need to find another way down.\"" << endl;

	}
	else
	{
		cout << "A wall blocks you." << endl;
	}
}

void Church::moveEast()
{
	if (playerLocation->getEast() != nullptr)
	{
		// If player tries to open a locked door.
		if (playerLocation->getEast()->getType() == DOOR)
		{
			if (doorOpen == true)
			{
				// Door is already opened.
				playerLocation->setPlayerLocatedOn(false);	// Player is no longer located on previous space.
				playerLocation = playerLocation->getEast();	// Move player east.
				playerLocation->setPlayerLocatedOn(true);	// Player is now located on the current space.
			}
			//else if (player->getInventorySelection() == CROWBAR && doorOpen == false) 
			//else if (getShelterInventorySelection() == CROWBAR && doorOpen == false)
			else if (cplayer->getInventorySelection() == CROWBAR && doorOpen == false)
			{
				cout << "\"Maybe I can use the crowbar to pry this door open.\"" << endl;
				getchar();
				cout << "\nYou wedge the crowbar into the door frame and try to force the door open." << endl;
				getchar();
				cout << "After a few moments, the door swings open." << endl;
				playerLocation->setPlayerLocatedOn(false);	// Player is no longer located on previous space.
				playerLocation = playerLocation->getEast();	// Move player east.
				playerLocation->setPlayerLocatedOn(true);	// Player is now located on the current space.
				doorOpen = true;
			}
			else if (doorOpen == false)
			{
				cout << "\"Locked tight. I'll need to find a way to open this.\"" << endl;
			}
			else
			{
				// Door is already opened.
				playerLocation->setPlayerLocatedOn(false);	// Player is no longer located on previous space.
				playerLocation = playerLocation->getEast();	// Move player east.
				playerLocation->setPlayerLocatedOn(true);	// Player is now located on the current space.
			}
		}
		else
		{
			playerLocation->setPlayerLocatedOn(false);
			playerLocation = playerLocation->getEast();
			playerLocation->setPlayerLocatedOn(true);
		}
	}
	// Default, but also out of "bounds."
	else
	{
		cout << "A wall blocks you." << endl;
	}
}

void Church::moveWest()
{
	if (playerLocation->getWest() != nullptr)
	{
		playerLocation->setPlayerLocatedOn(false);
		playerLocation = playerLocation->getWest();
		playerLocation->setPlayerLocatedOn(true);
	}
	else
	{
		cout << "A wall blocks you." << endl;
	}
}