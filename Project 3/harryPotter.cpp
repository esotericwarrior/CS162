/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 11, 2018                                                   *
* Description: HarryPotter.cpp is contains all the function definitions for *
* the HarryPotter class, as well as the dice logic used for attacking and   *
* defending.                                                                *
****************************************************************************/
#include "harryPotter.hpp"
#include <string>
using namespace std;

HarryPotter::HarryPotter() : HarryA1(6), HarryA2(6), HarryD1(6), HarryD2(6)
{
    name = "Harry Potter";
    armor = 0;
    alive = true;
    strength = 10;
}

 // Function used to determine an attack roll.
int HarryPotter::attackRoll()
{
    int harryRoll1, harryRoll2;
    sleep(1);
    harryRoll1 = HarryA1.roll();
    sleep(1);
    harryRoll2 = HarryA2.roll();

    cout << "\t\tAttack Roll 1: " << harryRoll1 << endl;
    cout << "\t\tAttack Roll 2: " << harryRoll2 << endl;
    return harryRoll1 + harryRoll2;
}

// Function used to determine a defense roll.
int HarryPotter::defenseRoll()
{
    int harryRoll1, harryRoll2;
    sleep(1);
    harryRoll1 = HarryD1.roll();
    sleep(1);
    harryRoll2 = HarryD2.roll();
    cout << "\t\t***** Harry Potter Defensive Roll *****" << endl;

    cout << "\t\tDefense Roll 1: " << harryRoll1 << endl;
    cout << "\t\tDefense Roll 2: " << harryRoll2 << endl;
    return harryRoll1 + harryRoll2;
}

void HarryPotter::setStrength(int s)
{
    int lives = 1;
    strength -= s; // Update health
    if(getStrength() <= 0 && lives == 1) // This will respawn HP 1 time
    {
        cout << "\t\tWhat's this? 'The boy who lived after all....'" << endl;
        cout << "\t\tHarry's resurrected and now has 20 strength!" << endl;
        strength = 20;
        lives++;
    }
    else if(getStrength() <= 0 && lives == 2) // If already respawned, then he dies
    {
        //cout << "\t\t\t\tmarking dead" << endl;
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