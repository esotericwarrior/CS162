/*********************************************************************
** Program name: doodle
** Author: John Casillas, Corbin Stripling, Tristan Santiago 
** Date: 2/18/2018
** Description: This is the critter header file.
*********************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <string>

using std::string;

class Critter{

     public:

      // Default constructor
      Critter();
      // Deconstructor
      ~Critter();

      // Constructor
      Critter(int r, int c);

      // Virtual move function undefined
      virtual void move(Critter* grid[][20], int numRows);

      // Virtual breed function undefined
      virtual void breed(Critter* grid[][20], int numRows);

      // Virtual starve function undefined
      virtual void starve(Critter* grid[][20], int numRows);

      // Virtual getSpecies function undefined
      virtual string getSpecies();

      /************************************************************
       * Function name: hasMoved
       * Description: Tells whether a Critter has moved in a timestep
       * **********************************************************/
      bool hasMoved() const;

      /************************************************************
       * Function name: setMoved
       * Description: Sets the moved member variable to true or false
       * **********************************************************/
      void setMoved(bool doneMoving);

      /************************************************************
       * Function name: hasDied
       * Description: Tells whether a Critter has died in a timestep
       * **********************************************************/
      bool hasDied() const;

      /************************************************************
       * Function name: setDied
       * Description: Sets the died member variable to true or false
       * **********************************************************/
      void setDied(bool death);

     protected:

      int stepsNotLucky; //# timesteps without breeding
      bool moved; // whether Critter has moved within a timestep
      bool died; // whether Critter has died
      int row; // row position in grid
      int col; // column position in grid

};

#endif