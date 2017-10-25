#pragma once
#include "stdafx.h"
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

struct Node {
	int name; //»м€ вершины
	map<int, int> edges_weights; //Name - weight
	map<int, Node*> pntr_next_nodes; //Name - pointer to next nodes
	//TODO: map<int, Node*> pntr_prev_nodes; //Name - pointer to previous nodes
	map<int, set<int>> weight_sort; //Weight - set of names

	int initial_weight;/*»сходна€ метка вершины. ¬ алгоритме ƒейкстры она изначально равна 
	бесконечности. ” мен€ она равна стоимости максимального перехода в вершину + 1*/
	int best_way[2]; /*Best weight - source node. For Dijkstra's algorithm. ѕосле завершени€
	алгоритма значение метки восстанавливаетс€ из initial_weight, а данные о вершинах обнул€ютс€.
	Ёто нужно дл€ того, чтобы алгоритм учитываел изначальные данные при повторном запуске*/

	int p_flag;//‘лаг пройденной вершины. For Dijkstra's algorithm.
	
	//«аписываем стоимость перехода к одной из ближайших вершин
	void Set_edges(const int& to, const int& weight, Node* pnext_node);
	//ћен€ем стоимость перехода к указанной вершине
	void Change_weight(const int& to, const int& weight);
	//¬озвращаем название вершины с наименьшей стоимостью перехода
	int Get_cheapest_edge();
};



