/********************************
/Assignment 6 Task 3 : WordCount.cpp
/
/By : Edwin Lo
/
/Nov. 22nd 2016
/
/This program allows the user to pass in a txt file through the command line prompt to analyze.
/Effectively reads the txt file using fstream, and outputs the result into an "anl" file with 
/the same name. The results should be in the format of:
/
/Number of Words: 1234
/Longest Word: 12
/Shortest Word: 1
/Average word Length: 9.32
/
/Any additonal arguments passed into the program will be the fragments that will be searched for.
/If more than 2 arguments are passed into the program, then it will also print out the number of
/occurances of that specific fragment.
/
********************************/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/* int countWords(char input[], int &longestLength, int &shortestLength, float &totalLength){
	
	char tempWord[16];
	int wordCount = 0;
	int wordLength = 0;
	int num = 0;
	int j = 0;
	
	cout << input <<endl;
	
	while(input[num] != '\0'){
		tempWord[j] = input[num];
		cout << (int)input[num] << "  " << input[num] <<endl;
		if (!(input[num] >= 65 && input[num] <=90) && !(input[num] >= 97 && input[num] <= 122)){
			if (j == 0){
				num++;
				continue;
			}
			else{
				if (j > longestLength){
					longestLength = j;
				}
				if (j < shortestLength && j > 2){
					shortestLength = j;
				}
				wordCount++;
				tempWord[j] = '\0';
				totalLength = totalLength + j;
				cout << "j " << j <<endl;
				cout << num <<endl;
				cout << input[num] <<endl;
				if (j > 14){
					cout << "The one word " << tempWord << " is too long" <<endl;
					wordCount--;
				}
				else if(j < 2){
					cout << "The one word " << tempWord << " is too short" <<endl;
					wordCount--;
				}				
				j = 0;
				cout << "word count is : " << wordCount <<endl;				
			}
			
		}
		else{
			j++;
		}
		num++;
	}
	cout << totalLength << "total length" <<endl;
	return wordCount;
} */

 int countWords (ifstream &infile, int &longestLength, int &shortestLength, int &totalLength, char input[]){
	char character = 'k';
	char tempWord[16];
	int wordCount = 0;
	int j = 0;
	int i = 0;
	int counter = 0;

	while (infile.get(character) != '\0'){
		input[counter] = character;
		tempWord[j] = character;
		
		if (!(character >= 65 && character <=90) && !(character >= 97 && character <= 122)){
			if (j == 0){
				continue;
			}
			else{
				tempWord[j] =  0;
		
				if (longestLength < j){
					longestLength = j;
				}
				if (shortestLength > j){
					shortestLength = j;
				}
				wordCount++;
				totalLength = totalLength + j;
			}

				j = 0;
		}
		else {
			j++;
		}
		counter++;
	}
	
	if ((character >= 65 && character <=90) && (character >= 97 && character <= 122)){
		wordCount++;
		totalLength = totalLength + j;
	}
/* 	else if (j < 2 && j > 0){
		tempWord[j] = '\0';
		cout << "The 1 word " << tempWord << " is too short" <<endl;
	}
	else if (j > 14){
		cout << "what face" <<endl;
		tempWord[j] = '\0';
		cout << "The 1 word " << tempWord << " is too long" <<endl;
	} */
	
	input[counter] = '\0';
	return wordCount;
}

int wordFragmentChecker(char input[], char frag[]){
	
	int fragCount = 0;
	int num = 0;
	char tempFrag[50];
	char tempInput[1000];
	
	//copying the frag and input into a temp char array
	for (int a = 0; frag[a] != '\0'; a++){
		tempFrag[a] = frag[a];
		num++;
	}
	tempFrag[num] = '\0';
	
	num = 0;
	
	for (int a = 0; input[a] != '\0'; a++){
		tempInput[a] = input[a];
		num++;
	}
	
	tempInput[num] = '\0';
	
	//converting to lower case
	for (int a = 0; tempFrag[a] != '\0'; a++){
		if (tempFrag[a] >= 65 && tempFrag[a] <= 90){
			tempFrag[a] = tempFrag[a] + 32;
		}
	}
	
	for (int a = 0; tempInput[a] != '\0'; a++){
		if (tempInput[a] >= 65 && tempInput[a] <= 90){
			tempInput[a] = tempInput[a] + 32;
		}
	}
	num = 0;
	
 	while (tempInput[num] != '\0'){
		int j = 0;
		int m = 1; 
		while ((tempFrag[j] != '\0')&& (m == 1)){		
			if (tempInput[num + j] != tempFrag[j]){			
				m = 0;
			}
			j++;
 		}
		if (m == 1){
			fragCount++;
		}
		++num;
	}
	
	return fragCount;
}

