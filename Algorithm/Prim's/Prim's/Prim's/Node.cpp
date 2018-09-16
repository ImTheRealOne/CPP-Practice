
#include "Node.h"



Node::Node()
{

}


Node::~Node()
{
	prev = nullptr;
	neighbors->clear();
	std::cout << "node destructor" << std::endl;
}

Node::Node(const Node  & otherNode) {
	std::cout << "copy constructor" << std::endl;
	this->data = otherNode.data;
	this->weight = otherNode.weight;
	this->prev = otherNode.prev;
	this->neighbors = otherNode.neighbors;
}

Node::Node(int newData) {
	this->data = newData;
	weight = 9999;
	prev = nullptr;
	neighbors = new std::vector<std::pair<Node*, int>>();
}

Node::Node(int newData, int newWeight) {
	this->data = newData;
	this->weight = newWeight;
	prev = nullptr;
	neighbors = new std::vector<std::pair<Node*, int>>();
}

int Node::getData() const {
	return this->data;
}

void Node::setData(int newData) {
	this->data = newData;
	
}

int Node::getWeight() const {
	return weight;
}

void Node::setWeight(int newWeight) {
	this->weight = newWeight;
}

void Node::addNeighbor(Node* newNeighbor, int cost) {
	this->neighbors->emplace_back(std::make_pair(newNeighbor,cost));
}

std::vector<std::pair<Node *, int>> * Node::getNeighbor() {
	return this->neighbors;
}

void Node::setPrev(Node * prevNode) {
	this->prev = prevNode;
}

Node * Node::getPrev()
{
	return prev;
}
