// This program is to demonstrate how to translate
// mathematical expressions into C++ code.
//
// The formulas are located in formulas_converted_to_code.png

#include <iostream>
#include <cmath> // pow, sqrt functions

using namespace std;

const double PI = 3.14156;

int main()
{
	// Use the symbols for these mathematical operations:
	// Add      +
	// Subtract -
	// Multiply *
	// Divide   /  (also fractions)


	// Calculate volume of a sphere

	double volume; // Output
	double r = 3;  // Input - defined here for demonstrative purposes

	volume = 4 / 3 * PI * pow(r, 3);

	cout << "The volume of a sphere with radius " << r << endl;
	cout << "is " << volume << " cubed." << endl << endl;



	// Calculate the value for the formula Philip made up

	double a = 15; // Input - Defined here for demonstrative purposes
	double b = 1;  // Input - Defined here for demonstrative purposes
	double p;      // Output

	// When doing division for a fraction other than just two numbers
	// being divided, parenthesis should be put around the numerator
	// and denominator.

	p = (pow(a, 2 * b)) / (sqrt(a*b));

	cout << "Philip's value is " << p << endl;

	return 0;
}
