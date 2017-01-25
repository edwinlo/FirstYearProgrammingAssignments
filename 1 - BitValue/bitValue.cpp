/********************************
/Assignment 1 Task 4 : bitValue.cpp
/
/By : Edwin Lo
/
/Sept. 26th 2016
/
/This program outputs the value of the binary digit at a specific
/position of an integer. 
/
********************************/
#include <iostream>

using namespace std;

int main(){

	int a = 0;
	int b = 0;

	cout << "Enter two integer numbers (each separated by a space): ";
	cin >> a >> b;
	
	int c = a >> b;
	
	int d = c&1;
	
	
	cout << "The value of Bit " << b << " is " << d <<endl;

	return 0;
}