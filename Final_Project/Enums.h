/*********************************************************************
** Program name: survive
** Author: Tristan Santiago
** Date: 3/20/2018
** Description: This file is dedicated only to ENUMS. Here are constants
** throughout the game that the user can find/visit/interact with.
*********************************************************************/

#pragma once
// Header file of the game_Enums namespace

#ifndef ENUMS_HPP
#define ENUMS_HPP

// https://stackoverflow.com/questions/8210935/creating-a-c-namespace-in-header-and-source-cpp
namespace game_Enums
{
	// Define types of spaces used in the game.
	enum spaceType { EMPTY, RUBBLE, DOOR, LADDER, RADIO, GOAL }; // Derived from Space class
	enum items { MAP, TOWNMAP, CROWBAR, FOOD, ANTENNA };
	enum Location { SHELTER, CHURCH, SCHOOL };
}

#endif // !ENUMS_HPP