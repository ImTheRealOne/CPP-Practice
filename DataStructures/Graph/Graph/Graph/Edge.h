#pragma once
#include "Node.h"
class Edge
{
public:
	Edge();
	~Edge();
	Edge(Node * newStart, Node * newEnd, int newCost);

	Edge(const Edge &otherEdge);
	Edge& operator= (const Edge &otherEdge);

	void setStart(Node * newStart);
	Node * getStart();

	void setEnd(Node * newEnd);
	Node* getEnd();

	void setCost(int &newCost);
	const int getCost();





private:
	Node * start;
	Node * end;
	int cost;
};

