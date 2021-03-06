// 16-17 ContSeq.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int	largestSubArray(int arr[], int size);
int cont_seq(int arr[], int size);

int main()
{
	int arr[] = { -2,1,-3,4,-1,2,1,-5,4 };

	std::cout<<"largest Sub array " << cont_seq(arr, sizeof(arr) / sizeof(*arr)) << std::endl;

	system("pause");
    return 0;
}

int largestSubArray(int arr[], int size)
{
	int largestSum = 0;
	int runningSum = 0;

	for (int i = 0; i < size; i++) {

		runningSum += arr[i];
		if (arr[i] > runningSum) {
			runningSum = arr[i];
		}
		if (runningSum > largestSum) {
			largestSum = runningSum;
		}
	}

	return largestSum;
}

int cont_seq(int array[], int size) {
	int max = array[0], run = max;
	std::pair<int, int> window(0, 1);

	while (window.first < size && window.second < size) {
		if (window.first == window.second) {
			window.second++;
			continue;
		}

		run += array[window.second];
		
		if (array[window.second] > run) {
			window.first = window.second;
			run = array[window.first];
		}

		if (run > max) {
			max = run;
		}

		window.second += 1;
		//if (window.first == window.second) {
		//	window.second++;
		//	continue;
		//}
		//int temp = run + array[window.second];

		//if (temp > max) {
		//	max = temp;
		//}

		//if (temp > run) {
		//	window.second++;
		//	run = temp;
		//}
		//else {
		//	run = temp - array[window.first];
		//	window.first++;
		//	window.second++;
		//	//window.second + 1 < size-1 ? window.second++: window.second;
		//}
	}

	return max;
}