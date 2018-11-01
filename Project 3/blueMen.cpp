/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 11, 2018                                                   *
* Description: BlueMen.cpp is contains all the function definitions for the *
* BlueMen class, as well as the dice logic used for attacking and defending.*
****************************************************************************/
#include "blueMen.hpp"
#include <string>

BlueMen::BlueMen() : BlueMenA1(10), BlueMenA2(10), BlueMenD1(6), BlueMenD2(6), BlueMenD3(6)
{
    name = "Blue Men";
    armor = 3;
    strength = 12;
    alive = true;
}


 // Function used to determine an attack roll.
int BlueMen::attackRoll()
{
    int BlueMenRoll1, BlueMenRoll2;
    sleep(1);
    BlueMenRoll1 = BlueMenA1.roll();
    sleep(1);
    BlueMenRoll2 = BlueMenA2.roll();

    cout << "\t\tAttack Roll 1: " << BlueMenRoll1 << endl;
    cout << "\t\tAttack Roll 2: " << BlueMenRoll2 << endl;
    return BlueMenRoll1 + BlueMenRoll2;
}

// Function used to determine a defense roll.
int BlueMen::defenseRoll()
{
    int BlueMenRoll1, BlueMenRoll2, BlueMenRoll3;
    // If strength is above 8, then roll 3 defensive die.
    cout << "\t\t***** Blue Men Defensive Roll *****" << endl;
    if (getStrength() > 8)
    {
        sleep(1);
        BlueMenRoll1 = BlueMenD1.roll();
        sleep(1);
        BlueMenRoll2 = BlueMenD2.roll();
        sleep(1);
        BlueMenRoll3 = BlueMenD3.roll();

        cout << "\t\tDefense Roll 1: " << BlueMenRoll1 << endl;
        cout << "\t\tDefense Roll 2: " << BlueMenRoll2 << endl;
        cout << "\t\tDefense Roll 3: " << BlueMenRoll3 << endl;
        return BlueMenRoll1 + BlueMenRoll2 + BlueMenRoll3;
    }
    // If strength is between 4 and 9, roll only 2 defensive die.
    else if(getStrength() > 4 && getStrength() <= 8)
    {
        sleep(1);
        BlueMenRoll1 = BlueMenD1.roll();
        sleep(1);
        BlueMenRoll2 = BlueMenD2.roll();

        cout << "\t\tA blue men has been killed! One less to defensive dice." << endl;
        cout << "\t\tDefense Roll 1: " << BlueMenRoll1 << endl;
        cout << "\t\tDefense Roll 2: " << BlueMenRoll2 << endl;
        return BlueMenRoll1 + BlueMenRoll2;
    }
    // If strength is below 5, then only roll 1 defensive die.
    else
    {
        sleep(1);
        BlueMenRoll1 = BlueMenD1.roll();

        cout << "\t\tOnly one blue men defensive dice left to go!" << endl;
        cout << "\t\tDefense Roll 1: " << BlueMenRoll1 << endl;
        return BlueMenRoll1;
    }

}


// Destructor
BlueMen::~BlueMen()
{
}