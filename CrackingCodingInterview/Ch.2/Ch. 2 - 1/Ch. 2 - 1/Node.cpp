#include "Node.h"
#include <iostream>



Node::Node()
{
	data = NULL;
	next = nullptr;
}

Node::Node(int num, Node* nextNode) {
	data = num;
	next = nextNode;

}

Node::~Node()
{
}

void Node::equals (const Node copyNode) {
	this->data = copyNode.data;
	this->next = copyNode.next;
}
