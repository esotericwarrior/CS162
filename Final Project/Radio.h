#pragma once
/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: The radio space. This is how the user can win. The
** user needs to guide the player to the antenna, and attach it to the
** radio to call for help.
*********************************************************************/
#ifndef RADIO_HPP
#define RADIO_HPP

#include "Space.h"

class Radio : public Space
{
private:

public:
	Radio();	// Default constructor.
	~Radio();	// Destructor.

	// Player specific functions
	void interact(Game*);

	// Map functions
	void printSpace();

};
#endif // !RADIO_HPP

Radio::Radio()
{
	type = RADIO;
}

Radio::~Radio()
{

}

void Radio::interact(Game* player)
{
	if (getType() == RADIO)
	{
		setType(GOAL);
		if (player->getInventorySelection() == ANTENNA)		// Check if the correct item is used.
		{
			cout << "With cautious optimism, you begin tuning the radio, praying for a signal." << endl;
			getchar();
			cout << "\"...BZZT...ZZTT...I repeat, the government has officially called for a cease fire!\"" << endl;
			getchar();
			cout << "You are suddenly overcome with joy as you hear the news." << endl;
			getchar();
			cout << "\"I made it. The war is finally over.\"" << endl;
			getchar();
			cout << "Congratulations! You survived the war!" << endl;

			player->removeItem();
			interactCheck = true;
			gameComplete = true;
		}
		else if (player->getInventorySelection() != ANTENNA)
 		{
 			cout << "You turn on the radio and begin searching through the stations, hoping for news." << endl;
 			getchar();
 			cout << "\"ZZZTT....BZZZTT....\" Nothing but static." << endl;
 			getchar();
 			//setType(GOAL);				// Set the type of the space to the goal.
 		}
		if (interactCheck)	// Check if player has interacted with this Space before.
		{
			cout << "The radio remains unchanged since you last used it." << endl;
		}
	//}
	// else if
	// {
	// 	cout << "You approach the broken radio with a renewed sense of hope." << endl;
	// 	getchar();
	// 	cout << "\"Perhaps if I had some sort of antenna, I could get a signal.\"" << endl;

	// 	if (player->getInventorySelection() == ANTENNA)		// Check if the correct item is used.
	// 	{
	// 		cout << "With cautious optimism, you begin tuning the radio, praying for a signal." << endl;
	// 		getchar();
	// 		cout << "\"...BZZT...ZZTT...I repeat, the government has officially called for a cease fire!\"" << endl;
	// 		getchar();
	// 		cout << "You are suddenly overcome with joy as you hear the news." << endl;
	// 		getchar();
	// 		cout << "\"I made it. The war is finally over.\"" << endl;
	// 		getchar();
	// 		cout << "Congratulations! You survived the war!" << endl;

	// 		player->removeItem();
	// 		interactCheck = true;
	// 		gameComplete = true;
	// 	}
		else
		{
			cout << "Not quite the effect you were hoping for." << endl;
		}
	}
}

void Radio::printSpace()
{
	// If the player occupies this spot...
	if (playerLocatedOn)
	{
		// Print this:
		cout << "|*=]";
	}
	else
	{
		cout << "|[=]";
	}
}