//Definition of the double linked class and its methods
#include "stdafx.h"
#include "DlinkedList_class.h"

//Creating empty list
DoublyLinkedList::DoublyLinkedList() : p_head(nullptr), p_tail(nullptr) {}

//Deleting all allocated memory
DoublyLinkedList::~DoublyLinkedList() {
	//Moving to the end of the list
	while (p_tail->next != nullptr) {
		Unit *temp = p_tail->next;
		p_tail = temp;
	}
	while (p_tail != nullptr) {
		Unit *previous_temp = p_tail->previous;
		delete[]p_tail;
		p_tail = previous_temp;
	}
}

//Adding new element to the end of the list
void DoublyLinkedList::Push_back(const int input) {
	//if list is empty
	if (!(p_head)) {
		Unit *temp = new Unit;
		temp->stored_data = input;
		temp->previous = nullptr;
		temp->next = nullptr;
		p_head = temp;
		p_tail = temp;
	}
	//if list is not empty
	else {
		Unit *temp = new Unit;
		p_tail->next = temp;
		temp->stored_data = input;
		temp->previous = p_tail;
		temp->next = nullptr;
		p_tail = temp;
	}
}
//moving back through the list and printing out stored data
void DoublyLinkedList::Pop_back() {
	if (p_head == nullptr) {
		std::cout << "List is empty." << std::endl;
	}
	else if (p_tail->previous == nullptr) {
		std::cout << p_tail->stored_data << std::endl;
		std::cout << "End of list." << std::endl;
	}
	else {
		std::cout << p_tail->stored_data << std::endl;
		Unit *temp = p_tail->previous;
		p_tail = temp;
	}
}
//moving forward through the list and printing out stored data
void DoublyLinkedList::Pop_forward() {
	if (p_head == nullptr)
		std::cout << "List is empty." << std::endl;
	else if (p_tail->next == nullptr) {
		std::cout << p_tail->stored_data << std::endl;
		std::cout << "End of list." << std::endl;
	}
	else {
		std::cout << p_tail->stored_data << std::endl;
		Unit *temp = p_tail->next;
		p_tail = temp;
	}
}
//Deleting one element
void DoublyLinkedList::Unit_Delete() {
	if (p_tail == nullptr)
		std::cout << "List is empty." << std::endl;
	else {
		Unit *previous_temp = p_tail->previous;
		previous_temp->next = p_tail->next;
		delete[]p_tail; //Deleting allocated memory
		std::cout << "Unit was deleted." << std::endl;
		p_tail = previous_temp;
	}
}

