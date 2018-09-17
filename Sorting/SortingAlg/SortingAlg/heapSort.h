#pragma once
#include "sortAbstract.h"

class heapSort
{
public:
	heapSort();
	~heapSort();

	void sort(std::vector<int> a);
	void buildMaxHeap(std::vector<int> a);
};

