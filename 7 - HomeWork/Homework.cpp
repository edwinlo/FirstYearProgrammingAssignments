/********************************
/Assignment 7 Task 1 : Homework.cpp
/
/By : Edwin Lo
/
/Dec. 5th 2016
/
/This program utilizes structs to organize assignments and due dates.
/A priority queue is implemented to help prioritize the assignments that are due
/earlier.
/
/This program requires HomeworkTester.cpp and Homework.h to run.
********************************/
#include <iostream>
#include "Homework.h"

using namespace std;

 /* struct Assignment 
{
	char  course[12];  	// CHE 102, MATH 117, etc.
	int	  assnNum; 		// Assignment Number
	int   dueMonth;		// Month due (1-12)
	int   dueDay;		// Day due (1-31)
	char* description;	// Assignment description
};
 
struct HomeworkQueue 
{
     const Assignment*    assgn;
     HomeworkQueue* next;
};  */

bool nullCheck(const char * a){
	
	for (int b = 0; b <= 12; b++){
		if (a[b] == '\0'){
			return true;
		}
	}
	return false;
}

bool isEarlier(const Assignment* a1, const Assignment* a2){
	
	if (a1->dueMonth < a2->dueMonth){
		return true;
	}
	
	else if (a1->dueMonth == a2->dueMonth){
		if (a1->dueDay <= a2->dueDay){
			return true;
		}
		else{
			return false;
		}
	}
	
	return false;
	
}

bool enqueue(const Assignment* assignment, HomeworkQueue*& queue){
	
	HomeworkQueue *hw = new HomeworkQueue;
	
	hw->assgn = assignment;
	
	int counter = 0;
	
	HomeworkQueue *previous;
	HomeworkQueue *current;
		
	if (assignment->dueDay > 31 || assignment->dueDay < 1 || assignment->dueMonth > 12 || assignment->dueMonth <1 || assignment->course[0] == 0 || nullCheck(assignment->course) == false){
		return false;
	}
	
	if (queue == 0){
		queue = hw;
		queue->next = NULL;
		
		//delete hw;
		//cout << hw->next <<endl;
		//cout << queue->next << endl;
		return true;
	}
	
	else {
		counter = 1;
		previous = 0;
		current = queue;
		
		//cout << current << endl;
		//cout << current->next<<endl;
	
		while (isEarlier(current->assgn, hw->assgn)){
			//cout << "current " << current->assgn->description <<endl;
			//cout << "hw " << hw->assgn->description <<endl;
			previous = current;
			current = current->next;
			counter++;
			//cout << current->assgn->description <<endl;
			//cout << "current address " << current <<endl;
			//cout << "next " <<queue->next << endl;
			
			if (current == 0){
				break;
			}
		}
		
		if (current == queue){
			queue = hw;
			queue->next = current;	
		}
		
/* 		else if ((current->assgn->dueDay == hw->assgn->dueDay)){
			cout << "ASDADSD" <<endl;
			previous->next = current;
			current->next = hw;		
		}
		 */
		else{
			previous->next = hw;
			hw->next = current;
		}
	}	
	
	return true;
}
const Assignment* dequeue(HomeworkQueue*& queue){
	
	HomeworkQueue *temp = new HomeworkQueue;
	
	if(queue == 0){
		return 0;
	}	
	
	temp = queue;
	queue = queue->next;
	
	return (temp->assgn);
}

/* void print(HomeworkQueue*& q)
{
	cout << endl;
	HomeworkQueue* temp = q;
	while(temp != NULL)
	{
		cout << temp->assgn->course << " " << temp->assgn->assnNum << " " << temp->assgn->dueMonth 
		     << " " <<  temp->assgn->dueDay <<" " << temp->assgn->description << endl;
		temp = temp->next;
	}
	cout << endl;
}


int main()
{
	HomeworkQueue* q = 0;
	
	Assignment a1 = { "ECE 150", 7, 12, 5, "linked list" };
	enqueue(&a1, q);
	Assignment a2 = {"ECE 150", 6, 11, 25, "struct"};
	enqueue(&a2, q);
	Assignment a3 = {"ECE 100", 3, 12, 5, "final report"};
	enqueue(&a3, q);
	Assignment a4 = {"Math 117", 9, 11, 30, "partial fraction"};
	enqueue(&a4, q);
	Assignment a5 = {"ECE 105", 10, 12, 2, "momentum"};
	enqueue(&a5, q);
	
	print (q);
	
	const Assignment* a;
	
	for(int i = 0; i < 5; i++)
	{
		a = dequeue(q);
		cout <<a->course << " assignment " << a->assnNum << " is taken off the to do list on " << a->dueMonth << '/' << a->dueDay<< endl;
	}
		
	return 0;
} */

/*
Sample Output:

ECE 150 6 11 25 struct
Math 117 9 11 30 partial fraction
ECE 105 10 12 2 momentum
ECE 150 7 12 5 linked list
ECE 100 3 12 5 final report

ECE 150 assignment 6 is taken off the to do list on 11/25
Math 117 assignment 9 is taken off the to do list on 11/30
ECE 105 assignment 10 is taken off the to do list on 12/2
ECE 150 assignment 7 is taken off the to do list on 12/5
ECE 100 assignment 3 is taken off the to do list on 12/5

*/

