/********************************
/Assignment 3 Task 4 : singleRowSnake.cpp
/
/By : Edwin Lo
/
/Oct. 14th 2016
/
/This program prints a rightward-facing snake that is trapped
/within the left and right walls on a single row.
/
********************************/
#include <iostream>

using namespace std;

int main(){

	char snakeBody ='*';
	char snakeHead = 'O';
	char wall = '|';
	char output[50] = " ";

	int userInput1, userInput2, userInput3;
	
	
	cout << "Wall-to-wall dimension: ";
	cin >> userInput1;
	
	cout << "Snake length: ";
	cin >> userInput2;
	
	cout << "Wall-to-snake tail distance: ";
	cin >> userInput3;
	
	if ( userInput1 <= 0){
		cerr << "Error. Invalid Input.";
		return -1;
	}
	

	int counter = 0;
	
	output[0] = wall;
	output[userInput1 -1] = wall;

	if ((userInput2 < userInput1 )&& (userInput1) <= (userInput2 + userInput1) && (userInput2 != 0 & userInput3 != 0)){
		
		if (userInput3 !=0){
			for (int a = 1 ; a <= userInput3; a++){
				output[a] = ' ';
			}
		}
		for (int a = userInput3 + 1; a <= userInput3 + userInput2 - 1 ; a++  ){
			output[a] = snakeBody;
		}
		

		output[userInput3 + userInput2] = snakeHead;
		
		for (int a = userInput3 + userInput2 + 1; a <= userInput1 -2 ; a++){
			output[a] = ' ';
		}
		
		cout << output <<endl;
	}
	
	else if(userInput3 == 0){
		
		for (int a = userInput3 + 1; a <= userInput3 + userInput2 - 1 ; a++  ){
			output[a] = snakeBody;
		}
		if (userInput2 != 0){
		output[userInput3 + userInput2] = snakeHead;
	}
		for (int a = userInput3 + userInput2 + 1; a <= userInput1 -2 ; a++){
			output[a] = ' ';
		}
			
		cout << output <<endl;
		
	}
	
	else if (userInput2 == 0 && userInput3 > 0){
		
		for (int a = 1; a < userInput1 - 1; a++){
			output[a] = ' ';
		}
				cout << output <<endl;
	}
	else if( userInput2 == 0 && userInput3 == 0){
		
		for (int a = 1; a < userInput1 - 1; a++){
			output[a] = ' ';		
		
		}
		
		cout << output <<endl;
		
		
	}
	else {
		cerr << "Error. Invalid Input!" << endl;
		return -1;
	}
	return 0;
	


}