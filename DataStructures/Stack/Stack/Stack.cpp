#pragma once
#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"


template <class T>
Stack<T>::Stack()
{
	Stack(NULL);
	top = nullptr;
}

template <class T>
Stack<T>::Stack(int cap) {
	this->capcity = cap;
	top = nullptr;
}



template <class T>
Stack<T>::~Stack()
{
	std::cout << "delete stack" << std::endl;


	if (top) {
		Node<T>* temp = nullptr;
		while (top) {
			temp = top;
			std::cout << "delete : " << temp->getData()<< std::endl;
			top = top->getNext();
			delete temp;
		}
	}

	system("pause");
}


template <class T>
bool Stack<T>::isFull() {
	return (size == capcity);
}

template <class T>
bool Stack<T>::push(T newData) {
	if (size >= capcity)
		return false;
	size++;
	
	Node<T>* newNode = new Node<T>(newData);
	if (top) {
		newNode->setNext(top);
		top = newNode;
	}
	else {
		top = newNode;
	}

	return true;
}

template <class T>
Node<T> Stack<T>::pop() {
	if (top) {
		Node<T>* temp = top;
		top = top->getNext();
		std::cout << "top : " << temp->getData() << std::endl;


		return *temp;
	}
	else
	{
		std::cout << "stack empty" << std::endl;
		return *new Node<T>(-1);
	}
}

template <class T> 
void Stack<T>::print() {
	if (top) {
		Node<T>* temp = nullptr;
		temp = top;
		while (temp) {
			std::cout << temp->getData() << " ";
			temp = (temp->getNext());
		}
		
	}
	else {
		std::cout << "stack empty" << std::endl;
	}
	std::cout << std::endl;
}

template <class T>
Node<T>* Stack<T>::getHead() {
	return top;

}


template <class T>
void Stack<T>::setTop(Node<T>* newHead) {
	top->equals(*newHead);

}

template<class T>
void Stack<T>::setCap(int newCap) {
	this->capcity = newCap;
}

#endif // !STACK_CPP
