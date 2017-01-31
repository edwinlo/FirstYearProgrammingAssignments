/********************************
/Assignment 3 Task 5 : triangleDraw.cpp
/
/By : Edwin Lo
/
/Oct. 14th 2016
/
/Draws a triangle with an odd number base.
/
********************************///triangleDraw.cpp
//By: Edwin Lo
//Draw a triangle with an odd number base.

#include <iostream>

using namespace std;

void drawTriangle(int base){

	int counter, height;
	counter = 0;
	
	char space = ' ';
	char asterisk = '*';
	height = (base / 2) + 1;
	
	for (int a = 0; a <= height; a++){
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
}

int main(){

	int base;
	
	cout << "Please enter an odd size for the base of the triangle: ";
	cin >> base;
	
	if (((base % 2) != 0) && (base > 0)) {
		drawTriangle(base);
	}
	
	else {
		cerr << "Error. Invalid input." <<endl;
		return -1;
	}


	return 0;
}