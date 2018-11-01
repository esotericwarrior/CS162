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
#include "character.hpp"

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
#endif