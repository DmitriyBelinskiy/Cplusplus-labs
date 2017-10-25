#pragma once
#include "stdafx.h"
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

struct Node {
	int name; //��� �������
	map<int, int> edges_weights; //Name - weight
	map<int, Node*> pntr_next_nodes; //Name - pointer to next nodes
	//TODO: map<int, Node*> pntr_prev_nodes; //Name - pointer to previous nodes
	map<int, set<int>> weight_sort; //Weight - set of names

	int initial_weight;/*�������� ����� �������. � ��������� �������� ��� ���������� ����� 
	�������������. � ���� ��� ����� ��������� ������������� �������� � ������� + 1*/
	int best_way[2]; /*Best weight - source node. For Dijkstra's algorithm. ����� ����������
	��������� �������� ����� ����������������� �� initial_weight, � ������ � �������� ����������.
	��� ����� ��� ����, ����� �������� ��������� ����������� ������ ��� ��������� �������*/

	int p_flag;//���� ���������� �������. For Dijkstra's algorithm.
	
	//���������� ��������� �������� � ����� �� ��������� ������
	void Set_edges(const int& to, const int& weight, Node* pnext_node);
	//������ ��������� �������� � ��������� �������
	void Change_weight(const int& to, const int& weight);
	//���������� �������� ������� � ���������� ���������� ��������
	int Get_cheapest_edge();
};



