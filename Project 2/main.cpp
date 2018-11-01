/********************************************************************
* Program name: zooTyc                                              *
* Author: Tristan Santiago                                          *
* Date: February 4, 2018                                            *
* Description: main.cpp includes all the class and function         *
* definitions and puts them all together to create a simplified     *
* version of Zoo Tycoon.                                            *
********************************************************************/
#include <iostream>
#include <string>
#include <unistd.h> // for sleep() //https://stackoverflow.com/questions/8486181/how-to-make-a-loading-animation-in-console-application-written-in-c
#include "inputValidation.cpp"
#include "zoo.cpp"
#include "tiger.cpp"
#include "penguin.cpp"
#include "turtle.cpp"
#include "functions.cpp"
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
    srand(time(NULL));
    int dayCount = 0;
    int amount, valid, response, choice, randomChoice, randArr, randBonus;
    Zoo TigerCage;
    Zoo TurtleCage;
    Zoo PenguinCage;
    Tiger tiger(0,10000,1,50,2000); // This would be a tiger setup
    Turtle turtle(0,100,10,5,20); // This would be a turtle setup
    Penguin penguin(0,1000,5,10,100); // This would be a penguin setup
    double tigerPayoff = 2000;
    double turtlePayoff = 20;
    double penguinPayoff = 100;
    double result = 0;         // Return variable used for balance after purchase or additional funds.
    bool varietyCheck1 = false;
    bool varietyCheck2 = false;
    bool varietyCheck3 = false;
    bool gameOver = false;
    bool babyCheck1 = false;
    bool babyCheck2 = false;
    bool babyCheck3 = false;
    bool oldEnough = false;
   /********************************************************
    *               1st -   Specific Money Give             *
    ********************************************************/
    double balance = 20000; // Starting balance.

