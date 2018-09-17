#pragma once
#ifndef STACK_H
#define STACK_H


#include "Node.h"
#include <iostream>
#include <stdlib.h>
template <class T>
class Stack
{
private:
	Node<T>* top, bottom;
	int capcity;
	int size;
public:
	Stack();
	Stack(int);
	~Stack();
	bool isFull();
	bool push(T data);
	Node<T> pop();
	void print();
	Node<T>* getHead();
	void setTop(Node<T>* );
	void setCap(int);
};

#include "Stack.cpp"

#endif // !STACK_H

