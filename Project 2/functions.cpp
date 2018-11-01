/********************************************************************
* Program name: zooTyc                                              *
* Author: Tristan Santiago                                          *
* Date: February 4, 2018                                            *
* Description: functions.cpp contains some of the key functions     *
* used in the program: buyAnimal, used for buying an animal, the    *
* payoff function for each animal, and the random event functions.  *
********************************************************************/

#include <cstdlib>
#include <ctime>
#include <iostream>


void buyAnimal(double var1, double var2, double* result);

void buyAnimal(double var1, double var2, double* result)
{
    *result = var1 - var2;
}

void Animal::payoff(double var1, double var2, double* result)
{
    *result = var1 + var2;
}

int rando()
{
    int randoms = 4;
    // Returns a random number in the range 1 - 4
    return rand() % randoms + 1;
}

int randArray()
{
    int randomArr = 3;
    // Returns a random number in the range 1 - 3
    return rand() % randomArr + 1;
}

int randMoney()
{
    //range has to be 250 - 500, starting at 250, but capping at 500 when adding 250.
    int randomDolls = 250;
    // Returns a random number in the range 250-500
    return rand() % randomDolls + 250;
}
