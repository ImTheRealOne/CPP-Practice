#include "BinSort.h"



BinSort::BinSort()
{
}


BinSort::~BinSort()
{
	delete v;
}

void BinSort::sort(std::vector<int> a) {
	v = new std::vector<std::vector<int>>();

	for (int i = 0; i < 10; i++) {

		v->push_back( *new std::vector<int>());
	}

	for (int i = 0; i < a.size(); i++) {
		v->at(a.at(i) / 10).push_back(a.at(i));
	}

	for (int i = 0; i < v->size(); i++) {
		insertionSort ins;
		ins.sortByRef((v->at(i)));

	}
	a.clear();
	for (int i = 0; i < v->size(); i++) {
		if (!v->at(i).empty()) {

			for (int j = 0; j < v->at(i).size(); j++) {
				a.push_back(v->at(i).at(j));

			}
		}

	}
	print(a);
}