#pragma once
#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "Vector.h"

template <class U>
Vector<U>::Vector()
{
	this->vectorArray = nullptr;
	this->size = 0;
	this->capacity = 4;
	this->endPtr = nullptr;
	this->beginPtr = nullptr;
}

template <class U>
Vector<U>::~Vector()
{
	//delete[] vectorArray;

}

template<class U>
Vector<U>::Vector(const Vector<U> & otherVector)
{
	this->size = otherVector.size;
	this->capacity = otherVector.capacity;

	this->vectorArray = new U[capacity];
	U* otherVectorWalker = otherVector.beginPtr;
	U* thisVectorWalker = this->vectorArray;

	while (otherVectorWalker != otherVector.endPtr) {
		*thisVectorWalker = U(*otherVectorWalker);
		thisVectorWalker++;
		otherVectorWalker++;

	}
	
	
}



template<class U>
Vector<U> & Vector<U>::operator=(const Vector<U> & otherVector)
{
	this->size = otherVector.size;
	this->capacity = otherVector.capacity;
	this->vectorArray = new U[otherVector.capacity];
	U* walkerPtr = vectorArray;
	beginPtr = vectorArray;
	U* otherBeginPtr = otherVector.beginPtr;
	while (otherBeginPtr != otherVector.endPtr) {
		if (otherBeginPtr)
			*walkerPtr = U(*otherBeginPtr);
		walkerPtr++;
		otherBeginPtr++;
	}
	this->endPtr = walkerPtr + 1;

	return *this;
}

template<class U>
void Vector<U>::insert(const int &position, U  element)
{
	if (size == 0) {
		reserve(1);
		size++;
		vectorArray[0] = element;
		beginPtr = vectorArray;
		endPtr = beginPtr + 1;
	}
	else
	{
		if (position > size) {
			std::cout << "invalid position for insertion : position > size" << std::endl;
			return;
		}
		if (capacity < size + 1) {
			reserve(capacity * 2);
		}
		size++;
		int i = 0;
		U * insertPlacePtr = beginPtr + position;
		U * endWalker = endPtr;
		endWalker++;
		endPtr = endWalker;
		while (endWalker != insertPlacePtr)
		{
			U newElement(*(endWalker - 1));
			*endWalker = newElement;
			endWalker--;
		}
		*endWalker = U(element);
	}
}

template<class U>
void Vector<U>::push_back(const U &element) {
	if (size == 0) {
		reserve(1);
		size++;
		vectorArray[0] = element;
		beginPtr = vectorArray[0];
		endPtr = beginPtr;
	}

}

template<class U>
void Vector<U>::reserve(const int &newCapacity) {
	U *tempPtr;
	int i = 0;
	tempPtr = this->beginPtr;
	U * newVector = new U[newCapacity];
	this->capacity = newCapacity;
	//copy all internal elements


	while (tempPtr != this->endPtr &&  i < newCapacity) {
		if (tempPtr)
			newVector[i] = U(*tempPtr);
		tempPtr++;
		i++;
	}
	delete[] vectorArray;
	vectorArray = newVector;
	beginPtr = vectorArray;
	endPtr = beginPtr + size;
}

template<class U>
void Vector<U>::print() {
	for (int i = 0; i < this->size; i++) {

		std::cout << vectorArray[i] << "  ";
	}
	std::cout << std::endl;
}

template<class U>
U * Vector<U>::end()
{
	return this->endPtr;
}

template<class U>
U * Vector<U>::begin()
{
	return this->beginPtr;
}




#endif // !VECTOR_CPP


