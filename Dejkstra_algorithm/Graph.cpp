#include "stdafx.h"
#include "Graph.h"

Graph::Graph(const Node& new_Node) {
	full_graph.insert(new_Node);
}

Graph::Graph(const Graph& new_Graph) {
	*this = new_Graph;
}

int Graph::GetEdgeWeight(Node& from, const Node& to) const {
	int result;
	if (from.neighbors_and_weights.count(to) != 0)
		return from.neighbors_and_weights[to];
	else
		throw logic_error("No way from " + from.node_name + " to " + to.node_name);

}

void Graph::Print_greedy_way(Node start, const Node& end) const {
	vector<string> final_way;
	do {
		final_way.push_back(start.node_name);
		auto i = start.weight_sort.begin();
		start = i->second;
	} while (start != end);


}
