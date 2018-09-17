#pragma once
#include <vector>
#include <iostream>
class sortAbstract abstract
{
public:
	sortAbstract();
	~sortAbstract();
	virtual void sort(std::vector<int> a)  = 0;
	void print(std::vector<int> a);
	void swap(std::vector<int>& a, int i, int j);
};

