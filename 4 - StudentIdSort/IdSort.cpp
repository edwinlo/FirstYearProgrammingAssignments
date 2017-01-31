/********************************
/Assignment 4 Task 1 : IdSort.cpp
/
/By : Edwin Lo
/
/Nov. 1st 2016
/
/This program allows the user to input 5 student IDs and uses the bubble sort
/algorithm to sort the 5 IDs in descending order.
/
********************************/
#include <iostream>

using namespace std;

int main(){

	int id[5];
	int swapCount = 0;
	int temp = 0;
	int newId;
	bool checkSwap = false;

	cout << "Enter 5 ID: ";
	
	for (int a = 0; a < 5; a++){
		cin >> id[a];
		if (cin.fail()){
			cerr << "Error. Invalid input." << endl;
			return -1;
		}
	}
	
	while (cin.good() && checkSwap == false){
	
		for (int a = 0; a < 5; a++){
			for (int b = 0; b < 4; b++){
				if (id[b] < id[b+1]){
					temp = id[b];
					id[b] = id[b+1];
					id[b+1] = temp;
					swapCount++;
				}
			}
		}
		
		checkSwap = true;
	}
	
	cout << "Sorted ID: ";
	
	for (int a = 0; a < 5; a++){
		cout << id[a] << " ";
	}
	
	cout << "\nSwap count: " << swapCount <<endl;
	
	cout << "Enter another input: ";
	cin >> newId;
	
	if (cin.fail()){
		cerr << "Error. Invalid input." << endl;
		return -1;
	}
	
	for (int d = 0; d < 5; d++){
		if (newId == id[d]){
			cerr << "Error: This ID exists."<<endl;
			return -1;
		}
	}
	
	checkSwap = false;
	id[5] = newId;
	
	while (cin.good() && !checkSwap){
	
		for (int a = 0; a < 6; a++){
			for (int b = 0; b < 5; b++){
				if (id[b] < id[b+1]){
					temp = id[b];
					id[b] = id[b+1];
					id[b+1] = temp;
					swapCount++;
				}
			}
		}
		
		checkSwap = true;
	}	
	
	int pos;
	
	for (int j = 0; j < 6 ; j++){
		if (id[j] == newId){
			pos = j;
		}
	}
	cout << "The value of " << newId<< " is in position " << pos<< endl;
	
	return 0;
}