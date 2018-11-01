/*********************************************************************
** Program name: doodle
** Author: John Casillas, Corbin Stripling, Tristan Santiago 
** Date: 2/18/2018
** Description: This is the Ant's header file.
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "critter.hpp"
#include <string>

using std::string;

class Ant : public Critter{

     public:

      // Constructors
      Ant();
      // Deconstructor
      ~Ant();

      Ant(int r, int c);

      /************************************************************
       * Function: move
       * Description: Has ant move randomly up, down, left, or right if
       *              space available. Otherwise Ant stays in position.
       * **********************************************************/
      void move(Critter* grid[][20], int numRows);

      /************************************************************
       * Function: breed
       * Description: Ant creates a new adjacent Ant if survived 3
       *              timesteps. Ant prefers to create new Ant to left
       *              and working clockwise. If no space, then doesn't
       *              breed. Ant must survive another 3 timesteps to
       *              breed again if offspring produced.
       * **********************************************************/
      void breed(Critter* grid[][20], int numRows);

      /***********************************************************
       * Function: getSpecies
       * Description: Returns "Ant"
       * *********************************************************/
      string getSpecies();


     protected:

      string species; // holds the species: Ant

};

#endif
