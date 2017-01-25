/********************************
/Assignment 1 Task 5 : netPriceCalc.cpp
/
/By : Edwin Lo
/
/Sept. 26th 2016
/
/This program calculates the net price given the offer price of the item, discount rate
/and the tax.
/
********************************/
#include <iostream>
#include <iomanip>


using namespace std;

int main(){
	
	float listPrice =0;
	float discount = 0;
	float tax = 0;
	
	cout <<setprecision(2)<<fixed;
	cout << "Enter the offer price of the item: ";
	cin >> listPrice;
	cout << "Discount rate (%): ";
	cin >> discount ;
	cout << "Tax rate (%): ";
	cin >> tax;
	
	discount = discount/100;
	tax = tax/100;
	
	listPrice = listPrice - (listPrice * discount);
	
	listPrice = listPrice + (listPrice *tax);

	
	cout << "The net price of the item is: " << listPrice;
	
	return 0;

}
