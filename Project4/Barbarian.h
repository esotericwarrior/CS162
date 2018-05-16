/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 11, 2018													*
* Description: barbarian.hpp is header file for the barbarian class that    *
* declares the functions the class will use in the game.                    *
****************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include <iostream>
#include <string>
#include "Character.h"
#include "Die.h"

using namespace std;

class Barbarian : public Character
{
public:
	int attackRoll();                   // Function used to determine an attack roll.
	int defenseRoll();                  // Function used to determine a defense roll.
	Barbarian();                        // Prototype
	~Barbarian();                       // Destructor
	Die BarbA1, BarbA2, BarbD1, BarbD2; // The barbarian has 2d6 for attack and 2d6 for defense.
};

/****************************************************************************
* Program Name: dieFight                                                    *
* Author: Tristan Santiago													*
* Date: February 11, 2018                                                   *
* Description: barbarian.cpp is contains all the function definitions for   *
* the barbarian class, as well as the dice logic used for attacking and     *
* defending.                                                                *
****************************************************************************/
Barbarian::Barbarian() : BarbA1(6), BarbA2(6), BarbD1(6), BarbD2(6)
{
	name = "Barbarian";
	armor = 0;
	strength = 12;
	alive = true;
	type = "Barbarian";
}

// string Barbarian::getType()
// {
//     type = "Barbarian";
//     return type;
// }

// Function used to determine an attack roll.
int Barbarian::attackRoll()
{
	int barbRoll1, barbRoll2;
	//sleep(1);
	barbRoll1 = BarbA1.roll();
	//sleep(1);
	barbRoll2 = BarbA2.roll();

	cout << "\t\tAttack Roll 1: " << barbRoll1 << endl;
	cout << "\t\tAttack Roll 2: " << barbRoll2 << endl;
	return barbRoll1 + barbRoll2;
}

// Function used to determine a defense roll.
int Barbarian::defenseRoll()
{
	int barbRoll1, barbRoll2;
	cout << "\t\t***** Barbarian Defensive Roll *****" << endl;
	//sleep(1);
	barbRoll1 = BarbD1.roll();
	//sleep(1);
	barbRoll2 = BarbD2.roll();

	cout << "\t\tDefense Roll 1: " << barbRoll1 << endl;
	cout << "\t\tDefense Roll 2: " << barbRoll2 << endl;
	return barbRoll1 + barbRoll2;
}


// Destructor
Barbarian::~Barbarian()
{
}
#endif