/*Creating double linked list.*/
#include "stdafx.h"
#include "DlinkedList_class.h" //Header with double linked list class
using namespace std;

int main()
{
	//Int double linked list
	cout << "------INT-------" << endl;
		DoublyLinkedList <int> integer_list;
	integer_list.Pop_back();
	//filling list with data
	for (int i = 0; i < 4; i++)
		integer_list.Push_back(i);
	//moving back through the list and printing out stored data
	for (int i = 0; i < 4; i++)
		integer_list.Pop_back();
	//moving forward through the list and printing out stored data
	for (int i = 0; i < 4; i++)
		integer_list.Pop_forward();
	//Deleting one unit
	integer_list.Unit_Delete();
	integer_list.Unit_Delete();

	integer_list.Pop_back();
	integer_list.Pop_back();

	//double double linked list
	cout << "-----DOUBLE------" << endl;
	DoublyLinkedList <double> double_list;
	double_list.Pop_back();
	double_list.Push_back(1.4556);
	double_list.Push_back(5.6754);
	
	double_list.Pop_back();
	double_list.Pop_back();
	std::cout << std::endl;

	/*
	cout << "-----STRING------" << endl;
	//string double linked list
	DoublyLinkedList <string> string_list;
	string_list.Pop_back();
	string_list.Push_back("one");
	string_list.Push_back("two");

	string_list.Pop_back();
	string_list.Pop_back();
	*/
	
	
	return 0;
}

