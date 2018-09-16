#include "Main.h"
#include <iostream>
#include "Graph.h"
#include<list>	
#include <vector>


Main::Main()
{
}


Main::~Main()
{
}

void buildOrder(Graph<Node<char>> g, std::vector<Node<char>*> * & build);
bool containsNode(std::vector<Node<char>*> v, Node<char>* searchNode);

int main() {

	//Graph<Node<int>>* graph = new Graph<Node<int>>();
	//Node<int>* newnode = new Node<int>(0);
	//Node<int>* newnode1 = new Node<int>(1);
	//Node<int>* newnode2 = new Node<int>(2);
	//Node<int>* newnode3 = new Node<int>(3);
	//Node<int>* newnode4 = new Node<int>(4);
	//Node<int>* newnode5 = new Node<int>(5);

	//

	//newnode->addNeighbor(newnode1);
	//newnode->addNeighbor(newnode4);
	//newnode->addNeighbor(newnode5);

	//newnode1->addNeighbor(newnode3);
	//newnode1->addNeighbor(newnode4);

	//newnode2->addNeighbor(newnode1);

	//newnode3->addNeighbor(newnode2);
	//newnode3->addNeighbor(newnode4);

	//std::list<Node<int>*> nodeList;

	//
	//
	//nodeList.push_back(newnode);
	//nodeList.push_back(newnode1);
	//nodeList.push_back(newnode2);
	//nodeList.push_back(newnode3);
	//nodeList.push_back(newnode4);
	//nodeList.push_back(newnode5);

	//std::cout<<newnode->printNeighbor();
	//
	//graph->insertNode(*newnode);
	//graph->insertNode(*newnode1);
	//graph->insertNode(*newnode2);
	//graph->insertNode(*newnode3);
	//graph->insertNode(*newnode4);
	//graph->insertNode(*newnode5);

	//graph->printNodes();

	//if (graph->DFStack(newnode, newnode2)) {
	//	std::cout << "path between";
	//}
	//else {
	//	std::cout << "Nope" << std::endl;
	//}

	//	delete graph;
		


	Graph<Node<char>> g ;
	Node<char> a('a'), b('b'), c('c'), d('d'), e('e'), f('f');

	Node<char> * nodePtr = &f;

	a.addNeighbor(&f);

	b.addNeighbor(&f);

	c.addNeighbor(&d);

	d.addNeighbor(&a);
	d.addNeighbor(&b);
	


	g.insertNode(a);
	g.insertNode(b);
	g.insertNode(c);
	g.insertNode(d);
	g.insertNode(e);
	g.insertNode(f);

	g.printNodes();
	

	std::vector<Node<char>*> * result = new std::vector<Node<char>*>;

	buildOrder(g, result);

	for (auto &it : *result) {
		std::cout << it->getData() << "   ";
	}
	system("pause");
	return 0;
}


void buildOrder(Graph<Node<char>> g, std::vector<Node<char>*>* &build) {
	
	std::vector<Node<char>*>* queue;
	queue = g.getNodes();
	int size = 0;
	
	do {
		size = queue->size();
		for (int i = 0; i < queue->size(); i++) {
			std::vector<Node<char>*> *children = queue->at(i)->getChildren();
			if (children == nullptr) {
				build->push_back(queue->at(i));
				queue->erase(queue->begin()+i);
			}
			else {
				bool canAdd = true;
				for (auto &it : *children) {
					if (!containsNode(*build, it))
						canAdd = false;
				}
				if (canAdd) {
					build->push_back(queue->at(i));
					queue->erase(queue->begin() + i);
				}
			}
		}

	}while (size != queue->size());

	
}


bool containsNode(std::vector<Node<char>*> v, Node<char>* searchNode)
{
	for (auto it : v) {
		if (it->getData() == searchNode->getData())
			return true;
	}
	return false;
}

