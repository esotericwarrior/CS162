/********************************************************************
** Program name: warGame                                            *
** Author: Tristan Santiago                                         *
** Date: January 28 2018                                            *
** Description: lodDie.cpp contains everything but the the type and *
** chance multiplier is being inherited from 'Die.'                 *
********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "loadDie.hpp"

    // Getting sides from Die
    LoadedDie::LoadedDie(int n)
        : Die(n)
    {
        turn = 1;
        dieType = "Loaded";
    }

    // Unique Loaded die roll
    int LoadedDie::roll()
    {
        // Every odd turn return the numSides, (biased) and in even turn number usual roll from Die class.
        int val = turn == 1 ? numSides : Die::roll();
        turn = (turn + 1) % 2;
        return val;
    }

// Default deconstructor
LoadedDie::~LoadedDie()
{
}