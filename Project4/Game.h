/****************************************************************************
* Program Name: dieFight                                                    *
* Author: Tristan Santiago                                                  *
* Date: February 18, 2018                                                   *
* Description: Game.h basically replaces Functions.h and takes over for     *
* running the game, updated from an earlier version in Project 2.           *
****************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include <stdio.h>
#include "Character.h"
#include "Medusa.h"
#include "Barbarian.h"
#include "Vampire.h"
#include "BlueMen.h"
#include "HarryPotter.h"
#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

class Game
{
protected:
	// Instantiate the pointers to both player's characters.
	Character * first;					// Refers to the first player's current character for simplicity.
	Character *second;					// Refers to the second player's current character for simplicity.

public:
	Game();								// Default Constructor.
	Game(Character *, Character *);		// Parameterized Constructor.
	~Game();							// Destructor.
	Character * fight();				// Combat function.
};
// Default Constructor that initializes first and second to NULL.
Game::Game()
{
	first = NULL;
	second = NULL;
}

/************************************************************************************
*						Game::Game(Character *a, Character *b)						*
* This is a parameterized constructor for Game, which takes two Character pointer	*
*parameters.																		*
************************************************************************************/
Game::Game(Character *a, Character *b)
{
	first = a;
	second = b;
}

/************************************************************************************
*									Destructor										*
* The Destructor deletes the pointers to the characters to avoid memory leaks.		*
************************************************************************************/
Game::~Game()
{
	first = NULL;
	second = NULL;
}

/************************************************************************************
*								Character * Game::fight()							*
* This function handles the tournament's combat and continues until all of the		*
* characters from one team have been eliminated.									*
************************************************************************************/
Character * Game::fight()
{
	int damage1, damage2, health1, health2, rounds;
	damage1 = 0;	// Initialize player 1's damage to 0.
	damage2 = 0;	// Initialize player 2's damage to 0.
	health1 = 0;	// Initialize player 1's health to 0.
	health2 = 0;	// Initialize player 2's health to 0.
	rounds = 1;		// Initialize rounds to 1.
	/********************************************************************
	*                           GAME START                              *
	********************************************************************/
	do {
		//cout << "\nCharacters have been selected." << endl;
		cout << "\nLet the tournament begin!" << endl;
		while (first->isAlive() == true && second->isAlive() == true)
		{
			if (rounds == 1)
			{
				cout << "Please press ENTER to continue..." << endl;
				//cin.ignore(); // This was causing us to have to press ENTER twice because it was ignoring the first ENTER.
				getchar();
				//cin.get();
			}
			else
			{
				cout << "Please press ENTER to continue..." << endl;
				//cin.get();
				getchar();
			}
			cout << "Beginning round " << rounds << endl;
			rounds++;
			// --------------------- ROUND 1 ---------------------//
			// Player 1 attacks.
			cout << "Player 1's character, " << first->getName() << ", with " << first->getArmor() << " armor, attacks first." << endl;
			damage1 = first->attackRoll() - second->defenseRoll() - second->getArmor();
			if (damage1 > 0)
			{
				cout << "Player 2 strength points before: " << second->getStrength() << endl;
				cout << "Damage done is " << damage1 << endl;
				second->setStrength(damage1);
				cout << "Player 2 strength points after: " << second->getStrength() << endl;
			}
			else
			{
				cout << "No damage was done." << endl;
				cout << "Player 2 still has " << second->getStrength() << " strength." << endl;
			}
			// Show Player 1's attack roll.
			// Player 2 defends.
			// Show Player 2's defense roll.
			// Calculate and display damage.
			if (second->getStrength() <= 0)
			{
				return first;
			}
			else
			{
				//cout << "On to the next round!" << endl;
			}
			// Check to see if both characters are still alive.
			// If they are, continue to...
			// --------------------- ROUND 2 ---------------------//
			// Repeat until someone dies.
			// Declare winner.
			// Prompt user to play again.
			cout << "Player 2's character, " << second->getName() << ", with " << second->getArmor() << " armor, attacks." << endl;
			damage2 = second->attackRoll() - first->defenseRoll() - first->getArmor();
			if (damage2 > 0)
			{
				cout << "\t\t\tPlayer 1 strength points before: " << first->getStrength() << endl;
				cout << "\t\t\tDamage done is " << damage2 << endl;
				first->setStrength(damage2);
				cout << "\t\t\tPlayer 1 strength points after: " << first->getStrength() << endl;
			}
			else
			{
				//cout << "\n\t\t\tLOL!!! Critical MISS!!!!" << endl;
				cout << "No damage was done." << endl;
				//cout << "\t\t\t(ie. nothing happens...)" << endl;
				cout << "Player 1 still has " << first->getStrength() << " strength." << endl;
			}
			if (rounds > 1 && first->getStrength() > 0 && second->getStrength() > 0)
			{
				// I'm picturing a sort of score screen here with damage dealt, strength, who's winning, etc...but I'm too lazy to write it now while I'm still testing... :P
				cout << "*******************************************" << endl;
				cout << "\t\tROUND SUMMARY" << endl;
				cout << "*******************************************" << endl;
				cout << "Player 1 Strength = " << first->getStrength() << endl;
				cout << "Player 2 Strength = " << second->getStrength() << endl;
				if (first->getStrength() > second->getStrength())
				{
					cout << "Player 1 is ahead." << endl;
				}
				else if (first->getStrength() < second->getStrength())
				{
					cout << "Player 2 is currently winning." << endl;
				}
				else
				{
					// Resisting the urge to cout "Looks like we've got ourselves a Mexican standoff here..."
					cout << "It's all tied up!" << endl;
				}
			}	// if(rounds > 1 && player1->getStrength() > 0 && player2->getStrength() > 0)
			if (first->getStrength() <= 0)
			{
				return second;
			}
			else
			{
				cout << "\t\t\tOn to the next round!" << endl;
			}

		}
	} while ((health1 > 0) && (health2 > 0));
	return NULL;
}

#endif