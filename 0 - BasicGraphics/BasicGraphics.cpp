/********************************
/Assignment 0 Task 1 : BasicGraphics.cpp
/
/By : Edwin Lo
/
/Sept. 19th 2016
/
/This program draws the picture that was shown in the assignment document.
/
/
********************************/

#include <iostream>

using namespace std;

int main(){
	
	for (int b = 0; b < 70; b++){
	cout << "-";
	}
	cout <<endl;
	
	cout <<"| *                                                                  |" <<endl;
	cout <<"| *                                                                  |" <<endl;
	cout <<"| *                                                                  |" <<endl;
	cout <<"| *                                                                  |" <<endl;	
	cout <<"| *                                                                  |" <<endl;	
	cout <<"| **********O                                                        |" <<endl;	
	
	for (int a =0; a<12; a++){
	cout << "|                                                                    |"<<endl;
	}	
	
	for (int b = 0; b < 70; b++){
	cout << "-";
	}
	
	return 0;

}