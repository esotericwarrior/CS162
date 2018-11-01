/************************************************************************
* Program Name: que							*
* Author: Tristan Santiago						*
* Date: February 24, 2018                                               *
* Description: This is the queue source. It houses the constructor and  *
* deconstructor for the queue class. Here we are adding, removing, and 	*
* returning values to main that are in the queue.			*
************************************************************************/
#include "queue.hpp"
#include <iostream>
using namespace std;

// Default Constructor
Queue::Queue()
{
    head = NULL;
}

// Returns head as null
bool Queue::isEmpty()
{
    return head == NULL;
}

// Places value onto back of list
void Queue::addBack(int val)
{
    if (isEmpty()) {
        head = new QueueNode;
        head->val = val;
        head->next = head;
        head->prev = head;
    }
    else {
        QueueNode* last = head->prev;

        //create a new node and set it prev and next value
        QueueNode* n = new QueueNode;
        n->val = val;
        n->prev = last;
        n->next = head;

        //make old last node's next to point to n
        last->next = n;
        //make head's previous to be new node n
        head->prev = n;
    }
}

// Returns head value
int Queue::getFront()
{
    return head->val;
}

// Removes head value
void Queue::removeFront()
{
    if (isEmpty())
        return;
    else if (head == head->next) //single element
    {
        delete head;
        head = NULL;
    }
    else {
        QueueNode* temp = head;
        head = head->next;
        head->prev = temp->prev;
        head->prev->next = head;
        delete temp;
    }
}

// Returns list
void Queue::printQueue()
{
    if (!isEmpty()) {
        QueueNode* curr = head;
        while (curr->next != head) {
            cout << curr->val << " ";
            curr = curr->next;
        }

        cout << curr->val << endl;
    }
    cout << endl;
}

// Deconstructor - Removes front values until it returns as empty
Queue::~Queue()
{
    while (!isEmpty())
        removeFront();
}

