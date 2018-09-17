#pragma once
#ifndef ARRAYMINHEAP_H
#define ARRAYMINHEAP_H

#include <vector>
#include "BinaryTreeNode.h"

template <class T>
class ArrayMinHeap
{
private:
	int size;
	std::vector<BinaryTreeNode<T>*>* heap;
public:
	ArrayMinHeap();
	~ArrayMinHeap();
	void insert(T);
	void heapify();
	void heapifyUp(int);
	void Print();
};




#include "ArrayMinHeap.cpp"

#endif // !ARRAYMINHEAP_H



