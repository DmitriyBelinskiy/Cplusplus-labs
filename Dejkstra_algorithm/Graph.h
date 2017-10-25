#pragma once
#include "Node.h"
#include <set>
class Graph {
	//��� ������� ���������� � �������
	map<int, Node*> full_graph; //Name and pntr to one node
public:
	//������������
	Graph() {}
	~Graph();
	//� ���� ������������ ������ ������ �������
	Graph(const int& name); 
	//���������� ��������� �������� �� ����� ������� � ������
	void Set_edges(const int& from, const int& to, const int& weight); 
	//������ ��������� ���������� �����
	void Change_weight(const int& from, const int& to, const int& weight);
	//Greedy algorithm
	void Print_greedy_way(int from, const int& to);
	//Dijkstra's algorithm
	void Print_Dijkstras_way(const int& from, const int& to);
};
