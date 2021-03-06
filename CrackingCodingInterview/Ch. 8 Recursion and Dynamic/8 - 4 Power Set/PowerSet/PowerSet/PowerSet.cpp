// PowerSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

void powerSetHelper(int arr[], int size);
void powerSet(int arr[], int size, int pos, std::string result);

int main()
{
	int arr[5] = { 1,2,3,4, 5 };
	powerSetHelper(arr, 5);
	system("pause");
    return 0;

}

void powerSetHelper(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		powerSet(arr, size, i,"");
	}

}
void powerSet(int arr[], int size, int pos, std::string result) {
	
	if (pos >= size)
		return;
	
		result += static_cast<char> (arr[pos] + 48);
		result += ",";
		std::cout << "{"<< result <<"}"<< std::endl;

	for (int i = pos; i < size; i++) {
		powerSet(arr, size, i+1, result);
	}

	
}

