// Malloc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>

void * align_malloc(const int size, const int multiple);

bool isMultiple(void * addressPtr, const int multiple);

int main()
{
	
	void * voidPtr = malloc(2000);
	int a = 128;
	//uintptr_t number = (uintptr_t)voidPtr;
	int number = *(int *)(&voidPtr);
	std::cout << voidPtr<<std::endl;
	std::cout << number << std::endl;
	int differnce = 0;
	while (number % 128 != 0)
	{
		number += 4;
		differnce += 1;
	}
	void * tempPtr = (static_cast<int *> ( voidPtr)) + differnce;
	std::cout << differnce << std::endl;
	std::cout << voidPtr <<std::endl;
	std::cout << tempPtr << std::endl;
	


	system("pause");
    return 0;
}

void * align_malloc(const int size, const int multiple) {
	void * voidPtr = malloc(1000);


	return voidPtr;
}

bool isMultiple(void * addressPtr, const int multiple) {
	if ((long)addressPtr % multiple) {
		return true;
	}
	return false;
}