/********************************************************************  
** Program name: letterFrequency                                    *
** Author: Tristan Santiago                                         *
** Date: January 22, 2018                                           *
** Description: This program reads a file filled with letters       *
** counts the letter frequencies in the file, and writes the results*
** to a new file. Each paragraph (newline character) has its own    *
** count.                                                           *
*********************************************************************/ 
#include <fstream>
#include <iostream>
#include <string>
#include "output.cpp"
using namespace std;

int main()
{
    // Variable Declarations
    char ch;
    string input;               // User-specified input file.             
    string output;              // User-specified output file.
    ifstream inFile;            // Read file object.
    ofstream outFile;           // Write file object.
    int frequency[128] = { 0 }; // 127 ASCII + 1 https://learn.parallax.com/support/reference/ascii-table-0-127
    int j = 1;                  // Paragraph number count set to 1 by default.

    // Prompt user to enter the name of the file they want read.
    cout << "\nThis program reads a file filled with letters, counts the letter frequencies";
    cout << " in the file, and writes the results to a new file." << endl;
    cout << "\nPlease enter the file name: ";
    cin >> input;

    // Open the file
    inFile.open(input.c_str());
    
    // If the file is successfully opened, Begin a while loop that read until
    // the end of the file.
    while(inFile.good())
    {
        // Letter count function which passes ASCII array and the user's input file.
        count_letters(inFile, frequency);

        // Prompt the user to enter the name of the file they want the results written to..
        cout << "\nEnter the name of the file you want the results written to " << j << ": ";
        cin >> output;

        // Update the number of paragraphs.
        j = j + 1;

        // Open the output file.
        outFile.open(output.c_str());

        // Write the frequency of each letter in the user-specified file.
        output_letters(outFile, frequency);

        // Close the output file.
        outFile.close();
    }
    // Close the input file.
    inFile.close();
return 0;
}