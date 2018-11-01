/************************************************************************
* Program Name: que                                                     *
* Author: Tristan Santiago						*	
* Date: February 24, 2018                                               *
* Description: Within main we house the main menu, and call to the	*
* functions in queue. We also utilize 'add' which sends data to		*
* queue.cpp.								*
************************************************************************/
#include "queue.cpp"
#include "inputValidation.cpp"
#include <iostream>
using namespace std;

// Initialize add function
void add(Queue& q);

// add Takes the que object and sends it to the queue.cpp to add a value to the end of the list.
void add(Queue& q)
{
    int valid, val;
        cout << "Enter a positive value: ";
        cin >> val;
        valid = integerValidation(val);
        q.addBack(valid);
}

int main()
{
    int choice, valid;
    bool stop = false;
    Queue que;
    
    cout << endl;
    cout << "Welcome to my queue!" << endl;
    cout << "\nPlease choose from the following options: " << endl;
    while (!stop) 
    {
        cout << endl;
        // The menu should provide the following options:
        // Add a value to the back of queue        
        cout << "1. Add value to back of queue" << endl;
        // Display the front value
        cout << "2. Display first node (front) of queue" << endl;
        // Remove the front node
        cout << "3. Remove first node (front)" << endl;
        // Display the queue’s content
        cout << "4. Display queue" << endl;
        // Exit
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        valid = menu5Validation(choice);
        switch (valid) 
        {
            case 1:
                add(que);
                break;
            case 2:
                if (que.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "The first node value is " << que.getFront() << endl;
                break;
            case 3:
                if (que.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Removing first node." << endl;
                    que.removeFront();
                break;
            case 4:
                cout << "Your queue is : ";
                que.printQueue();
                break;
            case 5:
                stop = true;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
