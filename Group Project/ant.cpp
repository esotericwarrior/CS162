/*********************************************************************
** Program name: doodle
** Author: John Casillas, Corbin Stripling, Tristan Santiago 
** Date: 2/18/2018
** Description: This is where the Ant is being setup. Using the Critter
** it derives it's characteristics from there and adds it's unique
** behavior
*********************************************************************/

#include "ant.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>

using std::cout;

Ant::Ant() : Critter(){

     species = "Ant";

}

Ant::Ant(int r, int c) : Critter(r,c){

     species = "Ant";

}

void Ant::move(Critter* grid[][20], int numRows){

     int direction = rand() % 4;
     int rowUp = row - 1;
     int rowDown = row + 1;
     int colLeft = col - 1;
     int colRight = col + 1;

     switch(direction){
      case 0:   // Move left
           if(colLeft >= 0 && grid[row][colLeft] == NULL){

            grid[row][colLeft] = grid[row][col];
            grid[row][col] = NULL;
            col = colLeft;
            moved = true;

           }
           break;

      case 1:   // Move up
           if(rowUp >= 0 && grid[rowUp][col] == NULL){

            grid[rowUp][col] = grid[row][col];
            grid[row][col] = NULL;
            row = rowUp;
            moved = true;

           }
           break;

      case 2:   // Move right
           if(colRight < 20 && grid[row][colRight] == NULL){

            grid[row][colRight] = grid[row][col];
            grid[row][col] = NULL;
            col = colRight;
            moved = true;

           }
           break;

      case 3:   // Move down
           if(rowDown < 20 && grid[rowDown][col] == NULL){

            grid[rowDown][col] = grid[row][col];
            grid[row][col] = NULL;
            row = rowDown;
            moved = true;

           }
           break;

      default:
           cout << "ERROR: INVALID DIRECTION. Exit program.\n";
           exit(1);
     }

}

void Ant::breed(Critter* grid[][20], int numRows){

     if(stepsNotLucky == 3){

      int rowUp = row - 1;
      int rowDown = row + 1;
      int colLeft = col - 1;
      int colRight = col + 1;

      //Breed to left
      if(colLeft >= 0 && grid[row][colLeft] == NULL){

           grid[row][colLeft] = new Ant(row, colLeft);
           stepsNotLucky = 0;

      //Breed upwards
      }else if(rowUp >= 0 && grid[rowUp][col] == NULL){

           grid[rowUp][col] = new Ant(rowUp, col);
           stepsNotLucky = 0;

      //Breed to right
      }else if(colRight < 20 && grid[row][colRight] == NULL){

           grid[row][colRight] = new Ant(row, colRight);
           stepsNotLucky = 0;

      //Breed downwards
      }else if(rowDown < 20 && grid[rowDown][col] == NULL){

           grid[rowDown][col] = new Ant(rowDown, col);
           stepsNotLucky = 0;

      }

     }else{

      stepsNotLucky++;

     }

}

string Ant::getSpecies(){

     return species;

}

Ant::~Ant()
{

}