//Header file with double linked list template class and its realization

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
struct Unit {
	Unit *next; //Pointer to the adress of the next Unit in the list
	Unit *previous; //Pointer to the adress of the previous Unit in the list
	T stored_data;
};

template <class T>
class DoublyLinkedList {
private:
	Unit<T> *p_head; //Pointer on the begining of the list
	Unit<T> *p_tail; //Pointer to the current adress


public:
	DoublyLinkedList(); //Creating empty list
	~DoublyLinkedList(); //Deleting all allocated memory
	void Push_back(const T); //Adding new element to the end of the list
	void Pop_back(); //moving back through the list and printing out stored data
	void Pop_forward(); //moving forward through the list and printing out stored data
	void Unit_Delete(); //Deleting one element
	/*TODO: 
	void insert(int); //inserting element in to the list
	*/
};



//Creating empty list
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : p_head(nullptr), p_tail(nullptr) {}

//Deleting all allocated memory
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	//Moving to the end of the list
	while (p_tail->next != nullptr) {
		Unit<T> *temp = p_tail->next;
		p_tail = temp;
	}
	while (p_tail != nullptr) {
		Unit<T> *previous_temp = p_tail->previous;
		delete[]p_tail;
		p_tail = previous_temp;
	}
}

//Adding new element to the end of the list
template <class T>
void DoublyLinkedList<T>::Push_back(const T input) {
	//if list is empty
	if (!(p_head)) {
		Unit<T> *temp = new Unit<T>;
		temp->stored_data = input;
		temp->previous = nullptr;
		temp->next = nullptr;
		p_head = temp;
		p_tail = temp;
	}
	//if list is not empty
	else {
		Unit<T> *temp = new Unit<T>;
		p_tail->next = temp;
		temp->stored_data = input;
		temp->previous = p_tail;
		temp->next = nullptr;
		p_tail = temp;
	}
}
//moving back through the list and printing out stored data
template <class T>
void DoublyLinkedList<T>::Pop_back() {
	if (p_head == nullptr) {
		cout << "List is empty." << endl;
	}
	else if (p_tail->previous == nullptr) {
		cout << p_tail->stored_data << endl;
		cout << "End of list." << endl;
	}
	else {
		cout << p_tail->stored_data << endl;
		Unit<T> *temp = p_tail->previous;
		p_tail = temp;
	}
}
//moving forward through the list and printing out stored data
template <class T>
void DoublyLinkedList<T>::Pop_forward() {
	if (p_head == nullptr)
		cout << "List is empty." << endl;
	else if (p_tail->next == nullptr) {
		cout << p_tail->stored_data << endl;
		cout << "End of list." << endl;
	}
	else {
		cout << p_tail->stored_data << endl;
		Unit<T> *temp = p_tail->next;
		p_tail = temp;
	}
}
//Deleting one element
template <class T>
void DoublyLinkedList<T>::Unit_Delete() {
	if (p_tail == nullptr)
		cout << "List is empty." << endl;
	else {
		Unit<T> *previous_temp = p_tail->previous;
		previous_temp->next = p_tail->next;
		delete[]p_tail; //Deleting allocated memory
		cout << "Unit was deleted." << endl;
		p_tail = previous_temp;
	}
}
