/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 11, 2018													*
* Description: bluemen.hpp is header file for the blue men class that       *
* declares the functions the class will use in the game.                    *
****************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include <iostream>
#include <string>
#include "character.hpp"

using namespace std;

class BlueMen : public Character
{
    public:
        int attackRoll();        // Function used to determine an attack roll.
        int defenseRoll();       // Function used to determine a defense roll.
        BlueMen();             // Prototype
        ~BlueMen();            // Destructor
        Die BlueMenA1, BlueMenA2, BlueMenD1, BlueMenD2, BlueMenD3;
};
#endif