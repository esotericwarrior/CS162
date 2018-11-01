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
#include "character.hpp"

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
#endif