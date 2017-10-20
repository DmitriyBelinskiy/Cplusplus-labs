#include "stdafx.h"
#include "Node.h"

Node::Node(string& new_name) {
	node_name = new_name;
}

void Node::Add_next_nod(string& next_node, int& weight) {
	neighbors_and_weights[next_node] = weight;
	weight_sort[weight].push_back(next_node);
}

bool operator<(const Node& lhs, const Node& rhs) {
	if (lhs.node_name < rhs.node_name)
		return true;
	else return false;
}

bool operator!=(const Node& lhs, const Node& rhs) {
	if (lhs.node_name != rhs.node_name)
		return true;
	else return false;
}

bool operator==(const Node& lhs, const Node& rhs) {
	if (lhs.node_name == rhs.node_name)
		return true;
	else return false;
}


