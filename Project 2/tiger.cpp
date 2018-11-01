/********************************************************************
* Program name: zooTyc                                              *
* Author: Tristan Santiago                                          *
* Date: February 4, 2018                                            *
* Description: tiger.cpp contains the class definition for the      *
* tiger class, inheriting from the animal class.                    *
********************************************************************/

#include "animal.cpp"
/****************************************************************************
*                              class Tiger                                  *
****************************************************************************/
class Tiger : public Animal
{
    public:
        Tiger(int age, double cost,int numberOfBabies, double baseFoodCost ,double payoff)
        :Animal(age, cost, numberOfBabies, baseFoodCost, payoff)
        {

        }



~Tiger()    // Free resources with destructor
{

}

};