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
#include <iostream>
#include <iomanip> // Needed for setw() and setfill()
using namespace std;

const double APPLE_PRICE = 2.50;
const double BANANA_PRICE = 3.50;
const double ORANGE_PRICE = 2.45;

// main function
int main()
{
	// Fruits    Price
	//  Apple     2.50
	//  Bananas   3.50
	// Oranges    2.45

	// Declare Variables
	int applesToBuy, bananasToBuy, orangesToBuy;
	double applesTotalPrice, bananasTotalPrice, orangesTotalPrice;

	// Prompt for user input
	cout << "How many apples do you want to buy? ";
	cin >> applesToBuy;
	cout << "How many bananas do you want to buy? ";
	cin >> bananasToBuy;
	cout << "How many oranges do you want to buy? ";
	cin >> orangesToBuy;

	// Do calculations
	applesTotalPrice = APPLE_PRICE * applesToBuy;
	bananasTotalPrice = BANANA_PRICE * bananasToBuy;
	orangesTotalPrice = ORANGE_PRICE * orangesToBuy;

	// Output values
	// Manipulators:
	// setprecision  /// Set the rounding for outputted decimals
	// showpoint     /// Always show decimal point, even when ending with .0000000
	// fixed         /// Always use decimal notation, never scientific


	cout << setprecision(2) << showpoint << fixed;

	cout << setfill('_') << left << setw(13) << "Apples: "
		<< " $" << setfill('.')<< right << setw(8) << applesTotalPrice << endl;

	cout << setfill('_') << left << setw(13) << "Bananas: "
		<< " $" << setfill('.') << right << setw(8) << bananasTotalPrice << endl;

	cout << setfill('_') << left << setw(13) << "Oranges: "
		<< " $" << setfill('.') << right << setw(8) << orangesTotalPrice << endl;

	// exit main
	return 0;
}