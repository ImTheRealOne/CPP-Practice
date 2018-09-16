#include "Main.h"
#include <iostream>


Main::Main()
{
}


Main::~Main()
{
}

int maxSubArray(int a[], int size, int& begin, int& end);

int main() {

	int a [] = { -2,1,-3,4,-1,2,1,-5,4 };
	int begin = 0;
	int end = 0;

	std::cout<<"max : " << maxSubArray(a, sizeof(a) / sizeof(*a), begin, end) << std::endl;

	std::cout << "begin : " << begin << "     end : "<<end << std::endl;


	system("pause");
	return 0;
}

int maxSubArray(int a[],int size, int& begin, int& end) {
	if (size <= 0)
		return -99999;
	
	int max = 0;
	int runningSum = 0;

	for (int i = 0; i < size-1; i++) {

		runningSum = runningSum + a[i];
		if (a[i] > runningSum) {
			runningSum = a[i];
			begin = i;
		}

		if (runningSum > max) {
			max = runningSum;
			end = i;
		}
			
	}


	return max;
}