/************************************************************************
** Program name: dieFight												*
** Author: Tristan Santiago												*
** Date: February 11, 2018												*
** Description: This is the base dice cpp file. Here we create defaults	*
** for the dice and gives a generic dice randomizer.					*
************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "die.hpp"

using namespace std;


    Die::Die(int n)
    {
        numSides = n;
    }

    // Virtual function will be overloaded in derived class
    int Die::roll()
    {
        // Bases random off system time.
        srand(time(NULL));
        // Returns a random number in the range 1 - numSides
        return rand() % numSides + 1;
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