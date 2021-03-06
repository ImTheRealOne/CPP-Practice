// 16-16 SubSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

std::pair<int, int> subSort(int arr[], int size);
std::pair<int, int> subSortBrute(int arr[], int size);

int main()
{
	int arr[] = { 1,2,4,7,10,11,20,12,6,7,16,18,19 };
	int arr2[] = { 3,2,6,3,4,2,1,4,5 };
		
	std::pair<int, int> result;
	
	//result = subSort(arr, sizeof(arr) / sizeof(*arr));
	result = subSort(arr2, sizeof(arr2) / sizeof(*arr2));
	//result = subSortBrute(arr, sizeof(arr) / sizeof(*arr));


	std::cout << "result : " << result.first << " - " << result.second << std::endl;
	system("pause");
    return 0;
}

std::pair<int, int> subSort(int arr[], int size) {
	int lowerIndex = -1;
	int upperIndex = -1;

	for (int i = 0; i < size -1; i++) {
		if (lowerIndex == -1 && arr[i] > arr[i + 1]) {
			int walkerIndex = 0;
			while (arr[i+1] > arr[walkerIndex])
			{
				walkerIndex++;
			}
			lowerIndex = walkerIndex;
		}
		else if (lowerIndex != -1 && arr[i] < arr[lowerIndex])
		{
			int walkerIndex = lowerIndex;
			while (arr[i] < arr[walkerIndex-1])
			{
				walkerIndex--;
			}
			lowerIndex = walkerIndex;
		}
	}

	for (int i = size - 1; i > 0; i--) {
		if (upperIndex == -1 && arr[i] < arr[i - 1]) {
			int walkerIndex = size-1;
			while (arr[i-1] < arr[walkerIndex] )
			{
				walkerIndex--;
			}
			upperIndex = walkerIndex;
		}
		else if(upperIndex != -1 && arr[i] > arr[upperIndex])
		{
			int walkerIndex = upperIndex;
			while (walkerIndex < size-1 && arr[i] > arr[walkerIndex+1] )
			{
				walkerIndex++;
			}
			upperIndex = walkerIndex;
		}
	}

	return std::pair<int, int>(lowerIndex, upperIndex);
}

std::pair<int, int> subSortBrute(int arr[], int size)
{
	int lowerIndex = -1;
	int upperIndex = -1;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size-1; j++) {
			if (lowerIndex == -1 && arr[i] > arr[j]) {
				lowerIndex = i;
			}

		}
	}

	for (int i = size-1; i > 0; i--) {
		for (int j = i-1; j > 0; j--) {
			if (upperIndex == -1 && arr[i] < arr[j]) {
				upperIndex = i;
			}
		}
	}

	return std::pair<int, int>(lowerIndex, upperIndex);
}
