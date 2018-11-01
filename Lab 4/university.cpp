/********************************************************************
* Program name: osuInfo                                             *
* Author: Tristan Santiago                                          *
* Date: February 4, 2018                                            *
* Description: university.cpp contains the class definitions for    *
* the university class.                                             *
********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include "person.cpp"
#include "building.cpp"

using namespace std;

// University Class
class University{
// The University class contains the following member variables:
public:
string name;    // name: name of the university.
// The name of the university MUST be “Oregon State University”
vector<Person*> persons;    // people: contains m number of Person objects
vector<Building> buildings; // buildings: contains n number of Building objects

// It contains the following member functions:
public:
// A function that prints the information on all the buildings in its information system (name, address, and building’s size)
void printAllBuildings(){
cout << "\nBuilding Details:" << endl;
for ( int j = 0; j < buildings.size() ; j++ ){
buildings[j].printBuilding();
}
}
// A function that prints the information of all the people (name, age, GPA or Rating)
void printAllPersonsRecord(){
cout << "\nPersons Details: " << endl;
for ( int i = 0; i < persons.size() ; i++ ){
persons[i]->printPerson();
}
}
};
// Note: When printing information of all people, you need to distinguish instructors and students by print either a “GPA” or “Rating”.