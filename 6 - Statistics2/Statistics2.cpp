/********************************
/Assignment 6 Task 1 : Statistics2.cpp
/
/By : Edwin Lo
/
/Nov. 22nd 2016
/
/This program is a redo of Task 1 of Assignment 5 but using "pass by reference" to pass in
/values into each function.

********************************/
#include <iostream>

using namespace std;

int convertToIntArray(int argc, char* argv[], int array[]){
	int counter = 0;
	int counter2 = 0;
	long long int test = 0;
	int power = 10;
	char input[100];
	bool negative = false;
	bool positive = false;
	
	if (argc == 1){
		return 0;
	}
	
	for (int a = 1; a < argc; a++){
		for (int b = 0; argv[a][b] != '\0'; b++){
			if (argv[a][b] == '+' || argv[a][b] == '-' || argv[a][b] == '0'|| argv[a][b] == '1'|| argv[a][b] == '2'|| argv[a][b] == '3'|| argv[a][b] == '4'|| argv[a][b] == '5'|| argv[a][b] == '6'|| argv[a][b] == '7'|| argv[a][b] == '8'||argv[a][b] == '9'){
			}
			else{
				return -counter;		//checking for invalid input
			}
		}
		counter ++;
	}
	
	counter = 0;
	
	for (int a = 1; a < argc; a++){
		power = 10;
		test = 0;
		counter = 0;
		negative = false;
		positive = false;
		for (int b = 0; argv[a][b] != '\0'; b++){
/* 			cout <<argv[a][b] <<endl; */
			if (argv[a][b] == '-'){
				negative = true;
			}
			else if(argv[a][b] == '+'){
				positive = true;
			}
			else{
				input[b] = argv[a][b];
				counter++;
			}
/* 			cout << "The counter is : " << counter <<endl; */
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
/* 			cout << test; */
			if (test < -2147483647){	// checking for out of bounds integer
				return 21;
			}
			
		}
		else if (positive){
			test = input[counter] - 48;
			array[a] = input[counter] - 48;
			for (int e = counter - 1; e > 0; e--){
				test = test + (input[e] - 48) * power;
				array[a] = array[a] + ((input[e] - 48) * power);
				power *= 10;
			}
			if (test > 2147483647){
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
/* 				cout << "asdasd"<< test<<endl; */
			}
			if (test > 2147483647){
				return 21;				//checking fo out of bounds integer
			}
		}
		counter2++;
	}
	
	if(counter2 > 20){
		return -counter2;
	}
	else {
		return counter2;
	}
	
}

int findMax(int array[], int numElements){
	
	int counter = numElements;
	int max = array[1];
	while (counter != 0){
		if (array[counter] > max){
			max = array[counter];
		}
		counter -- ;
	}
	return max;
}

int findMin(int array[], int numElements){
	
	int counter = numElements;
	int min = array[1];
	while (counter != 0){
		if (array[counter] < min){
			min = array[counter];
		}
		counter --;
	}
	return min;
}

float average (int array[], int numElements){
	
	float av = 0;
	for (int a = 1; a <= numElements; a++){
		av += array[a];
	}
	return av/numElements;
}

bool findMaxMinAvg(int array[], int numElements, int& max, int& min, float& avg){
	
	if (numElements < 1){
		return false;
	}
	return true;
}

int main(int argc, char* argv[]){

	int numInt = 0;
	int array[argc + 1];

	numInt = convertToIntArray(argc, argv, array);
	
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
	
	int max = findMax(array, numInt);
	int min = findMin(array, numInt);
	float avg = average(array, numInt);

	if (findMaxMinAvg(array, numInt, max, min, avg) == false){
		cerr << "Error: cannot compute max min or avg." <<endl;
		return -1;
	}
	
	cout << "Maximum: " << findMax(array, numInt) << endl;
	cout << "Minimum: " << findMin(array, numInt) << endl;
	cout << "Average: " << average(array, numInt) << endl;
	
	return 0;

}