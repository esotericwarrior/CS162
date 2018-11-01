/********************************************************************
** Program name: osuInfo                                            *
** Author:
** Date: February 4, 2018                                           *
** Description: university.cpp
*********************************************************************/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Building Class
class Building{
// The Building class contains the following member variables:
public:
string name;        // name: name of the building

int size;           // size: the size of the building (in sqft)
string address;     // address: address of the building (stored as string)

// You are encouraged to get the actual address and sizes of buildings that exist on the actual campus, here is the link to look this up, but this is not a hard requirement.
// http://facilities.oregonstate.edu/buildings (Links to an external site.)Links to an external site.

// Note: No additional member function required for this class.

public:
void printBuilding(){
cout << "Name: " << name << "\nAddress: " << address << "\n" << endl;
}
};