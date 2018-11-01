/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 10, 2018													*
* Description: character.hpp is header file for the abstract/base class     *
* that defines all of the functions to be inherited by the other classes.   *
****************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

using namespace std;

class Character
{
	// Protected is like private to everything except children classes.
	//protected:
public:
	string name;                    // Name corresponds to character type in this case.
	string firstName;
	int armor;                      // Variable used for the armor value of each character.
	int strength;                   // Variable used for the strength value of each character.
	bool alive;                     // Each character starts the game alive.
	string type;					// Variable used to identify the character's type.
	string team;					// Variable used for character's team.
	string getTeam();				// Getter function for character's team.
	void setTeam(string);			// Setter function for character's team.
	int restore();					// Function used to restore winner's health.
	string getFirstName();
	//==================
	//public:
	// All virtual functions so each child class can use any function when necessary.

	virtual string getType()
	{
		return type;
	}

	virtual void setName(std::string n)
	{
		name = n;
	}

	virtual string getName()        // Function that returns the character's name.
	{
		return name;
	}

	virtual int getArmor()          // Function that returns the character's armor stat.
	{
		return armor;
	}

	virtual int getStrength()       // Function that returns the character's strength stat.
	{
		return strength;
	}

	virtual void setStrength(int s) // Auto subtracts from strength points when integer passed
	{
		strength -= s;
	}

	virtual bool isAlive()          // Function used to determine whether or not a character is alive.
	{
		return alive;
	}

	virtual void setAlive(bool t)   // Update the character's status to dead or not
	{
		alive = t;
	}

	virtual int attackRoll()        // Function used to determine an attack roll.
	{
		return 0;
	}

	virtual int defenseRoll()       // Function used to determine a defense roll.
	{
		return 0;
	}

	Character()             // Prototype
	{
		name = " ";
		strength = 0;
		armor = 0;
		team = " ";
	}

	~Character()            // Destructor
	{

	}
};

string Character::getTeam()
{
	return team;
}

void Character::setTeam(string a)
{
	team = a;
}

int Character::restore()
{
	return strength + (strength / 2);
}

//get the given name
string Character::getFirstName() {

	return firstName;
}


#endif

