#include "Main.h"
#include <iostream>


Main::Main()
{
}


Main::~Main()
{
}

void BruteForce(int(&matrix)[ROWSIZE][COLSIZE], int const&target);



int main() {
	int matrix[ROWSIZE][COLSIZE] = {	{1, 5, 8, 13, 16, 19, 21},
										{3, 6, 9, 11, 15, 18, 20},
										{4, 10, 12, 14, 17, 22, 26} ,
										{7, 25, 28, 29, 33, 39, 41} };

	//BruteForce(matrix,  39);
	naiveBinarySearch(matrix, 7);		
	system("pause");
	return 0;
}	

void BruteForce(int(&matrix)[ROWSIZE][COLSIZE], int const&target) {
	for (int i = 0; i < ROWSIZE; i++) {
		for (int j = 0; j < COLSIZE; j++) {
			if (matrix[i][j] == target) {
				std::cout << "i : " << i << "  j : " << j << " -> " << matrix[i][j];
			}
			else if(matrix[i][j] > target) {
				break;
			}
		}
	}

}


void naiveBinarySearch(int (&matrix) [ROWSIZE][COLSIZE], int const &target) {
	int i = ROWSIZE/2;
	int j = COLSIZE/2;
	int lowerBoundI = 0;
	int lowerBoundJ = 0;
	int upperBoundI = ROWSIZE - 1;
	int upperBoundJ = COLSIZE - 1;
	int num = NULL;
	bool searchingX = true;
	bool oldNum = NULL;

	do {
		oldNum = num;
		num = matrix[i][j];
		
		if (num == target) {
			std::cout << "target : " << matrix[i][j] << " found at : " << "i = " << i << " j = " << j  << std::endl;
			return;
		}
		if (num > target && searchingX == true) {
			upperBoundI = i-1;
		}
		else if (num < target && searchingX == true)
		{
			lowerBoundI = i+1;
		}

		if (num > target && !searchingX) {
			upperBoundJ = j-1;
		}
		else if (num < target && !searchingX) {
			lowerBoundJ = j+1;
		}
		searchingX = !searchingX;
		i = (lowerBoundI + upperBoundI) / 2;
		j = (lowerBoundJ + upperBoundJ) / 2;
	} while ((num != target) && oldNum != num);
	
	std::cout << "couldn't find";
}