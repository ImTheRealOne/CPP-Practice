#include "Main.h"
#include <iostream>
#include <vector>
#include "Graph.h"

Main::Main()
{
}


Main::~Main()
{
}


int main() {

	Graph g;

	Node* s = new Node(1);
	Node* t = new Node(2);
	Node* x = new Node(3);
	Node* y = new Node(4);
	Node* z =  new Node(5);

	s->addNeighbor(t, 10);
	s->addNeighbor(y, 5);

	t->addNeighbor(y, 2);
	t->addNeighbor(x, 1);

	x->addNeighbor(z, 4);

	y->addNeighbor(t, 3);
	y->addNeighbor(z, 2);

	z->addNeighbor(x, 6);
	z->addNeighbor(s, 7);

	g.addVertex(s);
	g.addVertex(t);
	g.addVertex(x);
	g.addVertex(y);
	g.addVertex(z);

	g.dijkstraAlg(s,x);

	system("pause");
	return 0;
}