while(gameOver == false)
    {
    /********************************************************
    *            Needs 3 animals to start business          *
    ********************************************************/
    // Animals need to be able to be purchases by 1 or 2 quantity
    // Subtract amount from balance
    // All animals are 1 day old

    // If these conditions are met, begin day 1

if(dayCount == 0 && (varietyCheck1 == false && varietyCheck2 == false && varietyCheck3 == false))
    {
    cout << "               Welcome, New Zookeeper!" << endl;
    cout << "               -----------------------" << endl;
    cout << "\nYou must buy 3 types of animals to begin your business." << endl;
    cout << "You have $" << balance << " to spend." << endl;    // Starting balance
    cout << "Here's what's available for purchase: " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "1. Purchase turtle for $100." << endl;
    cout << "2. Purchase penguin for $1000." << endl;
    cout << "3. Purchase tiger for $10000." << endl;
    }
else if (dayCount == 0)
    {
    cout << "Remember, young zookeeper, you can't begin your business until you own at least 1 of each animal." << endl;
    cout << "You have $" << balance << " to spend." << endl;    // Starting balance
    if(varietyCheck1 == false)
    {
        cout << "You do not have turtles." << endl;
    }
    if(varietyCheck2 == false)
    {
        cout << "You do not have tigers." << endl;
    }
    if(varietyCheck3 == false)
    {
        cout << "You do not have penguins." << endl;
    }
    cout << "Here's what's available for purchase: " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "1. Purchase turtle for $100." << endl;
    cout << "2. Purchase penguin for $1000." << endl;
    cout << "3. Purchase tiger for $10000." << endl;
    }
        cin >> response;
        choice = menu4Validation(response);
    /********************************************************
    *                  Switch Statement                     *
    ********************************************************/
    switch(choice)
        {
            case 1:cout << "How many turtles do you want to buy? 1 or 2?\n" << endl;
            cin >> valid;
            amount = menuValidation(valid);
            // buys user specified amount
            for(int i = 0; i < amount; i++)
            {
                buyAnimal(balance,turtle.getCost(),&result);  // Pass the variable result by Reference
            }
            cout << "Remaining balance: " << result << endl;
            balance = result;
            // Adds turtles into turtle cage
            for(int i = 0; i < amount; i++)
            {
                TurtleCage.add(1);
            }
            break;
            case 2:cout << "How many penguins do you want to buy? 1 or 2?\n" << endl;
            cin >> valid;
            amount = menuValidation(valid);
            // buys user specified amount
            for(int i = 0; i < amount; i++)
            {
                buyAnimal(balance,penguin.getCost(),&result);  // Pass the variable result by Reference
            }
            cout << "Remaining balance: " << result << endl;
            balance = result;
            // Adds penguins into penguin cage
            for(int i = 0; i < amount; i++)
            {
                PenguinCage.add(1);
            }
            break;
            case 3:cout << "How many tigers do you want to buy? 1 or 2?\n" << endl;
            cin >> valid;
            amount = menuValidation(valid);
            // buys user specified amount
            for(int i = 0; i < amount; i++)
            {
                buyAnimal(balance,tiger.getCost(),&result);  // Pass the variable result by Reference
            }
            cout << "Remaining balance: " << result << endl;
            balance = result;
            // Adds tigers into penguin cage
            for(int i = 0; i < amount; i++)
            {
                TigerCage.add(1);
            }
            break;                      // Update balance
        }

    cout << "\nYou must buy 2 more types of animals to begin your business." << endl;
    cout << "You have $" << balance << " to spend." << endl;
    cout << "Here's what's available for purchase: " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "1. Purchase turtle for $100." << endl;
    cout << "2. Purchase penguin for $1000." << endl;
    cout << "3. Purchase tiger for $10000." << endl;
    cin >> response;

    choice = menu4Validation(response);
    /********************************************************
    *                  Switch Statement                     *
    ********************************************************/
    switch(choice)
        {
            case 1:cout << "How many turtles do you want to buy? 1 or 2?\n" << endl;
            cin >> valid;
            amount = menuValidation(valid);
            // buys user specified amount
            for(int i = 0; i < amount; i++)
            {
                buyAnimal(balance,turtle.getCost(),&result);  // Pass the variable result by Reference
            }
            cout << "Remaining balance: " << result << endl;
            balance = result;
            // Adds turtles into turtle cage
            for(int i = 0; i < amount; i++)
            {
                TurtleCage.add(1);
            }
            break;
            case 2:cout << "How many penguins do you want to buy? 1 or 2?\n" << endl;
            cin >> valid;
            amount = menuValidation(valid);
            // buys user specified amount
            for(int i = 0; i < amount; i++)
            {
                buyAnimal(balance,penguin.getCost(),&result);  // Pass the variable result by Reference
            }
            cout << "Remaining balance: " << result << endl;
            balance = result;
            // Adds penguins into penguin cage
            for(int i = 0; i < amount; i++)
            {
                PenguinCage.add(1);
            }
            break;
            case 3:cout << "How many tigers do you want to buy? 1 or 2?\n" << endl;
            cin >> valid;
            amount = menuValidation(valid);
            // buys user specified amount
            for(int i = 0; i < amount; i++)
            {
                buyAnimal(balance,tiger.getCost(),&result);  // Pass the variable result by Reference
            }
            cout << "Remaining balance: " << result << endl;
            balance = result;
            // Adds tigers into penguin cage
            for(int i = 0; i < amount; i++)
            {
                TigerCage.add(1);
            }
            break;
        }

    cout << "\nYou must buy 1 more types of animal to begin your business." << endl;
    cout << "You have $" << result << " to spend." << endl;    // Starting balance
    cout << "Here's what's available for purchase: " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "1. Purchase turtle for $100." << endl;
    cout << "2. Purchase penguin for $1000." << endl;
    cout << "3. Purchase tiger for $10000." << endl;
    cin >> response;
    choice = menu4Validation(response);
    /********************************************************
    *                  Switch Statement                     *
    ********************************************************/
    switch(choice)
        {
            case 1:cout << "How many turtles do you want to buy? 1 or 2?\n" << endl;
            cin >> valid;
            amount = menuValidation(valid);
            // buys user specified amount
            for(int i = 0; i < amount; i++)
            {
                buyAnimal(balance,turtle.getCost(),&result);  // Pass the variable result by Reference
            }
            cout << "Remaining balance: " << result << endl;
            balance = result;
            // Adds turtles into turtle cage
            for(int i = 0; i < amount; i++)
            {
                TurtleCage.add(1);
            }
            break;
            case 2:cout << "How many penguins do you want to buy? 1 or 2?\n" << endl;
            cin >> valid;
            amount = menuValidation(valid);
            // buys user specified amount
            for(int i = 0; i < amount; i++)
            {
                buyAnimal(balance,penguin.getCost(),&result);  // Pass the variable result by Reference
            }
            cout << "Remaining balance: " << result << endl;
            balance = result;
            // Adds penguins into penguin cage
            for(int i = 0; i < amount; i++)
            {
                PenguinCage.add(1);
            }
            break;
            case 3:cout << "How many tigers do you want to buy? 1 or 2?\n" << endl;
            cin >> valid;
            amount = menuValidation(valid);
            // buys user specified amount
            for(int i = 0; i < amount; i++)
            {
                buyAnimal(balance,tiger.getCost(),&result);  // Pass the variable result by Reference
            }
            cout << "Remaining balance: " << result << endl;
            balance = result;
            // Adds tigers into penguin cage
            for(int i = 0; i < amount; i++)
            {
                TigerCage.add(1);
            }
            break;

        }
     if(dayCount == 0)
        {
            for (int i = 0; i < TurtleCage.size(); i++)
            if(TurtleCage.pa[i] >= 1)  // If the number of turtles in the cage is greater than or equal to 1.
            {
                varietyCheck1 = true;
            }
            else
            {
                varietyCheck1 = false;
            }
            for (int i = 0; i < TigerCage.size(); i++)
            if(TigerCage.pa[i] >= 1)
            {
                varietyCheck2 = true;
            }
            else
            {
                varietyCheck2 = false;
            }
            for (int i = 0; i < PenguinCage.size(); i++)
            if(PenguinCage.pa[i] >= 1)
            {
                varietyCheck3 = true;
            }
            else
            {
                varietyCheck3 = false;
            }
        }
        else
        {
            cout << "Not enough variety." << endl;
        }

        if(balance <= 0)
        {
            cout << "Uh oh. Out of money. Game over." << endl;
            cout << "You made it " << dayCount << " days." << endl;
            gameOver = true;
            break;
        }

    // Begin Business on day 1.
    if(dayCount == 0 && (varietyCheck1 == true && varietyCheck2 == true && varietyCheck3 == true))
    {
        dayCount++;
    }


    /********************************************************
    *                    Day 1 Start                        *
    ********************************************************/
    // Increase animals age by 1
    // Pay cost of animal feed
    // One random event occurs
    // Calculate profit for day
    // Prompt user to buy one adult animal.
        // They don't have to.
        // Animal needs to be 3 days old

    // Prompt user to keep playing or not
    // End game if user has no money.


    // increases turtle's age by 1 day
while(dayCount > 0)
{
    cout << "\n*******************************************************************" << endl;
    cout << "|                      Starting Day " << dayCount << "                             |" << endl; // Spaced this far to line the edge.
    cout << "*******************************************************************" << endl;
    for (int i = 0; i < TurtleCage.size(); i++)
        {
            TurtleCage.pa[i]++;
        }

    // increases turtle's age by 1 day
    for (int i = 0; i < TigerCage.size(); i++)
        {
            TigerCage.pa[i]++;
        }

    // increases turtle's age by 1 day
    for (int i = 0; i < PenguinCage.size(); i++)
        {
            PenguinCage.pa[i]++;
        }

    // Pulls Turtle food out
    int turtleFood = 0;
    for (int i = 0; i < TurtleCage.size(); i++)
        {
            balance -= turtle.getFood();
            turtleFood += turtle.getFood();
        }

    // Pulls Tiger food out
    int tigerFood = 0;
    for (int i = 0; i < TigerCage.size(); i++)
        {
            balance -= tiger.getFood();
            tigerFood += tiger.getFood();
        }

    // Pulls Penguin food out
    int penguinFood = 0;
    for (int i = 0; i < PenguinCage.size(); i++)
        {
            balance -= penguin.getFood();
            penguinFood += penguin.getFood();
        }

        cout << "Today we spent $" << turtleFood << ".00 on turtle food, $"
        << tigerFood << ".00 on tiger food and $" << penguinFood << ".00 on penguin food." << endl;
        /********************************************************************
        *                       Random Events                               *
        ********************************************************************/
        randomChoice = rando();
        // testing babies
        randomChoice = 3;
        if(randomChoice == 1) // Original code
        {
            cout << "A sickness occurs to an animal in the zoo: " << endl;
            randArr = randArray();
            if(randArr == 1)
            {
                cout << "Tiger dies :(" << endl;
                TigerCage.kill();
            }
            else if(randArr == 2)
            {
                cout << "Penguin dies :(" << endl;
                PenguinCage.kill();
            }
            else
            {
                cout << "Turtle dies :(" << endl;
                TurtleCage.kill();
            }
        }
        else if(randomChoice == 2)
        {
            cout << "A boom in zoo attendance occurs: " << endl;
            randBonus = randMoney();
            cout << "You're earning an extra $" << randBonus << ".00 per Tiger today." << endl;
            for (int i = 0; i < TigerCage.size(); i++)
            balance += randBonus;
        }
        else if(randomChoice == 3)
        {
            randArr = randArray();
            cout << "A baby animal is born: " << endl;
            switch (randArr)
            //{
            {
                case 1:{
                for (int i = 0; i < TigerCage.size(); i++)
                {
                if (TigerCage.pa[i] >= 3)
                    oldEnough = true;
                }

                if (oldEnough == true)
                {
                    cout << "Baby tiger born." << endl;
                    //for (int i = 0; i < 1; i++)
                    TigerCage.add(0);
                    break;
                }   // if loop
                else
                {
                    cout << "Tiger is not old enough." << endl;
                    randArr = 2;
                    babyCheck1 = true;
                }   // else
                //}   // for loop

                }   // Case
                case 2:{
                for (int i = 0; i < PenguinCage.size(); i++)
                {
                if (PenguinCage.pa[i] >= 3)
                    oldEnough = true;
                }

                if (oldEnough == true)
                {
                    cout << "5 baby penguins born." << endl;
                    for (int i = 0; i < penguin.getBabes(); i++)
                    PenguinCage.add(0);
                    break;
                }   // if loop
                else
                {
                    cout << "Penguin is not old enough." << endl;
                    randArr = 3;
                    babyCheck2 = true;
                }   // else
                //}   // for loop

                }   // Case
                case 3:{
                for (int i = 0; i < TurtleCage.size(); i++)
                {
                if (TurtleCage.pa[i] >= 3)
                    oldEnough = true;
                }

                if (oldEnough == true)
                {
                    cout << "10 baby turtles born." << endl;
                    for (int i = 0; i < turtle.getBabes(); i++)
                    TurtleCage.add(0);
                    break;
                }   // if loop
                else
                {
                    cout << "Turtle is not old enough." << endl;
                    randArr = 1;
                    babyCheck3 = true;
                }   // else
                }   // Case
                }

            if(babyCheck1 == true && babyCheck2 == true && babyCheck3 == true)
            {
                babyCheck1 = false;
                babyCheck2 = false;
                babyCheck3 = false;
                cout << "No adult animals to breed..." << endl;
                cout << "... therefore nothing happens." << endl;
                //break;
            }

        }

        else
        {
            cout << "Nothing happens: " << endl;
        }

        /********************************************
        *                   Payoff                  *
        ********************************************/
        int tigerPay = 0;
        // Adds 20% per tiger
        for (int i = 0; i < TigerCage.size(); i++)
        {
            if(TigerCage.pa[i] >= 1)
            {
                Animal::payoff(balance, tigerPayoff, &result);
                balance = result;
                tigerPay += tigerPayoff;
            }
        }

        int turtlePay = 0;
        // Adds 5% per turtle
        for (int i = 0; i < TurtleCage.size(); i++)
        {
            if(TurtleCage.pa[i] >= 1)
            {
                Animal::payoff(balance, turtlePayoff, &result);
                balance = result;
                turtlePay += turtlePayoff;
            }
        }

        int penguinPay = 0;
        // Adds 10% per penguin
        for (int i = 0; i < PenguinCage.size(); i++)
        {
            if(PenguinCage.pa[i] >= 1)
            {
                Animal::payoff(balance, penguinPayoff, &result);
                balance = result;
                // penguinPay + penguinPayoff = penguinPay;
                penguinPay += penguinPayoff;
            }
        }
        cout << "Today we earned $" << turtlePay << ".00 on turtles, $"
        << tigerPay << ".00 on tigers and $" << penguinPay << ".00 on penguins." << endl;
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "Turtle Count           Tiger Count           Penguin Count" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "  " << TurtleCage.size() << "\t\t\t" << TigerCage.size() << "\t\t\t" << PenguinCage.size() << endl;
        cout << "\nYour balance for day " << dayCount << " is $" << balance << ".00" << endl;
        cout << "\nBefore this day ends, would you like to buy 1 adult animal?" << endl;
        cout << "1. Yes, I'd like to buy another animal." << endl;
        cout << "2. No, I do not want to buy another animal." << endl;
        cin >> response;
        choice = menuValidation(response);
        while(choice == 1)
        {
            {
            cout << "\nWhat type of animal would you like to buy?" << endl;
            cout << "1. Tiger for $10000" << endl;
            cout << "2. Penguin for $1000" << endl;
            cout << "3. Turtle for $100" << endl;
            cin >> response;
            valid = menu4Validation(response);
            }
            if (valid == 1)
            {
                // Add Tiger
                buyAnimal(balance,tiger.getCost(),&result);
                cout << "Purchasing tiger";
                // for(int i = 0; i < 1; i++)
                // {
                //     sleep(1);
                //     cout << "." << flush;
                //     sleep(1);
                //     cout << "." << flush;
                //     sleep(1);
                //     cout << "." << flush;
                //     sleep(1);
                //     cout << "\b\b\b   \b\b\b" << flush;
                // }
                cout << "\nPurchase complete!" << endl;
                cout << "\nRemaining balance: $" << result << endl;
                balance = result;
                // Adds a tiger to the tiger cage.
                TigerCage.add(3);
                choice = 2;
            }
            else if (valid == 2)
            {
                buyAnimal(balance,penguin.getCost(),&result);
                cout << "Purchasing penguin";
                // for(int i = 0; i < 1; i++)
                // {
                //     sleep(1);
                //     cout << "." << flush;
                //     sleep(1);
                //     cout << "." << flush;
                //     sleep(1);
                //     cout << "." << flush;
                //     sleep(1);
                //     cout << "\b\b\b   \b\b\b" << flush;
                // }
                cout << "\nPurchase complete!" << endl;
                cout << "\nRemaining balance: $" << result << endl;
                balance = result;
                // Adds a penguin to the penguin cage.
                PenguinCage.add(3);
                choice = 2;
            }
            else if (valid == 3)
            {
                buyAnimal(balance,turtle.getCost(),&result);
                cout << "Purchasing turtle";
                // for(int i = 0; i < 1; i++)
                // {
                //     sleep(1);
                //     cout << "." << flush;
                //     sleep(1);
                //     cout << "." << flush;
                //     sleep(1);
                //     cout << "." << flush;
                //     sleep(1);
                //     cout << "\b\b\b   \b\b\b" << flush;
                // }
                cout << "\nPurchase complete!" << endl;
                cout << "\nRemaining balance: $" << result << endl;
                balance = result;
                // Adds turtles into turtle cage
                TurtleCage.add(3);
                choice = 2;
            }
            else
            {
            cout << "Invalid choice." << endl;
            }
            choice = 2;
        }


        cout << "********************************************************************" << endl;
        cout << "|                      END OF DAY SUMMARY                          |" << endl;
        cout << "********************************************************************" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Turtle Count           Tiger Count           Penguin Count" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "  " << TurtleCage.size() << "\t\t\t" << TigerCage.size() << "\t\t\t" << PenguinCage.size() << endl;
        cout << "\nCurrent Balance: $" << balance << endl;
        cout << "\nWould you like to keep playing?" << endl;
        cout << "1. Yes, I enjoy tinkering with lives." << endl;
        cout << "2. No, I've had enough of playing God." << endl;
        cin >> choice;
            switch(choice)
            {
                case 1:cout << "You entered 1. Continuing Zoo Tycoon!\n" << endl;
                dayCount++;
                break;
                case 2:cout << "You entered 2. Quitting!" << endl;
                gameOver = true;
                dayCount = 0;
                break;
            }

            if(balance <= 0)
            {
                cout << "Uh oh. Out of money. Game over." << endl;
                cout << "You made it " << dayCount << " days." << endl;
                gameOver = true;
                break;
            }
        } // while loop for days greater than zero

    } // while loop for game over
    return 0;
} // main loop