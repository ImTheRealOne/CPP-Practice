#include "Graph.h"



Graph::Graph()
{
	this->vertices = new std::vector<Node *>();
	this->edges = new std::vector <Edge *> ();
}


Graph::~Graph()
{
	delete vertices;
	delete edges;
}

Graph::Graph(const Graph &otherGraph) {
	this->vertices = new std::vector<Node *>();
	this->edges = new std::vector < Edge*>();
	for (int i = 0; i < otherGraph.vertices->size(); i++) {
		this->vertices->emplace_back(new Node(*otherGraph.vertices->at(i)));

	}

	
	for (int i = 0; i < otherGraph.edges->size(); i++) {
		this->edges->emplace_back(new Edge(*otherGraph.edges->at(i)));
	}

	
}

Graph& Graph::operator= (const Graph &otherGraph) {
	this->vertices = new std::vector<Node*>();
	*vertices = *otherGraph.vertices;

	this->edges = new std::vector < Edge *>;

	*edges = *otherGraph.edges;

	return *this;

}

void Graph::setVertices(std::vector<Node*>* newVertices)
{
	this->vertices = newVertices;
}

 std::vector<Node*>* Graph::getVertices() const
{
	return this->vertices;
}

void Graph::setEdges(std::vector<Edge *>  * newEdges)
{
	this->edges = newEdges;
}

 std::vector<Edge *>* Graph::getEdges() const
{
	return this->edges;
}

const void Graph::print() {
	std::cout << std::endl;
	std::cout << std::endl << "Vertices : ";
	for (int i = 0; i < this->vertices->size(); i++) {
		std::cout << (char)((this->vertices->at(i)->getData()) + 'a') << "  ";
	}
	std::cout << std::endl << std::endl << "Edges : ";

	for (int i = 0; i < this->edges->size(); i++) {
		std::cout << (char)((this->edges->at(i)->getStart()->getData()) + 'a') << "->" 
						<< (char)((this->edges->at(i)->getEnd()->getData()) + 'a') <<
			" : " << (this->edges->at(i)->getCost()) << "    ";
	}
}

void Graph::addVertex(Node * newVertex) {
	this->vertices->emplace_back(newVertex);
}

void Graph::addEdge(Edge * newEdge) {
	this->edges->emplace_back(newEdge);

}