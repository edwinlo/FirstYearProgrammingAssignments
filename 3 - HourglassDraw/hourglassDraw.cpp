/********************************
/Assignment 3 Task 6 : hourglassDraw.cpp
/
/By : Edwin Lo
/
/Oct. 14th 2016
/
/This program draws a filled hourglass using asterisks with a certain
/base dimension as entered from the keyboard.
/
********************************/

#include <iostream>

using namespace std;

void drawHourglass (int base){

	int height, counter;
	counter = 0;
	
	char space = ' ';
	char asterisk = '*';
	height = (base / 2) + 1;
	
	//top part of hourglass
	for (int a = 0; a < height; a++){
		for (int a = 0; a < counter; a++){
			cout << space; 
		}
		for (int b = 0; b <= base - 1; b++){
			cout << asterisk;
		}
		cout << endl;
		base -= 2;
		counter += 1;
	}
	
	counter -= 1;
	
	//for bottom part of hourglass
	for (int a = 1; a < height; a++){
		for (int a = counter-1; a > 0; a--){
			cout << space; 
		}
		for (int b = 0; b <= base+ 3; b++){
			cout << asterisk;
		}
		cout << endl;
		base += 2;
		counter -= 1;
	}

}

int main(){

	int base;
	
	cout << "Please enter the base/height (odd number) of the hour-glass: ";
	cin >> base;
	
	//error checking
	if (((base % 2) != 0) && (base > 0)) {
		drawHourglass(base);
	}
	
	else {
		cerr << "Error. Invalid input." <<endl;
		return -1;
	}

	return 0;
}