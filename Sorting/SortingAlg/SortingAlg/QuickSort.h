#pragma once
#include "Header.h"
#include "sortAbstract.h"
class QuickSort : public sortAbstract
{
public:
	QuickSort();
	~QuickSort();

	void sort(std::vector<int> a);
	int partiition(int left, int right, int index);
	void qSort(int left, int right);
	void setVector(std::vector<int>* );
private:
	std::vector<int>* vectorPtr;
};

