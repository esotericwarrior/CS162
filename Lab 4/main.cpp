/********************************************************************
** Program name: osuInfo                                            *
** Author: Tristan Santiago                                         *
** Date: February 4, 2018                                           *
** Description: This program is a simple representation of an       *
* Oregon State information system that contains information about   *
* the university.                                                   *
********************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "university.cpp"
#include "inputValidation.cpp"
using namespace std;

int main()
{
    ofstream ofs;
    // ofs.open("saved.txt");  // Makes and overwrites data in saved.txt

    ofs.open("saved.txt", fstream::app);
    //if (ofs._is_open())
    if(!(ofs.is_open()))
    {
        ofstream ofs("saved.txt");
    }

    //ifstream ifs("saved.txt");
    // Instantiate at least 1 student, 1 instructor, and 2 buildings.
    Student student4;
    Student student;

	Instructor instructor2;
	Instructor instructor;

    student4.setName("Heath Ledger");
    student4.setAge(18);
    student4.setGPA(3.5);                    //The range for GPA must be between 0.0 and 4.0.

    instructor2.setName("Morgan Freeman");
    instructor2.setAge(65);
    instructor2.setRating(5.0);              // The range for rating must be between 0.0 and 5.0.

    Building building;                      // Declare building object.

    building.name = "Animal Physiology Lab";
    building.size = 1840;
    cout << endl;
    //building.address = "\n27280 TAMPICO RD CORVALLIS, OR 97330";
    building.address = "3550 Campus Way\n         Corvallis, OR 97331";
    Building building2;

    building2.name = "Adams Hall";
    building2.size = 11168;
    building2.address = "606 SW 15th ST\n         Corvallis, OR 97331";

    University university;

    university.name = "Oregon State University";
    university.persons.emplace_back(&student4);
    university.persons.emplace_back(&instructor2);
    university.buildings.push_back(building);
    university.buildings.push_back(building2);

    university.printAllBuildings();

    university.printAllPersonsRecord();

    int adultCount = 0;
    int studentCount = 0;

    int choice, response, responsePerson;
    ofstream writeFile;
    bool isValidMainChoice = false; // Variable used to operate the while loop.
    while (!isValidMainChoice)
    {
        cout << "           Welcome to the OSU Information System!\n" << endl;
        cout << "Please choose from the following menu:" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "1: Prints information about all the buildings." << endl;
        cout << "2: Prints information of everybody at the university." << endl;
        cout << "3: Choose a person to do work." << endl;
        cout << "4: Read saved information from file." << endl;
        cout << "5: Exit the program." << endl;
        cout << "-----------------------------------------------------" << endl;
        cin >> choice;
        //cout << "The value you entered is " << choice << endl;
        response = menu4Validation(choice);
        if (response == 1)
        {
            university.printAllBuildings();
        }
        else if (response == 2)
        {
            university.printAllPersonsRecord();
        }
        else if (response == 3)
        {
            int personChoice;
            bool isInputValid = false;
            while (!isInputValid) {
                cout << "Please choose the one of the following option to provide person's details." << endl;
                cout << "You are only allowed to enter one student and one instructor at a time." << endl;
                cout << "If you would like to add additional students and instructors, please re-run the program." << endl;
                cout << "5: Student" << endl;
                cout << "6: Instructor" << endl;
                cin >> personChoice;
                if (personChoice == 5 && studentCount == 0) {
                    isInputValid = true;
                    string studentName;
                    bool isValidName = false;
                    while (!isValidName) {
                        // cout << "Please enter the student's first name: ";
                        // cin >> studentName;

                        cout << "Please enter the name of the student: ";
	                    cin >> student.name;	// Ideally, this would take the user's input and store it in name.

                        // if (student.name.length() == 0)
                        // {
                        //     cout << "The name must not be blank. Please re-enter the student's name." << endl;
                        // }
                        if (student.name.length() == 0) {
                            cout << "The name must not be blank. Please re-enter the student's name: ";
                        }
                        else {
                            isValidName = true;
                        //}
                    }
                    }
                    int age1 = 0;
                    bool isValidAge1 = false;
                    while (!isValidAge1) {
                        // cout << " Kindly enter age of the student :" << endl;
                        // cin >> age1;
	                    cout << "Please enter the student's age: ";
	                    cin >> student.age;	// Ideally, this would take the user's input and store it in age.

                        if (student.age < 0 || student.age > 100)
                        {
                            cout << "Age must be greater than 0 or less than 100. Please re-enter the student's age." << endl;
                        }
                        else
                        {
                            isValidAge1 = true;
                        }
                    }
                    float gpa;
                    bool isValidGPA = false;
                    while (!isValidGPA) {
                        cout << "Please enter the student's GPA: ";
                        //cin >> gpa;
                        cin >> student.gpa;
                        if (student.gpa < 0.0 || student.gpa > 4.0) {
                            cout << " GPA must be greater than 0.0 and less than 4.0. Please re-enter the student's GPA: ";
                            isValidGPA = false;
                        }
                        else {
                            isValidGPA = true;
                        }
                    }
                    student.do_work();
                    ofs << student; // store the object to file
                    ofs << endl;
                    studentCount++;
                    // Read the object back in.
	           //     if(ifs >> student)
	           //     {
		          //  // Read was successful, therefore it is valid.
		          //      cout << endl << student << '\n'; // Print student.
	           //     }
	           //     ofs.close();
                    //Student student;
                    // student.setName(studentName);
                    // student.setAge(age1);
                    student.name;
                    student.age;
                    // student.setGPA(gpa);
                    student.gpa;
                    university.persons.emplace_back(&student);
                    university.printAllPersonsRecord();
                }

                else if (personChoice == 6 && adultCount == 0) {
                    isInputValid = true;
                    string instructorName;
                    bool isValidName = false;
                    while (!isValidName) {
                        // cout << " Kindly enter Name of the instructor :" << endl;
                        // cin >> instructorName;
                        cout << "Please enter the name of the instructor: ";
	                    cin >> instructor.name;
                        if (instructor.name.length() == 0) {
                            cout << "The name must not be blank. Please re-enter the instructor's name: ";
                        }
                        else {
                            isValidName = true;
                        }
                    }
                    float rating;
                    bool isValidRating = false;
                    while (!isValidRating) {
                        cout << "Please enter the instructor's rating: ";
                        //cin >> rating;
                        cin >> instructor.rating;
                        if (instructor.rating < 0.0 || instructor.rating > 5.0) {
                            cout << "The instructor's rating must be greater than 0.0 and less then 5.0. Please re-enter the instructor rating: ";
                            isValidRating = false;
                        }
                        else {
                            isValidRating = true;
                        }
                    }
                    int age2 = 0;
                    bool isValidAge2 = false;
                    while (!isValidAge2) {
                        // cout << " Kindly enter age of the instructor :" << endl;
                        // cin >> age2;
                        cout << "Please enter the instructor's age: ";
	                    cin >> instructor.age;
                        if (instructor.age < 0 || instructor.age > 100) {
                            cout << "The instructor's age must be greater than 0 and less than 100. Please re-enter the instructor's age: ";
                        }
                        else {
                            isValidAge2 = true;
                        }
                    }
                    instructor.do_work();
                    ofs << instructor;
                    ofs << endl;
                    adultCount++;
                    // Instructor instructor;
                    // instructor.setName(instructorName);
                    // instructor.setAge(age2);
                    // instructor.setRating(rating);
                //     if(ifs >> instructor)
	               // {
                // 	// read was successful therefore s2 is valid
                // 	    cout << endl << instructor << '\n'; // Print instructor.
                // 	}
                //     ofs.close();
                    instructor.name;
                    instructor.age;
                    instructor.rating;
                    university.persons.emplace_back(&instructor);
                //     if(ifs >> instructor)
	               // {
                // 	// read was successful therefore s2 is valid
                // 	    cout << endl << instructor << '\n'; // Print instructor.
                // 	}
                //     ofs.close();
                }
                else {
                    cout << "You entered an invalid value. Please try again." << endl;
                }
            }
        }
    else if (choice == 4)
    {
	ifstream ifs("saved.txt");

	// read the object back in
	if(ifs >> student)
	{
		// read was successful therefore is valid
		cout << endl << student << '\n'; // Print student.
	}

	if(ifs >> instructor)
	{
		// read was successful therefore is valid
		cout << endl << instructor << '\n'; // Print instructor.
	}

    }
    else if (choice == 5)
    {
        isValidMainChoice = true;
        cout << "\nThank you for using the OSU Information System. Goodbye." << endl;
    }
}
	return 0;
}