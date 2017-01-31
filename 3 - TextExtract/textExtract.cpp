/********************************
/Assignment 3 Task 3 : textExtract.cpp
/
/By : Edwin Lo
/
/Oct. 14th 2016
/
/This program takes in a text string (without whitespace) rom the keynoard of up to 100 characters,
/as well as two numerical inputs. The first numberical input denotes the start index, and the 
/second denotes the end index. The program then extracts a subset of the inputted text string
/based on the specified start and end indices.
/
********************************/
#include <iostream>

using namespace std;

int main(){

	char text[100];
	int start, end;
	int counter = 0;
	
	cout << "Please input a word: ";
	cin >> text;

	while (text[counter] != '\0'){
		counter ++;
	}
	
	if (counter > 100){
		cerr << "Error. Too large.";
		return -1;
	}	
	
	cout << "Please input the starting index: ";
	cin >> start;
	
	cout << "Please input the ending index: ";
	cin >> end;
	
	
	if (start < 0 || end > counter || start > end ){
		cerr << "Error. The index is out of range.";
		return -1;
	}
	
	cout << "The extracted word is: ";
	
	for (int a = start; a != end + 1; a++){
		cout << text[a];
	}

	return 0;

}
