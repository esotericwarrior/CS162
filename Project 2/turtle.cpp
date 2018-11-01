/********************************************************************
* Program name: zooTyc                                              *
* Author: Tristan Santiago                                          *
* Date: February 4, 2018                                            *
* Description: turtle.cpp contains the class definition for the     *
* turtle class, inheriting from the animal class.                   *
********************************************************************/

/****************************************************************************
*                              class Turtle                                 *
****************************************************************************/
class Turtle : public Animal
{
    public:
        Turtle(int age, double cost,int numberOfBabies, double baseFoodCost ,double payoff)
        :Animal(age, cost, numberOfBabies, baseFoodCost, payoff)
        {

        }



~Turtle()    // Free resources with destructor
{

}

};