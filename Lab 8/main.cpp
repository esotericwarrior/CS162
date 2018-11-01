/************************************************************************
** Program name: sort                                                   *
** Author: Tristan Santiago						*
** Date: March 4, 2018                                                  *
** Description: In this program, we use algorithms to search data and   *
* sort data from user-inputted files.                                   *
************************************************************************/
//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "inputValidation.cpp"
using namespace std;

// Function prototypes
int searchList(int array[], int file1ArraySize, int searchElement);
int binarySort(string inputfile);
void readFile(char fileName[], int array[], int &file1ArraySize);
void readFile(char fileName[], int array[], int &file1ArraySize);
void SelectionSort(string inputfile, string outputfile);

int main()
{
    // Variable declarations.
    int results;                // Holds the search results.
    int target;                 // User-defined target value.
    int valid;
    char file1[50];
    int file1Array[50];
    int file1ArraySize = 0;
    char file2[50];
    int file2Array[50];
    int file2ArraySize = 0;
    char file3[50];
    int file3Array[50];
    int file3ArraySize = 0;
    char file4[50];
    int file4Array[50];
    int file4ArraySize = 0;

    cout << "Please enter the name of the first file: ";
    cin >> file1;
    cout << "Please enter the name of the second file: ";
    cin >> file2;
    cout << "Please enter the name of the third file: ";
    cin >> file3;
    cout << "Please enter the name of the fourth file: ";
    cin >> file4;
    // Read file data for the first file.
    readFile(file1, file1Array, file1ArraySize);
    // Read file data for the second file.
    readFile(file2, file2Array, file2ArraySize);
    // Read file data for the third file.
    readFile(file3, file3Array, file3ArraySize);
    // Read file data for the second file.
    readFile(file4, file4Array, file4ArraySize);

    // Prompt the user to enter the value they wish to locate and begin search.
    cout << "What is the target value?" << endl;
    cin >> target;
    valid = integerValidation(target);
    // ---------- FILE 1 ---------- //
    results = searchList(file1Array, file1ArraySize, target);
    // If searchList returned -1, target was not found.
    if (results == -1)
    {
        cout << "Target not found in " << file1 << "\n";
    }
    else
    {
        // Otherwise, results contain the subscript of the first target found in the array.
        cout << "Target found in " << file1 << "\n";
        //cout << (results + 1) << ".\n";
    }
    // ---------- FILE 2 ---------- //
    results = searchList(file2Array, file2ArraySize, target);
    // If searchList returned -1, target was not found.
    if (results == -1)
    {
        cout << "Target not found in " << file2 << "\n";
    }
    else
    {
        // Otherwise, results contain the subscript of the first target found in the array.
        cout << "Target found in " << file2 << "\n";
        //cout << (results + 1) << ".\n";
    }
    // ---------- FILE 3 ---------- //
    results = searchList(file3Array, file3ArraySize, target);
    // If searchList returned -1, target was not found.
    if (results == -1)
    {
        cout << "Target not found in " << file3 << "\n";
    }
    else
    {
        // Otherwise, results contain the subscript of the first target found in the array.
        cout << "Target found in " << file3 << "\n";
        //cout << (results + 1) << ".\n";
    }
    // ---------- FILE 4 ---------- //
    results = searchList(file4Array, file4ArraySize, target);
    // If searchList returned -1, target was not found.
    if (results == -1)
    {
        cout << "Target not found in " << file4 << "\n";
    }
    else
    {
        // Otherwise, results contain the subscript of the first target found in the array.
        cout << "Target found in " << file4 << "\n";
        //cout << (results + 1) << ".\n";
    }
    //***************************************************************************
    //system("pause");
    ifstream inFile;
    string outputfile;
    string sortfile1;
    string sortfile2;
    string sortfile3;
    // ---------- FILE 1 ---------- //
    cout << "\nPlease enter the name of the file you want the algorithm to sort: ";
    //cin >> sortfile1;
    cin.ignore();
    getline(cin, sortfile1);
    inFile.open(sortfile1.c_str());
    while (inFile.fail()) // Check for mistakes in opening file.
    {
        cout << "Could not open the file. ";
        cout << "\nPlease enter the name of the file you want the algorithm to sort: ";
        cin >> sortfile1;
        inFile.clear();
        inFile.open(sortfile1.c_str());
    }
    cout << endl << "Enter a file name to store results to: ";
    cin >> outputfile;
    // binarySearch1 = outputfile;
    // Read file data for the first file.
    //SelectionSort("test1.txt", outputfile);
    SelectionSort(sortfile1, outputfile);
    binarySort(outputfile);
    inFile.close(); // This sort of fixes the weird loop.
    // ---------- FILE 2 ---------- //
    cout << "\nPlease enter the name of the file you want the algorithm to sort: ";
    //cin >> sortfile2;
    cin.ignore();
    getline(cin, sortfile2);
    inFile.open(sortfile2.c_str());
    while (inFile.fail()) // Check for mistakes in opening file.
    {
        cout << "Could not open the file. ";
        cout << "\nPlease enter the name of the file you want the algorithm to sort: ";
        cin >> sortfile2;
        inFile.clear();
        inFile.open(sortfile2.c_str());
    }
    cout << endl << "Enter a file name to store results to: ";
    cin >> outputfile;
    // binarySearch2 = outputfile;
    SelectionSort(sortfile2, outputfile);
    binarySort(outputfile);
    inFile.close(); // This sort of fixes the weird loop.
    // ---------- FILE 3 ---------- //
    cout << "\nPlease enter the name of the file you want the algorithm to sort: ";
    // cin >> sortfile3;
    cin.ignore();    
    getline(cin, sortfile3);
    inFile.open(sortfile3.c_str());
    while (inFile.fail()) // Check for mistakes in opening file.
    {
        cout << "Could not open the file. ";
        cout << "\nPlease enter the name of the file you want the algorithm to sort: ";
        cin >> sortfile3;
        inFile.clear();
        inFile.open(sortfile3.c_str());
    }
    cout << endl << "Enter a file name to store results to: ";
    cin >> outputfile;
    // binarySearch3 = outputfile;
    SelectionSort(sortfile3, outputfile);
    binarySort(outputfile);
    //cout << endl << "Enter a file name to store result: ";
    //cin >> outputfile;
    //SelectionSort("test2.txt", outputfile);
    //cout << endl << "Enter a file name to store result: ";
    //cin >> outputfile;
    //SelectionSort("test3.txt", outputfile);
    cout << endl;
    // binarySort("test1.txt");
    //binarySort(sortfile1);
    // binarySort(outputfile);
    //system("pause");
    return 0;
}

