/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 11, 2018													*
* Description: Tournament.hpp is header file for tournament functions.		*
****************************************************************************/
#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include <iostream>
#include "Losers.h"
#include "Queue.h"
#include "Game.h"
//#include "Functions.h"
#include "Character.h"
#include "Medusa.h"
#include "Barbarian.h"
#include "Vampire.h"
#include "BlueMen.h"
#include "HarryPotter.h"

class Tournament {
protected:
	Losers loserList;       //Stack to hold the losers from both teams; displayed first-in, last-out
	Queue A;               //Queue to hold one team
	Queue B;               //Queue to hold other team
	int winsA;              //# of wins for Team A
	int winsB;              //# of wins for Team B
	int playersA;
	int playersB;

public:
	Tournament();           //create a Tournament
							//~Tournament();

	void setTeamA(string, string);
	void setTeamB(string, string);

	int startRound(int);

	void displayLosers(int);              //diplay a list of losers
	void displayWinners();

	int getWinsA();                    //get winning points of Team A
	int getWinsB();                    //get winning points of Team B

	void getTeamA();                   //display list of Lineup Team A
	void getTeamB();                   //display list of Lineup Team B
	bool TeamA();
	bool TeamB();
};

//constructor
Tournament::Tournament() {

	winsA = 0;
	winsB = 0;

}

////destructor
//Tournament::~Tournament(){
//   
//    delete it;
//}

//add nodes to Lineup Team A
void Tournament::setTeamA(string a, string b)
{
	string team = "A";
	Character *it;

	if (a == "1")
	{
		it = new Medusa;
		it->setTeam(team);
		it->setName(b);
	}
	else if (a == "2")
	{
		it = new Barbarian;
		it->setTeam(team);
		it->setName(b);
	}
	else if (a == "3")
	{
		it = new Vampire;
		it->setTeam(team);
		it->setName(b);
	}
	else if (a == "4")
	{
		it = new BlueMen;
		it->setTeam(team);
		it->setName(b);
	}
	else if (a == "5")
	{
		it = new HarryPotter;
		it->setTeam(team);
		it->setName(b);
	}
	else
		it = NULL;

	A.addBack(it);

	//delete it;
	it = NULL;                      //or delete it???
}

//add nodes to Lineup Team B
void Tournament::setTeamB(string a, string b)
{
	string team = "B";

	Character *it2;

	if (a == "1") {
		it2 = new Medusa;
		it2->setTeam(team);
		it2->setName(b);
	}
	else if (a == "2") {
		it2 = new Barbarian;
		it2->setTeam(team);
		it2->setName(b);
	}
	else if (a == "3") {
		it2 = new Vampire;
		it2->setTeam(team);
		it2->setName(b);
	}
	else if (a == "4") {
		it2 = new BlueMen;
		it2->setTeam(team);
		it2->setName(b);
	}
	else if (a == "5") {
		it2 = new HarryPotter;
		it2->setTeam(team);
		it2->setName(b);
	}
	else
		it2 = NULL;

	B.addBack(it2);

	it2 = NULL;
}

//start a fight between two creatures
int Tournament::startRound(int a)
{
	Character *first;
	Character *second;
	Character *winner;
	int rounds = 1;
	int losers = 0;

	playersA = a;
	playersB = a;

	do {
		cout << "Round: " << rounds << endl;

		first = A.removeQ();
		second = B.removeQ();


		Game round(first, second);   //create a Game Round w/ these two creatures
		//Functions round(first, second);

		winner = round.fight();      //return pointer to winning Character

		if (winner == first)
		{
			A.addBack(first);          //PROBLEM
			first->restore();       //restore the winner's power
			winsA = winsA + 1;      //incrememnt Team A's wins
			loserList.add(second);  //PROBLEM
			playersB--;
			losers++;
		}

		if (winner == second) {
			B.addBack(second);          //PROBLEM
			second->restore();      //restore the winner's power
			winsB = winsB + 1;      //increment Team B's wins
			loserList.add(first);   //PROBLEM
			playersA--;
			losers++;
		}
		rounds++;
		cout << "\n";
	} while (!TeamA() && !TeamB());

	if (TeamA()) {
		cout << "The tournament is over. Team A lost!" << endl;
	}
	else if (TeamB()) {
		cout << "The tournament is over. Team B lost!" << endl;
	}
	return losers;

	first = NULL;
	second = NULL;
	winner = NULL;
}

