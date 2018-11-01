/****************************************************************************
* Program Name: dieFight                                                    *
* Author: Tristan Santiago                                                  *
* Date: February 18, 2018                                                   *
* Description: main.cpp only calls functions from function.cpp to run the   *
* program.																	*
****************************************************************************/
#include <iostream>
#include "functions.cpp"

using namespace std;

int main()
{
    Functions Functions;
    Functions.gameStart();
    return 0;
}