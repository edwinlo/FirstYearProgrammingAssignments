/********************************
/Assignment 4 Task 3 : marquee.cpp
/
/By : Edwin Lo
/
/Nov. 1st 2016
/
/This program prints off a marquee cycle, and allows the user to specify
/the number of marquee rotations.
/
********************************/
#include <iostream>
#include "stdlib.h"

using namespace std;

void printColumn(){
	
	char column = '=';
	for (int a = 0; a <= 60; a++){
		cout << column;
	}
	return;
}

int main(){

	int rotations = 0;
	int counter = 0;
	int temp = 0;
	char marquee[] = "!ECE150!";

	cout << "Enter the number of cycles: ";
	cin >> rotations;
	
	if (cin.fail()){
		cerr << "Error. Invalid Input.";
		return -1;
	}
	
	if (rotations <= 0){
		cerr << "Error. Invalid Input.";
		return -1;
	}
	
	while (cin.good() && rotations > 0){
		
		counter = 0;
		temp = 0;
		
		for (int a = 0; a <= 60; a++){
			
			system("cls");
			
			printColumn();		
			cout << endl;
			
			if (counter > 60 - 8){
				
				for(int c = 60 - counter; c < 8; c++){
					cout << marquee[c];
					temp++;
				}
				for (int d = 0; d < 52; d++ ){
					 cout << " " ;
				}
				for (int e = 0; e < 60 - counter; e++){
					cout << marquee[e];
				}
			}
			
			else if (counter <= 60 - 8 || counter > 60){
				for (int b = 0; b < counter; b++){
					cout << " ";
				}
				for (int d = 0; d < 8; d++){
					cout <<marquee[d];
				}
			}

			cout << endl;
			
			printColumn();
			
			cout << endl;
			
			counter ++;
			
			for(int i = 0; i < 10000000; i++){
				i = (i + i) / 2;
			}
		}
		rotations--;	
	}
	

		

	return 0;
}
	
	