int main(int argc, char* argv[]){
	
	if (argc < 2){
		cerr << "Error. Not enough arguments" <<endl;
		return -1;
	}
	
	ifstream infile;
	ofstream outfile;
	char input[6969];
	char parsedInput[6969];
	bool extension = false;
	char newFileName[100];
	char newOutputName[100];
	char *wordFrag[50];
	int numWords = 0;
	int numOccurance[50];
	int longestLength = 0;
	int shortestLength = 99;
	int totalLength;
	double totalAverage = 0;
	int j = 0;
	int counter = 0;

	//for extension checking
	while (argv[1][j] != '\0'){
		if (argv[1][j] == '.'){
			if (argv[1][j + 1] == 't'){
				if (argv[1][j + 2] == 'x'){
					if (argv[1][j + 3] == 't'){
						extension = true;
					}
					else{
						cerr << "Error: wrong extension" <<endl;
						return -1;
					}
				}
				else{
					cerr << "Error: wrong extension" <<endl;
					return -1;
				}
			}
			else{
				cerr << "Error: wrong extension" <<endl;
				return  -1;
			}
		}
		j++;
	}
	
	j = 0;
	
	int i = 0;
	
	if (extension){
		infile.open(argv[1]);
	
		while (argv[1][i] != '.'){
			newOutputName[i] = argv[1][i];
			i++;
		}
		newOutputName[i] = '.';
		newOutputName[i + 1] = 'a';
		newOutputName[i + 2] = 'n';
		newOutputName[i + 3] = 'l';
		newOutputName[i + 4] = '\0';
		   
		outfile.open(newOutputName);
	}
	
	else if (extension == false){		
		while (argv[1][j] != '\0'){
			newFileName[j] = argv[1][j];
			j++;
		}
		newFileName[j] = '.';
		newFileName[j + 1] = 't';
		newFileName[j + 2] = 'x';
		newFileName[j + 3] = 't';
		newFileName[j + 4] = '\0';
		
		infile.open(newFileName);
		
		j = 0;
		
		while (newFileName[j] != '.'){
			newOutputName[j] = newFileName[j];
			j++;
		}
		newOutputName[j] = '.';
		newOutputName[j+1] = 'a';
		newOutputName[j+2] = 'n';
		newOutputName[j+3] = 'l';
		newOutputName[j+4] = '\0';
		
		outfile.open(newOutputName);
	}

	if (!infile.good()){
		cerr << "ERROR FILE NOT FOUND"<<endl;
		return -1;
	}  	
	
	i = 0; 
	
	while (infile.good()){
		counter = 1;
		numWords = numWords + countWords(infile, longestLength, shortestLength, totalLength, parsedInput);
		
		if (argc > 2){
			//cout <<"somethigns" <<endl;
			while (counter <= argc - 2){	
			//	cout <<"what face " <<endl;
				numOccurance[counter] = wordFragmentChecker(parsedInput, argv[counter + 1]);
			//	cout << "num occurance" << counter << " " << numOccurance[counter] <<endl;
				i++;
				counter++;
		}
	}
	totalAverage = ((double)totalLength/numWords);
//	cout << totalAverage << endl;
	
	outfile << "Number of words: " << numWords << endl;
	outfile << "Longest word: " << longestLength <<endl;
	outfile << "Shortest word: " << shortestLength <<endl;
	outfile << "Average word length: " << setprecision(2) << fixed << totalAverage <<endl;
	for (int a = 1; a <= argc - 2; a++){
		outfile << "Number of occurences of " << argv[a + 1] << ": " << numOccurance[a] <<endl;
	}
	
	outfile.close();
	return 0;
	
}
}