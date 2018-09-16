#include "Main.h"
#include "Graph.h"
#include <map>

Main::Main()
{
}


Main::~Main()
{
}
/*
Name : hamiltonian cycle
paramater : a constant graph passed by reference, 
			a vector of visited nodes,
			a pointer to the current node,
			an integer value passed by reference
			a map that store start node as keys and the value is a end node and cost composed into a pair
purpose : cycle the optimal hamiltonian path

*/
std::vector<Node *> hamiltonianCycleHelper(const Graph &graph, std::vector<Node *> visitedNodes, Node * currentNode,
	int &lowerBound, std::map < Node *, std::vector<std::pair<Node *, int>>>);

std::vector<Node *> hamiltonianCycle(const Graph &graph, std::vector<Node *> visitedNodes, Node * currentNode,
	int &lowerBound, std::map < Node *, std::vector<std::pair<Node *, int>>>  map);


/*
name : initializeMap
parameter : graph 
purpose : update the map of edges to correspond to the new paths that are added as a part of the hamiltonian cycle
*/
std::map<Node*, std::vector<std::pair<Node *, int>> > initializeMap(const Graph & graph);

/*
name : updateMap
parameter :	graph
purpose : update the map with the next node visited
*/
std::map<Node*, std::vector<std::pair<Node *, int>> > updateMap(const Graph& graph, Node *source, Node * nextVisited
			, std::map<Node*, std::vector<std::pair<Node *, int>> >);

/*
name : calculateWeight
parameter : a map that store start node as keys and the value is a end node and cost composed into a pair
purpose : calculate the weight of the edges that are part of the hamiltonian cycle
*/
int calculateWeight(std::map < Node *, std::vector<std::pair<Node *, int>> > map);
	
/*
name : contains 
parameter : a vector of node ptr
			a Node ptr
purpose	:	check if a perticular node is in the visited vector
*/
bool contains(const std::vector<Node *> &visited, Node * target);

/*
name : printMap
parameter :	a std::map <Node *, std::vector<std::pair<Node *, int>> >
purpose :	formatted print the data stored inside the map
*/

const void printMap( std::map < Node *, std::vector<std::pair<Node *, int>> > &map);

int main() {

	Graph graphA;

	
	Node * a = new Node(0);
	Node * b = new Node(1);
	Node * c = new Node(2);
	Node * d = new Node(3);
	Node * e = new Node(4);

	graphA.addVertex(a);
	graphA.addVertex(b);
	graphA.addVertex(c);
	graphA.addVertex(d);
	graphA.addVertex(e);

	Edge * edgeAB = new Edge(a, b, 3);
	Edge * edgeAC = new Edge(a, c, 1);
	Edge * edgeAD = new Edge(a, d, 5);
	Edge * edgeAE = new Edge(a, e, 8);

	graphA.addEdge(edgeAB);
	graphA.addEdge(edgeAC);
	graphA.addEdge(edgeAD);
	graphA.addEdge(edgeAE);

	Edge * edgeBA = new Edge(b, a, 3);
	Edge * edgeBC = new Edge(b, c, 6);
	Edge * edgeBD = new Edge(b, d, 7);
	Edge * edgeBE = new Edge(b, e, 9);

	graphA.addEdge(edgeBA);
	graphA.addEdge(edgeBC);
	graphA.addEdge(edgeBD);
	graphA.addEdge(edgeBE);

	Edge * edgeCA = new Edge(c, a, 1);
	Edge * edgeCB = new Edge(c, b, 6);
	Edge * edgeCD = new Edge(c, d, 4);
	Edge * edgeCE = new Edge(c, e, 2);

	graphA.addEdge(edgeCA);
	graphA.addEdge(edgeCB);
	graphA.addEdge(edgeCD);
	graphA.addEdge(edgeCE);

	Edge * edgeDA = new Edge(d, a, 5);
	Edge * edgeDB = new Edge(d, b, 7);
	Edge * edgeDC = new Edge(d, c, 4);
	Edge * edgeDE = new Edge(d, e, 3);

	graphA.addEdge(edgeDA);
	graphA.addEdge(edgeDB);
	graphA.addEdge(edgeDC);
	graphA.addEdge(edgeDE);

	Edge * edgeEA = new Edge(e, a, 8);
	Edge * edgeEB = new Edge(e, b, 9);
	Edge * edgeEC = new Edge(e, c, 2);
	Edge * edgeED = new Edge(e, d, 3);

	graphA.addEdge(edgeEA);
	graphA.addEdge(edgeEB);
	graphA.addEdge(edgeEC);
	graphA.addEdge(edgeED);

	std::map < Node *, std::vector<std::pair<Node *, int>>> edgePaths;
	std::vector<Node *> visitedPaths;
	int optWeight = 99999;
	edgePaths = initializeMap(graphA);
	visitedPaths = hamiltonianCycleHelper(graphA, visitedPaths, a, optWeight, edgePaths);
	
	system("pause");
	return 0;
}

