#pragma once
/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: This is the shelter. It acts as the central hub for the
** other two locations. When it's day time we return here to hide, and
** can only leave to scavenge at night. This is where the radio is you
** need to repair.
*********************************************************************/
#ifndef SHELTER_HPP
#define SHELTER_HPP

#include "Space.h"
#include "Player.h"
#include "Enums.h"
#include "Church.h"
#include "School.h"
#include "inputValidation.h"
#include "Menu.h"
#include "Rubble.h"
#include "Ladder.h"
#include "Radio.h"
#include "Door.h"
#include "Game.h"
#include <vector>
#include <string>
#include <limits>
using namespace game_Enums;

// Initialize Church & School to be used later for the night phase.
Church church;
School school;

class Shelter
{
private:
	int rows;								// Rows for the shelter board.
	int columns;							// Columns for the shelter board.
	int choice;								// Variable used to get user's choice during the night phase.
	int day = 1;							// Initialize day count to 1.
	int night = 0;							// Initialize night count to 0.

	vector<items> shelterInventory;			// Shelter's inventory.
	vector<vector<Space*>> shelterBoard;	// Initialize vector to be used for the shelter.
	vector<Space*> boardColumn;

	Game* splayer;							// Create a pointer to Game class.
	Game** cplayer;
	Space* playerLocation;					// Create a pointer to Space class.

	bool playerAlive;						// Boolean used to track whether or not the player is alive.
	bool gameState;							// Boolean used to determine whether or not the game is being played.

public:
	Shelter();								// Default constructor.
	~Shelter();								// Destructor.
	bool getGameState();					// getGameState function declaration.
	bool doorOpen = false;					// Boolean used to determine whether or not a door has been opened.

	// Get Functions
	vector<items> getShelterInventory();	// Vector used for the shelter's inventory.
	Game* getsplayer();

	// Item-related functions
	bool addShelterItem(items);
	void removeShelterItem();
	void printShelterInventory();
	items getShelterInventorySelection();
	items useShelterItem(items);

	// Board Functions
	void initializeBoard();
	void printBoard();
	void printTownMap();

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

Shelter::Shelter()
{
	int rows = 3;
	int columns = 8;

	boardColumn.resize(columns, nullptr);
	shelterBoard.resize(rows, boardColumn);
	playerAlive = true;
	gameState = true;
	splayer = new Game();
	//cout << "Address of splayer: " << &splayer << endl;
	//cout << "Health of splayer: " << splayer->getHealth() << endl;
	cplayer = &splayer;
	//cout << "Address of cplayer: " << cplayer << endl;
	//cout << "Health of cplayer: " << (*cplayer)->getHealth() << endl;
	//cout << "splayer: " << splayer << endl;
	//cout << "getsplayer: " << getsplayer() << endl;
	//cout << "Health of getsplayer: " << getsplayer()->getHealth() << endl;
	church.setPlayer(splayer);	// Set the player in church to point to splayer in Shelter.
	church.setNight(night);		// Set the night pointer in church to point to night in Shelter.
	school.setPlayer(splayer);	// Set the player in school to point to splayer in Shelter.
	school.setNight(night);		// Set the night pointer in church to point to night in Shelter.
	//cout << "Church night: " << church.getNight() << endl;
	//cout << "Church player: " << church.getsplayer() << endl;
	//cout << "Church player Health: " << church.getsplayer()->getHealth() << endl;
}

Shelter::~Shelter()
{
	for (size_t i = 0; i < shelterBoard.size(); i++)
	{
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			delete shelterBoard[i][j];
			shelterBoard[i][j] = nullptr;
		}
	}
	delete splayer;
}

vector<items> Shelter::getShelterInventory()
{
	return shelterInventory;
}

Game * Shelter::getsplayer()
{
	return splayer;
}

// Item Functions
bool Shelter::addShelterItem(items newItem)
{
	if (shelterInventory.size() < 10)
	{
		shelterInventory.push_back(newItem);
		return true;
	}
	else
	{
		cout << "Your bag is too small to add more!" << endl;
		return false;
	}
}

void Shelter::removeShelterItem()
{
	shelterInventory.pop_back();
}

