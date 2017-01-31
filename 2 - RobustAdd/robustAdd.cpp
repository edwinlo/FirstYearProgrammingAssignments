/********************************
/Assignment 2 Task 3 : robustAdd.cpp
/
/By : Edwin Lo
/
/Oct. 3rd 2016
/
/This program takes two signed integer inputs from te keyboard and output their sum.
/Also checks if the input is valid or not.
/
********************************/
#include <iostream>
#include <climits>

using namespace std;

int main(){

	int userInput1;
	int userInput2;
	bool valid = cin.good();
	
	cout << "Enter two integers to add: ";
	cin >> userInput1 >> userInput2;

	if (valid){
		
		char next = cin.get();
		bool endOfInt = (next == ' ') || (next == '\n');
		int sum = userInput1 + userInput2;
		
		if (endOfInt && (sum < INT_MAX) && (sum > INT_MIN) ){
					
			cout <<"Sum of two numbers is: ";
			cout << sum <<endl;
				
		}
			
		else {
				
			cerr << "Error: Summed value out of the signed int range or Non-Integer. ";
			return(-1);
			}
									
		}
	
	if (cin.fail()){
		
		cerr << "Error: Invalid Input. Not an integer."<<endl;
		return(-1);
		
	}
	
	return 0;
}
