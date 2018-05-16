#pragma once
/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: This is a generic space. There is nothing in these
** spaces.
*********************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include "Enums.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

using namespace game_Enums;

class Space
{
protected:
	Space * North;
	Space *South;
	Space *East;
	Space *West;

	int spaceID;
	spaceType type;
	Location location;
	bool interactCheck;
	bool playerLocatedOn;
	bool gameComplete;

public:
	Space();
	virtual ~Space();

	// Setters
	void setID(int);
	void setType(spaceType);
	void setLocation(Location);		// Set location function.
	void setNorth(Space*);
	void setSouth(Space*);
	void setEast(Space*);
	void setWest(Space*);
	void setPlayerLocatedOn(bool);

	// Getters
	int getID();
	spaceType getType();
	Location getLocation();					// Get location function.
	Space* getNorth();
	Space* getSouth();
	Space* getEast();
	Space* getWest();
	bool getGameComplete();

	// Player specific functions
	//virtual void interact(Player*);
	virtual void interact(Game*);

	// Map functions
	virtual void printSpace();
};

#endif // !SPACE_HPP


Space::Space()
{
	spaceID = 0;
	North = nullptr;
	South = nullptr;
	East = nullptr;
	West = nullptr;
	type = EMPTY;
	interactCheck = false;
	playerLocatedOn = false;
	gameComplete = false;
}

Space::~Space()
{

}

// Setters
void Space::setID(int matrix)
{
	spaceID = matrix;
}

void Space::setType(spaceType Type)
{
	type = Type;
}

void Space::setLocation(Location Location)
{
	location = Location;
}

void Space::setNorth(Space* northPtr)
{
	North = northPtr;
}

void Space::setSouth(Space* southPtr)
{
	South = southPtr;
}

void Space::setEast(Space* eastPtr)
{
	East = eastPtr;
}

void Space::setWest(Space* westPtr)
{
	West = westPtr;
}

void Space::setPlayerLocatedOn(bool boolean)
{
	playerLocatedOn = boolean;
}

// Getters
int Space::getID()
{
	return spaceID;
}

spaceType Space::getType()
{
	return type;
}

Location Space::getLocation()
{
	return location;
}

Space* Space::getNorth()
{
	return North;
}

Space* Space::getSouth()
{
	return South;
}

Space* Space::getEast()
{
	return East;
}

Space* Space::getWest()
{
	return West;
}

bool Space::getGameComplete()
{
	return gameComplete;
}


void Space::interact(Game* player)
{
	cout << "There is nothing here." << endl;
}

void Space::printSpace()
{
	if (playerLocatedOn)
	{
		cout << "| * ";
	}
	else
	{
		cout << "|   ";
	}
}

