#include "stdafx.h"
#include <iostream>
#include "Graph.h"
using namespace std;

//����������� ������
Graph::~Graph() {
	for (auto m : full_graph)
		delete m.second;
}
//� ���� ������������ ������ ������ �������
Graph::Graph(const int& name) {
	Node *p_node = new Node;
	p_node->name = name;
	full_graph[name] = p_node;
	/* �������������� ���� ������������ ���� ������, ��� ��� � �������� ������� �� ����� 
	������� �����. ���������� ��� ��������� �������� */
	p_node->initial_weight = 0;
	//�������� �������� ����� �� ��������� ������
	p_node->best_way[0] = p_node->initial_weight;
	p_node->best_way[1] = 0;
	p_node->p_flag = 0;//�������������� ���� ������� ������� ��� ��������� ��������
}

//���������� ��������� �������� �� �������� ������� � ������
void Graph::Set_edges(const int& from, const int& to, const int& weight) {
	//���� ��� ������� ����������
	if (full_graph.count(from) != 0 && full_graph.count(to) != 0) {
		//��������� ��������� �� ��� ���. ���� ���, �� ���������
		if (full_graph[from]->edges_weights.count(to) == 0)
			full_graph[from]->Set_edges(to, weight, full_graph[to]);
		/* ���� �� - �� ���������� ������. ����� ��������� ��������� ���������� ������
		� ��������� ��������� �������� (��� �������� ������� � ������ ������)*/
		else
			throw logic_error("Edge already exists");
	}
	//���� ���������� ������ �������� �������
	else if (full_graph.count(from) != 0) {
		Node *p_next_node = new Node;
		p_next_node->name = to;
		p_next_node->p_flag = 0;//�������������� ���� ������� ������� ��� ��������� ��������
		full_graph[from]->Set_edges(to, weight, p_next_node);
		full_graph[to] = p_next_node;
	}
	//���� ������ �������� ������� ���
	else if (full_graph.count(to) != 0) {
		Node *p_current_node = new Node;
		p_current_node->name = from;
		/* �������������� ���� ������������ ���� ������, ��� ��� � �������� ������� �� �����
		������� �����. ���������� ��� ��������� �������� */
		p_current_node->initial_weight = 0;
		p_current_node->best_way[0] = p_current_node->initial_weight;
		p_current_node->best_way[1] = 0;
		p_current_node->p_flag = 0;//�������������� ���� ������� ������� ��� ��������� ��������

		full_graph[from]->Set_edges(to, weight, full_graph[to]);
	}
	//���� ����� ������ ��� - ������. ����� �� ��������� ����������� � ������� ������ �������
	else
		throw logic_error("Both nodes don't exist.");
}

//������ ��������� ���������� �����
void Graph::Change_weight(const int& from, const int& to, const int& weight) {
	//����������� �������� ������� ������ � �����
	if (full_graph.count(from) != 0 && full_graph.count(to) != 0) {
		//�������, �������� �� �������
		if (full_graph[from]->edges_weights.count(to) != 0) {
			//�������� ����� ��������� Node
			full_graph[from]->Change_weight(to, weight);
		} else
			throw logic_error("Nodes are not connected.");
	} else
		throw logic_error("One of the nodes doesn't exist.");
}


//Greedy algorithm
void Graph::Print_greedy_way(int from, const int& to) {
	//����������� �������� ������� ������ � �����
	if (full_graph.count(from) != 0 && full_graph.count(to) != 0) {
		vector<int> greedy_way;
		greedy_way.push_back(from);
		int weight_sum(0);
		//int save_previous_node; ��� �������� ���������� �������
		while (from != to) {
			//������� ������� � ����� ������� ���������
			int cheapest_node = full_graph[from]->Get_cheapest_edge();
			//��������� �� � �������������� �������
			greedy_way.push_back(cheapest_node);
			weight_sum += full_graph[from]->edges_weights[cheapest_node];
			//�������� ������� ������� �� ����� (����� �������)
			//save_previous_node = from;
			from = cheapest_node;
		}
		//������� ������ ���� �� �����
		for (const auto& node : greedy_way)
			cout << node << " - ";
		cout << "Total weight sum: " << weight_sum << endl;
	}
	else
		throw logic_error("Wrong nodes.");

	//���� �����, �� ������ ��������� from ���������� ������� � continue!!!!!!
	//�������� �������� �� ������ ��������� ������
}

//Dijkstra's algorithm
void Graph::Print_Dijkstras_way(const int& from, const int& to) {
	if (full_graph.count(from) != 0 && full_graph.count(to) != 0) {
		vector<int> dijkstras_way;
		int temp_from = from;
		//�������� ����� ��������� �������, ��� ��� � ��� ���������� ������ ����
		full_graph[temp_from]->best_way[0] = 0;
		full_graph[temp_from]->best_way[1] = 0;
		
		set<int> nodes_to_cover; //������ ������, ������� ����� ����������
		nodes_to_cover.insert(temp_from);//�������� � ������
		
		//���� ������ ������ ������ 0
		while (nodes_to_cover.size() > 0) {
			//���� ���� = 1, ������ ������� ��� ���������� � ���������� ��
			if (full_graph[temp_from]->p_flag != 1) {
				//������������� ��� ����� �� ���� �������� ��������, � ������� ����� �������
				for (auto m : full_graph[temp_from]->edges_weights) {
					//���������� ����������� ��� ��������� � ��������� ������ ��������
					int total_weight = full_graph[temp_from]->best_way[0] + m.second;
					//���� ���������� �������� ������ ���������� � ������� ������� - �������� ���
					if (full_graph[m.first]->best_way[0] >= total_weight) {
						full_graph[m.first]->best_way[0] = total_weight;
						//���������� ������� - �������� ��������
						full_graph[m.first]->best_way[1] = temp_from;
					}
					//��������� ����� �������(� ������� ����� ������� �� ��������) � ������
					//��� ���� ��������� �� ����� �����������
					nodes_to_cover.insert(m.first);
				}
				//������� ���������� - ���� ������������� � 1
				full_graph[temp_from]->p_flag = 1;
			}
			nodes_to_cover.erase(temp_from);//������� ������������ �������
			//���� ������ �� ������ - ����� ������ �������
			if (nodes_to_cover.size() != 0)
				temp_from = *nodes_to_cover.begin();
		}
	
		//��������� ����������� ����. � ����� �����.
		int temp_to = to;
		dijkstras_way.push_back(temp_to);
		while (temp_to != from) {
			temp_to = full_graph[temp_to]->best_way[1];
			dijkstras_way.push_back(temp_to);
		}

		//������� ����������� ���� �� �����
		for (int i = dijkstras_way.size() - 1; i != -1; i--)
			cout << dijkstras_way[i] << " - ";
		cout << "Total weight sum: " << full_graph[to]->best_way[0] << endl;

		//��������������� �������� ����� ������, ������ � ��������� ��������
		for (auto &node : full_graph) {
			node.second->best_way[0] = node.second->initial_weight;
			node.second->best_way[1] = 0;
			node.second->p_flag = 0;
		}
	}
	else
		throw logic_error("One of the nodes doesn't exist.");
}


