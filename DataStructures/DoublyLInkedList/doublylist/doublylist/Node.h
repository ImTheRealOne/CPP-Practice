#pragma once
#ifndef NODE_H
#define NODE_H



template <class T>
class Node
{
public:
	Node();
	Node(T);
	Node(T *);
	Node(const Node<T>&);

	~Node();

	void setData(T);
	T getData();

	void setNext(Node<T> *);
	Node<T>* getNext();

	void setPrev(Node<T> *);
	Node<T>* getPrev();

	void printData() {
		if(this)
			std::cout << data;
	}

private:
	T data;
	Node<T> *next;
	Node<T> *prev;
};

#include "Node.cpp"

#endif // !NODE_H