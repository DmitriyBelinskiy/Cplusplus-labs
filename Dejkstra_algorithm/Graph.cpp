#include "stdafx.h"
#include <iostream>
#include "Graph.h"
using namespace std;

Graph::Graph(const Node& new_Node) {
	full_graph.insert(new_Node);
}

Graph::Graph(const Graph& new_Graph) {
	*this = new_Graph;
}

void Graph::Set_Node(const Node& new_Node) {
	if (full_graph.count(new_Node) == 0)
		full_graph.insert(new_Node);
	else {
		//перегрузка сравнени€ сравнивает только пол€ названи€ класса Node
		full_graph.erase(new_Node);
		//ѕоэтому дл€ перезаписи обновленного узла графа нужно втсавить его заново
		full_graph.insert(new_Node);
	}
}

void Graph::Change_Weight(const Node& from, Node to, const int& new_weight) {
	auto p_from = full_graph.find(from);
	Node temp = *p_from;
	temp.Change_weight_Node(to, new_weight);
	full_graph.erase(from);
	full_graph.insert(temp);
}

void Graph::Print_greedy_way(const Node& start, const Node& end) const {
	vector<Node> final_way;
	Node temp = *full_graph.find(start);
	final_way.push_back(temp);
	while (temp != end) {
		/* Ќахожу в текущей вершине ближайшую вершину и с помощью механики итераторов нахожу ее 
		в классе графа и записываю найденное значение в temp. “аким образом обрабатываютс€ только
		вершины в текущем графе */
		temp = *full_graph.find(temp.Get_closest());
		final_way.push_back(temp);
	}
	for (auto n : final_way)
		cout << n.Get_name() << " - ";
}
