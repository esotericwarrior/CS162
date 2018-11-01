/****************************************************************************
* Program Name: dieFight                                                    *
* Author: Tristan Santiago                                                  *
* Date: February 18, 2018                                                   *
* Description: functions.cpp contains the bulk of the program. It executes	*
* every function used in the program.										*
****************************************************************************/
#include <iostream>
#include <ctime>    // for rand
#include <string>
#include <unistd.h> // for sleep
#include "die.cpp"
#include "barbarian.cpp"
#include "vampire.cpp"
#include "blueMen.cpp"
#include "medusa.cpp"
#include "harryPotter.cpp"
#include "inputValidation.cpp"
#include "functions.hpp"

using namespace std;
int choice, valid;

// Constructor with Player choice defaults
Functions::Functions()
{
	player1 = player2 = NULL;
}

/***********************************************************************
*                         Functions::gameStart                         *
* This is where the bulk of the game is handled. Within this section,  *
* the player 1 and player 2 are initialized based on user choices, and *
* then they fight to the death.										   *
***********************************************************************/
void Functions::gameStart()
{
    int damage, choice, choice1, choice2, valid, validInput, again;
    bool finished = false;
    bool gameOver = false;
    bool characterSelect = false;
    do{
    while(gameOver == false)
    {
        displayMenu();
        cin >> choice;
        //cout <<"\033[2J\033[1;1H";
        valid = menu4Validation(choice);
        if(valid == 1)
        {
            displayRules();
        }   // if valid == 1
        else if (valid == 2)
        {
            displayDescriptions();
        }   // if valid == 2
        /***********************************************************************
        *                          CHARACTER SELECTION                         *
        ***********************************************************************/
        else if (valid == 3)
        {
            //--------------------- PLAYER 1 ----------------------//
            cout << "\nPlayer 1, please choose your class:" << endl;
            displayClasses();
            cin >> choice;
            valid = menu5Validation(choice);
                // If user chooses 1, create a vampire.
                if (valid == 1)
                {
                    cout << "Creating vampire for player 1." << endl;
                    player1 = new Vampire;                   // Vampire object instantiation
                }
                // If user chooses 2, create a barbarian.
                else if (valid == 2)
                {
                    cout << "Creating barbarian for player 1." << endl;
                    player1 = new Barbarian;               // Barbarian object instantiation
                }
                // If user chooses 3, create a blue men. Blue man? =/
                else if (valid == 3)
                {
                    cout << "Creating blue men for player 1." << endl;
                    player1 = new BlueMen;                   // Blue Men object instantiation
                }
                // If user chooses 4, create Medusa.
                else if (valid == 4)
                {
                    cout << "Creating Medusa for player 1." << endl;
                    player1 = new Medusa;
                }
                // If user chooses 5, create Harry Potter.
                else if (valid == 5)
                {
                    cout << "Creating Harry Potter for player 1." << endl;
                    player1 = new HarryPotter;
                }
            //--------------------- PLAYER 2 ----------------------//
            cout << "\nPlayer 2, please choose your class." << endl;
            displayClasses();
            choice = 0;
            cin >> choice;
            valid = menu5Validation(choice);
                // If user chooses 1, create a vampire.
                if (valid == 1)
                {
                    cout << "Creating vampire for player 2." << endl;
                    player2 = new Vampire;
                }
                // If user chooses 2, create a barbarian.
                else if (valid == 2)
                {
                    cout << "Creating barbarian for player 2." << endl;
                    player2 = new Barbarian;
                }
                // If user chooses 3, create a blue men. Blue man? =/
                else if (valid == 3)
                {
                    cout << "Creating blue men for player 2." << endl;
                    player2 = new BlueMen;
                }
                // If user chooses 4, create Medusa.
                else if (valid == 4)
                {
                    cout << "Creating Medusa for player 2." << endl;
                    player2 = new Medusa;
                }
                // If user chooses 5, create Harry Potter.
                else if (valid == 5)
                {
                    cout << "Creating Harry Potter for player 2." << endl;
                    player2 = new HarryPotter;
                }
            characterSelect = true;
            break;
        }   // if valid == 3
        else if (valid == 4)
        {
            gameOver = true;
            cout << "Exiting Program." << endl;
            exit(0);
        }   // if valid == 4
    }       // while gameOver loop
        /********************************************************************
        *                           GAME START                              *
        ********************************************************************/
        if(characterSelect == true)
        {
            int rounds = 1;
            cout << "\nCharacters have been selected." << endl;
            while(player1->isAlive() == true && player2->isAlive() == true)
            {
            if(rounds == 1)
            {
            cout << "Please press ENTER to continue..." << endl;
            cin.ignore(); // This was causing us to have to press ENTER twice because it was ignoring the first ENTER.
            cin.get();}
            else
            {
                cout << "Please press ENTER to continue..." << endl;
                cin.get();
            }
            cout << "Beginning round " << rounds << endl;
            rounds++;
            // --------------------- ROUND 1 ---------------------//
            // Player 1 attacks.
            cout << "Player 1, a " << player1->getName() << ", with " << player1->getArmor() << " armor, attacks first." << endl;
            damage = player1->attackRoll() - player2->defenseRoll() - player2->getArmor();
            if(damage > 0)
            {
                cout << "Player 2 strength points before: " << player2->getStrength() << endl;
                cout << "Damage done is " << damage << endl;
                player2->setStrength(damage);
                cout << "Player 2 strength points after: " << player2->getStrength() << endl;
            }
            else
            {
                cout << "No damage was done." << endl;
                cout << "Player 2 still has " << player2->getStrength() << " strength." << endl;
            }
            // Show Player 1's attack roll.
            // Player 2 defends.
            // Show Player 2's defense roll.
            // Calculate and display damage.
            if (player2->getStrength() <= 0)
            {
                player2->setAlive(false);
                cout << "Player 1 wins." << endl;
                break;	// Added a break here to prevent player 2 from rolling again.
            }
            else
            {
                //cout << "On to the next round!" << endl;
            }
            // Check to see if both characters are still alive.
            // If they are, continue to...
            // --------------------- ROUND 2 ---------------------//
            // Repeat until someone dies.
            // Declare winner.
            // Prompt user to play again.
            cout << "\n\n\t\t\tPlayer 2, a " << player2->getName() << ", with " << player2->getArmor() << " armor, attacks." << endl;
            damage = player2->attackRoll() - player1->defenseRoll() - player1->getArmor();
            if(damage > 0)
            {
                cout << "\t\t\tPlayer 1 strength points before: " << player1->getStrength() << endl;
                cout << "\t\t\tDamage done is " << damage << endl;
                player1->setStrength(damage);
                cout << "\t\t\tPlayer 1 strength points after: " << player1->getStrength() << endl;
            }
            else
            {
                //cout << "\n\t\t\tLOL!!! Critical MISS!!!!" << endl;
                cout << "No damage was done." << endl;
                //cout << "\t\t\t(ie. nothing happens...)" << endl;
                cout << "Player 1 still has " << player1->getStrength() << " strength." << endl;
            }
            if(rounds > 1 && player1->getStrength() > 0 && player2->getStrength() > 0)
            {
            // I'm picturing a sort of score screen here with damage dealt, strength, who's winning, etc...but I'm too lazy to write it now while I'm still testing... :P
            cout << "*******************************************" << endl;
            cout << "\t\tROUND SUMMARY" << endl;
            cout << "*******************************************" << endl;
            cout << "Player 1 Strength = " << player1->getStrength() << endl;
            cout << "Player 2 Strength = " << player2->getStrength() << endl;
            if(player1->getStrength() > player2->getStrength())
            {
                cout << "Player 1 is ahead." << endl;
            }
            else if (player1->getStrength() < player2->getStrength())
            {
                cout << "Player 2 is currently winning." << endl;
            }
            else
            {
                // Resisting the urge to cout "Looks like we've got ourselves a Mexican standoff here..."
                cout << "It's all tied up!" << endl;
            }
            }	// if(rounds > 1 && player1->getStrength() > 0 && player2->getStrength() > 0)
            if (player1->getStrength() <= 0)
            {
                player1->setAlive(false);
                cout << "\t\t\tPlayer 2 wins." << endl;
                break;	// Added break here to prevent the program from letting player 1 roll again.
            }
            else
            {
                cout << "\t\t\tOn to the next round!" << endl;
            }

            }	// while(player1->isAlive() == true && player2->isAlive() == true)
        }	// If character select == true

        // Clears screen and prompts user whether they'd like to play again or not.
        int again;
        //cout <<"\033[2J\033[1;1H";    // Commenting this out for now because it doesn't really give you a chance to see the results of the game.
        delete player1;
        delete player2;
        cout << "\nWould you like to play again?" << endl;
        cout << "--------------------------------\n";
        cout << "1. Play again." << endl;
        cout << "2. Quit." << endl;
        cin >> again;

        validInput = menuValidation(again);

        switch(validInput)
        {
        case 1:cout << "\nYou entered one. Playing again.";
        finished = true;
        break;

        case 2:cout << "\nYou entered two. Quitting.";
        finished = false;
        break;
        }
} while(finished != false);
        gameOver = true;
        exit(0);
}

