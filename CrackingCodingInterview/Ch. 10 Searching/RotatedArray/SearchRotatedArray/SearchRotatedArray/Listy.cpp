#include "Listy.h"



Listy::Listy()
{
	std::vector<int> myVector;
	list = std::make_shared<std::vector<int>>(myVector);
}

Listy::Listy(int arr[], int size) {
	std::vector<int> myVector;
	list = std::make_shared<std::vector<int>>(myVector);
	for (int i = 0; i < size; i++) {
		list->push_back(arr[i]);
	}
}

Listy::~Listy()
{
	
}

int Listy::getAt(int i) {
	try {
		return list->at(i);
	}
	catch (const std::out_of_range & oor) {
		std::cout << "out of range : " << oor.what() << std::endl;
	}

	return -99;
}
