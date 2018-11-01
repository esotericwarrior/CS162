#pragma once
/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: This is the player class. This is where the player that
** the user controls is constructed. It track health, time, date and
** inventory here. One player is created and then the different places
** point to the player.
*********************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Enums.h"
#include "inputValidation.h"

using namespace game_Enums;

class Player
{
private:
	vector<items> inventory;

	int health;
	int clockTime = 0;
	bool victory;

public:

	// Default Constructor & Destructor
	Player();
	~Player();

	// Set Functions
	void setVictory(bool);
	void setDayTime();					// Set function for the time during the day phase.
	void setNightTime();				// Set function for time during the night phase.
	void resetTime();					// Reset time function during the night phase.

	// Get Functions
	int getHealth();					// Get function for current health.
	int getTime();						// Get function for current time.
	vector<items> getInventory();		// Get function for the player's inventory.
	bool getVictory();

	// Function used to adjust health.
	void adjustHealth(int);
	// Function used to adjust time.
	void adjustTime(int);

	// Item-related functions
	bool addItem(items);
	void removeItem();
	void printInventory();
	items getInventorySelection();
	items useItem(items);
};

#endif // !PLAYER_HPP

Player::Player()
{
	health = 45;
	clockTime = 0;
}

Player::~Player()
{

}

void Player::setVictory(bool boolean)
{
	victory = boolean;
}

void Player::setDayTime()
{
	clockTime = 6;
}

void Player::setNightTime()
{
	clockTime = 20;
}

void Player::resetTime()
{
	clockTime = 0;
}

int Player::getHealth()
{
	return health;
}

int Player::getTime()
{
	return clockTime;
}

vector<items> Player::getInventory()
{
	return inventory;
}

bool Player::getVictory()
{
	return victory;
}

void Player::adjustHealth(int adjust)
{
	health += adjust;
}

void Player::adjustTime(int n)
{
	if (n < 23)
	{
		clockTime += n;
		//return clockTime;
	}
	else
	{
		clockTime = 0;
		//return clockTime;
	}
}

// Item Functions
bool Player::addItem(items newItem)
{
	if (inventory.size() < 10)
	{
		inventory.push_back(newItem);
		return true;
	}
	else
	{
		cout << "Your bag is too small to add more!" << endl;
		return false;
	}
}

void Player::removeItem()
{
	inventory.pop_back();
}

void Player::printInventory()
{
	for (size_t i = 0; i < inventory.size(); i++)
	{
		cout << i + 1 << ". ";

		switch (inventory[i])
		{
		case MAP:
			cout << "Map" << endl;
			break;
		case CROWBAR:
			cout << "Crowbar" << endl;
			break;
		case FOOD:
			cout << "Canned Food" << endl;
			break;
		case ANTENNA:
			cout << "Antenna" << endl;
			break;
		default:
			cout << "Error: printInventory()" << endl;
		}
	}
}

items Player::getInventorySelection()
{
	if (inventory.size() <= 0)
	{
		cout << "\"I don't have any items.\"" << endl;
	}
	else
	{
		cout << "Which item would you like to use?" << endl;
		printInventory();

		int tempChoice = choiceValidation(inventory.size());

		return (inventory[tempChoice - 1]);
	}
	//cout << "Which item would you like to use?" << endl;
	//printInventory();

	//int tempChoice = choiceValidation(inventory.size());

	//return (inventory[tempChoice - 1]);
}

items Player::useItem(items targetItem)
{
	switch (targetItem)
	{
	case MAP:
		cout << endl;
		cout << "You open the Map..." << endl;
		return MAP;
		break;
	case CROWBAR:
		cout << "Crowbar" << endl;
		return CROWBAR;
		break;
	case FOOD:
		cout << "\"I'm starving...\"" << endl;
		cout << "You eat until your full. The food replenishes both your health and hunger." << endl;
		cout << "You gain 10 health." << endl;
		adjustHealth(10);
		cout << "10 Health restored. Current Health: " << getHealth() << ")" << endl;
		removeItem();
		return FOOD;
	case TOWNMAP:
		cout << endl;
		cout << "You open the Town Map..." << endl;
		return TOWNMAP;
		break;
	case ANTENNA:
		cout << endl;
		cout << "\"Hmm...\"" << endl;
		return ANTENNA;
		break;
	default:
		cout << "Error: useItem()" << endl;
	}
}