/***********************************************************************
*                       Functions::DisplayMenu                         *
* This is simply the main menu.                                        *
***********************************************************************/
void Functions::displayMenu()
{
    //cout <<"\033[2J\033[1;1H";
    cout << "\t\t\t---------------------------------" << endl;
    cout << "\t\t\t\t*** MAIN MENU ***" << endl;
    cout << "\t\t\t---------------------------------" << endl;
    cout << "\t\t\tPlease select one of the following options: " << endl;
    cout << "\t\t\t1) View game rules." << endl;
    cout << "\t\t\t2) View class descriptions." << endl;
    cout << "\t\t\t3) Choose starting characters." << endl;
    cout << "\t\t\t4) Exit program." << endl;
}

/***********************************************************************
*                      Functions::displayRules                         *
* Displays the rules of the games.									   *
***********************************************************************/
void Functions::displayRules()
{
    cout <<"\033[2J\033[1;1H";                                     // Clears the screen
    cout << "\t\t\t---------------------------------" << endl;
    cout << "\t\t\t\t*** GAME RULES ***" << endl;
    cout << "\t\t\t---------------------------------" << endl;
    cout << "This program allows two players to select a unique class and battle each other." << endl;
    cout << "Each class starts off with its own unique armor and strength points." << endl;
    cout << "Players take turns rolling the appropriate number and type of dice for attack and defense." << endl;
    cout << "Player 1 goes first and attacks by rolling the dice, while Player 2 attempts to defend with a roll for defense." << endl;
    cout << "The defense roll is subtracted from the attack roll." << endl;
    cout << "The result will be the damage to the defender (Player 2)." << endl;
    cout << "Player 2 then attacks Player 1, while Player 1 defends." << endl;
    cout << "Damage is calculated and the round ends." << endl;
    cout << "If both players are still alive, the next round begins." << endl;
    cout << "These rounds continue until one of the characters' strength points reaches 0 or less.\n" << endl;
    cout << "Press ENTER to return to the main menu..." << endl;
    cin.ignore();
    cin.get();
}

