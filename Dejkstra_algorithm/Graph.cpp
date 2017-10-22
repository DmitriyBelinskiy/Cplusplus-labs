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
		//���������� ��������� ���������� ������ ���� �������� ������ Node
		full_graph.erase(new_Node);
		//������� ��� ���������� ������������ ���� ����� ����� �������� ��� ������
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
	int weight_sum(0);
	Node current = *full_graph.find(start);
	final_way.push_back(current);
	while (current != end) {
		/* ������ � ������� ������� ��������� ������� � � ������� �������� ���������� ������ �� 
		� ������ ����� � ��������� ��������� �������� � temp. ����� ������� �������������� ������
		������� � ������� ����� */
		Node next = *full_graph.find(current.Get_closest());
		weight_sum += current.Get_weight(next);
		current = next;		
		final_way.push_back(current);
	}
	for (auto n : final_way)
		cout << n.Get_name() << " - ";
	cout << "weight sum = " << weight_sum;
}
