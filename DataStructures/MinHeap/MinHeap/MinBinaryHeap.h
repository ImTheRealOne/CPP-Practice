#pragma once

#ifndef MINBINARYHEAP_H
#define MINBINARYHEAP_H



#include "BST.h"
#include <string>
#include <algorithm>

template <class T>
class MinBinaryHeap : public BST<T>
{
private:
	int size;
public:
	MinBinaryHeap();
	~MinBinaryHeap();
	void insert(T);
	void reheapifyUp(BinaryTreeNode<T>*);
	std::string itob(int);void extractMin();
	
};


#include "MinBinaryHeap.cpp"

#endif // !MINBINARYHEAP_H

