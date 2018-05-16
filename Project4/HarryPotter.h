/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 11, 2018													*
* Description: harryPotter.hpp is header file for the Harry Potter class    *
* that declares the functions the class will use in the game.               *
****************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

class HarryPotter : public Character
{
private:
	int lives;														// Variable used to track Harry's special ability.
public:
	void setStrength(int s);
	int attackRoll();                                               // Function used to determine an attack roll.
	int defenseRoll();                                              // Function used to determine a defense roll.
	HarryPotter();                                                  // Prototype
	~HarryPotter();                                                 // Destructor
	Die HarryA1, HarryA2, HarryD1, HarryD2; // Harry Potter has 2d6 for attack and 2d6 for defense.
};

/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 11, 2018                                                   *
* Description: HarryPotter.cpp is contains all the function definitions for *
* the HarryPotter class, as well as the dice logic used for attacking and   *
* defending.                                                                *
****************************************************************************/
HarryPotter::HarryPotter() : HarryA1(6), HarryA2(6), HarryD1(6), HarryD2(6)
{
	name = "Harry Potter";
	armor = 0;
	alive = true;
	lives = 0;
	strength = 10;
	type = "Harry Potter";
}

// Function used to determine an attack roll.
int HarryPotter::attackRoll()
{
	int harryRoll1, harryRoll2;
	//sleep(1);
	harryRoll1 = HarryA1.roll();
	//sleep(1);
	harryRoll2 = HarryA2.roll();

	cout << "\t\tAttack Roll 1: " << harryRoll1 << endl;
	cout << "\t\tAttack Roll 2: " << harryRoll2 << endl;
	return harryRoll1 + harryRoll2;
}

// Function used to determine a defense roll.
int HarryPotter::defenseRoll()
{
	int harryRoll1, harryRoll2;
	//sleep(1);
	harryRoll1 = HarryD1.roll();
	//sleep(1);
	harryRoll2 = HarryD2.roll();
	cout << "\t\t***** Harry Potter Defensive Roll *****" << endl;

	cout << "\t\tDefense Roll 1: " << harryRoll1 << endl;
	cout << "\t\tDefense Roll 2: " << harryRoll2 << endl;
	return harryRoll1 + harryRoll2;
}

void HarryPotter::setStrength(int s)
{
	strength -= s; // Update health

	if ((getStrength() <= 0) && (lives == 1)) // This will respawn HP 1 time
	{
		cout << "\t\tWhat's this? 'The boy who lived after all....'" << endl;
		cout << "\t\tHarry's resurrected and now has 20 strength!" << endl;
		strength = 20;
		lives++;
	}
	else if ((getStrength() <= 0) && (lives == 1)) // If already respawned, then he dies
	{
		//cout << "\t\t\t\tmarking dead" << endl;
		strength = 0;
		alive = false;
	}
	else
	{
		//cout << "\t\t\t\tUpdating strength like normal" << endl;
	}
}

// Destructor
HarryPotter::~HarryPotter()
{
}
#endif