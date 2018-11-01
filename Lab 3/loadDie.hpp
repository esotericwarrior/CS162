/********************************************************************
** Program name: warGame                                            *
** Author: Tristan Santiago                                         *
** Date: January 28, 2018                                           *
** Description: loadDie.hpp is the header file for the loaded die   *
** class. It inherits all of the traits from the die class, while   *
** defining new ones for itself.                                    *
********************************************************************/
#ifndef LOADDIE_HPP
#define LOADDIE_HPP

#include "die.hpp"


class LoadedDie : public Die
{
    private:
        int turn;

    public:
        LoadedDie(int n);
        int roll();
        ~LoadedDie();

};

#endif