/****************************************************************
*				void Shelter::printShelterInventory()			*
* When called, this function will print all of the items in the	*
* shelter's inventory and display a brief description of those	*
* items.														*
****************************************************************/
void Shelter::printShelterInventory()
{
	for (size_t i = 0; i < shelterInventory.size(); i++)
	{
		cout << i + 1 << ". ";

		switch (shelterInventory[i])
		{
		case MAP:
			cout << "Map: ";
			cout << "This is a map of the shelter." << endl;
			break;
		case CROWBAR:
			cout << "Crowbar: ";
			cout << "A standard crowbar from the local hardware store. It can be used to break open locked doors ";
			cout << "and in dire situations, to defend yourself." << endl;
			break;
		case TOWNMAP:
			cout << "Town Map: ";
			cout << "This is a map of the town. Having it enables you to scavenge for supplies at night." << endl;
			break;
		case FOOD:
			cout << "Canned Food: ";
			cout << "Not very appetizing, but it does the job." << endl;
			break;
		case ANTENNA:
			cout << "Antenna: ";
			cout << "\"I'm sure I can put this to good use somehow.\"" << endl;
			break;
		default:
			cout << "Error: printInventory()" << endl;
		}
	}
}

items Shelter::getShelterInventorySelection()
{
	cout << "Which item would you like to use?" << endl;
	printShelterInventory();

	int tempChoice = choiceValidation(shelterInventory.size());

	return (shelterInventory[tempChoice - 1]);
}

items Shelter::useShelterItem(items targetItem)
{
	switch (targetItem)
	{
	case (MAP):
		cout << endl;
		cout << "You open the map and examine it closely." << endl;
		return MAP;
		break;
	case (CROWBAR):
		cout << endl;
		cout << "You reach for your crowbar." << endl;
		return CROWBAR;
		break;
	case (TOWNMAP):
		cout << endl;
		cout << "You open the town map and examine it closely." << endl;
		return TOWNMAP;
		break;
	case (FOOD):
		cout << endl;
		cout << "Not very tasty, but at least you're not as hungry anymore." << endl;
		splayer->adjustHealth(10);
		cout << "10 Health restored. Current Health: " << splayer->getHealth() << ")" << endl;
		return FOOD;
		break;
		removeShelterItem();
	case (ANTENNA):
		cout << endl;
		cout << "\"Hmm...\"" << endl;
		return ANTENNA;
		break;
	default:
		cout << "Error: useItem()" << endl;
	}
}

bool Shelter::getGameState()
{
	return gameState;
}

void Shelter::initializeBoard()
{
	/********************************************
	*			Set Time for Day Phase			*
	********************************************/
	splayer->setDayTime();	// Set time to 6 AM (0600)

	// Initialize each space in the Board's matrix.
	for (size_t i = 0; i < shelterBoard.size(); i++)
	{
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			/************************************
			*			Create Rubble			*
			************************************/
			if (i == 0 && j == 1)
			{
				shelterBoard[i][j] = new Rubble();
				shelterBoard[i][j]->setID(i * 10 + j);	// Set ID to 1.
				shelterBoard[i][j]->setLocation(SHELTER);
			}
			else if (i == 0 && j == 3)
			{
				shelterBoard[i][j] = new Rubble();
				shelterBoard[i][j]->setID(i * 10 + j);	// Set ID to 3.
				shelterBoard[i][j]->setLocation(SHELTER);
			}
			else if (i == 2 && j == 7)
			{
				shelterBoard[i][j] = new Rubble();
				shelterBoard[i][j]->setID(i * 10 + j);	// Set ID to 27. This is where the crowbar is.
				shelterBoard[i][j]->setLocation(SHELTER);
			}
			/************************************
			*			Create Ladders			*
			************************************/
			else if (i == 1 && j == 4)
			{
				shelterBoard[i][j] = new Ladder();
				shelterBoard[i][j]->setID(i * 10 + j);
				shelterBoard[i][j]->setLocation(SHELTER);
			}
			else if (i == 2 && j == 2)
			{
				shelterBoard[i][j] = new Ladder();
				shelterBoard[i][j]->setID(i * 10 + j);
				shelterBoard[i][j]->setLocation(SHELTER);
			}
			/************************************
			*			Create Doors			*
			************************************/
			else if (i == 1 && j == 3)
			{
				shelterBoard[i][j] = new Door();
				shelterBoard[i][j]->setID(i * 10 + j);
				shelterBoard[i][j]->setLocation(SHELTER);
			}
			else if (i == 1 && j == 7)
			{
				shelterBoard[i][j] = new Radio();
				shelterBoard[i][j]->setID(i * 10 + j);
				shelterBoard[i][j]->setLocation(SHELTER);
			}
			/************************************
			*		Create Empty Spaces			*
			************************************/
			else
			{
				shelterBoard[i][j] = new Space();
				shelterBoard[i][j]->setID(i * 10 + j);
				shelterBoard[i][j]->setLocation(SHELTER);
			}
		}
	}

	// Link all Space's North pointers.
	for (size_t i = 1; i < shelterBoard.size(); i++)
	{
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			shelterBoard[i][j]->setNorth(shelterBoard[i - 1][j]);
		}
	}

	// Link all Space's South pointers.	
	for (size_t i = 0; i < shelterBoard.size() - 1; i++)
	{
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			shelterBoard[i][j]->setSouth(shelterBoard[i + 1][j]);
		}
	}

	// Link all Space's East pointers.
	for (size_t i = 0; i < shelterBoard.size(); i++)
	{
		for (size_t j = 0; j < boardColumn.size() - 1; j++)
		{
			shelterBoard[i][j]->setEast(shelterBoard[i][j + 1]);
		}
	}

	// Link all Space's West pointers.
	for (size_t i = 0; i < shelterBoard.size(); i++)
	{
		for (size_t j = 1; j < boardColumn.size(); j++)
		{
			shelterBoard[i][j]->setWest(shelterBoard[i][j - 1]);
		}
	}

	// Set the player's starting location.
	setPlayerLocation(shelterBoard[1][0]);
	shelterBoard[1][0]->setPlayerLocatedOn(true);

	// Give player starting item.
	addShelterItem(MAP);
	//splayer->addItem(ANTENNA);
	//splayer->addItem(CROWBAR);
}

