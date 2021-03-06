/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 11, 2018													*
* Description: vampire.hpp is header file for the vampire class that        *
* declares the functions the class will use in the game.                    *
****************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <iostream>
#include <string>
#include "Character.h"
#include <ctime>    // for rand
#include "Die.h"

using namespace std;

class Vampire : public Character
{
public:
	int attackRoll();       // Function used to determine an attack roll.
	int defenseRoll();      // Function used to determine a defense roll.
	int charm();
	Vampire();              // Prototype
	~Vampire();             // Destructor
	Die VampA1, VampD1;
};
/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 11, 2018                                                   *
* Description: vampire.cpp is contains all the function definitions for the *
* vampire class, as well as the dice logic used for attacking and defending.*
****************************************************************************/
Vampire::Vampire() : VampA1(12), VampD1(6)
{
	name = "Vampire";
	armor = 1;
	strength = 18;
	alive = true;
	type = "Vampire";
}

// Function to 'flip a coin' between choice 1 or 2 that's random.
int Vampire::charm()
{
	// Bases random off system time.
	srand(time(NULL));
	int chance = 2;
	// Returns a random number in the range 1 or 2, for 50% chance
	return rand() % chance + 1;
}

// Function used to determine an attack roll.
int Vampire::attackRoll()
{
	int vampRoll;
	//sleep(1);
	vampRoll = VampA1.roll();

	cout << "\t\tAttack Roll 1: " << vampRoll << endl;
	return vampRoll;
}

// Function used to determine a defense roll.
int Vampire::defenseRoll()
{
	cout << "\t\t***** Vampire Defensive Roll *****" << endl;
	int vampRoll;
	// If charm is 2, then charm worked
	if (charm() == 2)
	{
		cout << "\t\tVampire has charmed the pants off it's victim. Attack fails." << endl;
		// The high defense blocks all moves, including Medusa's glare
		vampRoll = 9999;
	}
	else
	{
		//sleep(1);
		vampRoll = VampD1.roll();
		cout << "\t\tDefense Roll 1: " << vampRoll << endl;
	}
	return vampRoll;
}

// Destructor
Vampire::~Vampire()
{
	// Leave blank?
}
#endif