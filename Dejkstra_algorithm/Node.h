#pragma once
#include "stdafx.h"
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Node {
	string node_name;
	map<string, int> neighbors_and_weights;
	map<int, vector<string>> weight_sort;

	Node() {};
	Node(string&);
	void Add_next_nod(string&, int&);
	friend bool operator<(const Node& lhs, const Node& rhs);
	friend bool operator!=(const Node& lhs, const Node& rhs);
	friend bool operator==(const Node& lhs, const Node& rhs);
};
