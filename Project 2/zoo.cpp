/********************************************************************
* Program name: zooTyc                                              *
* Author: Tristan Santiago                                          *
* Date: February 4, 2018                                            *
* Description: zoo.cpp implements the dynamic arrays used for each  *
* animal type, as well as the add animal and kill animal functions. *
********************************************************************/

#include <iostream>
#include <string>
/****************************************************************************
*                              Zoo Class                                    *
* Also, the zoo class should have a dynamic array for each type of animal.  *
* Each dynamic array should have a capacity of 10 animals to start with. If *
* more animals are added, you should resize the dynamic array by doubling   *
* the starting capacity to hold more animals.                               *
****************************************************************************/
class Zoo  // Should be called Zoo    https://www.cs.nmsu.edu/~rth/cs/cs471/C%2B%2BDynamicArray.pdf
{
public:
    int *pa;                    // points to the array
    int length;                     // the # elements
    int nextIndex;                  // the next highest index value

    // Zoo();                     // the constructor
    // ~Zoo();
    // {
    //     delete [] pa;
    // }//    the    destructor
    // int& operator[](int index);     // the indexing operation
    // void add(int val);              // add a new value to the end
    // int size();                     // return length


    Zoo()
    {
        // Creates an array with 1 element, inititializes to blank
        pa = new int[1];
        // pa = new int[NULL];
        for (int i = 0; i < 1; i++)
        {
            pa[i] = 0;
        }
        length = 1;
        nextIndex = 0;
    }

// Adds an element to the array
void add(int val)
{
    int *pnewa;
    if (nextIndex == length)
    {
        length = length + 1;
        pnewa = new int[length];
        for (int i = 0; i < nextIndex; i++)
                pnewa[i] = pa[i];
        for (int j = nextIndex; j < length; j++)
                pnewa[j] = 0;
        delete [] pa;
        pa = pnewa;
    }
    pa[nextIndex++] = val;
}

void kill()
{
    //int *pnewa;
    if (nextIndex == length && length != 0)
    {
        pa[length--];
    }
    else
    {
        cout << "No animals in this cage to kill." << endl;
    }
}

int size()
{
    return length;
}

 ~Zoo()
    {
        delete [] pa;
    }//    the    destructor




};