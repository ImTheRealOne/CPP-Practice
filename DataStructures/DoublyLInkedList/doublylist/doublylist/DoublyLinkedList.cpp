#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP

#include "DoublyLinkedList.h"

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(Node<T>* newHead)
{
	head = newHead;
	if (!tail) {
		tail = newHead;
	}
}



template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	if (head)
		delete head;

}

template<class T>
void DoublyLinkedList<T>::setHead(Node<T>* newHead)
{
	head = newHead;
}

template<class T>
Node<T>* DoublyLinkedList<T>::getHead()
{
	return head;
}

template<class T>
void DoublyLinkedList<T>::setTail(Node<T>* newTail)
{
	tail = newTail;
}

template<class T>
Node<T>* DoublyLinkedList<T>::getTail()
{
	return tail;
}

template<class T>
void DoublyLinkedList<T>::addToTail(Node<T>* newTail)
{
	if (!head) {
		head = newTail;
		tail = newTail;
	}
	else
	{
		Node<T> *walker = head;
		while (walker->getNext()) {
			walker = walker->getNext();
		}
		walker->setNext(newTail);
		newTail->setPrev(walker);
		tail = newTail;
	}
}

template<class T>
void DoublyLinkedList<T>::insertToHead(Node<T>* newHead)
{	
	if (!head) {
		tail = newHead;
	}
	newHead->setNext(head);
	if (head) {
		head->setPrev(newHead);
	}
	head = newHead;
}

template<class T>
void DoublyLinkedList<T>::moveToHead(Node<T>* currNode)
{
	if (currNode == tail) {
		if (currNode->getPrev()) {
			tail = currNode->getPrev();
		}
		else
		{
			tail = nullptr;
		}
	}
	Node<T> *prevNode = currNode->getPrev();
	prevNode->setNext(currNode->getNext());
	currNode->setPrev(nullptr);
	insertToHead(currNode);
}

template<class T>
void DoublyLinkedList<T>::removeCurrNode(Node<T>* currNode)
{
	if (currNode == tail) {
		if (currNode->getPrev()) {
			tail = currNode->getPrev();
		}
		else
		{
			tail = nullptr;
		}
	}
	if (currNode == head) {
		head = currNode->getNext();
		head->setPrev(nullptr);
	}
	else {
		Node<T> *prevNode = currNode->getPrev();
		prevNode->setNext(currNode->getNext());
		if (currNode->getNext()) {
			currNode->getNext()->setPrev(prevNode);
		}
	}
	currNode->setNext(nullptr);
	currNode->setPrev(nullptr);
	delete currNode;

}

template<class T>
void DoublyLinkedList<T>::print()
{
	std::cout << std::endl << "Head : "; 
	head->printData();
	std::cout << "	Tail : ";
	tail->printData();
	std::cout << std::endl;;
	Node<T> *walker = head;
	while (walker) {
		walker->printData();
		walker = walker->getNext();
		std::cout << "->";
	}
	std::cout << std::endl;
}





#endif // !DOUBLYLINKEDLIST_CPP


