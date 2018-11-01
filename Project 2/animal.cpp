/********************************************************************
* Program name: zooTyc                                              *
* Author: Tristan Santiago                                          *
* Date: February 4, 2018                                            *
* Description: animal.cpp declares the Animal class and includes    *
* all of its member functions to be later inherited by other        *
* classes.                                                          *
********************************************************************/

#include <iostream>
#include <string>


class Animal
{

private:

public:

    int age;
    double cost;
    int numberOfBabies;
    double baseFoodCost;
    //double payoff;
    static void payoff(double, double, double*); // This member function does not have a receiver object. It's basically a normal function that's nested inside of the scope of the class.

    // Every animal has an age, a cost, a certain number of babies, a base food cost, and a payoff.
    Animal(int age, double cost, int numberOfBabies, double baseFoodCost, double payoff)
    {
        //https://www.youtube.com/watch?v=I2-RmR7JRdc
        this->age = age; // this->age refers to the public int age in the class, where age is only in the scope of the function.
        this->cost = cost;
        this->numberOfBabies = numberOfBabies;
        this->baseFoodCost = baseFoodCost;
        //this->payoff = payoff;
    }

    double getCost()
    {
        return cost;
    }

    int getBabes()
    {
        return numberOfBabies;
    }

    double getFood()
    {
        return baseFoodCost;
    }

};
