/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 12, 2018                                                   *
* Description: medusa.hpp is header file for the Medusa class that          *
* declares the functions the class will use in the game.                    *
****************************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <iostream>
#include <string>
#include "character.hpp"

using namespace std;

class Medusa : public Character
{
    public:
        int attackRoll();                   // Function used to determine an attack roll.
        int defenseRoll();                  // Function used to determine a defense roll.
        Medusa();                           // Prototype
        ~Medusa();                          // Destructor
        Die MedusaA1, MedusaA2, MedusaD1;   // Medusa has 2d6 for attack and 1d6 for defense.
};
#endif