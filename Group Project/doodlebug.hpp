/*********************************************************************
** Program name: doodle
** Author: John Casillas, Corbin Stripling, Tristan Santiago 
** Date: 2/18/2018
** Description: This is the Doodlebug's header file
*********************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "critter.hpp"
#include <string>

using std::string;

class Doodlebug : public Critter{

     public:

      // Constructors
      Doodlebug();
      ~Doodlebug();
      Doodlebug(int r, int c);

      /************************************************************
       * Function: move
       * Description: Has Doodlebug move to an adjacent cell with an ant
       *           and eat the ant. It has a preference to eat from
       *           the left and move clockwise. If no adjacent ant,
       *           then Doodlebug moves randomly up, down, left, or
       *           right if space available. Otherwise Doodlebug
       *           stays in position.
       * **********************************************************/
      void move(Critter* grid[][20], int numRows);

      /************************************************************
       * Function: breed
       * Description: Doodlebug creates a new adjacent Doodlebug if
       *           survived 8 timesteps. Doodlebug prefers to create
       *           new Doodlebug to left and working clockwise. If
       *           no space, then doesn't breed. Doodlebug must
       *           survive another 8 timesteps to breed again if
       *           offspring was produced.
       * **********************************************************/
      void breed(Critter* grid[][20], int numRows);

      /************************************************************
       * Function: starve
       * Description: Doodlebug dies if it has not eaten within 3
       *            timesteps.
       * **********************************************************/
      void starve(Critter* grid[][20], int numRows);

      /***********************************************************
       * Function: getSpecies
       * Description: Returns "Doodlebug"
       * *********************************************************/
      string getSpecies();

     protected:

      string species;
      int stepsNotEaten; // # timesteps Doodlebug has not eaten

};

#endif
