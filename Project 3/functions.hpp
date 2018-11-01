/****************************************************************************
* Program Name: dieFight                                                    *
* Author: Tristan Santiago                                                  *
* Date: February 18, 2018                                                   *
* Description: This is the header file for functions.cpp.					*
****************************************************************************/
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>

using namespace std;

class Functions
{
    public:
        Character *player1, *player2;

        Functions();
        void displayMenu();
        void displayRules();
        void displayDescriptions();
        void displayClasses();
        void gameStart();
        ~Functions();
};

#endif