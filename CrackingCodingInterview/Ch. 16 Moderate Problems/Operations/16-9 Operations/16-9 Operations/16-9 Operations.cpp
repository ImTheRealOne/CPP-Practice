// 16-9 Operations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int negate( int num);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main()
{
	int a = 0;
	int b = -3;
	std::cout << negate(b) << std::endl;
	std::cout << a << " + " << b << " = " << add(a, b) <<std::endl;
	std::cout << a << " - " << b << " = " << subtract(a, b) << std::endl;
	std::cout << a << " * " << b << " = " << multiply(a, b) << std::endl;
	try {
		std::cout << a << " / " << b << " = " << divide(a, b) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}
	system("pause");
    return 0;
}

int negate( int number) {
	int signValue = 0;
	int result = 0;
	signValue = (number > 0) ? -1 : 1;
	
	while (number != 0) {
		result += signValue;
		number += signValue;
	}

	return result;
}

int add(int a, int b)
{
	int result = a + b;
	return result;
}

int subtract(int a, int b)
{
	int result = a + negate(b);
	return result;
}

int multiply(int a, int b)
{
	bool bIsNeg = false;
	int absB = (b > 0) ? b : (bIsNeg = true, negate(b));
	int result = 0;
	for (int i = 0; i < b; i++) {
		result += a;
	}
	if (bIsNeg) {
		result = negate(result);
	}


	return result;
}

int divide(int a, int b)
{
	if (b == 0)
		throw(std::invalid_argument("dividend is 0"));
	int result = 0;
	bool aIsNeg = false;
	bool bIsNeg = false;
	int absA = (a > 0) ? a : (aIsNeg = true, negate(a));
	int absB = (b > 0) ? b : (bIsNeg = true, negate(b));

	while (absA >= absB) {
		absA += negate(absB);
		result++;
	}

	if (aIsNeg ^ bIsNeg) {
		result = negate(result);
	}

	return result;
}
