/********************************************************************
** Program name: warGame                                            *
** Author: Tristan Santiago                                         *
** Date: January 28, 2018                                           *
** Description: die.cpp contains the default function definitions   *
** for the dice and gives a generic dice randomizer.                *
********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "die.hpp"

using namespace std;


    Die::Die(int n)
    {
        numSides = n;
        dieType = "a Normal"; // Default dice type 'normal'
    }

    // Virtual function will be overloaded in derived class
    int Die::roll()
    {
        // Returns a random number in the range 1 - numSides
        return rand() % numSides + 1;
    }

    // Implement accessor function - get Die Type
    std::string Die::getDieType()
    {
        return dieType;
    }
    // Implement accessor function - get Number of Sides
    int Die::getNumSides()
    {
        return numSides;
    }
// default destructor
Die::~Die()
{
}