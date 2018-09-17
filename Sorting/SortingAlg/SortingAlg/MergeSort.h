#pragma once
#include "sortAbstract.h"
class MergeSort : public sortAbstract
{
public:
	MergeSort();
	~MergeSort();

	void sort(std::vector<int> a);
	void sort(std::vector<int> &a, int p, int r);
	void merge(std::vector<int> &a, int p , int q, int r);
	void setVector(std::vector<int> *a);
private:
	std::vector<int> * vectorPtr;
};



