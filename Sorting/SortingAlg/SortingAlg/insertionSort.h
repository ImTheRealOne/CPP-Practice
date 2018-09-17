#pragma once
#include "sortAbstract.h"
class insertionSort:public sortAbstract
{
public:
	insertionSort();
	~insertionSort();

	void sort(std::vector<int> a);
	void sortByRef(std::vector<int> & a);
};

