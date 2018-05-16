#pragma once

/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: The school is one of the locations. It houses the radio
** antenna.
*********************************************************************/
#ifndef SCHOOL_HPP
#define SCHOOL_HPP

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

class School
{
private:
	int rows;
	int columns;
	int i = 0;
	int &night = i;

	vector<vector<Space*>> schoolBoard;
	vector<Space*> boardColumn;

	Game* scplayer;
	Space* playerLocation;
	bool playerAlive;
	bool gameState;
public:
	School();
	~School();
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

School::School()
{
	int rows = 3;
	int columns = 4;
	boardColumn.resize(columns, nullptr);
	schoolBoard.resize(rows, boardColumn);
	playerAlive = true;
	gameState = true;
}


Game * School::getsplayer()
{
	return scplayer;
}

void School::setPlayer(Game* player)
{
	scplayer = player;
}

void School::setNight(int &n)
{
	night = n;
}

int School::getNight()
{
	return night;
}

School::~School()
{
	for (size_t i = 0; i < schoolBoard.size(); i++)
	{
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			delete schoolBoard[i][j];
			schoolBoard[i][j] = nullptr;
		}
	}
	//delete cplayer;
}

bool School::getGameState()
{
	return gameState;
}

// School Functions
void School::initializeBoard()
{
	// Initialize each space in the School's matrix.
	for (size_t i = 0; i < schoolBoard.size(); i++)
	{
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			/****************************
			*		Create Ladders		*
			****************************/
			if (i == 1 && j == 2)
			{
				schoolBoard[i][j] = new Ladder();
				schoolBoard[i][j]->setID(i * 10 + j);
				schoolBoard[i][j]->setLocation(SCHOOL);
			}
			/****************************
			*		Create Rubble		*
			****************************/
			else if (i == 0 && j == 0)
			{
				schoolBoard[i][j] = new Rubble();
				schoolBoard[i][j]->setID(i * 10 + j);
				schoolBoard[i][j]->setLocation(SCHOOL);
			}
			else if (i == 0 && j == 1)
			{
				schoolBoard[i][j] = new Rubble();
				schoolBoard[i][j]->setID(i * 10 + j);
				schoolBoard[i][j]->setLocation(SCHOOL);
			}
			else if (i == 2 && j == 0)
			{
				schoolBoard[i][j] = new Rubble();
				schoolBoard[i][j]->setID(i * 10 + j);
				schoolBoard[i][j]->setLocation(SCHOOL);
			}
			else if (i == 2 && j == 2)
			{
				schoolBoard[i][j] = new Rubble();
				schoolBoard[i][j]->setID(i * 10 + j);
				schoolBoard[i][j]->setLocation(SCHOOL);
			}
			else
			{
				schoolBoard[i][j] = new Space();
				schoolBoard[i][j]->setID(i * 10 + j);
				schoolBoard[i][j]->setLocation(SCHOOL);
			}
		}
	}

	// Link all Space's North pointers.
	for (size_t i = 1; i < schoolBoard.size(); i++)
	{
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			schoolBoard[i][j]->setNorth(schoolBoard[i - 1][j]);
		}
	}

	// Link all Space's South pointers.	
	for (size_t i = 0; i < schoolBoard.size() - 1; i++)
	{
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			schoolBoard[i][j]->setSouth(schoolBoard[i + 1][j]);
		}
	}

	// Link all Space's East pointers.
	for (size_t i = 0; i < schoolBoard.size(); i++)
	{
		for (size_t j = 0; j < boardColumn.size() - 1; j++)
		{
			schoolBoard[i][j]->setEast(schoolBoard[i][j + 1]);
		}
	}

	// Link all Space's West pointers.
	for (size_t i = 0; i < schoolBoard.size(); i++)
	{
		for (size_t j = 1; j < boardColumn.size(); j++)
		{
			schoolBoard[i][j]->setWest(schoolBoard[i][j - 1]);
		}
	}

	// Set the player's starting location.
	setPlayerLocation(schoolBoard[1][0]);
	schoolBoard[1][0]->setPlayerLocatedOn(true);

	scplayer->addItem(MAP);
}

