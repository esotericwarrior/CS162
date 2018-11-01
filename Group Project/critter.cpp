/*********************************************************************
** Program name: doodle
** Author: John Casillas, Corbin Stripling, Tristan Santiago 
** Date: 2/18/2018
** Description: This is the critter source. In here are the default
** critter settings which acts a base class for ant and doodlebug.
*********************************************************************/

#include "critter.hpp"

Critter::Critter(){

     stepsNotLucky = 0;
     moved = false;
     died = false;
     row = -1;
     col = -1;
}

Critter::Critter(int r, int c){

     stepsNotLucky = 0;
     moved = false;
     died = false;
     row = r;
     col = c;
}

void Critter::move(Critter* grid[][20], int numRows){

     // Intentionally undefined

}

void Critter::breed(Critter* grid[][20], int numRows){

     // Intentionally undefined

}

void Critter::starve(Critter* grid[][20], int numRows){

     // Intentionally undefined

}

string Critter::getSpecies(){

     // Intentionally undefined

}

bool Critter::hasMoved() const{

     return moved;

}

void Critter::setMoved(bool doneMoving){

     moved = doneMoving;

}

bool Critter::hasDied() const{

     return died;

}

void Critter::setDied(bool death){

     died = death;

}

Critter::~Critter()
{

}