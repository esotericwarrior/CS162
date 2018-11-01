/************************************************************************
* Program Name: que							*	
* Author: Tristan Santiago						*
* Date: February 24, 2018                                               *
* Description: This is the header file for queue.cpp. This is where the	*
* queue node is initialized, as well as the queue class.		*
************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

// Create a struct that is called QueueNode that represents each node.
    struct QueueNode 
    {
    int val;
// next, a pointer to the next Node object    
    QueueNode* next;
// prev, a pointer to the previous Node object    
    QueueNode* prev;
    };

// Queue class
// head, a pointer to the first QueueNode object in the queue 

class Queue 
{
private:
    QueueNode* head;

public:
    Queue();                    // Constructor
    bool isEmpty();             // Checks if the queue is empty. If so, returns true; otherwise, return false.
    void addBack(int val);      // Takes a user-inputted integer, creates a QueueNode with user-inputted integer, and appends it to the back of the list.
    int getFront();             // Returns the value of the node at the front of the queue.
    void removeFront();         // Removes the front QueueNode of the queue and free the memory.
    void printQueue();          // Traverses through the queue from head using next pointers, and prints the values of each QueueNode in the queue.
    ~Queue();                   // Destructor
};

#endif
