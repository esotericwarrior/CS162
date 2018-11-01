/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: This is the game class. In here we create a default
** player which will ultimately be shared between all locations. We 
** also use this class to forward any data from the player class to 
** the various locations.
*********************************************************************/
#pragma once
#ifndef GAME_HPP
#define GAME_HPP
#include "Player.h"
#include "Space.h"
#include "Enums.h"

class Game
{
public:
	Player* player;						// Create a pointer to Player class.
	Game();
	~Game();
	void setDayTime();
	void resetTime();					// Reset time function during the night phase.
	int getTime();
	int getHealth();
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
	bool getTownMap();

};

Game::Game()
{
	player = new Player();
}

Game::~Game()
{
	delete player;
}

void Game::setDayTime()
{
	player->setDayTime();
}

int Game::getTime()
{
	return player->getTime();
}

void Game::resetTime()
{
	return player->resetTime();
}

int Game::getHealth()
{
	return player->getHealth();
}

void Game::adjustHealth(int adjust)
{
	player->adjustHealth(adjust);
}

void Game::adjustTime(int n)
{
	player->adjustTime(n);
}

void Game::printInventory()
{
	player->printInventory();
}

items Game::getInventorySelection()
{
	return player->getInventorySelection();
}

items Game::useItem(items targetItem)
{
	return player->useItem(player->getInventorySelection());
}

// Item Functions
bool Game::addItem(items newItem)
{
	return player->addItem(newItem);
}

void Game::removeItem()
{
	return player->removeItem();
}
bool Game::getTownMap()
{
	if (TOWNMAP)
	{
		//cout << "\It's late. I better get some rest.\"" << endl;
		return false;
	}
	else
	{
		//cout << "Town Map" << endl;
		return true;
	}
	
}


#endif // !GAME_HPP
