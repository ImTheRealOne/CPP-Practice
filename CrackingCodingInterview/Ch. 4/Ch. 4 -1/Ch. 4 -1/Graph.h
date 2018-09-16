#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
template <class T>
class Graph
{
private:
	std::vector<T*>* nodes;
	int size;

public:
	Graph();
	~Graph();
	void insert(T);
	//void insertNode( T* const &newNode) ;
	void printNodes();
	void insertNode(T&);
	bool DFStack(T * root, T * searchNode);
	std::vector<T*>* getNodes();
	//void insertNode(Node<T> newNode);
	bool BFS (T *, T * );
	bool DPS(T*, T*);

	bool DPSearch(T * root, T * searchNode, std::vector<T*> visited);

};

#include "Graph.cpp"

#endif

