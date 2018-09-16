#include "Edge.h"



Edge::Edge()
{
	start = nullptr;
	end = nullptr;
}


Edge::~Edge()
{
	delete start;
	delete end;
}

Edge::Edge(Node * newStart, Node * newEnd, int newCost)
{
	this->start = newStart;
	this->end = newEnd;
	this->cost = newCost;
}

Edge::Edge(const Edge &otherEdge) {
	this->start = new Node(*otherEdge.start);
	this->end = new Node(*otherEdge.end);
	this->cost = otherEdge.cost;
}

Edge& Edge::operator=(const Edge &otherEdge) {
	delete this->start;
	delete this->end;

	this->start = new Node(*otherEdge.start);
	this->end = new Node(*otherEdge.end);
	this->cost = otherEdge.cost;

	return *this;

}

void Edge::setStart(Node * newStart)
{
	this->start = newStart;
}

Node * Edge::getStart()
{
	return this->start;
}

void Edge::setEnd(Node * newEnd)
{
	this->end = newEnd;
}

Node * Edge::getEnd()
{
	return this->end;
}

void Edge::setCost(int & newCost)
{
	this->cost = newCost;
}

const int Edge::getCost()
{
	return this->cost;
}


