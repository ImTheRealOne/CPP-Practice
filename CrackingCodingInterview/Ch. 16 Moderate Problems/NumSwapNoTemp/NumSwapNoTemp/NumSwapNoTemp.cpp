// NumSwapNoTemp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

void numberSwapperXor(int &a, int &b);


int main()
{
	int a = 4;
	int b = 5;
	
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	
	numberSwapperXor(a, b);


	std::cout << "a : " << a <<std::endl;
	std::cout << "b : " << b << std::endl;


	system("pause");
    return 0;
}

void numberSwapperXor(int &a, int &b) {
	a = (unsigned short)a ^ (unsigned short)b;
	b = (unsigned short)b ^ (unsigned short)a;
	a = (unsigned short)a ^ (unsigned short)b;
	
}

