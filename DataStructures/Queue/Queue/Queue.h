#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
template <class T> class Queue
{
private:
	T data;
	Node head;

public:
	Queue();
	~Queue();
	void enqueue(T);
	Node<T> dequeue(T);
};

#include "Queue.cpp"


#endif // !QUEUE_H


