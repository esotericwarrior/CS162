/********************************************************************
* Program name: zooTyc                                              *
* Author: Tristan Santiago                                          *
* Date: February 4, 2018                                            *
* Description: penguin.cpp contains the class definition for the    *
* penguin class, inheriting from the animal class.                  *
********************************************************************/

/****************************************************************************
*                              class Penguin                                *
****************************************************************************/
class Penguin : public Animal
{
    public:
        Penguin(int age, double cost,int numberOfBabies, double baseFoodCost ,double payoff)
        :Animal(age, cost, numberOfBabies, baseFoodCost, payoff)
        {

        }


~Penguin()    // Free resources with destructor
{

}

};