void Shelter::printBoard()
{
	// https://www.asciiart.eu/buildings-and-places/houses
	cout << " My Shelter" << endl;
	cout << "       ________[_]________" << endl;
	cout << "      //\\        ______   \\" << endl;
	cout << "     //_\\       \\    /\\    \\" << endl;
	cout << "    //___\\       \\__/  \\    \\" << endl;
	cout << "   //_____\\       \\ |[]|     \\" << endl;
	cout << "  //_______\\       \\|__|      \\" << endl;
	cout << " /XXXXXXXXXX\\                  \\" << endl;
	cout << "/_I_II  I__I_\\__________________\\" << endl;

	// This goes through each row.
	for (size_t i = 0; i < shelterBoard.size(); i++)
	{
		//Prints top lines for map squares
		for (int count = 0; count < 8; count++)
		{
			cout << " ---";
			if (i == 1 && count == 7)
			{
				cout << "  <--- Attic" << "\t\t| Day: " << day;
			}
			else if (i == 2 && count == 7)
			{
				cout << "  <--- Ground Floor" << "\t| Time: " << splayer->getTime() << ":00";
			}
		}
		cout << endl;
		//This goes through each column.
		for (size_t j = 0; j < boardColumn.size(); j++)
		{
			if (shelterBoard[i][j] != nullptr)
			{
				shelterBoard[i][j]->printSpace();
			}
			else
			{
				cout << "nullptr ";
			}
		}
		cout << "|" << endl;
	}
	// Prints the bottom lines for the shelterBoard.
	for (int count = 0; count < 8; count++)
	{
		cout << " ---";
		if (count == 7)
		{
			cout << "  <--- Basement" << "\t\t| Current Health: " << splayer->getHealth() << endl;
			//cout << "Health of cplayer: " << (*cplayer)->getHealth() << endl;
		}
	}
	cout << endl;
}

// Player-related Functions
void Shelter::setPlayerLocation(Space* playerSpace)
{
	playerLocation = playerSpace;
}

