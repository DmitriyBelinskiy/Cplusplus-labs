﻿#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <exception>
#include <sstream>
#include <iomanip>
#include "Node.h"
#include "Graph.h"
using namespace std;

int main()
{
	try {
		Graph test(1);

		test.Set_edges(1, 2, 7);
		test.Set_edges(1, 3, 9);
		test.Set_edges(1, 6, 14);
		test.Set_edges(2, 3, 10);
		test.Set_edges(2, 4, 15);
		test.Set_edges(3, 6, 2);
		test.Set_edges(3, 4, 11);
		test.Set_edges(6, 5, 9);
		test.Set_edges(4, 5, 6);
		
		test.Print_greedy_way(1,5);
		cout << endl;
		/*
		test.Change_weight(3, 6, 15);
		test.Print_greedy_way(1, 5);
		cout << endl;

		test.Set_edges(2, 5, 9);
		test.Print_greedy_way(1, 5);
		cout << endl;
		*/
		test.Print_Dijkstras_way(1, 5);
		cout << endl;

		test.Print_Dijkstras_way(1, 4);
		cout << endl;
		
	}
	catch (const logic_error& er) {
		cout << er.what() << endl;
	}

	return 0;
}

