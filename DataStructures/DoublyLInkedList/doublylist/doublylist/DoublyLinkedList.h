#pragma once
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"

template <class T>
class DoublyLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;

public:
	DoublyLinkedList();
	DoublyLinkedList(Node<T> *newHead);
	~DoublyLinkedList();

	void setHead(Node<T>* newHead);
	Node<T>* getHead();

	void setTail(Node<T>* newTail);
	Node<T>* getTail();

	void addToTail(Node<T>* newTail);
	void insertToHead(Node<T>* newHead);

	void moveToHead(Node<T>* currNode);
	void removeCurrNode(Node<T>* currNode);

	void print();
};




#include "DoublyLinkedList.cpp"

#endif // !DOUBLYLINKEDLIST_H

