#pragma once
#include "Node.h"
#include <set>
class Graph : private Node
{
	set<Node> full_graph;
public:
	Graph() {}
	Graph(const Node&);
	Graph(const Graph&);
	int GetEdgeWeight(Node&, const Node&) const;
	//Greedy algorithm
	void Print_greedy_way(Node start, const Node& end) const;


};

