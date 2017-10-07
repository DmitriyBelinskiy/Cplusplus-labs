/*Creating double linked list.*/
#include "stdafx.h"
#include "DlinkedList_class.h" //Header with double linked list class

int main()
{
	DoublyLinkedList test;
	test.Pop_back();
	//filling list with data
	for (int i = 0; i < 4; i++)
		test.Push_back(i);
	//moving back through the list and printing out stored data
	for (int i = 0; i < 4; i++)
		test.Pop_back();
	//moving forward through the list and printing out stored data
	for (int i = 0; i < 4; i++)
		test.Pop_forward();
	//Deleting one unit
	test.Unit_Delete();
	test.Unit_Delete();

	test.Pop_back();	
	test.Pop_back();
	
	
	return 0;
}

