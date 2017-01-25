/********************************
/Assignment 1 Task 3 : floatPtNum.cpp
/
/By : Edwin Lo
/
/Sept. 26th 2016
/
/This program gets the user to input two numbers, then divides the first number by the second number.
/
********************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	
	double A;
	double B;
	
	cout << setprecision(20) << fixed;
	
	cout << "Enter two numbers (each separated by a space) : ";
	cin >> A >> B;
	
	cout << "A/B = " << (A/B) <<endl;
	
	return 0;


}