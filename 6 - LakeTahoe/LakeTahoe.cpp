/********************************
/Assignment 6 Task 4 : LakeTahoe.cpp
/
/By : Edwin Lo
/
/Nov. 22nd 2016
/
/This class reads the "Lake TahoeDEM.csv", determines minor corrections to the elecation data,
/and calculates an estimate of the surface area and volume of the lake.
/
/The main function is located in LakeTahoeMain.cpp, and LakeTahoe.h is also required to run this
/program.
********************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include "LakeTahoe.h"

using namespace std;

bool readTahoeData(char* filename, float lake[420][210]){
	
	ifstream infile;
	char chr;
	char temp[10];
	int j = 0;
	int b = 0;
	int length;
	int width;
	
	infile.open(filename);
	
	infile >> length >> width;
	
	if (length != 420 || width != 210){
		return false;
	}
	
	if (!infile.good()){
		return false;
	}
	
	for (int a = 0; a < 420; a++){
		for (int b = 0; b < 210; b++){
			
			infile >> lake[a][b];

			while (!isdigit(infile.peek()) && infile.peek() != '-'){
				infile.get(chr);
				if (infile.eof()){
					break;
				}
			}
		}
	}
	
/* 	if (infile.get(char) == '4'){
		if (infile.get(char) == '2'){
			if (infile.get(char) == '0'){
				
			}
		}
	}
	
	while(infile.good()){
		for (int a = 0; a <= 420; a++){
			temp[0] = '\0';
			while (b <= 210){
				infile.get(chr);
				
				if (chr == '.' || chr == '1' || chr == '2' || chr == '3' || chr == '4' || chr == '5' || chr == '6' || chr == '7' || chr == '8' || chr == '9'){
					temp[j] = chr;
					if (infile.peek() == ','){
						temp[j + 1] = '\0';
						lake[a][b] = strtof(temp, NULL);
						cout << lake[a][b] <<endl;
						b++;
					}
				} 
/* 				else if (chr == '\t' || chr == ' '){
					continue;
				}
				 */
/* 			}
		}	
	} */

	return true;
}

void cleanData(float lake[420][210]){
	
	float cleanData[420][210];
	float temp;
	float average;
	int counter = 0;
	
	for (int a = 0; a < 420; a++){ 
		for (int b = 0; b < 210; b++){
			cleanData[a][b] = lake[a][b];
	//		cout << cleanData[a][b] <<endl;
		}
	}
	
	// clean data
	
	for (int a = 0; a < 420; a++){
		for (int b = 0; b < 210; b++){
			if (a == 0 || a == 419 || b == 0 || b == 209){
				counter++;
				cleanData[a][b] = lake[a][b];
			}
			
			else{
				temp = lake[a][b];
				average = (lake[a-1][b-1] + lake[a-1][b] + lake[a-1][b+1] + lake[a][b-1] + lake[a][b+1] + lake[a+1][b-1] + lake[a+1][b] + lake[a+1][b+1])/8;
				average = round(average * 100) /100;
				
				temp = average - temp;
				
				if (temp < 0 ){
					temp = temp*(-1);
				}
				
				if (temp > 100){
					cleanData[a][b] = average;
				//	cout << "The outlier was:" << lake[a][b] << " on " << a << " " << b <<  endl;					
				}
				
				else if (temp <= 100){
					cleanData[a][b] = lake[a][b];
				}
			}
		}
	}
	
	for (int a = 0; a < 420; a++){
		for (int b = 0; b < 210; b++){
			lake[a][b] = cleanData[a][b];
			//cout <<lake[a][b] <<endl;
		}
	}
	
	return;
}

float area(float lake[420][210]){
	
	float sArea = 0;
	
	for (int a = 0; a < 420; a++){
		for (int b = 0; b < 210; b++){
			if (lake[a][b] < 0){
				sArea = sArea + 1;
			}
		}
	}
	
	sArea = sArea * 10000;
	return sArea;
}

float volume(float lake[420][210]){

	float volume = 0;
	
	for (int a = 0; a < 420; a++){
		for (int b = 0; b < 210; b++){
			if (lake[a][b] < 0){
				volume = volume + (lake[a][b]);
			}
		}
	}
	
	volume = volume * (-1) *10000;
	return volume;
}

/* int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Usage Error: " << argv[0] << " <filename>" << endl;
    exit(-1);
  }

  float lake[420][210];
  if (!readTahoeData(argv[1], lake)) {
    cerr << "Unable to read datafile: " << argv[1] << endl;
    exit(-1);
  }

  cleanData(lake);
	cout << "Lake Tahoe area is: " << area(lake) << endl;
	cout << "Lake Tahoe volume is: " << volume(lake) << endl;

  return 0;
} */
 