/********************************************************************
** Program name: warGame                                            *
** Author: Tristan Santiago                                         *
** Date: January 28, 2018                                           *
** Description: main.cpp creates a game object and calls functions  *
** from the game class to run the entire program.                   *
********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "game.cpp"


//main method
int main()

{
    // Declare object for the class Game
    Game Game;

    // Call the methods using the object
    Game.displayMenu();
    Game.play();
    Game.results();


    // Exit program
    return 0;
}