void School::printBoard()
{
	// https://www.asciiart.eu/electronics/clocks
	cout << "\n St. Mary's Academy" << endl;
	cout << "        _ " << endl;
	cout << "      ,/_\\\\," << endl;
	cout << "    ,/_/ \\_\\," << endl;
	cout << "   /_/ ___ \\_\\" << endl;
	cout << "  /_/ |(V)| \\_\\" << endl;
	cout << "    |  .-.  |" << endl;
	cout << "    | / / \\ |" << endl;
	cout << "    | \\ \\ / |" << endl;
	cout << "    |  '-'  |" << endl;
	cout << "  __'--,-,--'__" << endl;

	//cout << "        |\\  " << endl;
	//cout << "        |_\\  " << endl;
	//cout << "        |    " << endl;
	//cout << "    ____|____" << endl;
	//cout << "   /         \\" << endl;
	//cout << "  /           \\" << endl;
	cout << " /             \\" << endl;
	cout << "/    SCHOOL     \\" << endl;
	//cout << "   ______________" << endl;
	for (size_t i = 0; i < schoolBoard.size(); i++)
	{
		//Top Lines
		for (int count = 0; count < 4; count++)
		{
			cout << " ---";
		}
		if (i == 1)
		{
			cout << "  <--- Upper Level  | Night: " << getNight();
		}
		if (i == 2)
		{
			cout << "  <--- Ground Level | Time: " << scplayer->getTime() << ":00";
		}
		cout << endl;

		for (size_t j = 0; j < boardColumn.size(); j++)
		{

			if (schoolBoard[i][j] != nullptr)
			{
				schoolBoard[i][j]->printSpace();
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
			cout << " ===============" << "  <--- Basement";
		}
	}	// Prints last bottom line for map
	cout << endl;
}

// Player-related Functions
void School::setPlayerLocation(Space* playerSpace)
{
	playerLocation = playerSpace;
}

void School::playerChoose()
{
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
			scplayer->adjustHealth(-1);	// Subtract one health from the player.
			if (scplayer->getTime() >= 24)
			{
				scplayer->resetTime();
				scplayer->adjustTime(1);		// Add time with movement.
			}
			else
			{
				scplayer->adjustTime(1);		// Add time with movement.
			}
			//cplayer->adjustTime(6);		// Add time with movement.
			printBoard();
			//cout << "Current health: " << cplayer->getHealth() << endl << endl;
			cout << "Current health: " << scplayer->getHealth() << endl << endl;

			if (scplayer->getHealth() <= 0)	// Check if player has died.
			{
				playerAlive = false;
			}
			break;
		case 2:
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			playerLocation->interact(scplayer);		// This function calls interact at the player's current location.
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

			scplayer->printInventory();		// Print Inventory.
			break;
		case 4:
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (scplayer->useItem(scplayer->getInventorySelection()) == MAP)	// Use an item. If it's the Map, print the School.
			{
				printBoard();
			}
			cout << endl;
			break;
		case 5:
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			// DO SOMETHING HERE
			//********************************************
			//*			Set Time for Day Phase			*
			//********************************************/
			scplayer->setDayTime();	// Set time to 6 AM. (0600)
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
		cout << "You fall to the ground." << endl;
		getchar();
		cout << "As your vision darkens, you hear the voice." << endl;
		cout << "\"A good attempt.\"" << endl;
		getchar();
		cout << "GAME OVER" << endl;
		gameState = false;
	}
}

// Move Functions
void School::moveNorth()
{
	if (playerLocation->getNorth() != nullptr)
	{
		playerLocation->setPlayerLocatedOn(false);
		playerLocation = playerLocation->getNorth();
		playerLocation->setPlayerLocatedOn(true);
	}
	else
	{
		cout << "A wall blocks you." << endl;
	}
}

void School::moveSouth()
{
	if (playerLocation->getSouth() != nullptr)
	{
		playerLocation->setPlayerLocatedOn(false);
		playerLocation = playerLocation->getSouth();
		playerLocation->setPlayerLocatedOn(true);
	}
	else
	{
		cout << "A wall blocks you." << endl;
	}
}

void School::moveEast()
{
	if (playerLocation->getEast() != nullptr)
	{
		playerLocation->setPlayerLocatedOn(false);
		playerLocation = playerLocation->getEast();
		playerLocation->setPlayerLocatedOn(true);
	}
	else
	{
		cout << "A wall blocks you." << endl;
	}
}

void School::moveWest()
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