void Shelter::playerChoose()
{
// DO WHILE TEST
do {
	if (playerAlive)	// Check if player is alive.
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		printBoard();
		cout << "\n*************************" << endl;
		cout << "*\tDAY PHASE\t*" << endl;
		cout << "*************************" << endl;
		switch (menuChoice5("What do you do?", "Move", "Check your surroundings", "Check your inventory", "Use an item", "Quit"))	// Prompt user for input.
		{
			// Move.
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
			splayer->adjustHealth(-1);	// Subtract one health from the player.
			splayer->adjustTime(1);		// Add time with movement.
			// Display current HP and Time.
			cout << "Current Health: " << splayer->getHealth() << endl << endl;
			cout << "Current Time: " << splayer->getTime() << ":00" << endl;
			if (splayer->getHealth() <= 0)	// Check if player has died.
			{
				playerAlive = false;
			}
			break;
			// Check surroundings.
		case 2:
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			playerLocation->interact(splayer);
			if (playerLocation->getGameComplete())	// Check if player has completed the game.
			{
				gameState = false;
			}
			cout << endl;
			break;
			// Check inventory.
		case 3:
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nMy Backpack:" << endl;
			splayer->printInventory();		// Print Inventory.
			cout << "\nMy Things:" << endl;
			printShelterInventory();		// Print Shelter Inventory
			break;
			// Use item.
		case 4:
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			/************************************************************
			*				SHELTER INVENTORY SELECTION					*
			************************************************************/
			int choice1;
			int valid;
			cin.clear();
			cout << "1. My Inventory" << endl;
			cout << "2. Shelter Inventory" << endl;
			cin >> choice1;
			valid = menuValidation(choice1);
			switch (valid)
			{
			case 1:
				//If the user chooses the map:
				if (splayer->useItem(splayer->getInventorySelection()) == MAP)
				{
					printBoard();		// Print the shelter board.
				}
				if (splayer->useItem(splayer->getInventorySelection()) == TOWNMAP)
				{
					church.printBoard();		// Print the Town Map.
				}
			case 2:
				if (useShelterItem(getShelterInventorySelection()) == MAP)	// Use an item. If it's the Map, print the Board.
				{
					printBoard();		// Print the shelter board.
				}
				if (useShelterItem(getShelterInventorySelection()) == TOWNMAP)	// Use an item. If it's the Town Map, print it.
				{
					church.printBoard();		// Print the Town Map.
				}
			}
			cout << endl;
			break;
			// Quit.
		case 5:
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	if (splayer->getTime() >= 20)
	/*if (splayer->getTime() >= 20 && splayer->getTownMap() == true)*/
	{
		cout << "\n*************************" << endl;
		cout << "*\tNIGHT PHASE\t*" << endl;
		cout << "*************************" << endl;
		// Increment day counter.
		day++;
		// Increment night counter.
		night++;
		church.setNight(night); // Set night count in Church.
		//if (player->getInventory() == TOWNMAP)
		//if (splayer->getTownMap() == true)
		//{
		//	choice = 3;
		//}
		cout << "\"It's night time. I can go scavenging for supplies.\"" << endl;
		// Print Town Map
		printTownMap();
		// Prompt user to choose whether or not to scavenge or skip the night phase.
		//int choice;
		cin.clear();
		cout << "\"Where should I go?\"" << endl;
		cout << "1. Church" << endl;
		cout << "2. School" << endl;
		cout << "3. Stay at home (skip to The Morning Phase)" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			/************
			*	Church	*
			************/
			church.initializeBoard();
			church.printBoard();
			do
			{											// Prompt user input until player dies or game over occurs.
				church.playerChoose();
			} while (church.getGameState());
			//********************************************
			//*			Set Time for Day Phase			*
			//********************************************/
			//player->setDayTime();	// Set time to 6 AM. (0600)
			splayer->setDayTime();	// Set time to 6 AM. (0600)
			cout << endl; 
			break;
		case 2:
			/************
			*	School	*
			************/
			school.initializeBoard();
			school.printBoard();
			do
			{											// Prompt user input until player dies or game over occurs.
				school.playerChoose();
			} while (school.getGameState());
			//********************************************
			//*			Set Time for Day Phase			*
			//********************************************/
			//player->setDayTime();	// Set time to 6 AM. (0600)
			splayer->setDayTime();	// Set time to 6 AM. (0600)
			cout << endl;
			break;
		case 3:
			cout << endl;
			cout << "You choose to skip scavenging tonight." << endl;
			cout << "\n\\I think I'll just stay home tonight.\"" << endl;
			cout << "\n(Skipping to The Morning Phase)" << endl;
			//********************************************
			//*			Set Time for Day Phase			*
			//********************************************/
			splayer->setDayTime();	// Set time to 6 AM. (0600)
			cout << endl;
			//// Set the player's starting location.
			//setPlayerLocation(shelterBoard[1][0]);
			//shelterBoard[1][0]->setPlayerLocatedOn(true);
			//// Print the Shelter's map.
			printBoard();
			cout << endl;
			//// Increment Day Counter
			//// day++;
			break;
		default:
			break;
		}
	}
	} while (splayer->getTime() >= 5 && splayer->getTime() >= 20); // DO WHILE TEST
}	// Function Definition