//diplay a list of losers
void Tournament::displayLosers(int a)
{
	//Character *y;
	Character *y = nullptr;
	for (int i = 0; i < a; i++)
	{
		y = loserList.remove();
		if (y == NULL)
		{
			cout << "The most recent losers were reborn to take their medals.";
			return;
		}
		cout << "Team " << y->getTeam() << " " << y->getName() << " the " << y->getType() << endl;
	}
	delete y;
}

//get winning points of Team A
int Tournament::getWinsA() {

	return winsA;
}

//get winning points of Team B
int Tournament::getWinsB() {

	return winsB;
}

//display list of Lineup Team A
void Tournament::getTeamA()
{
	//A.printQ();
	A.printQueue();
}

//display list of Lineup Team B
void Tournament::getTeamB()
{
	//B.printQ();
	B.printQueue();
}

//return true if Team A is empty
bool Tournament::TeamA() {

	return A.isEmpty();
}

//return true if Team B is empty
bool Tournament::TeamB() {

	return B.isEmpty();
}

void Tournament::displayWinners()
{
	Character *a;
	Character *b;

	//if Team A has survivors (aka the winner)
	if (!TeamA()) {
		if (playersA > 2) {                  //Get the two with the highest scoring points
			A.print1();             //print the last one in the line-up (last to be added)
			for (int i = 0; i < playersA - 3; i++) {
				A.removeQ();
			}
			a = A.removeQ();        //3rd place
			b = A.removeQ();        //2nd place
			cout << "Second Place: Team " << b->getTeam() << " " << b->getName() << " the " << b->getType() << endl;
			cout << "Third Place: Team " << a->getTeam() << " " << a->getName() << " the " << a->getType() << endl;
		}

		else if (playersA == 2) {      //Get the two with the highest scoring points
			A.print1();             //print the winner
			a = A.removeQ();        //2nd place winner
			cout << "Second Place: Team " << a->getTeam() << " " << a->getName() << " the " << a->getType() << endl;
			b = loserList.remove();
			cout << "     The following loser is reborn to take its medal:" << endl;
			cout << "Third Place: Team " << b->getTeam() << " " << b->getName() << " the " << b->getType() << endl;
		}
		else if (playersA == 1) {          //Get two with highest scoring points
			A.print1();
			a = loserList.remove();
			cout << "     The following loser is reborn to take its medal:" << endl;
			cout << "Second Place: Team " << a->getTeam() << " " << a->getName() << " the " << a->getType() << endl;
			b = loserList.remove();
			if (b == NULL)
				return;
			cout << "     The following loser is reborn to take its medal:" << endl;
			cout << "Third Place: Team " << b->getTeam() << " " << b->getName() << " the " << b->getType() << endl;
		}
	}

	//if Team B has survivors (aka the winner)
	else if (!TeamB()) {                   //Team B still has survivors, but how many?
		if (playersB > 2) {                  //Get the two with the highest scoring points
			for (int i = 0; i < playersB - 3; i++) {
				B.removeQ();
			}
			B.print1();             //print the last one in the line-up (last to be added)
			a = B.removeQ();        //3rd place
			b = B.removeQ();        //2nd place
			cout << "Second Place: Team " << b->getTeam() << " " << b->getName() << " the " << b->getType() << endl;
			cout << "Third Place: Team " << a->getTeam() << " " << a->getName() << " the " << a->getType() << endl;
		}

		else if (playersB == 2) {          //Get the two with the highest scoring points
			B.print1();                 //print the winner
			a = B.removeQ();            //2nd place winner
			cout << "Second Place: Team " << a->getTeam() << " " << a->getName() << " the " << a->getType() << endl;
			b = loserList.remove();
			cout << "     The following loser is reborn to take its medal:" << endl;

			cout << "Third Place: Team " << b->getTeam() << " " << b->getName() << " the " << b->getType() << endl;
		}
		else if (playersB == 1) {          //Get two with highest scoring points
			B.print1();
			a = loserList.remove();
			cout << "     The following loser is reborn to take its medal:" << endl;
			cout << "Second Place: Team " << a->getTeam() << " " << a->getName() << " the " << a->getType() << endl;
			b = loserList.remove();
			if (b == NULL)
				return;
			cout << "     The following loser is reborn to take its medal:" << endl;
			cout << "Third Place: Team " << b->getTeam() << " " << b->getName() << " the " << b->getType() << endl;

		}
	}
}

#endif 