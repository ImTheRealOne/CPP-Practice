#include "Main.h"
#include <iostream>


Main::Main()
{
}

int insertMIntoN(int m, int n, int i, int j);

Main::~Main()
{
}

int main() {

	int m = 32768;
	int n = 64;
	int i = 5;
	int j = 12;
		std::cout << "insert m into N : " << insertMIntoN(m, n, i, j);
	system("pause");
	return 0;
}

int insertMIntoN(int m, int n, int i, int j) {
	int result =0;
	
	int numOfBits = 0;
	
	int tempM = m;
	while (tempM >> 1 != 0) {
		tempM = tempM >> 1;
		numOfBits++;
	}

	if (tempM == 1) {
		numOfBits++;
	}

	tempM = m;
	tempM = tempM >> i;
	tempM = tempM << i;

	int clear = numOfBits -j + i;

	int mask = 1 << clear;

	unsigned int mask2 = tempM & (mask - 1);

	mask2 = ~mask2;

	result = (m&mask2) | (n << i);

		return result;
}

