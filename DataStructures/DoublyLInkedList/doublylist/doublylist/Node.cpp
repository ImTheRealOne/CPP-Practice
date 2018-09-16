#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

template <class T>
Node<T>::Node()
{
	std::cout << "created node";
	next = nullptr;
	prev = nullptr;
}

template <class T>
Node<T>::Node(T newData) {
	data = newData;
	next = nullptr;
	prev = nullptr;
}

template<class T>
Node<T>::Node(T * newData)
{
	this->data = *newData;
	this->next = nullptr;
	this->prev = nullptr;

}

template<class T>
Node<T>::Node(const Node<T>& otherNode)
{
	this->setData(otherNode.getData());
	this->setNext(otherNode.getNext());
	this->setPrev(otherNode.getPrev());
}



template <class T>
Node<T>::~Node()
{
		
}

template<class T>
T Node<T>::getData()
{
	return data;
}

template<class T>
void Node<T>::setNext(Node<T>* newNext)
{
	next = newNext;
}

template<class T>
Node<T>* Node<T>::getNext()
{
	if(next != nullptr)
		return next;
	else
	{
		return nullptr;
	}
}

template<class T>
void Node<T>::
setPrev(Node<T>* newPrev)
{
	prev = newPrev;
}

template<class T>
Node<T>* Node<T>::getPrev()
{
	if(prev)
		return prev;
	else
	{
		return nullptr;
	}
}




#endif // !NODE_CPP