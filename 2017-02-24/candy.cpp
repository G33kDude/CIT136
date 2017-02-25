// This program calculates the total sales price, depending on
// what type and flavor of candy you are buying.
//
// It demonstrates how to use "if/else if/else", and how to
// use "nested" if statements (if statements appearing inside
// the braces of other if statements).


#include <iostream>
#include <string>
using namespace std;


// Some constants for candy prices
const double red_taffy_price = 10.00;
const double blue_taffy_price = 9.99;
const double starburst_price = 5.00;
const double airhead_price = 2.50;


int main() {
	// Declare Variables
	char candy_type;   // Input - type of candy person is buying
	char candy_flavor; // Input - flavor of candy person is buying
	int how_many;      // Input - The number of candies the person wants to buy

	double price;           // Output - The total sales price of the candy
	string full_candy_type; // Output - Type of candy detected by program
	// string full_candy_flavor; // Output - Flavor of candy detected by program (NOT USED)


	// Get user input
	cout << "What type of candy would you like to buy: ";
	cin >> candy_type; // Read the first character of input
	cin.ignore(999999, '\n'); // Throw away everything else until 999999 characters later, or until an enter (\n) is encountered.

	// Ask them for the flavor regardless of if we use it -- Could be improved
	cout << "What flavor of candy would you like to buy: ";
	cin >> candy_flavor; // Read the first character of input
	cin.ignore(999999, '\n'); // Throw away everything else until 999999 characters later, or until an enter (\n) is encountered.

	cout << "How many would you like to buy: ";
	cin >> how_many;

	cout << endl; // Add some extra spacing after inputs are finished


	// Process the data
	candy_type = toupper(candy_type);     // Overwrite candy_type with the uppercase form of candy_type
	candy_flavor = toupper(candy_flavor); // Overwrite candy_flavor with the uppercase form of candy_flavor

	if (candy_type == 'L') // If they entered something starting with L
	{
		full_candy_type = "Laffy Taffy"; // Assume it's Laffy Taffy, save the name to echo to the user

		if (candy_flavor == 'R') // If they want a flavor starting with r (red)
		{
			price = how_many * red_taffy_price;
		}
		else if (candy_flavor == 'B') // If they want a flavor starting with b (blue)
		{
			price = how_many * blue_taffy_price;
		}
		else
		{
			price = 0; // Other taffy flavors are free
		}
	}
	else if (candy_type == 'S') // If they entered something starting with S
	{
		full_candy_type = "Starbust"; // Assume it's Starburst, save the name to echo to the user

		price = how_many * starburst_price; // All starburst flavors cost the same
	}
	else if (candy_type == 'A') // If they entered something starting with A
	{
		full_candy_type = "Airheads"; // Assume it's Airheads, save the name to echo to the user

		price = how_many * airhead_price; // All Airhead flavors cost the same
	}
	else // If we didn't recognize the candy that was inputted
	{
		full_candy_type = "Used Gum"; // Give them used gum from public street railing

		price = 0; // No charge for ABC gum
	}


	// Output
	cout << "You chose " << full_candy_type << endl;
	cout << "Your price is " << price << endl;


	// End of main
	return 0;
}