// Move Functions
void Shelter::moveNorth()
{
	/********************************************************
	*			Moving north from the basement.				*
	********************************************************/
	if (playerLocation->getNorth() == shelterBoard[1][2])
	{
		cout << "\"I can use this ladder to climb back up.\"" << endl;
		cout << "You use the ladder to climb back upstairs." << endl;
		playerLocation->setPlayerLocatedOn(false);
		playerLocation = playerLocation->getNorth();
		playerLocation->setPlayerLocatedOn(true);
	}
	/********************************************************
	*			Moving north from the ground floor.			*
	********************************************************/
	else if (playerLocation->getNorth() == shelterBoard[0][0])
	{
		cout << "\"I need to find another way up.\"" << endl;
	}
	else if (playerLocation->getNorth() == shelterBoard[0][1])
	{
		cout << "\"I need to find another way up.\"" << endl;
	}
	else if (playerLocation->getNorth() == shelterBoard[0][2])
	{
		cout << "\"I need to find another way up.\"" << endl;
	}
	// Ladder here now.
	else if (playerLocation->getNorth() == shelterBoard[0][4])
	{
			cout << "\"I can use this ladder to climb up to the next level.\"" << endl;
			cout << "You use the ladder to climb up into the attic." << endl;
			playerLocation->setPlayerLocatedOn(false);
			playerLocation = playerLocation->getNorth();
			playerLocation->setPlayerLocatedOn(true);
	}
	else if (playerLocation->getNorth() == shelterBoard[0][5])
	{
		cout << "\"I need to find another way up.\"" << endl;
	}
	else if (playerLocation->getNorth() == shelterBoard[0][6])
	{
		cout << "\"I need to find another way up.\"" << endl;
	}
	else if (playerLocation->getNorth() == shelterBoard[0][7])
	{
		cout << "\"I need to find another way up.\"" << endl;
	}
	else if (playerLocation->getNorth() == shelterBoard[1][7])
	{
		cout << "\"I need to find another way up.\"" << endl;
	}
	else if (playerLocation->getNorth() != nullptr)
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

void Shelter::moveSouth()
{
	/********************************************************
	*			Moving south from the attic.				*
	********************************************************/
	if (playerLocation->getSouth() == shelterBoard[1][0])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[1][1])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[1][1])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[1][2])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[1][3])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[1][4])
	{
		cout << "\"I can use this ladder to climb back downstairs.\"" << endl;
		getchar();
		cout << "You climb back down to the ground floor." << endl;
		playerLocation->setPlayerLocatedOn(false);
		playerLocation = playerLocation->getSouth();
		playerLocation->setPlayerLocatedOn(true);

	}
	else if (playerLocation->getSouth() == shelterBoard[1][5])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[1][6])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[1][7])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[2][0])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[2][1])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[2][2])
	{
		cout << "\"I can use this ladder to climb down.\"" << endl;
		getchar();
		cout << "You climb down into the basement." << endl;
		playerLocation->setPlayerLocatedOn(false);
		playerLocation = playerLocation->getSouth();
		playerLocation->setPlayerLocatedOn(true);
	}
	else if (playerLocation->getSouth() == shelterBoard[2][3])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[2][4])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[2][5])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[2][6])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() == shelterBoard[2][7])
	{
		cout << "\"I need to find another way down.\"" << endl;
	}
	else if (playerLocation->getSouth() != nullptr)
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

void Shelter::moveEast()
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
			else if (splayer->getInventorySelection() == CROWBAR && doorOpen == false)
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

void Shelter::moveWest()
{
	// If player tries to move into a wall.
	if (playerLocation->getWest() != nullptr)
	{
		playerLocation->setPlayerLocatedOn(false);
		playerLocation = playerLocation->getWest();
		playerLocation->setPlayerLocatedOn(true);
	}
	// Default, but also out of "bounds."
	else
	{
		cout << "A wall blocks you." << endl;
	}
}

void Shelter::printTownMap()
{
	cout << "You remove the town map from your bag and study it carefully." << endl;
	cout << endl;
	cout << "==================================================" << endl;
	cout << "iiiiiiii ############  iiii|  |  |i ########### ii" << endl;
	cout << "iiiiiiii #          #  iiii|  |  |i #         # ii" << endl;
	cout << "iiiiiiii #--#########  iiii|  |  |i #         # ii" << endl;
	cout << "iiiiiiii  MY SHELTER   iiii|  |  |i #####--#### ii" << endl;
	cout << "iiiiiiii               iiii|  |  |i SUPERMARKET ii" << endl;
	cout << "___________________________   |   ______________" << endl;
	cout << "\n---------------------------       --------------" << endl;
	cout << "___________________________       ______________" << endl;
	cout << "ii ###--### iii ###--### ii|  |  | #####--#### ii" << endl;
	cout << "ii #      # iii #      # ii|  |  | #         # ii" << endl;
	cout << "ii #      # iii #      # ii|  |  | #         # ii" << endl;
	cout << "ii ######## iii ######## ii|  |  | ########### ii" << endl;
	cout << "ii  CHURCH  iii  SCHOOL  ii|  |  |   HOSPITAL  ii" << endl;
	cout << "=================================================" << endl;
	cout << endl;
}


