#pragma once
#include "stdafx.h"
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

class Node {
private:
	int name;
	map<Node, int> next_nodes_weights;
	map<int, set<Node>> weight_sort;
public:
	Node() {};
	Node(const int&);
	int Get_name();
	void Set_closest_node(const Node&, int);
	int Get_weight(Node&);
	Node Get_closest(int i = 0);
	void Change_weight_Node(const Node& where, const int&);
	friend bool operator<(const Node& lhs, const Node& rhs);
	friend bool operator!=(const Node& lhs, const Node& rhs);
	friend bool operator==(const Node& lhs, const Node& rhs);
};