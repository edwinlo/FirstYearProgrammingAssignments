/********************************
/Assignment 1 Task 1 : passcode.cpp
/
/By : Edwin Lo
/
/Sept. 26th 2016
/
/This program takes in three characters from the keyboard
/and determines an 8-9 digit passcode according to the given rule:
/ 		passcode = 1000000Aascii + 1000Bascii + Cassci
/
********************************/
#include <iostream>

using namespace std;

int main(){
	
	char userInput[2];
	char AASCII, BASCII, CASCII;
	int passcode = 0;
	
	cout << "Enter three characters consecutively without space: ";
	cin >> userInput;
	
	AASCII = userInput[0];
	BASCII = userInput[1];
	CASCII = userInput[2];

	passcode = 1000000 * AASCII + 1000 * BASCII + CASCII;
	
	cout << "The corresponding passcode is: ";
	cout <<passcode<<endl;
	
	
	return 0;

}