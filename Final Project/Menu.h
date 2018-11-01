#pragma once
/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: This is a class that creates generic menus. We pass 
** the data here in the form of strings so that the user can make a
** selection and then we return that after input validating.
*********************************************************************/
#include "inputValidation.h"
#include <string>
#include <iostream>
#include <string>
#include <limits>

#ifndef MENU_HPP
#define MENU_HPP

int welcomeScreen();
bool playAgain();
int menuChoice2(string, string, string);
int menuChoice3(string, string, string, string);
int menuChoice4(string, string, string, string, string);
int menuChoice5(string, string, string, string, string, string);
int menuChoice8(string, string, string, string, string, string, string, string, string);

#endif // MENU_HPP

//****************************************************************************************************
// Menu function which creates a welcome screen for the program.									 *
//****************************************************************************************************
int welcomeScreen()
{
	cout << string(41, '-') << endl;
	cout << "|" << "  \"In war, not everyone is a solider.\"  " << "|" << endl;
	cout << string(41, '-') << endl;

	int tempChoice = 0;

	cout << "1. Start Game." << endl;
	cout << "2. Quit" << endl;

	tempChoice = choiceValidation(2);

	switch (tempChoice) {
	case 1:
		//cout << "The goal of this game is to use items on the various statues located throughout the room to solve a puzzle." << endl;
		//cout << "You will only have 45 moves to finish the puzzle. A hidden space on the game board will heal you for an additional 10 moves." << endl;
		//cout << "Some dialogue will require you to press the 'Enter' key in order to display the next line of text like right now." << endl;
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//getchar();
		//cout << "Good luck and have fun." << endl;
		//getchar();
		return 1;
		break;
	case 2:
		cout << "Exiting program..." << endl;
		return 2;
		break;
	default:
		return 0;
	}
}

//****************************************************************************************************
// Menu function which controls whether the player would like to execute the program again.			 *
//****************************************************************************************************
bool playAgain()
{
	int tempChoice = 0;

	cout << "Would you like to play again?" << endl;
	cout << "1. Yes." << endl;
	cout << "2. No." << endl;

	tempChoice = choiceValidation(2);

	switch (tempChoice) {
	case 1:
		return true;
		break;
	case 2:
		cout << "Exiting program..." << endl;
		return false;
		break;
	default:
		return 0;
	}
}

int menuChoice2(string prompt, string option1, string option2)
{
	int tempChoice = 0;

	cout << prompt << endl;
	cout << "1. " << option1 << endl;
	cout << "2. " << option2 << endl;

	tempChoice = choiceValidation(2);
	return tempChoice;
}

int menuChoice3(string prompt, string option1, string option2, string option3)
{
	int tempChoice = 0;

	cout << prompt << endl;
	cout << "1. " << option1 << endl;
	cout << "2. " << option2 << endl;
	cout << "3. " << option3 << endl;

	tempChoice = choiceValidation(3);
	return tempChoice;
}

int menuChoice4(string prompt, string option1, string option2, string option3, string option4)
{
	int tempChoice = 0;

	cout << prompt << endl;
	cout << "1. " << option1 << endl;
	cout << "2. " << option2 << endl;
	cout << "3. " << option3 << endl;
	cout << "4. " << option4 << endl;

	tempChoice = choiceValidation(4);
	return tempChoice;
}

int menuChoice5(string prompt, string option1, string option2, string option3, string option4, string option5)
{
	int tempChoice = 0;

	cout << prompt << endl;
	cout << "1. " << option1 << endl;
	cout << "2. " << option2 << endl;
	cout << "3. " << option3 << endl;
	cout << "4. " << option4 << endl;
	cout << "5. " << option5 << endl;

	tempChoice = choiceValidation(5);
	return tempChoice;
}

int menuChoice8(string prompt, string option1, string option2, string option3, string option4, string option5, string option6, string option7, string option8)
{
	int tempChoice = 0;

	cout << prompt << endl;
	cout << "1. " << option1 << endl;
	cout << "2. " << option2 << endl;
	cout << "3. " << option3 << endl;
	cout << "4. " << option4 << endl;
	cout << "5. " << option5 << endl;
	cout << "6. " << option6 << endl;
	cout << "7. " << option7 << endl;
	cout << "8. " << option8 << endl;

	tempChoice = choiceValidation(8);
	return tempChoice;
}