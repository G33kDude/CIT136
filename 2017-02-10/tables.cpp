/****************************
Author: Philip Taylor
Date: Feb 10, 2017

This program demonstrates how to create nice looking columns.  It takes data
in from candy_store.txt, where the format of the file is as follows:

candy_type       color      price     amount_in_stock



The program outputs the data from each line, then outputs the amount it would
cost you if you were to purchase the percentage of candy specified in the
HOW_MUCH_TO_BUY_PCTG constant.

*****************************/

// --- Preprocessor Directives ---

// These lines are kind of like settings for the compiler (in this case,
// visual studio) so that it knows what needs to be included when turning
// your cpp source file into an exe.
#include <iostream>   // This is necessary for cin and fout
#include <iomanip>    // This is necessary for fancy output tables
#include <fstream>    // This is necessary for file input and output
#include <string>     // This is necessary for storing text in a variable

using namespace std;  // This is necessary to use the #included libraries


// --- Constants ---

// When you use 'const' before the data type when declaring a variable, it
// makes it into a constant. Constants are like normal variables, but they
// cannot be changed after the program is compiled.
//
// For this class, constants are going to be declared outside of the main
// function, where variable declarations usually go. All constants we declare
// should be named in all capital letters, with an underscore used to separate
// words.
//
// For example, you could use constants for:
//
// * Information that wouldn't change each time you run the program, but that
//   might need to be updated eventually
//    - Tax rate
//    - Minimum wage
//    - Global population
//
// * Conversion ratios
//    - Pennies per quarter
//    - Gallons of paint per sqft of wall space
//
// * Mathematical and universal constants
//    - The circle constant (pi)
//    - The golden ratio
//    - Euler's number (e)
//    - Speed of light (c)
//    - Speed of sound through air
//
// * Information that you use in more than one place in a program
//    - Width of table columns for output
//
// * Settings that might need to be changed
//    - What file to read data from
//    - What file to write output to
//    - Should output go to a file or the screen
//    - How many walls does a room have (change from 4 to 5 so you can
//      calculate how much paint it would take to paint the Pentagon)
//
// However, you would NOT use constants for:
//
// * Saving input from the user
// * Storing the results of calculations your program does
// * Storing any value that would need to change, or vary, while the program
//   is running.
//    - Values being counted by the program
//    - Values being totalled by the program

const int FIRST_COLUMN_WIDTH = 15;
const int SECOND_COLUMN_WIDTH = 15;
const int THIRD_COLUMN_WIDTH = 8;
const int FOURTH_COLUMN_WIDTH = 15;

// Percentages are represented as decimals between 0.00 and 1.00.
// 0.25 would be 25%, 0.50 would be 50%, and 0.75 would be 75%.
// 0.5 would also be 50%, and 0.05 would be 5%.
const double HOW_MUCH_TO_BUY_PCTG = 0.10;


