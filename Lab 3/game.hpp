/********************************************************************
** Program name: warGame                                            *
** Author: Tristan Santiago                                         *
** Date: January 28, 2018                                           *
** Description: This is the header file for the game Class.         *
********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

class Game
{
    private:
        // Store the dice for the players
        Die *dice1, *dice2;

        // Array to hold the result of each round for the 2 players. Max is 100 rounds
        // but I limit it to 90, to keep the charts from getting too off.
        int rounds[100][2];
        int numRounds;


    public:
        Game();
        void input();
        void play();
        void results();
        int displayMenu();
        void setRounds();
        ~Game();





};

#endif