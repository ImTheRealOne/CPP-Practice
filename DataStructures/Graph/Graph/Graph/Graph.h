#pragma once
#include "Node.h"
#include "Edge.h"
#include <vector>
#include <iostream>

class Graph
{
public:
	Graph();
	~Graph();
	Graph(const Graph & otherGraph);

	Graph& operator= (const	Graph &otherGraph);

	void setVertices(std::vector<Node *> * newVertices);
	 std::vector<Node *> * getVertices() const;

	void setEdges(std::vector<Edge *> * newEdges);
	 std::vector<Edge *> * getEdges() const;
	
	void addVertex(Node * newVertex);
	void Graph::addEdge(Edge * newEdge);

	const void print();

private:
	std::vector<Node *> * vertices;
	std::vector <Edge *> * edges;

};

