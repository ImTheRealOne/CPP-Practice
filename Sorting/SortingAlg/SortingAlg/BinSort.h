#pragma once
#include "Header.h"

class BinSort : public sortAbstract
{
public:
	BinSort();
	~BinSort();
	void sort(std::vector<int>);
private:
	std::vector<std::vector<int>> * v;
};

