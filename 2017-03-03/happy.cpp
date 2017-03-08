/****************************
Name: Philip Taylor
Course: CIT163 - Intro to Programming w/C++
Date: March 3, 2017
***************************
Files for Assignment: happy.cpp
Purpose of File:
	This program checks how many numbers between 1 and a value you
	specify are happy. A happy number is a number defined by the
	following process:
	1) Start with any positive integer
	2) Take the sum of the squares of its digits (35 -> 3^2+5^2)
	3) Repeat, using the sum as the new number, until that sum equals 1,
	or until it gets stuck in and endless loop that does not include 1.
Assistance Received: Everyone consulted
*****************************/


// Preprocessor Directives
#include <iostream>
#include <cmath> // Used for pow function
using namespace std;


// Define constants
const int MAXLOOPS = 1000000;


// Main function
int main()
{
	// Declare Variables
	int total_to_check; // How many numbers should we check for happines, total
	int total_happy = 0; // How many of those numbers were found to be happy
	int number; // The number currently being cycled to check for happiness
	int digit; // Holder for the digit being pulled from the number
	int sum = 0; // Sum for the squares of the digits of number
	int counter = 0; // A counter to let us stop checking after MAXLOOPS happy cycles


	// Explain the purpose of the program to the user
	cout << "This program checks how many numbers between 1 and a value you" << endl;
	cout << "specify are happy. A happy number is a number defined by the" << endl;
	cout << "following process:" << endl;
	cout << "1) Start with any positive integer" << endl;
	cout << "2) Take the sum of the squares of its digits (35 -> 3^2+5^2)" << endl;
	cout << "3) Repeat, using the sum as the new number, until that sum equals 1," << endl;
	cout << "   or until it gets stuck in and endless loop that does not include 1." << endl;
	cout << endl;


	// Prompt for input
	cout << "Please enter how many numbers to be checked for happiness: ";
	cin >> total_to_check;
	cout << endl;


	// Check for happy numbers

	// starting at 1 (int i = 1), repeat up to "total_to_check" times, 
	// and increase "i" by 1 each time.
	for (int i = 1; i <= total_to_check; i++)
	{

		// Check if the number is happy, or assume it isn't if it doesn't
		// reach 1 in a reasonable number of loops (MAXLOOPS)
		number = i;
		counter = 0;
		do // Do the loop contents once before checking
		{
			// Calculate the next number in the happy cycle
			// Splitting it into its digits can be done by repeatedly dividing
			// by ten, and taking the remainder.
			// 1234 -> 123, remainder 4 (take 4, square it, add to sum)
			// 123 -> 12, remainder 3  (take 3, square it, add to sum)
			// 12 -> 1, remainder 2  (take 2, square it, add to sum)
			// 1 -> 0, remainder 1  (take 1, square it, add to sum)
			// Stop looping once you reach 0.
			sum = 0;
			while (number > 0)
			{
				digit = number % 10;
				number = number / 10;
				sum = sum + pow(digit, 2);
			}
			number = sum;
		} while	(number != 1 && counter++ < MAXLOOPS); // Now do the check


		if (number == 1) // If the starting number ended up happy
		{
			total_happy += 1;
			cout << total_happy << "/" << i << " Happy number :D" << endl;
		}
		else
		{
			cout << total_happy << "/" << i << " Unhappy number D:" << endl;
		}
	}


	// Output the results
	cout << endl;
	cout << "A total of " << total_happy << " happy numbers between ";
	cout << "1 and " << total_to_check << " were found." << endl << endl;


	// End of main function
	return 0;
}
