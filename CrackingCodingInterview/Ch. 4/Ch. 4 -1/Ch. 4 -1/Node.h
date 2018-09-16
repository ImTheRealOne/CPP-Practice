#pragma once
#ifndef NODE_H
#define NODE_H
#include <vector>
#include <iostream>
#include <string>

template <class T>
class Node
{
private:
	T data;
	std::vector<Node<T>*>* children ;
public:
	Node();
	Node(T);
	~Node();
	void addNeighbor( Node<T>* const newNode );
	std::string printNeighbor();
	T const & getData () const;
	void setData(T);
	std::vector<Node<T>*>* const& getChildren() const;
	void setChildren(std::vector<Node<T>*>*);
	friend std::ostream& operator<< (std::ostream& os, const Node<T>* & node) {
		os << node->getData();
		return os;
	}
	
};


#include "Node.cpp"


#endif // !NODE_H



