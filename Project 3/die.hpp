/************************************************************************
** Program name: dieFight												*
** Author: Tristan Santiago												*
** Date: February 11, 2018												*
** Description: This is the base dice class header file. A lof of these	*
** will be inherited by laoded dice.									*
************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
    protected:
        int numSides;

    public:
        Die(int n);
        virtual int roll(); // Virtual function will be overloaded in derived class.
        int getNumSides();
        ~Die();

};

#endif