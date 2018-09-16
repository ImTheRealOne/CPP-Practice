#pragma once


#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <class U>
class Vector
{
private:
	U * vectorArray;
	int size;
	int capacity;
	U * beginPtr;
	U * endPtr;
public:
	Vector();
	~Vector();
	Vector(const Vector &otherVector);
	Vector& operator=(const Vector& otherVector);
	void insert(const int &position, U element);
	void erase(int &position);
	void push_back(const U &element);
	void pop_back();
	void reserve(const int & newCapacity);
	void print();
	U * end();
	U * begin();

};


#include "Vector.cpp"

#endif // !VECTOR_H





