#pragma once
#include "Node.h"
#include <set>
class Graph
{
private:
	set<Node> full_graph;
	map<int, Node> full_graph_weigted;//тут хранятся обновляемые веса вершин!!!
public:
	Graph() {}
	Graph(const Node&);
	Graph(const Graph&);
	void Set_Node(const Node&);
	void Change_Weight(const Node&, Node, const int&);
	//Greedy algorithm
	void Print_greedy_way(const Node& start, const Node& end) const;


};

