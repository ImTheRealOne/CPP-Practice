#include "Main.h"



Main::Main()
{
}


Main::~Main()
{
}

void hamiltonianCircuit(int graphSize, Node * start, Node * current, std::vector<Node*> visited);

bool containsNode(const Node * node, std::vector<Node*> visited);

void print(std::vector<Node *> hamPath);

int main() {


	Graph  graph;

	/*
	Node * a = new Node(0);
	Node * b = new Node(1);
	Node * c = new Node(2);
	Node * d = new Node(3);
	Node * e = new Node(4);
	Node * f = new Node(5);

	a->addNeighbor(b, 0);
	a->addNeighbor(c, 0);
	a->addNeighbor(d, 0);
	
	b->addNeighbor(a, 0);
	b->addNeighbor(c, 0);
	b->addNeighbor(f, 0);

	c->addNeighbor(a, 0);
	c->addNeighbor(b, 0);
	c->addNeighbor(d, 0);
	c->addNeighbor(e, 0);
	
	d->addNeighbor(a, 0);
	d->addNeighbor(c, 0);
	d->addNeighbor(e, 0);

	e->addNeighbor(c, 0);
	e->addNeighbor(d, 0);
	e->addNeighbor(f, 0);

	f->addNeighbor(b, 0);
	f->addNeighbor(e, 0);

	graph.addVertex(a);
	graph.addVertex(b);
	graph.addVertex(c);
	graph.addVertex(d);
	graph.addVertex(e);
	graph.addVertex(f);

	std::vector<Node *> visitedVector;
	int graphSize = graph.getVertices()->size();
	hamiltonianCircuit(graphSize, a, a, visitedVector);
	*/

	Node * a = new Node(0);
	Node * b = new Node(1);
	Node * c = new Node(2);
	Node * d = new Node(3);
	Node * e = new Node(4);

	a->addNeighbor(b, 3);
	a->addNeighbor(c, 1);
	a->addNeighbor(d, 5);
	a->addNeighbor(e, 8);

	b->addNeighbor(a, 3);
	b->addNeighbor(c, 6);
	b->addNeighbor(d, 7);
	b->addNeighbor(e, 9);

	c->addNeighbor(a, 1);
	c->addNeighbor(b, 6);
	c->addNeighbor(d, 4);
	c->addNeighbor(e, 2);

	d->addNeighbor(a, 5);
	d->addNeighbor(b, 7);
	d->addNeighbor(c, 4);
	d->addNeighbor(e, 3);

	e->addNeighbor(a, 8);
	e->addNeighbor(b, 9);
	e->addNeighbor(c, 2);
	e->addNeighbor(d, 3);



	system("pause");
	return 0;
}

void print(std::vector<Node *> hamPath) {
	for (std::vector<Node*>::iterator &visitedIterator = hamPath.begin(); visitedIterator != hamPath.end(); visitedIterator++) {
		std::cout << (char)((*visitedIterator)->getData() + 'a') << " -> ";
	}
	std::cout << (char)(hamPath.at(0)->getData() + 'a');
	std::cout << std::endl;
}

void hamiltonianCircuit(int graphSize, Node * start, Node * current, std::vector<Node*> visited) {
	
	
	
		visited.push_back(current);
		//std::cout << std::endl << "added Node : " << (char)(current->getData() + 'a');
	
	
	for (std::vector<std::pair<Node *, int>>::iterator &neighborIterator = current->getNeighbor()->begin(); neighborIterator != current->getNeighbor()->end(); neighborIterator++) {
		
		if (!containsNode(neighborIterator->first, visited)) {
			//std::cout << std::endl << "added Node : " << (char)(neighborIterator->first->getData() + 'a');
			
			hamiltonianCircuit(graphSize, start, neighborIterator->first, visited);
		}
	}

	if (graphSize == visited.size()) {
		for (std::vector<std::pair<Node *, int>>::iterator &neighborIterator = current->getNeighbor()->begin(); neighborIterator != current->getNeighbor()->end(); neighborIterator++) {
			if (neighborIterator->first == start) {
				print(visited);
			}
		}

	}

}

bool containsNode(const Node * node, std::vector<Node*> visited) {
	for (std::vector<Node*>::iterator &visitedIterator = visited.begin(); visitedIterator != visited.end(); visitedIterator++) {
		if (node == *visitedIterator)
			return true;
	}
	return false;
}