/********************************
/Assignment 2 Task 1 : robustInput.cpp
/
/By : Edwin Lo
/
/Oct. 3rd 2016
/
/This program prompts the user for an integer, and outputs it back out. If the 
/integer is not a number nor an integer, then it will output an error message
/and exit the program. 
/
********************************/
#include <iostream>

using namespace std;

int main() {

	int userInput;
	bool valid = cin.good();	// set the value to true, if the input was successful
	
	cout << "Enter an integer: ";
	cin >> userInput;
	
	if (cin.fail()){	//error message for when the input is not a number
	
		cerr << "Error: Invalid input. Not a number." <<endl;
		return(-1);
	}

	if (valid){		// process for checking if the input is an integer or not
		
		char next = cin.get();
		bool endOfInt = (next == ' ') || (next == '\n');
		
		if (next == '.'){	// checks if there is a decimal point after the final digit of the integer
			
			cerr << "Error: Invalid Input. Not an integer.";
			return(-1);
		}
		
		else if (next <= 9 && next >= 0 || endOfInt ){

			cout << "The integer that you have entered is " << userInput << endl;
			
		}
		
		else {
			
			cerr << "Error: Invalid Input. Not an integer.";
		}
	
	}

	return 0;

}
