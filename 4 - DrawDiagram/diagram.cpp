/********************************
/Assignment 4 Task 2 : diagram.cpp
/
/By : Edwin Lo
/
/Nov. 1st 2016
/
/This program prints off a display and simulates "sending a character flying across the screen".
/
********************************/
#include <iostream>
#include "stdlib.h"

using namespace std;

int main(){
	
	char column = '=';
	char letter = '0';
	char row2[60];
	
	for (int a = 0; a <= 60; a++){
		row2[a] = ' ';
	}

	int counter = 0;
	
	while (counter !=60){
		
		system("cls");
		
		for (int a = 0; a < 60; a++){
			cout << column;
		}
		
		cout << endl;
		
		if (counter >0){
			row2[counter - 1] = ' ';
		}
		
		row2[counter] = 'O';
		
		cout << row2 << endl;
		
		for (int a = 0; a < 60; a++){
			cout << column;
		}
		
		for(int i = 0; i < 1000000; i++){
			i = (i + i) / 2;
		}
		
		counter++;
	}
	
	return 0;
}