// --- Main Function ---
int main()
{
	// --- Declare Variables ---

	// We will need a variable for every type of data that we will receive as
	// input.
	//
	// For data that is always a whole number, we will use the type
	// called "int", which is short for integer.
	//
	// For data that can sometimes be a decimal (e.g. 0.25) we will use the
	// type called "double".
	//
	// For textual data, such as names or descriptions, we will use the type
	// called "string", which is like a bunch of individual characters all
	// strung together. To use strings, you have to #include the <string>
	// library first.

	string candy_type;  // We use a string here, because candy type is text
	string candy_color; // We use a string here, because candy color is text
	double price;       // We use a double here, because candy price is money with a decimal point
	int amt_in_stock;   // We use an int here because you cannot stock half of a piece of candy

	// We will need variables for every value we will be calculating. This
	// program only calculates the total price for if we were to buy a bunch
	// of candy, so we only need one variable.
	//
	// Because the value we're calculating is money and could contain a
	// decimal point, we will use a double.
	//
	// Because the value we're calculating is a total count, and we want to
	// start counting from 0, we will set the starting value to 0.

	double total_price;
	total_price = 0;

	// (Tip!) The two lines above can can be combined as one line:
	// double total_price = 0;
	//
	//
	// We will need a variable for accessing each of the files we want to use.
	// Variables used to access files are declared using the data types called
	// "ifstream", which is short for "input file stream", and "ofstream",
	// which is short for "output file stream".
	//
	// For our file access variable names we will use fin and fout, because
	// that is what is preferred by Professor Morgan. It is not required to
	// use these names, and you could instead call them any valid variable
	// name you want.
	//
	// For example:
	//
	// * input_file, output_file
	// * candy_store_file, program_output_file
	// * apple, orange
	//   - Please don't use these names, you'd probably get points off because
	//     they don't have anything to do with what the variables are actually
	//     used for.

	ifstream fin;
	ofstream fout;


	// --- Open Input and Output Files ---

	// Before we can process any input data, we will need to open the file
	// that we are getting the data from. We may as well open the output file
	// right now as well.

	fin.open("candy_store.txt");
	fout.open("candy_store_output.txt");


	// --- Process and Output the Data ---

	// Because we only declared one variable for each type of data we are
	// getting as input, we will have to process and output each entry one at
	// a time.
	//
	// Before we get to that, however, we will have to set the output
	// formatting settings so that it will display money correctly.
	//
	// The 'fixed' manipulator makes it so that C++ will never automatically
	// switch to using scientific notation for its number output. Otherwise,
	// if you have a lot of money, it might show up as 1.23e+06 dollars
	// instead of 1234567.89 dollars

	fout << fixed;

	// The 'showpoint' manipulator makes it so that the decimal point is
	// always shown and never automatically hidden. Otherwise, if you have 52
	// dollars and 0 cents, it would show up as $52 instead of $52.00. This is
	// usually okay, but it can look ugly when formatting things in a table.

	fout << showpoint;

	// The 'setprecision' manipulator makes it so that the output of a number
	// is rounded to the specified number of decimal places. Otherwise, if you
	// have a third of a dollar, it would show up as $0.33333333334 instead of
	// as $0.34c

	fout << setprecision(2);

	// Once our output has been set up, we will want to start outputting our
	// table data. The first row of a table should usually be the column
	// headers, so that is what we are outputting here.
	//
	// The first column, candy type, will be aligned to the left because it is
	// text and text is normally aligned to the left. We will set the width of
	// the column to the value of the FIRST_COLUMN_WIDTH constant.

	fout << left << setw(FIRST_COLUMN_WIDTH) << "Candy Type";

	// The second column, candy color, will be aligned to the left because it
	// is also text.

	fout << left << setw(SECOND_COLUMN_WIDTH) << "Candy Color";

	// The third column, the price of the candy, will be aligned to the right
	// because it is also a number. However, before we do the alignment, we
	// will want to add some extra space (" ") for the dollar sign.

	fout << " " << right << setw(THIRD_COLUMN_WIDTH) << "Price";

	// The fourth column, the amount of candy in stock, will be aligned to the
	// right because it is a number, and numbers are normally aligned to the
	// right so that the value places line up (ones to ones, tens to tens,
	// hundreds to hundreds, etc).

	fout << right << setw(FOURTH_COLUMN_WIDTH) << "# In Stock";

	// At the end of the row, we will put an endl, which is short for "end the
	// line".

	fout << endl;

	// Now we need to read in our first set of data from the input file.

	fin >> candy_type >> candy_color >> price >> amt_in_stock;

	// The formula for determining how much it will cost to buy
	// HOW_MUCH_TO_BUY_PCTG percent of the candy goes something like this:
	//
	// Figure out how many will be bought:
	//    percentage * amount in stock
	// Then figure out how much in actual money that will be:
	//    unit price * number being bought
	//
	// Once we have the actual dollar amount, we can add it to our total price
	// count.

	total_price = total_price + price * (HOW_MUCH_TO_BUY_PCTG * amt_in_stock);

	// (Tip!) The line above can be shortened from
	// "total_price = total_price + value"
	// to
	// "total_price += value"
	//
	//
	// Now that we have done our calculations we can output the data and move
	// on to the next item. To do this, we take the same code for outputting
	// the column headers, but we replace the header text with the actual
	// variables that we want to output.
	//
	// We will also want to put a dollar sign before the money column!

	fout << left << setw(FIRST_COLUMN_WIDTH) << candy_type;
	fout << left << setw(SECOND_COLUMN_WIDTH) << candy_color;
	fout << "$" << right << setw(THIRD_COLUMN_WIDTH) << price;
	fout << right << setw(FOURTH_COLUMN_WIDTH) << amt_in_stock;
	fout << endl;

	// Now we repeat the code for the first entry three more times, adding to
	// our total price each time.

	fin >> candy_type >> candy_color >> price >> amt_in_stock;
	total_price = total_price + price * (HOW_MUCH_TO_BUY_PCTG * amt_in_stock);
	fout << left << setw(FIRST_COLUMN_WIDTH) << candy_type;
	fout << left << setw(SECOND_COLUMN_WIDTH) << candy_color;
	fout << "$" << right << setw(THIRD_COLUMN_WIDTH) << price;
	fout << right << setw(FOURTH_COLUMN_WIDTH) << amt_in_stock;
	fout << endl;

	fin >> candy_type >> candy_color >> price >> amt_in_stock;
	total_price = total_price + price * (HOW_MUCH_TO_BUY_PCTG * amt_in_stock);
	fout << left << setw(FIRST_COLUMN_WIDTH) << candy_type;
	fout << left << setw(SECOND_COLUMN_WIDTH) << candy_color;
	fout << "$" << right << setw(THIRD_COLUMN_WIDTH) << price;
	fout << right << setw(FOURTH_COLUMN_WIDTH) << amt_in_stock;
	fout << endl;

	fin >> candy_type >> candy_color >> price >> amt_in_stock;
	total_price = total_price + price * (HOW_MUCH_TO_BUY_PCTG * amt_in_stock);
	fout << left << setw(FIRST_COLUMN_WIDTH) << candy_type;
	fout << left << setw(SECOND_COLUMN_WIDTH) << candy_color;
	fout << "$" << right << setw(THIRD_COLUMN_WIDTH) << price;
	fout << right << setw(FOURTH_COLUMN_WIDTH) << amt_in_stock;
	fout << endl;

	// Finally, we will output the calculated total.
	//
	// Let's add some extra lines between the table and the total for visual
	// purposes.

	fout << endl << endl << endl;

	// The percentage is multiplied by 100 when outputting, so it will show up
	// as 50.00% instead of 0.50%.

	fout << "The total cost to buy " << HOW_MUCH_TO_BUY_PCTG * 100
		<< "% of the candy would be $" << total_price << endl;


	// --- Close Files ---

	// When we're done using a file, we should always close it.

	fin.close();
	fout.close();


	// --- Exit main function ---
	return 0;
}
