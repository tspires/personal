#include <iostream> 
/*********************************************************************
** Program Filename: echo.cpp
** Author: Timothy Spires
** Date: 06/25/2014
** Description: A program to print a user entered integer to the screen
** Input: int
** Output: int
*********************************************************************/

using namespace std;
int main () { 
	cout << "Please enter a number: "; // Get user input
	double userInput;
	while ( ! (cin >> userInput)) { // Type check loop
		cout << "Please enter a number! ";
		cin.clear (); // Dump previous error flag
		cin.ignore (1000, '\n'); //Ignore previous input preceding enter key
	}
	cout << userInput << endl; // Print input to screen
	return 0; //System return
}

