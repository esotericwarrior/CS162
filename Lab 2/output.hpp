/********************************************************************  
** Program name: letterFrequency                                    *
** Author: Tristan Santiago                                         *
** Date: January 22, 2018                                           *
** Description: output.hpp contains the functions to be used later  *
** in the program.                                                  *
********************************************************************/ 
#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// Define letter count function.
void count_letters(ifstream &, int*);

// Define letter output function.
void output_letters(ofstream &, int*);

#endif