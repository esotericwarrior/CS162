#pragma once
/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: This is the rubble space. In here, depending on the 
** coordinates of the rubble as well as location, we specify what a 
* user may find in a pile. All items are in Rubble, and once searched,
* the user will only find junk.
*********************************************************************/
#include "Space.h"
#include "Enums.h"

class Rubble : public Space
{
protected:

private:

public:
	// Default Constructor / Destructor
	Rubble();
	~Rubble();

	// Player specific functions
	//void interact(Player*);
	void interact(Game*);

	// Map functions
	void printSpace();

};

Rubble::Rubble()
{
	type = RUBBLE;
}

Rubble::~Rubble()
{
}


void Rubble::interact(Game* player)
{
	/********************************
	*		Shelter Rubble			*
	********************************/
	if (getID() == 1 && getLocation() == SHELTER)
	{
		if (interactCheck)	// Check if player has interacted with this Space before.
		{
			cout << "\"Just junk.\"" << endl;
		}
		else
		{
			// Randomly award player an item of value, such as food, medicine, etc.
			//player->addItem(TOWNMAP);	// Add the town map to the player's inventory.
			// Display the town map.
			// DIALOGUE
			setType(EMPTY);				// Set the type of the space to the empty.
			interactCheck = true;		// Set interact to true, indicating this player has already scavenged here.
		}
	}
	if (getID() == 3 && getLocation() == SHELTER)	// If this is the rubble behind the locked door.
	{
		if (interactCheck)	// Check if player has interacted with this Space before.
		{
			cout << "\"Just junk.\"" << endl;
		}
		else
		{
			cout << "You begin searching through the pile of debris." << endl;
			getchar();
			cout << "\"An old map of town? This should come in handy.\"" << endl;
			getchar();
			cout << "You find an old town map." << endl;
			getchar();
			player->addItem(TOWNMAP);	// Add the town map to the player's inventory.
			cout << "The Town Map has been added to your inventory." << endl;
			// Display the town map.
			//s.printTownMap();
			//cout << endl;
			cout << "\"With this, I should be able to find my way around town to scavenge for supplies.\"" << endl;
			cout << "You've unlocked the ability to scavenge at night for supplies." << endl;
			// Set something true here, so that player can scavenge at night.
			setType(EMPTY);				// Set the type of the space to the empty.
			interactCheck = true;		// Set interact to true, indicating this player has already scavenged here.
		}
	}
	//if (getID() == 27)	// Check this space's ID for the crowbar.
	if (getID() == 27 && getLocation() == SHELTER)	// Check this space's ID for the crowbar.
	{
		// If true
		if (interactCheck)	// Check if player has interacted with this Space before.
		{
			cout << "\"There's nothing else of value here.\"" << endl;
		}
		else
		{
			// DIALOGUE
			cout << "\"A crowbar? This might come in handy.\"" << endl;
			getchar();	// Wait for the user to press ENTER to continue.
			cout << "You place the crowbar into your bag." << endl;
			getchar();	// Wait for the user to press ENTER to continue.
			player->addItem(CROWBAR);
			cout << "The crowbar has been added to your inventory." << endl;
			interactCheck = true;	// Set interact check to true, indicating this player has received the crowbar.
		}
	}
	/********************************
	*		Church Rubble			*
	********************************/
	if (getID() == 0 && getLocation() == CHURCH)
	{
		if (interactCheck)	// Check if player has interacted with this Space before.
		{
			cout << "\"Nothing but junk left.\"" << endl;
		}
		else
		{
			// Randomly award player an item of value, such as food, medicine, etc.
			// DIALOGUE
			cout << "You locate a small can of food in an old box." << endl;
			getchar();
			cout << "Relieved, you place the food in your bag." << endl;
			player->addItem(FOOD);
			setType(EMPTY);				// Set the type of the space to the empty.
			interactCheck = true;		// Set interact to true, indicating this player has already scavenged here.
		}
	}
	if (getID() == 1 && getLocation() == CHURCH)
	{
		if (interactCheck)	// Check if player has interacted with this Space before.
		{
			cout << "\"Just junk.\"" << endl;
		}
		else
		{
			// Randomly award player an item of value, such as food, medicine, etc.
			// DIALOGUE
			cout << "You locate a small can of food in an old box." << endl;
			getchar();
			cout << "Relieved, you place the food in your bag." << endl;
			player->addItem(FOOD);
			setType(EMPTY);				// Set the type of the space to the empty.
			interactCheck = true;		// Set interact to true, indicating this player has already scavenged here.
		}
	}
	/********************************
	*		School Rubble			*
	********************************/
	
	if (getID() == 1 && getLocation() == SCHOOL)
	{
		if (interactCheck)	// Check if player has interacted with this Space before.
		{
			cout << "\"Just junk.\"" << endl;
		}
		else
		{
			// Randomly award player an item of value, such as food, medicine, etc.
			//player->addItem(TOWNMAP);	// Add the town map to the player's inventory.
			// Display the town map.
			// DIALOGUE
			setType(EMPTY);				// Set the type of the space to the empty.
			interactCheck = true;		// Set interact to true, indicating this player has already scavenged here.
		}
	}
	if (getID() == 0 && getLocation() == SCHOOL)	// If this is the rubble behind the locked door.
	{
		if (interactCheck)	// Check if player has interacted with this Space before.
		{
			cout << "\"Just junk.\"" << endl;
		}
		else
		{
			cout << "You begin searching through the pile of debris." << endl;
			getchar();
			cout << "\"Awful lot of cobwebs in here\" You mutter to yourself as you dig." << endl;
			getchar();
			cout << "\"What the..?\"" << endl;
			getchar();
			cout << "You turn your hand over to see a giant spider crawling across your palm." << endl;
			getchar();
			//player->addItem(TOWNMAP);	// Add the town map to the player's inventory.
			//cout << "The Town Map has been added to your inventory." << endl;
						cout << "You freak out and fling the spider across the room." << endl;
			// Display the town map.
			//s.printTownMap();
			//cout << endl;
			cout << "\\shudders\\ \"Yikes. I hate those things.\"" << endl;
			// Set something true here, so that player can scavenge at night.
			setType(EMPTY);				// Set the type of the space to the empty.
			interactCheck = true;		// Set interact to true, indicating this player has already scavenged here.
		}
	}
	if (getID () == 22 && getLocation() == SCHOOL)	// Check this space's ID for the crowbar.
	{
		// If true
		if (interactCheck)	// Check if player has interacted with this Space before.
		{
			cout << "\"There's nothing else of value here.\"" << endl;
		}
		else
		{
			// DIALOGUE
			cout << "\"A telescoping antenna! This is what I need to get out of here!.\"" << endl;
			getchar();	// Wait for the user to press ENTER to continue.
			cout << "You add the antenna to your inventory." << endl;
			getchar();	// Wait for the user to press ENTER to continue.
			player->addItem(ANTENNA);
			interactCheck = true;	// Set interact check to true, indicating this player has received the crowbar.
		}
	}
	if (getID() == 1 && getLocation() == SCHOOL)
	{
		if (interactCheck)	// Check if player has interacted with this Space before.
		{
			cout << "\"Just junk.\"" << endl;
		}
		else
		{
			// Randomly award player an item of value, such as food, medicine, etc.
			// DIALOGUE
			cout << "You locate a small can of food in an old box." << endl;
			getchar();
			cout << "Relieved, you place the food in your bag." << endl;
			player->addItem(FOOD);
			setType(EMPTY);				// Set the type of the space to the empty.
			interactCheck = true;		// Set interact to true, indicating this player has already scavenged here.
		}
	}
}

void Rubble::printSpace()
{
	// If the player occupies this spot...
	if (playerLocatedOn)
	{
		// Print this:
		cout << "| *#";
		//cout << "  * ";
	}
	else
	{
		cout << "| # ";
		//cout << "  # ";
	}
}