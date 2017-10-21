#include "stdafx.h"
#include "Node.h"

Node::Node(const int& new_name) : name(new_name) {}
int Node::Get_name() { return name; }

void Node::Set_closest_node(const Node& next_node, int weight) {
	next_nodes_weights[next_node] = weight;
	weight_sort[weight].insert(next_node);
}

int Node::Get_weight(Node& to){
	if (next_nodes_weights.count(to.name) != 0)
		return next_nodes_weights[to.name];
	else
		throw logic_error("No way");
}
Node Node::Get_closest(int i){
	if (weight_sort.size() != 0) {
		for (auto n : weight_sort) {
			if (i < n.second.size()) {
				set<Node>::iterator it;
				it = n.second.begin();
				advance(it, i);
				return *it;
			}
			else 
				throw logic_error("No more Nodes");
		}
	}
	else
		throw logic_error("Dead road");
}

void Node::Change_weight_Node(const Node& where, const int& new_w) {
	if (next_nodes_weights.count(where) != 0) {
		int old_weight = next_nodes_weights[where];
		next_nodes_weights[where] = new_w;
		weight_sort[new_w].insert(where);
		weight_sort[old_weight].erase(where);
		if (weight_sort[old_weight].size() == 0)
			weight_sort.erase(old_weight);
	}
	else {
		throw logic_error("No way to this Node");
	}
}

bool operator<(const Node& lhs, const Node& rhs) {
	if (lhs.name < rhs.name)
		return true;
	else return false;
}

bool operator!=(const Node& lhs, const Node& rhs) {
	if (lhs.name != rhs.name)
		return true;
	else return false;
}

bool operator==(const Node& lhs, const Node& rhs) {
	if (lhs.name == rhs.name)
		return true;
	else return false;
}


