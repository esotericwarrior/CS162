/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: This is the door space. Doors can be pried open with
** a crowbar, and contain a check to see if they've already been 
** opened or not.
*********************************************************************/
#pragma once
#include "Space.h"
#include "Enums.h"

class Door : public Space
{
protected:

private:

public:
	// Default Constructor / Destructor
	Door();
	~Door();

	// Player specific functions
	void interact(Player*);

	// Map functions
	void printSpace();

};

Door::Door()
{
	type = DOOR;
}

Door::~Door()
{
}

void Door::interact(Player* player)
{
	if (interactCheck)	// Check if player has interacted with this Space before.
	{
		cout << "There's nothing of value left." << endl;
	}
	else
	{
		//player->addItem(DAGGER);
		// Randomly award player an item of value, such as food, medicine, etc.
		setType(EMPTY);				// Set the type of the space to the empty.
	}
}

void Door::printSpace()
{
	if (playerLocatedOn)
	{
		//cout << "| * ";
		cout << "|[*]";
	}
	else
	{
		cout << "|[ ]";
	}
}