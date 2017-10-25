#pragma once
#include "Node.h"
#include <set>
class Graph {
	//¬се вершины записываем в словарь
	map<int, Node*> full_graph; //Name and pntr to one node
public:
	// онструкторы
	Graph() {}
	~Graph();
	//¬ этом конструкторе задаем первую вершину
	Graph(const int& name); 
	//«аписываем стоимость перехода от одной вершины к другой
	void Set_edges(const int& from, const int& to, const int& weight); 
	//ћен€ем стоимость указанного ребра
	void Change_weight(const int& from, const int& to, const int& weight);
	//Greedy algorithm
	void Print_greedy_way(int from, const int& to);
	//Dijkstra's algorithm
	void Print_Dijkstras_way(const int& from, const int& to);
};
