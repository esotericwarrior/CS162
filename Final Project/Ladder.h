/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: This is the file for the ladder space. Using ladders
** users can either unlock the ability to go up or down (north/south)
** within a given location, to transfer between floors.
*********************************************************************/
#pragma once
#include "Space.h"
#include "Enums.h"
#include "Player.h"

class Ladder : public Space
{
protected:

private:

public:
	// Default Constructor / Destructor
	Ladder();
	~Ladder();

	// Player specific functions
	void interact(Player*);

	// Map functions
	void printSpace();

};

Ladder::Ladder()
{
	type = LADDER;
}

Ladder::~Ladder()
{
}

void Ladder::interact(Player* player)
{
	if (interactCheck)	// Check if player has interacted with this Space before.
	{
		double choice, valid;
		cout << "There are Ladder here." << endl;
		cout << "1. Go up." << endl;
		cout << "2. Go down." << endl;
		cin >> choice;
		valid = inputValidation(choice);
		if (valid == 1)
		{
			cout << "You take the Ladder up to the next floor." << endl;
			//playerLocation->getNorth
		}
		else if (valid == 2)
		{
			cout << "You take the Ladder down." << endl;
		}
		else
		{
			// Nothing. Default else.
		}
	}
	else
	{
		//setType(EMPTY);				// Set the type of the space to the empty.
	}
}

void Ladder::printSpace()
{
	if (playerLocatedOn)
	{
		cout << "||*|";
	}
	else
	{
		cout << "| H ";
	}
}