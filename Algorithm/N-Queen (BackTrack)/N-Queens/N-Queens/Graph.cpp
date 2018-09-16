#include "Graph.h"



Graph::Graph()
{
	vertices = new std::vector<Node *>();
}


Graph::~Graph()
{
	delete vertices;
}

void Graph::addVertex(Node * newVertex) {
	this->vertices->emplace_back(newVertex);
}

std::vector<Node *> * Graph::getVertices() {

	return vertices;
}

void Graph::dijkstraAlg(Node * start, Node * end) {
	//uses 2 minimum priority queue to store the nodes and resort the nodes
	std::priority_queue<Node*, std::vector<Node*>, minQcomparison> minPQ;
	std::priority_queue<Node*, std::vector<Node*>, minQcomparison> minPQ2;
	//shortest path vector
	std::vector<Node *> shortestPath;
	//initialize minPQ by pushing all the nodes into it
	for (std::vector<Node*>::iterator it = this->vertices->begin(); it != this->vertices->end(); ++it){
		minPQ.push(*it);
	}
	//initialize the starting node weight as 0
	start->setWeight(0);
	Node * tempNode = nullptr;
	//dequeue the minPQ
	while (!minPQ.empty())
	{
		tempNode = minPQ.top();
		minPQ.pop();	
		shortestPath.push_back(tempNode);
		//relax each edge that's connected to the current node
		int j = minPQ.size();
		for (int i = 0; i < j; i++) {
			for (std::vector<std::pair<Node *, int> >::iterator it = tempNode->getNeighbor()->begin(); it != tempNode->getNeighbor()->end(); ++it) {
				//we can't change the properties of any element inside a minPQ that's not the top
				//so we need to interate through the neighbors of current node and compare it to the front minPQ node
				if (it->first == minPQ.top()) {
					relax(tempNode, it->first, it->second);
				}
			}
			//need to reorder the nodes after relaxing them
			//minPQ doesn't automatically reorder after they have been inserted into the queue
			//using two minPQ allows us to maintain the min priority property after relaxation
			minPQ2.push(minPQ.top());
			minPQ.pop();
		}
		//reinitialize the amount of times minPQ needs to pop
		j = minPQ2.size();
		for (int i = 0; i < j; i++) {
			minPQ.push(minPQ2.top());
			minPQ2.pop();
		}

	}

	for (int i = 0; i < shortestPath.size(); i++) {
		std::cout << shortestPath.at(i)->getWeight() << " -> ";
	}
}

void relax(Node * startNode, Node * endNode, int costFromStartNode) {
	if (endNode->getWeight() > startNode->getWeight() + costFromStartNode) {
		endNode->setWeight(startNode->getWeight() + costFromStartNode);
		
		endNode->setPrev(startNode);
	}
}

bool Graph::bellmanFordAlg(Node * start, Node * end) {
	//initialize the weight of starting node
	start->setWeight(0);
	//double for loop to iterate through every edge in the graph
	for (int i = 0; i < this->vertices->size(); i++) {
		for (int j = 0; j < this->vertices->size(); j++) {
			Node * currNode = vertices->at(j);
			//edges are stored in the vertices not graph
			for (std::vector<std::pair<Node*, int>>::iterator it = currNode->getNeighbor()->begin();
				it != currNode->getNeighbor()->end(); it++) { 
				relax(currNode, it->first, it->second);
			}


		}

	}
	//check for negative weight cycles if there is return false
	//if there is then no shortest path can be detected through bellman ford
	for (int i = 0; i < this->vertices->size(); i++) {
		Node * currNode = vertices->at(i);
		for (std::vector<std::pair<Node*, int>>::iterator it = currNode->getNeighbor()->begin();
			it != currNode->getNeighbor()->end(); it++) {
			if (it->first->getWeight() > currNode->getWeight() + it->second)
				return false;
		}
	}

	
	return true;
}

void Graph::primsAlg( Node * startVertex) {
	Graph minSpanningTree;
	std::priority_queue<Node*, std::vector<Node*>, minQcomparison> minPQ;
	std::priority_queue<Node*, std::vector<Node*>, minQcomparison> minPQ2;
	//a vertex weight is the key
	//a vertex prev is pi
	for (int i = 0; i < this->vertices->size(); i++) {
		vertices->at(i)->setWeight(9999);
		vertices->at(i)->setPrev(nullptr);
	}

	//push all vertices into a min priority queue
	for (int i = 0; i < this->vertices->size(); i++) {
		Node * tempNodePtr = vertices->at(i);
		minPQ.push(tempNodePtr);
	}
	startVertex->setWeight(0);
	Node * currNodePtr;
	//Node * nextMinNode;
	//while queue is not empty process the front node and add all its neighbor that has not been visited into the queue
	while (!minPQ.empty()) {
		currNodePtr = minPQ.top();
		minPQ.pop();
		int lowestPathIndex = 0;
		if (currNodePtr->getNeighbor()->size() > 0) {
			for (int neighborIndex = 0; neighborIndex < currNodePtr->getNeighbor()->size(); neighborIndex++) {
				int minPQsize = minPQ.size();
				for (int minPQindex = 0; minPQindex < minPQsize; minPQindex++) {
					//check all currNode neighbors connection to get the lowest path cost
					if (currNodePtr->getNeighbor()->at(neighborIndex).first == minPQ.top()) {
						if (currNodePtr->getNeighbor()->at(neighborIndex).second
							< currNodePtr->getNeighbor()->at(lowestPathIndex).second) {
							lowestPathIndex = neighborIndex;
						}
					}
					//reinsert all nodes into min priority queue
					minPQ2.push(minPQ.top());
					minPQ.pop();
				}

				int minPQ2size = minPQ2.size();
				for (int i = 0; i < minPQ2size; i++) {
					minPQ.push(minPQ2.top());
					minPQ2.pop();
				}
			}
		
			//update the new lowest cost path
			int minPQsize = minPQ.size();
			for (int i = 0; i < minPQsize; i++) {
				if (minPQ.top() == currNodePtr->getNeighbor()->at(lowestPathIndex).first) {
					currNodePtr->getNeighbor()->at(lowestPathIndex).first->setPrev(currNodePtr);
					currNodePtr->getNeighbor()->at(lowestPathIndex).first->setWeight(currNodePtr->getNeighbor()->at(lowestPathIndex).second);
				}
				else
				{
					minPQ2.push(minPQ.top());
					minPQ.pop();
				}
			}
			int minPQ2size = minPQ2.size();
			for (int i = 0; i < minPQ2size; i++) {
				minPQ.push(minPQ2.top());
				minPQ2.pop();
			}


		}


	}
	
	recursivePrintMST(currNodePtr);

	
	system("pause");
}

void recursivePrintMST(Node * start) {
	if (start->getPrev()) {
		recursivePrintMST(start->getPrev());
	}
	std::cout << start->getWeight() << " -> ";
}