/********************************************************************
** Program name: warGame                                            *
** Author: Tristan Santiago                                         *
** Date: January 28, 2018                                           *
** Description: die.hpp is the header file for the die class. It    *
** contains all the traits to be inherited by the loaded die class. *
********************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
    protected:
        int numSides;
        std::string dieType;

    public:
        Die(int n);
        virtual int roll(); // Virtual function will be overloaded in derived class.
        std::string getDieType();
        int getNumSides();
        ~Die();
};
#endif