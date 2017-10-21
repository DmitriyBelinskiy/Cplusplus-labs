#include "stdafx.h"
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
		Node one(1);
		Node two(2);
		Node three(3);
		Node four(4);
		Node five(5);
		Node six(6);
		
		five.Set_closest_node(six, 10);
		four.Set_closest_node(six, 20);
		three.Set_closest_node(four, 10);
		three.Set_closest_node(five, 15);
		two.Set_closest_node(five, 15);
		two.Set_closest_node(three, 5);
		one.Set_closest_node(two, 10);
		one.Set_closest_node(three, 5);


		Graph test(one);
		test.Set_Node(two);
		test.Set_Node(three);
		test.Set_Node(four);
		test.Set_Node(five);
		test.Set_Node(six);

		test.Print_greedy_way(one,six);
		cout << endl;
		three.Change_weight_Node(four, 20);
		test.Set_Node(three);
		test.Print_greedy_way(one, six);



	}
	catch (const logic_error& er) {
		cout << er.what() << endl;
	}

	return 0;
}

