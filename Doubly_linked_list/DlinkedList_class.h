//Header file with double linked list class
//TODO: template <typename T>
#pragma once
#include <iostream>
#include <iomanip>

struct Unit {
	Unit *next; //Pointer to the adress of the next Unit in the list
	Unit *previous; //Pointer to the adress of the previous Unit in the list
	int stored_data;
};

class DoublyLinkedList {
private:
	Unit *p_head; //Pointer on the begining of the list
	Unit *p_tail; //Pointer to the current adress


public:
	DoublyLinkedList(); //Creating empty list
	~DoublyLinkedList(); //Deleting all allocated memory
	void Push_back(const int); //Adding new element to the end of the list
	void Pop_back(); //moving back through the list and printing out stored data
	void Pop_forward(); //moving forward through the list and printing out stored data
	void Unit_Delete(); //Deleting one element
	/*TODO: 
	void insert(int); //inserting element in to the list
	*/
};