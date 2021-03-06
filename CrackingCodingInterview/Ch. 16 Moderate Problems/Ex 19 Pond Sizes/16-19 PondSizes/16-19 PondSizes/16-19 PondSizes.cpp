// 16-19 PondSizes.cpp : Defines the entry point for the console application.
//

/*

Pond Sizes: You have an integer matrix representing a plot of land, where the value at that location
represents the height above sea level. A value of zero indicates water. A pond is a region of
water connected vertically, horizontally, or diagonally. The size of the pond is the total number of
connected water cells. Write a method to compute the sizes of all ponds in the matrix.
EXAMPLE
Input:
0 2 1 0
0 1 0 1
1 1 0 1
0 1 0 1
Output: 2, 4, 1 (in any order)

*/
					

#include "stdafx.h"
#include <iostream>
#include <vector>

const int landHeight = 4;
const int landWidth = 4;

std::vector<int> listOfPondSize(int land[landWidth][landHeight]);

int searchNeighborCells(const int i, const int j, int land[landWidth][landHeight]);

int main()
{

	std::vector<int> pondSizes;

	int land[4][4] = { {0,2,1,0},
						{0,1,0,1},
						{1,1,0,1},
						{0,1,0,1} };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << land[i][j];
		}
		std::cout << std::endl;
	}
	pondSizes = listOfPondSize(land);

	for (auto& walker : pondSizes) {
		std::cout << walker << " , ";
	}

	system("pause");
    return 0;
}

//iterate through all cells and calls searchNeighbor on the cell it's 
//returns a vector of sizes
std::vector<int> listOfPondSize(int land[landWidth][landHeight])
{
	std::vector<int> pondSizes;

	std::vector<int>::iterator walker;
	int pondSize = -1;
	for (int i = 0; i < landWidth; i++) {
		for (int j = 0; j < landHeight; j++) {
			if (land[i][j] == 0) {
				pondSize = -1;
				pondSize = searchNeighborCells(i, j, land);
				pondSizes.push_back(pondSize);
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << land[i][j];
		}
		std::cout << std::endl;
	}
	
	return pondSizes;
}


//recursively calls itself passing new row and col if they are 0
//recursively adds one everytime it finds a new 0
int searchNeighborCells(const int row, const int col,int land [landWidth][landHeight])
{
	int pondSize = 1;
	//puts a -1 at 0s to indicate the cell has been counted
	land[row][col] = -1;
	for (int i = row - 1; i <= row + 1; i++) {
		for (int j = col - 1; j < col + 1; j++) {
			if (i >= 0 && i < landWidth && j >= 0 && j < landHeight) {
				if (land[i][j] == 0) {
					pondSize += searchNeighborCells(i, j, land);
				}
			}
		}
	}
	return pondSize;
}
