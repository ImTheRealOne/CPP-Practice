#include "sortAbstract.h"



sortAbstract::sortAbstract()
{
}


sortAbstract::~sortAbstract()
{
}

void sortAbstract::print(std::vector<int> a) {
	for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
}

void sortAbstract::swap(std::vector<int>& a, int i, int j) {

	int temp = a.at(i);
	a.at(i) = a.at(j);
	a.at(j) = temp;
}