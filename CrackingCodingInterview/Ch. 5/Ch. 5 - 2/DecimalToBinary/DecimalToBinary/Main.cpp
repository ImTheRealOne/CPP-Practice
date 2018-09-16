#include "Main.h"
#include <iostream>
#include <string>

Main::Main()
{
}


Main::~Main()
{
}

std::string decToBin(double num);

int longestSeriesOfOne(double num);

void printNextSmallestBiggest(int num);

int main() {

	double a = .72f;
	double b = 0;
	std::cout<<longestSeriesOfOne(b)<<std::endl;
	std::cout << decToBin(a);


	system("pause");
	return 0;
}

void printNextSmallestBiggest(int num) {


}

int longestSeriesOfOne(double num) {
	int oneBeforeFirstZero = 0;
	int oneAftereFirstZero = 0;
	bool zeroFlag = false;
	int length = 0;

	std::string numString = std::to_string(num);
	numString = numString.substr(0, numString.find("."));

	for (std::string::iterator it = numString.begin(); it != numString.end(); it++) {
		if (*it == '1') {
			if (!zeroFlag) {
				oneBeforeFirstZero++;
			}
			else
			{
				oneAftereFirstZero++;
			}
		}
		if (*it == '0') {
			if (!zeroFlag) {
				zeroFlag = true;
				oneBeforeFirstZero++;
			}
			else
			{
				if ((oneAftereFirstZero + oneBeforeFirstZero) > length)
					length = oneAftereFirstZero + oneBeforeFirstZero ;
				oneBeforeFirstZero = oneAftereFirstZero;
				oneAftereFirstZero = 0;
			}
		}


	}
	if (length < oneBeforeFirstZero)
		length = oneBeforeFirstZero;

	return length;
}

std::string decToBin(double num) {
	std::string result = "";
	int tempNum = 0;
	double tempDouble = num;

	while(result.length() < 32) {
		tempNum = tempDouble * 10;
		tempDouble *= 10;
		tempDouble -= tempNum;

		std::string tempResult = "";
		while (tempNum != 1 && tempNum  != 0) {
			if (tempNum % 2 == 1) {
				tempResult += '1';
			}
			else
			{
				tempResult += '0';
			}
			tempNum /= 2;
		}
		tempResult += std::to_string(tempNum);
		while (tempResult.length() < 4) {
			tempResult.insert(0, "0");
		}
		tempResult += "";
		result += tempResult;

		tempNum /= 10;

	}

	 

	return result;

}