/********************************************************************** 
** Program name: letterFrequency                                      *
** Author: Tristan Santiago                                           *
** Date: January 22, 2013                                             *
** Description: output.cpp includes output.hpp and uses two functions *
** to successfully perform the program's operations.                  * 
**********************************************************************/ 
#include <iostream>
#include <fstream>
#include <string>
#include "output.hpp"
using namespace std;
/**********************************************************************
*                          Default Constructor                        *
**********************************************************************/
void count_letters();
/**********************************************************************
*                          Default Constructor                        *
**********************************************************************/
void output_letters();
/**********************************************************************
*            void count_letters(ifstream &inFile, int *count)         *
* This function counts the frequency of each letter found in the      *
* user-specified file and instructs the program to create a new       *
* output file each time the function encounters a newline.            *
**********************************************************************/
void count_letters(ifstream &inFile, int *count)
{
       // Variable Declarations
       int j = 0;
       char character;             
       char ch;                    
       const char newLine = '\n';  // Sets the newline character to a constant.
       string para = "", line;     // Set paragraph to a blank and initializes line.

       // While loop that iterates until it reaches the end of the user's file.
       while (ch != EOF)
       {
              ch = tolower(ch);    // Converts each letter to lowercase.
              count[ch]++;         // Counters each letter as the file is read.
              ch = inFile.get();   // Run individual characters through 'ch' to...

              if(ch == newLine)    // ... catch newLines! If it catches a \n...
              {
                     break;        // ... it breaks the while, moving to paragraph counting.
              }
              else
              {
                     // Otherwise, the lines are concatinated.
                     para += line + ' ';
              }
       }
       // Set the intial paragraph value to 0
       para.erase(para.length() - 1);
       // Loop for number of letters.
       for (j = 0; j < 26; j++)
       {
              count[j] = 0;
       }
       // This loop runs for length of the paragraph, only grabbing
       // letters, the ASCII codes are between 97 and 122.
       for (j = 0; j < para.length(); j++)
       {
              // It only grabs only lowercase from para[j]
              // and sets it to check which ASCII code it is.
              ch = tolower(para[j]);
              if ((int)ch >= 97 && (int)ch <= 122)
              {      // Starting from a and ending at z.
                     count[(int)ch - 97] += 1;
              }
       }
}

/**********************************************************************
*            void out_letters(ofstream &foutput, int *count)          *
* This function writes the letter frequencies to user-created files   *
* before clearing letter counts, to put the rest of the data into     *
* the next file, only counting that paragraph's letters.              *
**********************************************************************/
//Function for output_letters
void output_letters(ofstream &foutput, int *count)
{
       // Varaible declaration
       int ch;

       // Write to file if chars are between a and z
       for (char ch = 'a'; ch <= 'z'; ch++)
       {
              foutput << ch << " : " << count[ch] << endl;
       }
       // Clear current count, so that the program can start counting
       // letters from the next paragraph.
       for (ch = 0; ch < 128; ch++)
       {
              count[ch] = 0;
       }
}
