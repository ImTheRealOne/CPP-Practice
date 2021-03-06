// 17 - 4 MissingNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <random>

const int N = 8;

void createArr(int arr[N], int size, int randomInt);
void printArr(int arr[N], int size, std::string description);
void initializeArrWithZero(int arr[N], int size);
void count01Bits(int arr[N],int arrSize, int zeroBitArr[N],int zeroSize, int oneBitArr[N], int oneSize);
int main()
{
	int arr[N];
	int zeroBitArr[N];
	int oneBitArr[N];
	initializeArrWithZero(zeroBitArr, N);
	initializeArrWithZero(oneBitArr, N);

	srand(time(NULL));
	createArr(arr, N, 999);
	printArr(arr, N, "missing Num : ");
	count01Bits(arr,sizeof(arr)/sizeof(*arr), zeroBitArr, sizeof(zeroBitArr) / sizeof(*zeroBitArr),
					oneBitArr, sizeof(oneBitArr) / sizeof(*oneBitArr));
	printArr(zeroBitArr, N, "zero bit ");
	printArr(oneBitArr, N, "one bit ");

	int arr2[N - 1];
	int zeroBitArr2[N-1];
	int oneBitArr2[N-1];
	createArr(arr2, N-1, 5);
	printArr(arr2, sizeof(arr2) / sizeof(*arr2) , "missing Num : ");
	initializeArrWithZero(zeroBitArr2, sizeof(zeroBitArr2)/sizeof(*zeroBitArr2));
	initializeArrWithZero(oneBitArr2, sizeof(oneBitArr2)/sizeof(*oneBitArr2));
	count01Bits(arr2, sizeof(arr2) / sizeof(*arr2), zeroBitArr2, sizeof(zeroBitArr2) / sizeof(*zeroBitArr2),
		oneBitArr2, sizeof(oneBitArr2) / sizeof(*oneBitArr2));
	printArr(zeroBitArr2, sizeof(zeroBitArr2) / sizeof(*zeroBitArr2), "zero bit ");
	printArr(oneBitArr2, sizeof(oneBitArr2) / sizeof(*oneBitArr2), "one bit ");

	system("pause");
    return 0;
}

void createArr(int arr[N], int size, int randomInt) {
	
	std::cout << " randMissingNum : " << randomInt << std::endl;
	
	for (int i = 0; i < size; i++) {
		if (i >= randomInt) {
			arr[i] = i + 1;
		}
		else
		{
			arr[i] = i;
		}
	}
}

void printArr(int arr[N], int size, std::string description) {
	std::cout << description << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
}

void initializeArrWithZero(int arr[N], int size)
{
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

void count01Bits(int arr[N], int arrSize, int zeroBitArr[N], int zeroSize, int oneBitArr[N], int oneSize)
{
	int tempInt = 0;
	int numOfBits = 0;
	tempInt = arrSize;
	while (tempInt != 0) {
		numOfBits++;
		tempInt = tempInt >> 1;
	}
	for (int i = 0; i < arrSize-1; i++) {
		tempInt = arr[i];
		int bitIndex = 0;

		while (bitIndex <= numOfBits){
			int bit = tempInt & 1;
			
			if (bit) {
				oneBitArr[bitIndex] = oneBitArr[bitIndex] + 1;
			}
			else
			{
				zeroBitArr[bitIndex] = zeroBitArr[bitIndex] + 1;
			}
			

			bitIndex++;
			tempInt = tempInt >> 1;
		}

	}
}
