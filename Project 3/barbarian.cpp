/****************************************************************************
* Program Name: dieFight                                                    *
* Author: Tristan Santiago													*
* Date: February 11, 2018                                                   *
* Description: barbarian.cpp is contains all the function definitions for   *
* the barbarian class, as well as the dice logic used for attacking and     *
* defending.                                                                *
****************************************************************************/
#include "barbarian.hpp"
#include <string>

Barbarian::Barbarian() : BarbA1(6), BarbA2(6), BarbD1(6), BarbD2(6)
{
    name = "Barbarian";
    armor = 0;
    strength = 12;
    alive = true;
}


 // Function used to determine an attack roll.
int Barbarian::attackRoll()
{
    int barbRoll1, barbRoll2;
    sleep(1);
    barbRoll1 = BarbA1.roll();
    sleep(1);
    barbRoll2 = BarbA2.roll();

    cout << "\t\tAttack Roll 1: " << barbRoll1<< endl;
    cout << "\t\tAttack Roll 2: " << barbRoll2 << endl;
    return barbRoll1 + barbRoll2;
}

// Function used to determine a defense roll.
int Barbarian::defenseRoll()
{
    int barbRoll1, barbRoll2;
    cout << "\t\t***** Barbarian Defensive Roll *****" << endl;
    sleep(1);
    barbRoll1 = BarbD1.roll();
    sleep(1);
    barbRoll2 = BarbD2.roll();

    cout << "\t\tDefense Roll 1: " << barbRoll1 << endl;
    cout << "\t\tDefense Roll 2: " << barbRoll2 << endl;
    return barbRoll1 + barbRoll2;
}


// Destructor
Barbarian::~Barbarian()
{
}