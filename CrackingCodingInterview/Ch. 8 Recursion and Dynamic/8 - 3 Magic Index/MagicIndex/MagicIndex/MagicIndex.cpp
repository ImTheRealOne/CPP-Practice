// MagicIndex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool magicIndex(int arr[], int lowerB, int upperB);

int main()
{
	int arr[5] = { 1,2,3,3,4 };

	std::cout << "result : ";
	if (!magicIndex(arr, 0, sizeof(arr) / sizeof(*arr))) {
		std::cout << "no magic number";
	}


	system("pause");
	return 0;
}

bool magicIndex(int arr[],  int lowerB, int upperB) {
	int midIndex = (upperB + lowerB) / 2;
	bool result = false;

	if (lowerB <= upperB) {

		if (midIndex == arr[midIndex]) {
			std::cout << midIndex;
			return true;
		}
		if (midIndex < arr[midIndex]) {
			result = magicIndex(arr, lowerB, midIndex - 1);
		}
		else if ( midIndex > arr[midIndex]) {
			result = magicIndex(arr, midIndex+1, upperB);
		}
	}

	return result;
}

