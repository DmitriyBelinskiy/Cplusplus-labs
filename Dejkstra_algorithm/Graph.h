#pragma once
#include "Node.h"
#include <set>
class Graph
{
private:
	set<Node> full_graph;
public:
	Graph() {}
	Graph(const Node&);
	Graph(const Graph&);
	void Set_Node(const Node&);
	void Change_Weight(const Node&, Node, const int&);
	//Greedy algorithm
	void Print_greedy_way(const Node& start, const Node& end) const;


};

