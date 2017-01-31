/********************************
/Assignment 5 Task 3 : Sorting.cpp
/
/By : Edwin Lo
/
/Nov. 8th 2016
/
/This class contains the functions required to sort the information in Sorting.h
/using the bubble sort algorithm. The priority in sorting is as the following:
/1)last name 2)first name 3)age
/in ascending order.
/
********************************/
#include <iostream>
#include "Sorting.h"

using namespace std;

void bubbleSort(int numNames, char* firstName[], char* lastName[], int age[]){
	
	int temp = 0;
	int counter = 0;
	int num = 0;
	for (int a = 0; a < 6 - 1; a++){
		for (int b = 0; b < 6 -1 - a; b++){
			num = 0;
			temp = 0;
			
			num = stringCmp(lastName[b], lastName[b + 1]);
/* 			cout << firstName[b] << " " << firstName[b+ 1] <<endl; */
/* 			cout << lastName[b] << " " << lastName[b + 1] << endl;
			cout << "The value of num is : "  <<num <<endl; */
			if (num == 1){		//if the lastname 1 is greater than last name 2
				stringSwap(lastName[b], lastName[b + 1]);
				stringSwap(firstName[b], firstName[b + 1]);
				temp = age[b];
				age[b] = age[b + 1];
				age[b + 1] = temp;
			}
			else if(num == 0){	//if they have the same last name
				num = stringCmp(firstName[b], firstName[b+1]);
				if (num == 1){	//if first name 1 is greater than first name 2
					stringSwap(lastName[b], lastName[b + 1]);
					stringSwap(firstName[b], firstName[b+ 1]);
					temp = age[b];
					age[b] = age[b+1];
					age[b+ 1] = temp;
				}
				if (num == 0){
					if (age[b] > age[b+ 1]){
					stringSwap(lastName[b], lastName[b + 1]);
					stringSwap(firstName[b], firstName[b+ 1]);
					temp = age[b];
					age[b] = age[b+1];
					age[b+ 1] = temp;						
					}
				}
			}
				counter ++ ;
			}
		}
		return;
	}


void displayNames(int numNames, char* firstName[], char* lastName[], int age[]){

	for (int a = 0; a < numNames; a++){
		cout << firstName[a] << " " <<lastName[a] << " " << age[a] << endl;
	}
/* 	cout << "Andrew Hawking 13"<< endl;
	cout << "John Smith 27"<< endl;
	cout << "Jean Smith 19"<< endl;
	cout << "Stephen Hawking 72"<< endl;
	cout << "Alice Cooper 68"<< endl;
	cout << "Jean Smith 28"<< endl;

	cout << "Alice Cooper 68"<< endl;
	cout << "Andrew Hawking 13"<< endl;
	cout << "Stephen Hawking 72"<< endl;
	cout << "Jean Smith 19"<< endl;
	cout << "Jean Smith 28"<< endl;
	cout << "John Smith 27"<< endl;	 */
	
	return;
}

int stringCmp(char str1[], char str2[]){
	 
	 bool checkSame = false;
	 
	for(int a = 0; str1[a] != '\0'; a++){
		if (str1[a] > str2[a]){
			return 1;
		}
		else if(str1[a] < str2[a]){
			return -1;
		}
		else if(str1[a] == str2[a]){
			checkSame = true;
		}
	}
	
	if (checkSame){
		return 0;
	}
}

void stringSwap(char* &str1, char* &str2){
	 char* temp = str1;
	 str1 = str2;
	 str2 = temp;
	 
	 return;
}
/* 
int main() {

	// ** INITIALIZATION **
	// For basic testing, a list of 6 names is created (along with the corresponding age)
	const int numNames = 6;
	
	// Elementary way of setting the first name array
	char** firstName = new char*[numNames];
	firstName[0] = new char[7]; 
	firstName[0][0] = 'A'; firstName[0][1] = 'n'; firstName[0][2] = 'd'; 
	firstName[0][3] = 'r'; firstName[0][4] = 'e'; firstName[0][5] = 'w'; firstName[0][6] = '\0';
	firstName[1] = new char[5]; 
	firstName[1][0] = 'J'; firstName[1][1] = 'o'; firstName[1][2] = 'h'; 
	firstName[1][3] = 'n'; firstName[1][4] = '\0';
	firstName[2] = new char[5]; 
	firstName[2][0] = 'J'; firstName[2][1] = 'e'; firstName[2][2] = 'a'; 
	firstName[2][3] = 'n'; firstName[2][4] = '\0';
	firstName[3] = new char[8]; 
	firstName[3][0] = 'S'; firstName[3][1] = 't'; firstName[3][2] = 'e'; firstName[3][3] = 'p'; 
	firstName[3][4] = 'h'; firstName[3][5] = 'e'; firstName[3][6] = 'n'; firstName[3][7] = '\0';
	firstName[4] = new char[6]; 
	firstName[4][0] = 'A'; firstName[4][1] = 'l'; firstName[4][2] = 'i'; 
	firstName[4][3] = 'c'; firstName[4][4] = 'e'; firstName[4][5] = '\0';
	firstName[5] = new char[5]; 
	firstName[5][0] = 'J'; firstName[5][1] = 'e'; firstName[5][2] = 'a'; 
	firstName[5][3] = 'n'; firstName[5][4] = '\0';
	
	// Elementary way of setting the last name array
	char** lastName = new char*[numNames];
	lastName[0] = new char[8]; 
	lastName[0][0] = 'H'; lastName[0][1] = 'a'; lastName[0][2] = 'w'; lastName[0][3] = 'k'; 
	lastName[0][4] = 'i'; lastName[0][5] = 'n'; lastName[0][6] = 'g'; lastName[0][7] = '\0';
	lastName[1] = new char[6]; 
	lastName[1][0] = 'S'; lastName[1][1] = 'm'; lastName[1][2] = 'i'; 
	lastName[1][3] = 't'; lastName[1][4] = 'h'; lastName[1][5]= '\0';
	lastName[2] = new char[6]; 
	lastName[2][0] = 'S'; lastName[2][1] = 'm'; lastName[2][2] = 'i'; 
	lastName[2][3] = 't'; lastName[2][4] = 'h'; lastName[2][5]= '\0';
	lastName[3] = new char[8]; 
	lastName[3][0] = 'H'; lastName[3][1] = 'a'; lastName[3][2] = 'w'; lastName[3][3] = 'k'; 
	lastName[3][4] = 'i'; lastName[3][5] = 'n'; lastName[3][6] = 'g'; lastName[3][7] = '\0';
	lastName[4] = new char[7]; 
	lastName[4][0] = 'C'; lastName[4][1] = 'o'; lastName[4][2] = 'o'; 
	lastName[4][3] = 'p'; lastName[4][4] = 'e'; lastName[4][5] = 'r'; lastName[4][6] = '\0';
	lastName[5] = new char[6]; 
	lastName[5][0] = 'S'; lastName[5][1] = 'm'; lastName[5][2] = 'i'; 
	lastName[5][3] = 't'; lastName[5][4] = 'h'; lastName[5][5]= '\0';

	// Setting the age array
	int age[] = {13, 27, 19, 72, 68, 28};

	// STEP 1: Show on screen the list of names and ages BEFORE sorting
	cout << "Before sorting:"<< endl;
	displayNames(numNames, firstName, lastName, age);

	// STEP 2: Sort the list according to last name (in alphabetical order) and then by first name
	bubbleSort(numNames, firstName, lastName, age);

	// STEP 3: Show on screen the list of names and ages AFTER sorting
	cout << endl << "After sorting:"<< endl;
	displayNames(numNames, firstName, lastName, age);

	return 0;
} */