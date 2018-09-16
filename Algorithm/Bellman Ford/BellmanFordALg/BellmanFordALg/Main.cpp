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

	Node * s = new Node(1);
	Node * t = new Node(2);
	Node * x = new Node(3);
	Node * y = new Node(4);
	Node * z = new Node(5);

	s->addNeighbor(t, 6);
	s->addNeighbor(y, 7);

	t->addNeighbor(x, 5);
	t->addNeighbor(z, -4);
	t->addNeighbor(y, 8);

	x->addNeighbor(t, -2);
	
	y->addNeighbor(x, -3);
	y->addNeighbor(z, 9);

	z->addNeighbor(s, 2);
	z->addNeighbor(x, 7);

	g.addVertex(s);
	g.addVertex(t);
	g.addVertex(x);
	g.addVertex(y);
	g.addVertex(z);

	g.bellmanFordAlg(s, z);


	system("pause");
	return 0;
}