// searchList function adopted from example in textbook on page 605.
/********************************************************************************
*                               searchList                                      *
* This function performs a linear search on an integer array. The list array,   *
* which has size elements, is search for the number stored in value. If the     *
* number is found, its array subscript is returned. Otherwise, -1 is returned.  *
********************************************************************************/
int searchList(int array[], int file1ArraySize, int searchElement)
{
    int index = 0;                      // Used as a subscript to search array.
    int position = -1;                  // Used to record position of search value.
    bool found = false;                 // Flag to indicate if the value was found.

    while (index < file1ArraySize && !found)
    {
        if (array[index] == searchElement)       // If the value is found.
        {
            found = true;                       // Set the flag.
            position = index;                   // Record the value's subscript.
        }
        index++;                                // Go to the next element.
    }
    return position;                            // Return the position, or -1.
}

// Function used to read file.
void readFile(char fileName[], int array[], int &file1ArraySize)
{
    ifstream inFile(fileName);
    // Check to see if the file exist or not.
    if (!inFile)
    {
        cout << endl << "File not found." << fileName << endl;
        return;
    }
    int inputData, i = 0;
    while (!inFile.eof())
    {
        inFile >> inputData;
        array[i++] = inputData;
    }
    file1ArraySize = i;
}

// https://www.geeksforgeeks.org/selection-sort/
void SelectionSort(string inputfile, string outputfile)
{
    string line;
    int length = 0;
    int blank;
        ifstream in(inputfile.c_str());
    while(!in.eof())
    {
            in >> blank;
            length++;
    }
    cout << endl;
    int num, i = 0;
    int data[length];
    int comp = 0;
    ifstream again(inputfile.c_str());
    while (!again.eof())
    {
        again >> num;
        data[i++] = num;
    }
    int j, first, temp;
    i = 0;
    int numLength = length;
    for (i = numLength - 1; i > 0; i--)
    {
        first = 0;
        for (j = 1; j <= i; j++)
        {
            comp++;
            if (data[j] < data[first])
            first = j;
        }
        temp = data[first];
        data[first] = data[i];
        data[i] = temp;
    }
    cout << endl << inputfile << " is sorted after " << comp << " different number comparisons." << endl;
    // Storing sorted data into filename specified by the user.
    ofstream out(outputfile.c_str());
    cout << "The numbers in descending order: ";
    for (i = 0; i < length; i++)
    {
        out << data[length-i-1] << " ";
        cout << data[i] << " ";
    }
    cout << endl;
    cout << "The numbers in ascending order: ";
    for (int i = 0; i < length; i++)
    {
        cout << data[numLength-1] << " ";
        numLength--;
    }
    cout << endl << "The values have been sorted in ascending order in the following file: " << outputfile;
    return;
}

// https://www.geeksforgeeks.org/binary-search/
int binarySort(string inputfile)
{
       ifstream infile(inputfile);
   cout << "\nNow starting a binary search in " << inputfile << endl;
   if(!infile)
   {
       cout << "\nUnable to open file." << endl;
       return 0;
   }
   
	string line;
    int length = 0;
    int blank;
        ifstream count(inputfile.c_str());
    while(!count.eof())
    {
            count >> blank;
            length++;
    }
    

//   int num;
//   cout << "\nHow many numbers should be read from the input file?" << endl;
//   cout << "**PLEASE NOTE that this number should match the number of integers in the file ";
//   cout << "in order to properly locate your target.**" << endl;
//   cin >> num;
   int* array = new int[length];
   for(int i=0; i<length; i++){
       if(infile.eof()) break;
       infile >> array[i];
   }
   cout << "We found " << length - 1 << " integers in this file." << endl;
   int key;
   cout << "Which integer would you like to search for? ";
   cin >> key;
   int low = 0; int high = length-1;
   int found = false;
   int index = 0;
   while(low<=high){
       int mid = (low+high)/2;
       if(array[mid]==key){
           index = mid;
           found = true;
           break;
       }
       else if(array[mid] < key)
       {
           low = mid+1;
       }
       else
       {
           high = mid-1;
       }
   }
   if(found)
   {
       cout << key <<" was found at index "<< index << "." << endl;
   }
   else
   {
       cout << key << " was not found in the array." << endl;
   }
}
