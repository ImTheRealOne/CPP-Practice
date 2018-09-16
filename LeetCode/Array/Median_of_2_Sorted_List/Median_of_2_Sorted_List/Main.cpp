#include "Main.h"
#include <iostream>


Main::Main()
{
}


Main::~Main()
{
}

float medianOfTwoSortedList(int array1 [],int , int array2 [], int);

int main() {

	int array1[01];
	int array2[] = { 1 };

	int array3[] = { 1 };
	int array4[] = { 1,2,3 };


	std::cout << "Median : " << medianOfTwoSortedList(array1, (sizeof(array1))/sizeof(*array1), array2, (sizeof(array2)) / sizeof(*array2)) <<std::endl;
	std::cout << "Median : " << medianOfTwoSortedList(array3,1, array4,3) << std::endl;
	
	system("pause");
	return 0;
}

float medianOfTwoSortedList(int array1[],int one, int array2[], int two) {
	int size1 = one;//(sizeof(array1) / sizeof(*array1));
	int size2 = two;// (sizeof(array2) / sizeof(*array2));
	int size3 = size1 + size2;
	float currNum = 0;
	for (int pos = 0,i = 0, j = 0; pos <= size3; pos++) {
		//check if we reached middle of 2 arrays
		if (pos == (size3+1) / 2) {
			//odd
			if (size3 % 2 == 1) {
				return currNum;
			}
			//even
			else
			{
				if (i < size1  && j < size2 ) {
					currNum += (array1[i] < array2[j]) ? array1[i] : array2[j];
				}
				else if (j >= size2) {
					currNum += array1[i ];
					return currNum / 2;
				}
				else {
					currNum += array2[j ];
					return currNum / 2;
				}
			}

		}
		//increment walkers
		if (i < size1 && j < size2) {
			if (array1[i] < array2[j]) {
				currNum = array1[i];
				i++;
			}
			else {
				currNum = array2[j];
				j++;
			}
		}
		else {
			if (i > size1 ) {
			
				currNum = array2[j];
				j++;
			}
			else {
				currNum = array1[i];
				i++;
			}
		}

	}

	return currNum;
}