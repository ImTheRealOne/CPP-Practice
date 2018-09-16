#include "Main.h"
#include <iostream>
#include <Graph.h>

Main::Main()
{
}


Main::~Main()
{
}



int main() {

	Graph g;

	Node * a = new Node(1);
	Node * b = new Node(2);
	Node * c = new Node(3);
	Node * d = new Node(4);

	a->addNeighbor(b, 5);
	a->addNeighbor(c, 10);

	b->addNeighbor(d, 11);
	b->addNeighbor(a, 5);
	b->addNeighbor(c, 4);

	c->addNeighbor(d, 5);
	c->addNeighbor(a, 10);
	c->addNeighbor(b, 4);

	d->addNeighbor(b, 11);
	d->addNeighbor(c, 5);

	g.addVertex(a);
	g.addVertex(b);
	g.addVertex(c);
	g.addVertex(d);

	g.primsAlg(a);


	system("pause");
	return 0;
}

