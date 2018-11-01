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
#include "character.hpp"

using namespace std;

class HarryPotter : public Character
{
    public:
        void setStrength(int s);
        int attackRoll();                                               // Function used to determine an attack roll.
        int defenseRoll();                                              // Function used to determine a defense roll.
        HarryPotter();                                                  // Prototype
        ~HarryPotter();                                                 // Destructor
        Die HarryA1, HarryA2, HarryD1, HarryD2; // Harry Potter has 2d6 for attack and 2d6 for defense.
};
#endif