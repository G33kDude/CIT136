/****************************
Name:
Course: CIT163 – Intro to Programming w/C++
Date:
***************************
Files for Assignment:
Purpose of File:
Assistance Received:
*****************************/

//Preprocessor Directives
#include<iostream>
#include <iomanip>
#include <string>
using namespace std;

// main function
int main()
{
	char mychara, mycharb, mycharc;
	string mystringa, mystringb, mystringc;


	cout << "Enter some characters: ";
	cin >> mychara; // Gets one character, skips white space
	cout << "one character: " << mychara << endl;

	cin.ignore(1000, '\n'); // Discard, ignore, destroy, anything the user inputted not saved to a variable
	cout << "Enter some characters: ";
	cin.get(mychara);  // Gets one character, doesn't skip white space
	cout << "one character: " << mychara << endl;
	//  cin.get();

	cin.ignore(1000, '\n'); // Discard, ignore, destroy, anything the user inputted not saved to a variable
	cout << "Enter a line of text: " << endl;
	getline(cin, mystringa); // Gets a whole line of text, including any white space
	cout << "Your line: " << mystringa << endl;

	// exit main
	return 0;
}