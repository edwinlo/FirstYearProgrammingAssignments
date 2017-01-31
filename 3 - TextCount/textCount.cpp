/********************************
/Assignment 3 Task 2 : textCount.cpp
/
/By : Edwin Lo
/
/Oct. 14th 2016
/
/This program takes in any text string (without whitespace) from the keyboard
/of up to 100 characters and determines the length of the inputted text.
/
********************************/
#include <iostream>

using namespace std;

int main(){

	char userInput[99];
	
	cout << "Enter text without whitespace: ";
	cin >> userInput[99];
	
	if (cin.fail()){
		cerr << "Error. Invalid input." << endl;
		return -1;
	}
	
	int counter = 1;
	
	if (cin.good()){
		
	
		char next;
		bool endOfInput;
		
		do {
			next = cin.get();
			
			endOfInput = (next == '\n' || next == ' ');
			
			counter ++;
			
			if (endOfInput == true){
				counter --; 
				break;
			}
			
			if (counter > 100){
				cerr << "Error. Input is over 100 characters.";
				return -1;
			}
			
		} while (endOfInput == false);
		
	}

	cout << "The length of the entered text is: " << counter <<endl;
	return 0;
}