#include "stdafx.h"
#include "Node.h"

//���������� ��������� �������� � ����� �� ��������� ������ (���������� �� � ������� ���������)
void Node::Set_edges(const int& to, const int& weight, Node* pnext_node) {
	edges_weights[to] = weight;
	pntr_next_nodes[to] = pnext_node;
	weight_sort[weight].insert(to);

	//������������� ����� ��� ��������� ��������
	pnext_node->initial_weight = 1000000; //���� �������������
	/*if (pnext_node->initial_weight < weight) {
		pnext_node->initial_weight = weight + 1; //������ ��� ������� ��������� �������� (������ �������������)
		��� �� ��������. ���������� ������ ���� ����� ����� ���� ��������� ������ + 1!!!
		����� ������� ����, ������� ��� ���������� ������ ����� ������������ ����� ���������
		� �������� �������� ����� ���� � ������ �������! ���� ����� 1000000 �����.
		*/
		//�������� �������� ����� �� ��������� ������
	pnext_node->best_way[0] = pnext_node->initial_weight;
	pnext_node->best_way[1] = 0;
	//}
}

//������ ��������� �������� � ��������� �������
void Node::Change_weight(const int& to, const int& weight) {
	//���������� ������ ��������
	int old_weight = edges_weights[to];
	edges_weights[to] = weight;	
	//���� ������� ���� �������������� ��������� ������, ������� ��������
	if (weight_sort[old_weight].size() > 1)
		weight_sort[old_weight].erase(to);
	//� ��������� ������� ������ ���� ����
	else
		weight_sort.erase(old_weight);
	//���������� � ������� ����� ��������� �������� � ��� ������� �����
	weight_sort[weight].insert(to);
}

//���������� �������� ������� � ���������� ���������� ��������
int Node::Get_cheapest_edge() {
	auto i = weight_sort.begin();
	auto j = i->second.begin();
	return *j;
}

/*
//����������� ��������� ��� ������ Node
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

*/