// PaintFill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <time.h>  
#include <vector>


const int ROWSIZE = 4;
const int COLSIZE = 4;




void initGrid(COLOR  Grid[ROWSIZE][COLSIZE]);
void printGrid(COLOR Grid[ROWSIZE][COLSIZE]);



int main()
{
	COLOR grid[ROWSIZE][COLSIZE];
	initGrid(grid);
	printGrid(grid);
	
	COLOR (*gridPtr)[COLSIZE] = grid;
	GridGraph gridGraph(gridPtr, ROWSIZE, COLSIZE);

	system("pause");
    return 0;
}

void initGrid(COLOR Grid[ROWSIZE][COLSIZE]) {
	srand(time(NULL));
	
	for (int i = 0; i < ROWSIZE; i++) {
		for (int j = 0; j < COLSIZE; j++) {
			int r = rand() % 4;
			Grid[i][j] = (COLOR) r;
		}
	}
}

void printGrid(COLOR Grid[ROWSIZE][COLSIZE]) {
	std::cout << std::endl;
	for (int i = 0; i < ROWSIZE; i++) {
		for (int j = 0; j < COLSIZE; j++) {
			
			std::cout << (int)Grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}