std::vector<Node *> hamiltonianCycleHelper(const Graph &graph, std::vector<Node *> visitedNodes, Node * currentNode, 
	int &lowerBound, std::map < Node *, std::vector<std::pair<Node *, int>>>  map) {
	std::map < Node *, std::vector<std::pair<Node *, int>>>  tempMap;

	map = initializeMap(graph);
	
	visitedNodes =	hamiltonianCycle(graph, visitedNodes, currentNode, lowerBound, map);

	return visitedNodes;
}

std::vector<Node *> hamiltonianCycle(const Graph &graph, std::vector<Node *> visitedNodes, Node * currentNode, 
	int &lowerBound, std::map < Node *, std::vector<std::pair<Node *, int>>>  map) {
	std::map < Node *, std::vector<std::pair<Node *, int>>>  tempMap;
	//check if current node is already visited
	visitedNodes.push_back(currentNode);

	//check if all nodes are pushed if yes then check if optimal weight should be updated
	if (graph.getVertices()->size() == visitedNodes.size()) {
		Node* sourceNode = visitedNodes.at(0);
		Node * endNode = visitedNodes.at(visitedNodes.size() - 1);
		
		tempMap = updateMap(graph, endNode, sourceNode, map);
		int tempWeight = calculateWeight(tempMap);

		if (lowerBound > tempWeight) {
			lowerBound = tempWeight;
			//printMap(tempMap);
			if (tempMap.at(endNode).at(0).first == sourceNode || tempMap.at(endNode).at(1).first == sourceNode) {
				std::cout << std::endl << "Hamiltonian Graph" << std::endl;
				std::cout << " weight : " << tempWeight << std::endl;
				for (int i = 0; i < visitedNodes.size(); i++) {
					std::cout << (char)(visitedNodes.at(i)->getData() + 'a') << "   ";
				}
				std::cout << std::endl;
			}
		}
		
		
	}
	
	//find next node to visit
 	for (int i = 0; i < graph.getVertices()->size()-1; i++) {
		if (!contains(visitedNodes, graph.getVertices()->at(i + 1))) {
			//std::cout << std::endl << "   next node : " << (char)(graph.getVertices()->at(i + 1)->getData() + 'a') << std::endl;
			tempMap = updateMap(graph, currentNode, graph.getVertices()->at(i + 1), map);
			//printMap(tempMap);
			hamiltonianCycle(graph, visitedNodes, graph.getVertices()->at(i + 1), lowerBound, 
				updateMap(graph, currentNode, graph.getVertices()->at(i + 1), map));


		}
	}
	
	return visitedNodes;
}

