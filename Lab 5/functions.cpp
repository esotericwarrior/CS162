/********************************************************************
* Program name: recurs                                              *
* Author: Tristan Santiago                                          *
* Date: February 10, 2018                                           *
* Description: functions.cpp contains the function definitions for  *
* all of the recursive functions used in main.cpp.                  *
********************************************************************/
#include <iostream>
#include <string>
#include "functions.hpp"

void firstRecursive(const string& str)
{
    size_t numOfChars = str.size();

    if(numOfChars == 1)
    {
       cout << str << endl;
    }
    else
    {
        cout << str[numOfChars - 1];
        firstRecursive(str.substr(0, numOfChars - 1));
    }
}

int secondRecursive(int arrayValue[], int length)      //bring over array length and array
{
    if(length == 1)             // End the adding portion if 1, since this is the end
    {
        return arrayValue[0];
    }
    else                        // If length isn't 1, then use the recursive function to increase the element by 1. Since arrays begin
    {                           // at zero, the +1 begins at length value, and continues adding downwards until 1, whilst updating the sum in main.
        return arrayValue[0] + secondRecursive(arrayValue+1, length-1);
    }
}

int thirdRecursive(int third) // from the powerpoint in the module
{
    if (third >= 1)
    {
        return third + thirdRecursive(third - 1);
    }
    else
    {
        return 0; // recursive call
    }
}
