/****************************************************************************
** Program name: fibonacci													*
** Author: Tristan Santiago													*
** Date: 3/17/2018															*
** Description: http://www.cplusplus.com/forum/windows/39170/				*
** On cplusplus, I found a demo that combined both recursive and incursive	*
** functions in the main. From this point it was simple to add a menu		*
** and the time tracking capabilities.										*
****************************************************************************/
#include <iostream>
#include <ctime>
#include "inputValidation.cpp"


using namespace std;

/* Fibonacci: recursive version */
int Fibonacci_R(int n)
{
	if(n <= 0) 
	    return 0;
	    
	else if(n == 1) 
	    return 1;
	 
	else 
	    return Fibonacci_R(n - 1) + Fibonacci_R(n - 2);	
}

// iterative version
int Fibonacci_I(int n)
{
	int fib[] = {0,1,1};
	for(int i = 2; i <= n; i++)
	{
		fib[i % 3] = fib[(i - 1) % 3] + fib[(i - 2) % 3];
		cout << "fib(" << i << ") = " << fib[i % 3] << endl;
	}
	return fib[n % 3];
}

int main(void)
{		
    int a, choice, valid, inputTest;
    clock_t tStart = clock();

    cout << "Please enter your choice for iterative or resursive." << endl;
    cout << "1. Recursive" << endl;
    cout << "2. Iterative" << endl;
    cin >> choice;	
    valid = menuValidation(choice);
    
    cout << "Enter the number of terms: ";
    cin >> inputTest;
    
    a = integerValidation(inputTest);
	
    if (valid == 1)
    {
	// calculate the fib(i) from scratch for each i <= a using your recursive function
	cout << endl << "From recursive function" << endl;
	for(int i=1; i<=a; ++i)
	        cout << "fib(" << i << ") = " << Fibonacci_R(i) << endl;
	cout << endl;
    }
    
    else if(valid == 2)
    {
	// or calculate fib(a) once and output the intermediate results from the looping version
	cout << "From iterative function" << endl;
	Fibonacci_I(a);
    }
    
    int stop_s = clock();
    cout << "time: ";
    cout << double(clock() - tStart) / (double)CLOCKS_PER_SEC << " seconds." << endl;

	cout << endl;
	return 0;
}