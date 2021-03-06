/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 12, 2018                                                   *
* Description: medusa.cpp is contains all the function definitions for the  *
* Medusa class, as well as the dice logic used for attacking and defending. *
****************************************************************************/
#include "medusa.hpp"
#include <string>

Medusa::Medusa() : MedusaA1(6), MedusaA2(6), MedusaD1(6)
{
    name = "Medusa";
    armor = 3;
    strength = 8;
    alive = true;
}


 // Function used to determine an attack roll.
int Medusa::attackRoll()
{
    int MedusaRoll1, MedusaRoll2;
    sleep(1);
    MedusaRoll1 = MedusaA1.roll();
    sleep(1);
    MedusaRoll2 = MedusaA2.roll();

    cout << "\t\tAttack Roll 1: " << MedusaRoll1 << endl;
    cout << "\t\tAttack Roll 2: " << MedusaRoll2 << endl;

    // cout << "\n\n\nTesting medusa stare, setting both rolls to 6\n\n\n" << endl;
    // MedusaRoll1 = 6;
    // MedusaRoll2 = 6;

    // If double 6's...
    if(MedusaRoll1 + MedusaRoll2 == 12)
    {
        // ... then make an attack of 9999 which can only be defeated by vampire's charm of 9999 defense
        cout << "Medusa rolls a 12!!! This turns the other player into stone, killing them instantly." << endl;
        MedusaRoll1 = 9999;
        return MedusaRoll1;
    }
    // Otherwise, return whatever Medusa rolled.
    else
    {
    return MedusaRoll1 + MedusaRoll2;
    }
}

// Function used to determine a defense roll.
int Medusa::defenseRoll()
{
    int MedusaRoll1;
    sleep(1);
    MedusaRoll1 = MedusaD1.roll();

    cout << "\t\t***** Medusa Defensive Roll *****" << endl;
    cout << "\t\tDefense Roll 1: " << MedusaRoll1 << endl;
    return MedusaRoll1;
}


// Destructor
Medusa::~Medusa()
{
}