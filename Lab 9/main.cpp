/****************************************************************************
* Program Name: stackQueue                                                  *
* Author: Tristan Santiago													*
* Date: March 11, 2018                                                      *
* Description: First prompt user for number of rounds, percentages for push	*
* and pop, while input validating. During first round, if new element is	*
* not added to the queue, and pop is triggered based off random number		*
* generated, then the pop will error, since queue cannot be empty to pop.	*
* Second menu option is to create a palindrome. Here we 'copy' the string,	*
* and 'paste' it in reverse once original string is complete. Third menu	*
* option exits the program.													*
****************************************************************************/
//#include "stdafx.h"
#include <iostream>
#include <queue>
#include <list>
#include <time.h>
#include <string>
#include <string.h>
#include <stack>
#include "inputValidation.cpp"

using namespace std;

// http://www.learntosolveit.com/cprogramming/Ex_4.13_reverse_string.html
// Function definition
    /****************************************************
    *                 Reverse Stack                     *
    ****************************************************/
void reverse(char *str, int len)
{
	std::stack<char>s;
	int i;
	for (i = 0; i<len; i++)
	{
		s.push(str[i]);
	}
	for (i = 0; i<len; i++)
	{
		str[i] = s.top();
		s.pop();
	}
}


int main()
{

	int rounds, percentPush, percentPop, num, percent, status_push, status_pop;
	bool finished = false;
	double choice;
	double avg = 0, a_prev;
	// STL Containers
	queue<int, list<int>> que, temp;
	srand(time(NULL));

    /****************************************************
    *                   MAIN MENU                       *
    ****************************************************/
    do{
    // Create a menu for the user to test the buffer and create a palindrome.
    cout << "Please choose from the following options: " << endl;
    cout << "1. Test the buffer." << endl;
    cout << "2. Create a palindrome." << endl;
    cout << "3. Exit Program." << endl;
    cin >> choice;
    menuValidation(choice); // Call menu validation to check user input.
    if (choice == 1)
    // For the queue, prompt the user to enter the two percentages, and the total number of rounds. Then, display the results to the console in each round.
    {
    	//taking input from user and validating it against any string input instead of integer.

    	cout << "Enter the number of rounds for the simulation: ";
    	while (!(cin >> rounds))
    	{
    		//when the input fails, it clears the last cin and for completion of line of the given input, asking again to enter valid input.
    		cin.clear();
    		while (cin.get() != '\n')
    			continue;
    		cout << "Please enter valid input: ";
    	}

    	cout << "Enter percentage chance to put a random number at the end of buffer: ";
    	while (!(cin >> percentPush))
    	{
    		cin.clear();
    		while (cin.get() != '\n')
    			continue;
    		cout << "\nPlease enter valid input: ";
    	}

    	cout << "Enter percentage chance to take out number from the front of buffer: ";
    	while (!(cin >> percentPop))
    	{
    		cin.clear();
    		while (cin.get() != '\n')
    			continue;
    		cout << "Please enter valid input: ";
    	}

    	//iterating for the number of rounds.
    	for (int i = 1; i <= rounds; i++)
    	{
    		status_push = 0;
    		status_pop = 0;
    		a_prev = avg;

    		//random number in range 1 to 1000
    		num = rand() % 1000 + 1;
    		cout << "Random Number Chosen is: " << num << endl;

    		//random number in range 1 to 100
    		percent = rand() % 100 + 1;

    		//comparing with user provided values and pushing if it obeys
    		if (percent <= percentPush)
    		{
    			que.push(num);
    			status_push++; //incrementing status indicating push happened
    		}

    		//comparing with user provided values and popping if it obeys and queue is not empty
    		percent = rand() % 100 + 1;
    		if (percent <= percentPop && !que.empty())
    		{
    			que.pop();
    			status_pop++; //decrementing status indicating pop happened
    		}

    		//temp queue is filled with our queue
    		temp = que;
    		cout << "\nRound " << i << endl;
    		if (status_push && status_pop)
    			cout << "Both push & pop triggered.\n";
    		else if (status_push)
    			cout << "Only push triggered.\n";
    		else if (status_pop)
    			cout << "Only pop triggered.\n";
    		else
    			cout << "Neither push nor pop triggered.\n";

    		//printing the elements of queue using temp queue
    		cout << "Elements of the queue from front are: ";
    		while (!temp.empty())
    		{
    			cout << temp.front() << ". ";
    			temp.pop();
    		}
    		cout << endl;

    		//printing length of the buffer after every round.
    		cout << "Length of the buffer after round " << i << " is: " << que.size() << endl;;


    		//calculating average as per the given formula and printing it.
    		avg = (a_prev*(i - 1) + que.size()) / i;
    		cout << "Average length of the queue afer round " << i << " is: " << avg << endl << endl;

    		cout << "Press '1' and then 'Enter' to begin next round." << endl;
    		string pause;

    		cin >> pause;
    		cout << endl;
    	    cout << "\nReturning to main menu..." << endl;

    	}
    }   // If choice == 1.
	if (choice == 2)
    // For the stack, prompt the user to enter a string. Create the palindrome and then display it.
	{
    	/************************************
    	*           Palindrome              *
    	************************************/
    	cout << "Please enter a string: " << endl;
        char str[50];
        cin.clear();
        cin.ignore(100, '\n');
    	cin.getline(str, 100);
    	int len = strlen(str);
    	cout << str << "";
    	reverse(str, len);
    	cout << str << endl;
    	cout << "\nReturning to main menu..." << endl;
    	cout << endl;
	}   // If choice == 2.
	if (choice == 3)
	{
	    finished = true;    // Finished = true to exit do-while loop.
	    cout << "Exiting Program." << endl;
	    exit(0);
	}   // If choice == 3.
}   while (finished != true);   // Do-while loop.
	//system("pause");

	return 0;
}