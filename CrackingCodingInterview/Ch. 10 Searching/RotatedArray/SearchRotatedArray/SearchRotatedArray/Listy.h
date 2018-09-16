#pragma once
#include <vector>
#include <memory>
#include <iostream>

class Listy
{
public:
	Listy();
	Listy(int arr [] , int size);
	~Listy();
	int getAt(int i);

private:
	std::shared_ptr<std::vector<int>> list;
};

