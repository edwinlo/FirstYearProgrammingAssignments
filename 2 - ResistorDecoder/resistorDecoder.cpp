/********************************
/Assignment 2 Task 3 : resistorDecoder.cpp
/
/By : Edwin Lo
/
/Oct. 3rd 2016
/
/This program takes the color coding of a four-band resistor and derives
/the corresponding resistances along with the tolerance level.
/
********************************/
#include <iostream>
#include <cmath>

using namespace std;

int main(){

	char userInput[4];;
	double firstBand, secondBand, thirdBand, fourthBand;
	double resistance;
	double tolerance;
	
	cout << "Enter the four resistor color codes: ";
	cin >> userInput[0] >> userInput[1] >> userInput[2] >> userInput[3];
	
	switch(userInput[0]){
		case 'k' :
			firstBand = 0;
			break;
		case 'n' :
			firstBand = 10;
			break;
		case 'R' : 
			firstBand = 20;
			break;
		case 'O' :
			firstBand = 30;
			break;
		case 'Y' : 
			firstBand = 40;
			break;
		case 'G' :
			firstBand = 50;
			break;
		case 'B' : 
			firstBand = 60;
			break;
		case 'V' :
			firstBand = 70;
			break;
		case 'y' :
			firstBand = 80;
			break;
		case 'W' :
			firstBand = 90;
			break;
		default :
			cerr <<"Error. Invalid color.";
			return(-1);	
	}
	
	switch(userInput[1]){
		case 'k' :
			secondBand = 0;
			break;
		case 'n' :
			secondBand = 1;
			break;
		case 'R' : 
			secondBand = 2;
			break;
		case 'O' :
			secondBand = 3;
			break;
		case 'Y' : 
			secondBand = 4;
			break;
		case 'G' :
			secondBand = 5;
			break;
		case 'B' : 
			secondBand = 6;
			break;
		case 'V' :
			secondBand = 7;
			break;
		case 'y' :
			secondBand = 8;
			break;
		case 'W' :
			secondBand = 9;
			break;
		default :
			cerr <<"Error. Invalid color.";
			return(-1);	
	}
	
	switch(userInput[2]){
		case 'k' :
			thirdBand = 1;
			break;
		case 'n' :
			thirdBand = 10;
			break;
		case 'R' : 
			thirdBand = 100;
			break;
		case 'O' :
			thirdBand = 1000;
			break;
		case 'Y' : 
			thirdBand = 10000;
			break;
		case 'G' :
			thirdBand = 100000;
			break;
		case 'B' : 
			thirdBand = 1000000;
			break;
		case 'V' :
			thirdBand = 10000000;
			break;
		case 'y' :
			thirdBand = 100000000;
			break;
		case 'W' :
			thirdBand = 1000000000;
			break;
		case 'd' :
			thirdBand = 0.1;
			break;
		case 'S' : 
			thirdBand = 0.01;
			break;
		default :
			cerr <<"Error. Invalid color.";
			return(-1);	
	}
	
	switch(userInput[3]){
		case 'n' :
			fourthBand = 0.01;
			break;
		case 'R' :
			fourthBand = 0.02;
			break;
		case 'G' :
			fourthBand = 0.005;
			break;
		case 'B' :
			fourthBand = 0.0025;
			break;
		case 'V' :
			fourthBand = 0.001;
			break;
		case 'y' :
			fourthBand = 0.0005;
			break;
		case 'd' :
			fourthBand = 0.05;
			break;
		case 'S' :
			fourthBand = 0.10;
			break;
		case 'N' :
			fourthBand = 0.20;
			break;
		default :
			cerr <<"Error. Invalid color.";
			return(-1);				
	}
	
	resistance = (firstBand + secondBand) * thirdBand;
	tolerance = resistance * fourthBand;
	
	cout << "Resistance is ";
	cout << resistance;
	cout << " ohms (+/-";
	cout << tolerance;
	cout << " ohms tolerance)"<<endl;

}