// 17 - 1 BitwisePlus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int bitwiseAddition( int a,  int b);

int reverseBitArray(int arr [], int size);
int add(int, int);

int main()
{
	signed int test = 6;
	
	std::cout<<add(3, -4)<< std::endl;
	system("pause");
    return 0;
}

int bitwiseAddition( int a,  int b)
{
	int carryBit = 0;
	int aBit = 0;
	int bBit = 0;
	int resultBit = 0;
	int aSignBit = 0;
	int bSignBit = 0;
	int resultArray[64];
	int num = 0;
	if (a < 0) {
		aSignBit = 1;
	}
	if (b < 0) {
		bSignBit = 1;
	}
	int i = 0;
	while ((a != 0) || (b != 0) || carryBit) {
		resultBit = 0;
		aBit = a & 1;
		bBit = b & 1;
		if (carryBit) {
			resultBit = 1;
			carryBit = 0;
		}
		if (aBit & bBit) {
			carryBit = 1;
			aBit = 0;
			bBit = 0;
		}
		else if((aBit ^ bBit) & resultBit)
		{
				carryBit = 1;
				resultBit = 0;
			if (aBit) {
				aBit = 0;
			}
			if (bBit) {
				bBit = 0;
			}
		}
		
			resultBit = (aBit ^ bBit) ^ resultBit;
		resultArray[i] = resultBit;
		i++;
		a = a >> 1;
		b = b >> 1;
		
	}

	int result = reverseBitArray(resultArray, i-1);

	return result;
}

int reverseBitArray(int arr[], int size) {
	int result = 0;
	for (int i = size; i > 0; i--) {
		result = result | arr[i];
		result = result << 1;
	}
	return result;
}

int add(int a, int b) {
	 while (b != 0) {
		 int sum = a ^ b; // add without carrying
		 int carry = (a & b) << 1; // carry, but don't add a sum;
		 std::cout << " a : " << a << ", b : " << b << " , sum : " << sum << " , carry : " << carry << std::endl;
		 a = sum;
		b = carry;
	}
	return a;
	
}