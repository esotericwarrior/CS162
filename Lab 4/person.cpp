/********************************************************************
* Program name: osuInfo												*
* Author: Tristan Santiago											*
* Date: February 4, 2018											*
* Description: person.cpp contains the class definitions for the	*
* person class, student class, and instructors to be used later in	*
* the program.                                                      *
********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Person Class (which is also the base class)
class Person {
// Person class is polymorphic, a Person pointer can hold an Instructor/Student object.
// The Person class contains the following member variables:
public:
string name;    // name: name of the person
// The age of a person can be randomized or from input, but make it realistic
int age;

void setName(string name) {
this->name = name;
}

void setAge(int age) {
this->age = age;
}

// The Person class contains the following member function:
// A function called “do_work()” that generates a random number that represents how many hours they will do work for, and then output message depending on if the Person is a Student or an Instructor.
virtual void do_work(){

}

virtual void printPerson(){

}
};

class Student: public Person
{

// private:
// float gpa; // GPA, the student’s GPA (double or float data type)


public:
float gpa; // GPA, the student’s GPA (double or float data type)
void setGPA(float gpa) {
this->gpa = gpa;
}

float getGPA(){
return gpa;
}

//For “do_work()” in Person class, if the Person is a Student, then the function should output the following message:
//“PERSON_NAME did X hours of homework.” Where PERSON_NAME is the person’s name, and X is the randomly generated number.
void do_work()
{
    cout << name << " did " << rand() % 8 + 1 << " hours of homework.\n" << endl;
}


void printPerson()
{
    cout << "Name: " << name << "\nAge: " << age << "\nGPA: " << getGPA() << "\n" << endl ;
}



    // Insertion operator
	friend std::ostream& operator<<(std::ostream& os, const Student& s) // http://www.cplusplus.com/forum/beginner/49924/
	{
		// write out individual members of s with an end of line between each one
		os << s.name << '\n';
		os << s.age << '\n';
		os << s.gpa;
		return os;
	}

	// Extraction operator
	friend std::istream& operator>>(std::istream& is, Student& s)
	{
		// read in individual members of s
		is >> s.name >> s.age >> s.gpa;
		return is;
	}

};

// Derived class
class Instructor: public Person {

// private:
// float rating;

public:
float rating;
void setRating(float rating)
{
    this->rating = rating;
}

float getRating()
{
    return rating;
}

void do_work()
{
    cout << name << " graded papers for " << rand() % 8 + 1 << " hours.\n" << endl;
}

void printPerson(){
cout << "Name : " << name << "\nAge: " << age << "\nRating: " << getRating() << "\n" << endl ;
}

	// Insertion operator
	friend std::ostream& operator<<(std::ostream& os, const Instructor& i) // http://www.cplusplus.com/forum/beginner/49924/
	{
		// write out individual members of i with an end of line between each one
		os << i.name << '\n';
		os << i.age << '\n';
		os << i.rating;
		return os;
	}

	// Extraction operator
	friend std::istream& operator>>(std::istream& is, Instructor& i)
	{
		is >> i.name >> i.age >> i.rating;
		return is;
	}


};

