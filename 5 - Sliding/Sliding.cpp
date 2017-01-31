/********************************
/Assignment 5 Task 2 : Sliding.cpp
/
/By : Edwin Lo
/
/Nov. 8th 2016
/
/Within this main() function, the following operations should be performed:

1)	Convert numerical strings within the argv array into int values, and store them respectively
	in a variable that stores the sliding window size and an array that stores all the raw voltage readings.
	You can reuse the convertToIntArray() function that you have developed in Task 1 to
	achieve this operation (you can assume that the voltage measurement values entered into the
	program are all integers). Also, in line with Task 1, the maximum number of voltage measurements
	to be handled is limited to 20 (though do not forget about the extra value specifying the size of the
	sliding window when dealing with command-line arguments!).

2)  Calculate the sliding-window average values based on the raw voltage data input. This will be
	done through a call to the function with signature described in (b) (see below).

3)  Draw a histogram of raw voltage input data.

4)  Draw another histogram
/
********************************/
#include <iostream>
#include <cmath>

using namespace std;

int convertToIntArray(int argc, char* argv[], int array[]){
	int counter = 0;
	int counter2 = 0;
	long long int test = 0;
	int decimalPosition = 0;
	int power = 10;
	char input[100];
	bool negative = false;
	
	for (int a = 1; a < argc; a++){
		for (int b = 0; argv[a][b] != '\0'; b++){
			if (argv[a][b] == '-' || argv[a][b] == '0'|| argv[a][b] == '1'|| argv[a][b] == '2'|| argv[a][b] == '3'|| argv[a][b] == '4'|| argv[a][b] == '5'|| argv[a][b] == '6'|| argv[a][b] == '7'|| argv[a][b] == '8'||argv[a][b] == '9' ||argv[a][b] == '.'){
			}
			else{
				return -counter;		//checking for invalid input
			}
		}
		counter ++;
	}
	counter = 0;	
	for (int a = 1; a < argc; a++){
/* 		decimalPosition = 0; */
		power = 10;
		test = 0;
		counter = 0;
		negative = false;
		for (int b = 0; argv[a][b] != '\0'; b++){
			if (argv[a][b] == '-'){
				negative = true;
			}
/* 			else if(argv[a][b] == '.'){
				decimalPosition = counter;
			} */
			else{
				input[b] = argv[a][b];
				counter ++;
			}
		}
		if(negative){
			test = input[counter] -48;
			array[a] = input[counter]- 48;
			for (int d = counter - 1; d > 0; d--){
				test = test + (input[d] - 48) * power;
				array[a] = array[a] + ((input[d] - 48) * power);
				power *= 10;
			}
			test = -test;
			array[a] = -array[a];
			
			if (test < -2147483647){	// checking for out of bounds integer
				return 21;
			}
		}
		else {
			test = input[counter - 1] -48;

			array[a] = input[counter - 1]- 48;
			for (int c = counter -2; c >= 0; c--){
				test = test + (input[c] -48) * power;
				array[a] = array[a] + ((input[c] - 48) * power);
				power *= 10;
			}
			if (test > 2147483647){
				return 21;				//checking fo out of bounds integer
			}
		}
		counter2++;
	}
	return counter2 - 1;

}

int slideAvg(int inputVoltages[], int sampleSize, int windowSize, float slidingAverage[]){
	
	int counter = 0;
	int numAvg = sampleSize - windowSize + 1;
	if (numAvg <= 0) {
		return -1;
	}
	for(int a = 2; a < numAvg + 2; a++){
		for(int b = 0; b < windowSize; b++){
			slidingAverage[a - 2] = (int)(slidingAverage[a - 2] + inputVoltages[a + b]);
		}
		slidingAverage[a - 2] = (slidingAverage[a - 2] / windowSize);
		counter ++;
	}
	
	return counter;
}

void displayHistogram(int numElements, float array[]){ 		//for float array
	
	int counter = 0;
	
	cout << "100V------105V------110V------115V------120V------125V------130V------135V------140V" <<endl;
	for (int a = 0; a < numElements; a++){
		counter = 0;
		array[a] = round((array[a]) * 2);
		array[a] = array[a] /2;
		counter = ((array[a] - 100 )/ 0.5 + 1); 
		if (counter <= 0){
			cout << "!"<<endl;
		}
		else if (counter > 81){
			for (int b = 0; b < 81; b++){
				cout << "#";
			}
			cout << "+";
			cout <<endl;
		}
		else {
			for (int c = 0; c < counter; c++){
				cout << "#";
			}
			cout << endl;
		}
	}
	return;
}

void displayHistogram(int numElements, int array[]){ 	//for inputvoltages array
	
	int counter = 0;
	
	cout << "100V------105V------110V------115V------120V------125V------130V------135V------140V" <<endl;
	for (int a = 2; a < numElements + 2; a++){
		counter = 0;
		array[a] = round((array[a]*2));
		array[a] = array[a] / 2;
/* 		cout << array[a]<<endl; */
		counter = ((array[a] - 100 )/ 0.5 + 1); 
		if (counter <= 0){
			cout << "!"<<endl;
		}
		else if (counter > 81){
			for (int b = 0; b < 81; b++){
				cout << "#";
			}
			cout << "+";
			cout <<endl;
		}
		else {
			for (int c = 0; c < counter; c++){
				cout << "#";
			}
			cout << endl;
		}
	}
	return;
}


int main(int argc, char* argv[]){
	
	if (argc < 3){
		cerr <<"Error. Not enough arguments. " <<endl;
		return -1;
	}
	
	int numInt = 0;
	int numAverages = 0;
	int inputVoltages[argc - 2];
	float slidingAverage[argc - 2];
	for (int a = 0; a < argc -2; a++){
		slidingAverage[a] = 0;
	}
	
	numInt = convertToIntArray(argc, argv, inputVoltages);
	
	if (inputVoltages[1] <= 0){
		cerr<<"Error, Invalid window size."<<endl;
		return -1;
	}
	
	if (numInt < -20){
		cerr << "Error: too many input arguments; maximum 20 permitted." <<endl;
		return -1;
	}
	else if (numInt == 21){
		cerr <<"Error: out of bounds integer. "<<endl;
		return -1;
	}
	else if (numInt < 0 && numInt > -20){
		cerr << "Error: argument number " << numInt << " is an invalid input."<<endl;
		return -1;
	}
	
	numAverages = slideAvg(inputVoltages, numInt, inputVoltages[1], slidingAverage);
	
	if (numAverages == -1){
		cerr <<"Error. Invalid arguments." <<endl;
		return -1;
	}
	
/* 	for (int a =0; a < numAverages; a++){
		cout << "The sliding averages are " << slidingAverage[a]<<endl;
	}

	cout << "The num int is " << numInt <<endl;
	
	for (int b = 2; b <= numInt + 1 ; b++){
		cout << "The inputVoltages are : "<< inputVoltages[b] <<endl;
		
	} */
	
	displayHistogram(numInt, inputVoltages);	
	displayHistogram(numAverages, slidingAverage);

	return 0;
}