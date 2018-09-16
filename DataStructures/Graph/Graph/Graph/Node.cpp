#include "Node.h"



Node::Node()
{
	data = -9999;

}


Node::~Node()
{
}

const int Node::getData()
{
	return data;
}

void Node::setData(const int &newData)
{
	this->data = newData;
}

Node& Node::operator= (const Node& otherNode) {
	Node * tempNode	= new Node(otherNode);
	return *tempNode;
}