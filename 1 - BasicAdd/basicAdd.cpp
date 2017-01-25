/********************************
/Assignment 1 Task 4 : basicAdd.cpp
/
/By : Edwin Lo
/
/Sept. 26th 2016
/
/This program takes in the input of three integers and adds the first two together, and then the 
/second and the third integer together afterwards.
/
********************************/
#include <iostream>

using namespace std;

int main(){

	int A = 0;
	int B = 0;
	unsigned int C = 0;
	
	cout << "Enter three integer numbers (each separated by a space): ";
	cin >> A >> B >> C ;
	
	cout << "A + B = ";
	cout << A+B<<endl;
	
	cout << "B + C = ";
	cout << B+C<<endl;
	
	return 0; 


}