/***********************************************************************
*                   Functions::displayDescriptions                     *
* This is just describing the character attributes and special attacks *
***********************************************************************/
void Functions::displayDescriptions()
{
    //--------------------- CLASS DESCRIPTIONS ---------------------//
    cout <<"\033[2J\033[1;1H";
    cout << "\t\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\t *** CLASS DESCRIPTIONS ***" << endl;
    cout << "\t\t\t--------------------------------------------" << endl;
    cout << "** VAMPIRE ** Suave, debonair, but vicious and surprisingly resilient!" << endl;
    cout << "Vampires can charm an opponent into not attacking. For a given attack there is a 50% chance that their" << endl;
    cout << "opponent does not actually attack them." << endl;
    cout << "Armor: 1, Strength Points: 18\n" << endl;
    cout << "** Barbarian ** Similar to Conan or Hercules from the movies. Big sword, big muscles, bare torso." << endl;
    cout << "Armor: 0, Strength Points: 12\n" << endl;
    cout << "** Blue Men ** These small men are fast and tough. They are hard to hit and can take some damage. " << endl;
    cout << "They can do a lot of damage when they crawl inside the armor or clothing of an opponent. " << endl;
    cout << "Blue Men are a swarm of individuals. For every 4 points of damage they lose one defense die." << endl;
    cout << "Armor: 3, Strength Points: 12\n" << endl;
    cout << "** Medusa ** Scrawny lady with snakes for hair. They help with fighting. Just don't look at her!" << endl;
    cout << "If Medusa rolls a 12 in attack, then the target has looked her in the eyes and is turned to stone." << endl;
    cout << "The Medusa then wins!" << endl;
    cout << "Armor: 3, Strength Points: 8\n " << endl;
    cout << "** Harry Potter ** Everyone knows who Harry Potter is, no description needed!" << endl;
    cout << "If Harry dies, he immediately recovers and his total strength becomes 20. " << endl;
    cout << "If he were to die again, then he is dead." << endl;
    cout << "Armor: 0, Strength Points: 10 (first life), 20 (second life)\n" << endl;
    cout << "Press ENTER to return to the main menu..." << endl;
    cin.ignore();
    cin.get();
}


// The menu of champs to be chosen
void Functions::displayClasses()
{
    //cout <<"\033[2J\033[1;1H";
    cout << "1) Vampire" << endl;
    cout << "2) Barbarian" << endl;
    cout << "3) Blue Men" << endl;
    cout << "4) Medusa" << endl;
    cout << "5) Harry Potter" << endl;
    cin.ignore();
}

// Deconstructor
Functions::~Functions()
{
}