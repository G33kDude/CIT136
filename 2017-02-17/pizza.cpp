/****************************
Name: Philip Taylor
Course: CIT163 - Intro to Programming w/C++
Date: Feb 17, 2017
***************************
Files for Assignment: pizza.cpp
Purpose of File:
	A simple "weak artificial intelligence" based around pizza.
	https://en.wikipedia.org/wiki/Weak_AI
Assistance Received: Stacy LastName, Blake LastName, Jacob LastName
*****************************/


// Preprocessor Directives
#include <iostream> // For cin/cout
#include <string>   // For string data type
using namespace std;


// Main function
int main()
{
	// Declare variables
	string input_text;


	// Prompt for input
	cout << "Tell me something about pizza: ";

	// Use getline for text input so that a whole line of text can be
	// inputted, not just a single word.
	//
	// We don't need to call cin.get() or cin.ignore() here because
	// it isn't after a previous 'cin >> some_variable'.
	getline(cin, input_text);


	// Echo back input values (echo means to output the input)
	cout << "You typed: " << input_text << endl << endl;


	// Process the data and output accordingly
	if (input_text == "I like pizza") // If the user entered: I like pizza
	{
		cout << "Here, have some pizza <)";
	}
	else if (input_text == "I hate pizza") // Otherwise, if the user entered: I hate pizza
	{
		cout << "Too bad, you get pizza";
	}
	else if (input_text == "I love pizza") // Otherwise, if the user entered: I love pizza
	{
		cout << "Welcome to heaven";
	}
	else if (input_text == "I ate pizza") // Otherwise, if the user entered: I ate pizza
	{
		cout << "Go buy more pizza";
	}
	else if (input_text == "I dropped my pizza") // Otherwise, if the user entered: I dropped my pizza
	{
		cout << "You poor soul";
	}
	else // Otherwise, if the user entered something else
	{
		cout << "Don't you love pizza?";
	}


	// Exit main
	return 0;
}
