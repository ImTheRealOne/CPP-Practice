#include "QuickSort.h"



QuickSort::QuickSort()
{
}


QuickSort::~QuickSort() 
{
}

void QuickSort::sort(std::vector<int> a) {

	qSort(0,this->vectorPtr->size()-1);
	
}

void QuickSort::qSort( int left, int right) {
	if (left >= right)
		return;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(left, right);
	int pivot= distribution(generator);


	int pos = partiition( left, right, pivot);
	//print(*this->vectorPtr);
	qSort( left, pos - 1);
	qSort(pos + 1, right);

	
	return;
}

void QuickSort::setVector(std::vector<int>* a) {
	this->vectorPtr = a;
}


int QuickSort::partiition( int left, int right, int index) {
	
	sortAbstract::swap(*this->vectorPtr, index, right);
	int pos = left;
	for (int i = left; i < right; i++) {
		if (vectorPtr->at(i) <= vectorPtr->at(right)) {
			sortAbstract::swap(*vectorPtr, i, pos);
			pos++;
		}
	}
	//print(*this->vectorPtr);
	//std::cout << "pos : " << vectorPtr->at(pos) << "     right   :   " << vectorPtr->at(right) << std::endl;
	sortAbstract::swap(*this->vectorPtr, pos, right);
	//print(*this->vectorPtr);
	//std::cout << "pos : " << vectorPtr->at(pos) << "     right   :   " << vectorPtr->at(right) << std::endl;
	return pos;
}