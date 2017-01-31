/********************************
/Assignment 3 Task 1 : factorial.cpp
/
/By : Edwin Lo
/
/Oct. 14th 2016
/
/This program uses a while loop to compute the factorial for any integer between
/0 and 20.
/
********************************/
#include <iostream>

using namespace std;

int main(){

	int integer;
	
	cout << "Enter a number: ";
	
	cin >> integer;
		
	long long factorial = 1;
	int temp = integer;
	
	if (cin.fail()){
		cerr << "Error. Invalid Input.";
		return -1;
	}
	
	else if (integer < 0){
		cerr << "Error. Input is not between 0 and 20."<<endl;
		return -1;
	}
	
	else if (integer == 0){
		factorial = factorial;
	}
	
	else if (integer > 1 && integer < 21){
		
		while (temp != 0){
		factorial = factorial * temp;
		temp--;
		}
		
	}
	
	cout << "Its factorial is ";
	cout << factorial << endl;
	
	return 0;

}