std::map < Node *, std::vector<std::pair<Node *, int>> > initializeMap(const Graph  &graph) {
	std::map<Node*, std::vector<std::pair<Node *, int>> > result;
	std::map < Node *, std::vector<std::pair<Node *, int>>>::iterator it;

	//go through all vertices 
	for (int i = 0; i < graph.getVertices()->size(); i++) {
		//look for the two lowest edges
		for (int j = 0; j < graph.getEdges()->size(); j++) {
			if (graph.getVertices()->at(i) == graph.getEdges()->at(j)->getStart()) {

				it = result.find(graph.getVertices()->at(i));
				Node * tempNodePtr = graph.getVertices()->at(i);
				//new Node add a new vector to the map
				if (it == result.end()) {
					std::vector <  std::pair<Node*, int>> keyVector = *new std::vector <  std::pair<Node*, int>>();
					keyVector.emplace_back(*new std::pair<Node*, int >(graph.getEdges()->at(j)->getEnd(),
						graph.getEdges()->at(j)->getCost()));
					
					result[tempNodePtr] = keyVector;
				}
				else
				{
					//if there's not a second chosen edge add the new edge to the vector
					if (result[tempNodePtr].size() < 2) {
						result.at(tempNodePtr).emplace_back(*new std::pair<Node*, int>(graph.getEdges()->at(j)->getEnd(),
							graph.getEdges()->at(j)->getCost()));
					}
					//look for the smaller one
					else
					{
						//replace the larger edge of the two edges
						if (graph.getEdges()->at(j)->getCost() < result.at(tempNodePtr).at(0).second ||
							graph.getEdges()->at(j)->getCost() < result.at(tempNodePtr).at(1).second) {
							if (result.at(tempNodePtr).at(0).second < result.at(tempNodePtr).at(1).second) {
								result.at(tempNodePtr).at(1).first = graph.getEdges()->at(j)->getEnd();
								result.at(tempNodePtr).at(1).second = graph.getEdges()->at(j)->getCost();
							}
							else
							{
								result.at(tempNodePtr).at(0).first = graph.getEdges()->at(j)->getEnd();
								result.at(tempNodePtr).at(0).second = graph.getEdges()->at(j)->getCost();
							}
						}
					}
				}
			}

		}
	}

	return result;
}

std::map < Node *, std::vector<std::pair<Node *, int>>> updateMap(const Graph& graph, Node *source, Node * nextVisited,
	std::map<Node*, std::vector<std::pair<Node *, int>> > map) {
	std::map<Node*, std::vector<std::pair<Node *, int>> >::iterator it;
	//map vector pos 0 is previous, pos 1 is next
	//find source node in map
	it = map.find(source);
	if (it != map.end()) {
		if (it->second.at(1).first == nextVisited) {
			//do nothing next is already at pos 1
		}
		//swap the vector elements at 0 with 1
		else if (it->second.at(0).first == nextVisited) {
			std::pair<Node *, int > tempPair = it->second.at(0);
			it->second.at(0) = it->second.at(1);
			it->second.at(1) = tempPair;
		}
		else
		{
			it->second.at(1).first = nextVisited;
			for (int i = 0; i < graph.getEdges()->size(); i++) {
				if (graph.getEdges()->at(i)->getStart() == source && graph.getEdges()->at(i)->getEnd() == nextVisited) {
					it->second.at(1).second = graph.getEdges()->at(i)->getCost();
				}
			}
		}
	}
	it = map.find(nextVisited);
	if (it != map.end()) {
		//prvious is in next slot swap 
		if (it->second.at(1).first == source) {
			std::pair<Node *, int > tempPair = it->second.at(0);
			it->second.at(0) = it->second.at(1);
			it->second.at(1) = tempPair;
		}
		//swap the vector elements at 0 with 1
		else if (it->second.at(0).first == source) {
			//prev is already source do nothing
		}
		else
		{
			
			it->second.at(0).first = source;
			for (int i = 0; i < graph.getEdges()->size(); i++) {
				if (graph.getEdges()->at(i)->getStart() == source && graph.getEdges()->at(i)->getEnd() == nextVisited) {
					it->second.at(0).second = graph.getEdges()->at(i)->getCost();
				}
			}
		}

	}
	
	return map;
}

bool contains(const std::vector<Node *> &visited, Node * target) {
	for (int i = 0; i < visited.size(); i++) {
		if (visited.at(i) == target)
			return true;
	}
	return false;
}

int calculateWeight(std::map < Node *, std::vector<std::pair<Node *, int>> > map) {
	std::map < Node *, std::vector<std::pair<Node *, int>> >::iterator it;
	int weight = 0;
	for (it = map.begin(); it != map.end(); it++) {
		for (int i = 0; i < it->second.size(); i++) {
			weight += it->second.at(i).second;
		}

	}

	return weight/2;
}

const void printMap( std::map < Node *, std::vector<std::pair<Node *, int>> > & map) {
	for (std::map < Node *, std::vector<std::pair<Node *, int>>>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << " start : " << (char)(it->first->getData() + 'a') << "   ";
		for (int i = 0; i < it->second.size(); i++) {
			std::cout << "end : " << (char)(it->second.at(i).first->getData() + 'a') << "  cost : " << it->second.at(i).second << "   ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}