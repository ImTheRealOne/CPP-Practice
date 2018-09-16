#pragma once
#include <vector>
#include "Node.h"
#include <queue>
#include <iostream>



void relax(Node*startNode, Node *endNode, int costFromStartNode);
void recursivePrintMST(Node * start);
class Graph
{
public:
	Graph();
	~Graph();

	
	std::vector<Node *> * getVertices();
	void addVertex(Node * newVertex);
	void dijkstraAlg(Node * start, Node * end);
	bool bellmanFordAlg(Node * start, Node * end);
	void primsAlg(Node * start);

	class minQcomparison {
	public:
		bool operator() (const Node*  lhs, const Node*  rhs) const {

			return(lhs->getWeight() > rhs->getWeight());
		}
	};

private:
	std::vector<Node *> * vertices;
};

