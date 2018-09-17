#include "bubbleSort.h"



bubbleSort::bubbleSort()
{
}


bubbleSort::~bubbleSort()
{
}


void bubbleSort::sort(std::vector<int> a)  {
	std::cout << "bubble sort" << std::endl;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size()-1; j++) {
			if (a.at(j) > a.at(j + 1)) {
				int temp = a.at(j);
				a.at(j) = a.at(j + 1);
				a.at(j + 1) = temp;
			}

		}
	}

	print(a);

}

void bubbleSort::print(std::vector<int> a) {

	std::cout << "bubbleSort Print";
	sortAbstract::print(a);
}