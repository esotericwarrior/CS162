// TristanFinal.cpp : Defines the entry point for the console application.
//
/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: The radio space. This is how the user can win. The
** user needs to guide the player to the antenna, and attach it to the
** radio to call for help.
*********************************************************************/
//#include "stdafx.h"
#include "Shelter.h"
#include "Menu.h"
#include <iostream>

using namespace std;

int main()
{
	if (welcomeScreen() == 1)		// Prompt player to start or exit game.
	{
		do {
			/************
			*	Shelter	*
			************/
			Shelter shelter;
			shelter.initializeBoard();
			shelter.printBoard();

			// Opening Dialogue
			cin.clear();
			getchar();
			cout << "\"When the fighting began, no one thought it would last for more than few weeks.\"" << endl;
			getchar();
			cout << "\"Yet many months later, the civil war still rages on.\"" << endl;
			getchar();
			cout << "\"The rebels eventually made their way to the city and we've been under siege for weeks now.\"" << endl;
			getchar();
			cout << "\"For so long, it seemed like it would never end.\"" << endl;
			getchar();
			cout << "\"Many people were beginning to lose hope until recently.\"" << endl;
			getchar();
			cout << "\"The government says they are close negotiating a cease fire.\"" << endl;
			getchar();
			cout << "\"With any luck, it should be happening any day now.\"" << endl;
			getchar();
			cout << "\"I've come too far to give up now.\"" << endl;
			getchar();
			cout << "\"I just need to survive a little bit longer.\"" << endl;
			//getchar();
			cout << "You are a civilian trapped in a city besieged by enemy rebel forces." << endl;
			getchar();
			cout << "Your goal is simple. Survive by any means necessary until the cease fire is issued, however long that may take." << endl;
			getchar();
			cout << "You awaken suddenly to the sound of distant gunfire." << endl;
			getchar();
			cout << "\"Just another bad dream.\" You think to yourself." << endl;
			getchar();
			cout << "You take a moment to examine your surroudings." << endl;
			getchar();
			cout << "You recognize this place." << endl;
			getchar();
			cout << "Until recently, you weren't able to reach this part of the city." << endl;
			getchar();
			cout << "But now that you can, you feel optimistic about surviving until the cease fire." << endl;
			getchar();
			cout << "\"There's gotta be something around her that's useful.\"" << endl;
			getchar();
			cout << "\"I better take a look around.\"" << endl;
			getchar();
			do {											// Prompt user input until player dies or game over occurs.
				shelter.playerChoose();
			} while (shelter.getGameState());

		} while (playAgain());		// Prompt user to play again or quit program.
	}

	return 0;
}
