/********************************
/Assignment 7 Task 2 : StringClass.cpp
/
/By : Edwin Lo
/
/Dec. 5th 2016
/
/This program recreates the string library with most of the basic functions of the
/built-in string library.
/
/This program requires StringClassTester.cpp and StringClass.h to run.
********************************/
#include <iostream>
#include "StringClass.h"

using namespace std;
/* 
class myStr {
 public:
  int length() const;
  int strCmp(const myStr& compareMe) const;
  int strCmp(const char* compareMe) const;
  bool strCpy(const myStr& copyMe);
  bool strCpy(const char* copyMe);
  int subStr(const char* findMe) const;
  int subStr(const myStr& findMe) const;
  int subStr(const char* findMe, int startingAt) const;
  int subStr(const myStr& findMe, int startingAt) const;
  char at(const unsigned int index) const; 
  void print();

  myStr();
  myStr(const myStr& copyMe);
  myStr(const char* copyMe);
  ~myStr();

 private:
  friend std::ostream& operator<<(std::ostream& os, const myStr& s) {
    if (s.strLen == 0)
      return os;
    if (s.dataLen > s.strLen && s.data != 0 && s.data[s.strLen] == 0) {
      os << s.data;
      return os;
    }
    else if (s.data != 0) {
      for (int i = 0; i < s.strLen; ++i) {
	os << s.data[i];
      }
      return os;
    }
    else {
      std::cerr << "Error: Attempted to output string when data is NULL";
      return os;
    }
  };

 private:
  int   strLen;
  int   dataLen;
  char* data;
}; */

myStr::myStr(){
	this->strLen = 0;
	this->dataLen = 1;
	this->data = new char[1];
}

myStr::myStr(const myStr& copyMe){
	int countWords = 0;
	
	while(copyMe.data[countWords] != '\0'){
		countWords++;
	}
	
	this->strLen = countWords;
	this->dataLen = countWords + 1;
	
	this->data = new char[this->dataLen];
	
	for (int b = 0; b < this->strLen; b++){
		this->data[b] = copyMe.data[b];
	}
	
	this->data[this->strLen] = '\0';
//	cout << "strLen" << this->strLen << endl;
	
}

myStr::myStr(const char * copyMe){
	int countWords = 0;

	while(copyMe[countWords] != '\0'){
		countWords++;
	}
	
	this->strLen = countWords;
	this->dataLen = countWords + 1;
	
	this->data = new char[this->dataLen];
	
	for(int a = 0; a < this->strLen; a++){
		this->data[a] = copyMe[a];
	}
	this->data[this->strLen] = '\0';
//	cout << "strLen" << this->strLen <<endl;
	
}

myStr::~myStr(){
	this->strLen = -1;
	this->dataLen = -1;
}

int myStr::length()const{
	return this->strLen;
}

int myStr::strCmp(const myStr& compareMe) const{
	bool checkSame = false;
	
	int a = 0;
	
	while (this->data[a] != 0 || compareMe.data[a] != 0){
		if (this->data[a] < compareMe.data[a]){
			return 1;
		}
		else if (this->data[a] > compareMe.data[a]){
			return -1;
		}
		else if (this->data[a] == compareMe.data[a]){
			checkSame = true;
		}
		a++;
	}
	
	if (checkSame){
		return 0;
	}
}
 
int myStr::strCmp(const char* compareMe) const{
	
	char temp1[dataLen];
	char temp2[500];
	
	bool checkSame = false;
	
	int a = 0;
	
	while (this->data[a] != 0 || compareMe[a] != 0){
		if (this->data[a] < compareMe[a]){
			return 1;
		}
		else if(this->data[a] > compareMe[a]){
			return -1;
		}
		else if(this->data[a] == compareMe[a]){
			checkSame = true;
		}
		a++;
	}
	
	if (checkSame){
		return 0;
	}
}

bool myStr::strCpy(const myStr& copyMe){
	
	int a = 0;
	
	while(copyMe.data[a] != 0){
		a++;
	}
	
	this->strLen = a;
	this->dataLen = a + 1;
	
	this->data = new char[dataLen];
	
	a = 0;
	
	for (int b = 0; b <strLen ; b++){
		this->data[b] = copyMe.data[b];
	}
	
	this->data[strLen] = '\0'; 
	
	return true;	
}

bool myStr::strCpy(const char * copyMe){
	int a = 0;
	
	while(copyMe[a] != 0){
		a++;
	}
	
	this->strLen = a;
	this->dataLen = a + 1;
	
	this->data = new char[dataLen];
	
	a = 0;
	
	for (int b = 0; b <strLen ; b++){
		this->data[b] = copyMe[b];
	}
	
	this->data[strLen] = '\0'; 
	
	return true;	
}

int myStr::subStr(const char * findMe)const{
	

	int c = 0;
	while(this->data[c] != '\0'){
		int a = 0;
		int b = 1;		
		while((findMe[a] != '\0') && (b == 1)){
			//cout << "ASD" <<endl;
			if (this->data[c + a] != findMe[a]){
				b = 0;
			}
			a++;
		}
		if (b == 1){
			//cout << this->data[c] <<endl;
			return c;
		}
		c++;
	}
	//cout <<"im outti" <<endl;
	
	return -1;
}

int myStr::subStr(const myStr& findMe) const{
	

	int c = 0;
	while(this->data[c] != '\0'){
		int a = 0;
		int b = 1;	
		while((findMe.data[a] != '\0') && (b == 1)){
			if (this->data[c + a] != findMe.data[a]){
				b = 0;
			}
			a++;
		}
		if (b == 1){
			return c;
		}
		c++;
	}
	
	return -1;
}

int myStr::subStr(const char* findMe, int startingAt) const{
		

	int c = startingAt;
	
	while(this->data[c] != '\0'){
		int a = 0;
		int b = 1;		
		while((findMe[a] != '\0') && (b == 1)){
			if (this->data[c + a] != findMe[a]){
				b = 0;
			}
			a++;
		}
		if (b == 1){
			return c;
		}
		c++;
	}
	
	return -1;
}

int myStr::subStr(const myStr& findMe, int startingAt) const{
		

	int c = startingAt;
	while(this->data[c] != '\0'){
		int a = 0;
		int b = 1;		
		while((findMe.data[a] != '\0') && b == 1){
			if (this->data[c + a] != findMe.data[a]){
				b = 0;
			}
			a++;
		}
		if (b == 1){
			return c;
		}
		c++;
	}
	
	return -1;
}

char myStr::at(const unsigned int index) const{
	return this->data[index];
}

/* int main() {
  myStr fred("?`&,w62=Eb2UCJ,qTublBO7AaP*{F9fh{nv2D)Qk+eBPOobCeEO(viKXYXU s[(.J");
  myStr quote(fred);
  
  cout << fred <<endl;
  cout << quote <<endl;
  
  cout << "Quote length is: " << quote.length() << endl;
  cout << "Fred is at index " << quote.subStr(fred) << " in Quote" << endl;

  cout << "fred.strCmp(\"Fred\"): " << fred.strCmp("Fred") << endl;
  cout << "fred.strCmp(quote): " << fred.strCmp(quote) << endl;
  cout << "quote.strCmp(fred): " << quote.strCmp(fred) << endl;
cout << "quote.subStr(fred): " << quote.subStr("gV;TbiGTh$") << endl;
  cout << "quote.subStr(fred, 0): " << quote.subStr(fred,0) << endl;
  cout << "quote.subStr(fred, 20): " << quote.subStr(fred,20) << endl;
  const unsigned int i = 5;
 cout << i << "th index of quote is character: " << quote.at(i) << endl;
  
  return 0;
} */
