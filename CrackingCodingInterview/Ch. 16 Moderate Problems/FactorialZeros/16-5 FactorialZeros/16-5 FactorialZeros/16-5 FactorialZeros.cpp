// 16-5 FactorialZeros.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
int factorialZero(int const n);

int main()
{
	const int N = 200;
	for (int i = N; i > 0; i--) {
		std::cout << " trailing zeros for " << i << " : " << factorialZero(i) << std::endl;
	}

	system("pause");
    return 0;
}

int factorialZero(const int n) {
	int tempN = n;
	int trailingZeroes = 0;
	int quotient = 0;
	while (tempN >= 5) {
		if (tempN % 5 == 0) {
			trailingZeroes++;
			quotient = tempN / 5;
			while (quotient % 5 == 0) {
				trailingZeroes++;
				quotient /= 5;
			}
			tempN -= 5;
		}
		else
		{
			tempN--;
		}
	}
	return trailingZeroes;
}
