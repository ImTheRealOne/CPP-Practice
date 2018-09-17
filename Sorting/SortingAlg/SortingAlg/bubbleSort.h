#pragma once
#include "sortAbstract.h"
class bubbleSort: public sortAbstract
{
public:
	bubbleSort();
	~bubbleSort();
	
	void sort(std::vector<int> a) override;
	void print(std::vector<int> a);
};

