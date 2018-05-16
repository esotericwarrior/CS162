/****************************************************************************
* Program Name: dieFight													*
* Author: Tristan Santiago													*
* Date: February 11, 2018													*
* Description: Queue.hpp provides the function definitions that will be		*
* for the lineups during the tournament.									*
****************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include "Character.h"
#include "Medusa.h"
#include "Barbarian.h"
#include "Vampire.h"
#include "BlueMen.h"
#include "HarryPotter.h"
#include "Game.h"
//#include "Functions.h"
#include "Losers.h"

struct node
{
	Character *P;
	int val;
	node *nextNode;
	node *prevNode;
};

class Queue
{
private:
	node * head;
	node *tail;

public:
	Queue();
	~Queue();
	//void addQ(Character *);
	void addBack(Character *);
	Character * removeQ();
	int getFront();             // Returns the value of the node at the front of the queue.
	Character * removeFront();
	void printQueue();
	bool isEmpty();
	void print1();
};
//constructor
Queue::Queue() 
{
	head = NULL;
	tail = NULL;
}

//print the Lineupclass list
void Queue::printQueue()
{

	if (head == NULL)
	{
		//cout << "Queue is empty." << endl;
		return;
	}
	else
	{
		node *temp = head;

		while (temp != NULL) {
			//cout << temp->P->getName() << " the " << temp->P->getName();  //print the P in the current node
			cout << temp->P->getName() << " the " << temp->P->getType();  //print the P in the current node
			temp = temp->nextNode;              //move temp to the next node

			cout << endl;
		}
	}
}

// Returns head value
int Queue::getFront()
{
	return head->val;
}

//print the last person in the Team (most recently added, the winner)
void Queue::print1()
{

	if (head == NULL)
	{
		cout << "Queue is empty." << endl;
	}
	else
	{
		node *temp = tail;
		cout << "First place: Team " << temp->P->getTeam() << " " << temp->P->getName() << " the " << temp->P->getName();  //print the P in the current node
		cout << endl;
	}
}

// Add a character to the queue/lineup.
//void Queue::addQ(Character *a)
void Queue::addBack(Character *a)
{
	if (head == NULL)
	{
		head = new node;
		head->P = a;
		head->nextNode = NULL;
		head->prevNode = NULL;
		tail = head;
	}
	else
	{
		tail->nextNode = new node;
		tail->nextNode->P = a;
		tail->nextNode->nextNode = NULL;
		tail->nextNode->prevNode = tail;
		tail = tail->nextNode;
	}
}

// Remove a character from the queue/lineup.
Character* Queue::removeQ()
{
	Character *r;
	node *temp = head;
	node *temp2 = head;

	if (head == NULL)
	{
		cout << "Nothing to remove. The list is empty." << endl;
		r = NULL;
		return r;
	}

	else if (head->nextNode == NULL)
	{  
		// If there is only one character in the current queue/lineup.
		r = head->P;
		delete head;
		head = NULL;
		tail = NULL;
		return r;
	}

	else
	{                  
		// If there is one ore more characters in the current queue/lineup.
		temp = temp2->nextNode;
		r = head->P;
		delete head;
		head = temp;
		head->prevNode = NULL;	// Point to the front of the queue/lineup.
		return r;
	}
}

// Destructor
Queue::~Queue()
{
	node * temp = head;
	node *garbage = head;

	if (head != NULL)
	{	// If there is only one character to delete:
		if (temp->nextNode == NULL)
		{
			delete temp;
			head = NULL;
		}
		else
		{
			while (temp != NULL)
			{           
				// If there is more than one character to delete:
				garbage = temp;				// Garbage keeps track of node to be deleted.
				temp = temp->nextNode;		// Move ptr to the next node.
				delete garbage;				// Delete the "garbage" node.
			}
		}
	}
}

// This function determines whether or not the queue/lineup is empty.
bool Queue::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif 