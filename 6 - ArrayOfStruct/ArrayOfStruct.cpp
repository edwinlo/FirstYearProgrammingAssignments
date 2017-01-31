/********************************
/Assignment 6 Task 2 : ArrayOfStruct.cpp
/
/By : Edwin Lo
/
/Nov. 22nd 2016
/
/This class contains the functions required to sort the information in ArrayOfStruct.h and
/ArrayOfStrcutMain.cpp using the bubble sort algorithm. The priority in sorting is as the following:
/1)last name 2)first name 3)age
/in ascending order. The information is stored using person structs
/
********************************/
#include <iostream>
#include <fstream>

#include "ArrayOfStruct.h"

using namespace std;

/*    struct Person {
  char firstName[20];
  char lastName[20];
  int age;
};

void bubbleSort(int numPeople, Person people[]);
void displayNames(int numPeople, Person people[]);  */
int stringCmp(char str1[], char str2[]);
//int stringCmp2(char str1[], char str2[]);

void peopleSwap(struct Person &people1, struct Person &people2){
/* 	cout << "people 1 " << *people1 << endl;
	cout << "people 2 " << *people2 <<endl; */
	 Person temp = people1;
	 people1 = people2;
	 people2 = temp;
	 
	 return;
}

void bubbleSort(int numPeople, Person people[]){
	
	int temp = 0;
	int counter = 0;
	int num = 0;
/* 	char* firstName1[20];
	char* firstName2[20];
	char* lastName1[20];
	char* lastName2[20];
	 */
	for (int a = 0; a < numPeople; a++){
		for (int b = 0; b < numPeople - 1 - a; b++){
			num = 0;
			temp = 0;
/* 		//	for (int c = 0; people[b].firstName[c] != ' '; c++){
				firstName1[b] = people[b].firstName;
		//	}
		//	for (int d = 0; people[b + 1].firstName[d] != ' '; d++){
				firstName2[b] = people[b+1].firstName;
		//	}
	//		for (int e = 0; people[b].lastName[e] != ' '; e++){
				lastName1[b] = people[b].lastName;
	//		}
	//	for (int f = 0; people[b + 1].lastName[f] != ' '; f++){
				lastName2[b] = people[b+1].lastName;
	//		} */

		//	cout << people[b].lastName << " ASD " << people[b+1].lastName <<endl; 
	
			num = stringCmp(people[b].lastName, people[b+1].lastName);
//			cout << "num is : " << num<<endl;
 			cout << people[b].firstName << " " << people[b+1].firstName <<endl; 
 			cout << people[b].lastName << " " << people[b+1].lastName << endl;
			cout << "The value of num is : "  <<num <<endl; 
			if (num == 1){		//if the lastname 1 is greater than last name 2
				peopleSwap(people[b], people[b + 1]);
	//		cout << people[b].lastName << " ASD " << people[b+1].lastName <<endl; 				
			}
			else if(num == 0){	//if they have the same last name
				num = stringCmp(people[b].firstName, people[b+1].firstName);
				cout << "ASdasdasdasdasdasd num " <<num <<endl;
				if (num == 1){	//if first name 1 is greater than first name 2
					peopleSwap(people[b], people[b + 1]);
				}
				if (num == 0){
					if (people[b].age > people[b+1].age){
					peopleSwap(people[b], people[b + 1]);						
					}
				}
			}
				counter ++ ;
			}
		}
		return;
	}


void displayNames(int numPeople, Person people[]){

	for (int a = 0; a < numPeople; a++){
		cout << people[a].firstName << " " << people[a].lastName << " " << people[a].age << endl;
	}
	return;
}

int stringCmp(char str1[], char str2[]){
	
	int counter = 0;
	bool checkSame = false;
	char temp1[30];
	char temp2[30];
	
	while (str1[counter] != '\0'){
		temp1[counter] = str1[counter];
		counter ++;
	}
	temp1[counter] = '\0';
	counter = 0;
	while (str2[counter] != '\0'){
		temp2[counter] = str2[counter];
		counter++;
	}
	temp2[counter] = '\0';
//	cout << "temp1 " << temp1 <<endl;
//	cout << "temp2 " << temp2 <<endl;
	
	counter =0;
	while (temp1[counter] != '\0'){
		if (temp1[counter] >= 97 && temp1[counter] <= 122){
			temp1[counter] = temp1[counter] - 32;
		}
		counter++;
	}
	counter = 0;
	
	while (temp2[counter] != '\0'){
		if (temp2[counter] >= 97 && temp2[counter] <= 122){
			temp2[counter] = temp2[counter] - 32;
		}
		counter ++;
	}
	
//	cout << temp1 << " asd " << temp2 <<endl;
	int a = 0;
	while(temp1[a] != '\0' || temp2[a] != '\0'){
		if (temp1[a] > temp2[a]){
			return 1;
		}
		else if (temp1[a] < temp2[a]){
			return -1;
		}
		else if (temp1[a] == temp2[a]){
			checkSame = true;
		}
		a++;
	}
	
	if (checkSame){
		return 0;
	}
}

/*    int read(ifstream & fin, Person people[])
{
	int i = 0;
	
	while (i < 20 && fin >> people[i].firstName)
	{
		fin >> people[i].lastName >> people[i].age ;
		i++;
	}
	return i;
}


int main() {
  ifstream fin ("members.txt");
  if (fin.fail()) {
      cerr << "Error: file not open.\n";
      return -1;
  }
  
  Person people[20];
  int numPeople = read(fin, people);
  cout << "Before Sorting:\n\n";
  displayNames(numPeople, people);
  
  bubbleSort(numPeople, people);
  
  cout << "\n\nAfter Sorting:\n\n";
  displayNames(numPeople, people);
	
  return 0;
}    */