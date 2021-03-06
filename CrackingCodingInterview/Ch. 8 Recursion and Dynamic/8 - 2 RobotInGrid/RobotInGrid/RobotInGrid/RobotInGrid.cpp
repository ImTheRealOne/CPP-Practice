// RobotInGrid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

const int ROW_SIZE = 4;
const int COL_SIZE = 4;

enum Cell_Status {
	OPEN, USED, BLOCK, FAILED

};

void mazeSolver(Cell_Status maze[ROW_SIZE][COL_SIZE], int i, int j);
void print(Cell_Status maze[ROW_SIZE][COL_SIZE]);

int main()
{
	Cell_Status maze1[ROW_SIZE][COL_SIZE] = { { USED, OPEN, BLOCK, OPEN },
												{ OPEN, OPEN, OPEN, OPEN },
												{ OPEN, OPEN, BLOCK, OPEN },
												{ OPEN, OPEN, OPEN, OPEN }, };
	Cell_Status maze2[ROW_SIZE][COL_SIZE] =  { { OPEN, OPEN, BLOCK, OPEN },
												{ OPEN, OPEN, BLOCK, OPEN },
												{ OPEN, OPEN, BLOCK, OPEN },
												{ OPEN, OPEN, BLOCK, OPEN }, };;

	print(maze1);
	std::cout << std::endl;

	mazeSolver(maze1, 0, 0);
	std::cout << std::endl;
	print(maze1);
	std::cout << std::endl;
	system("pause");
    return 0;
}

void mazeSolver(Cell_Status maze[ROW_SIZE][COL_SIZE], int i, int j)
{
	//check if you are at the exit
	if (i == ROW_SIZE - 1 && j == COL_SIZE - 1) {
		print(maze);
	}
	if (maze[i][j] == Cell_Status::FAILED) {
		return;
	}
	//check if right is available
	if (j + 1 < COL_SIZE && maze[i][j + 1] == Cell_Status::OPEN) {
		maze[i][j + 1] = Cell_Status::USED;
		mazeSolver(maze, i, j + 1);
		if (maze[i][j + 1] != Cell_Status::FAILED) {
			maze[i][j + 1] = Cell_Status::OPEN;
		}
	}
	if(i+1 < ROW_SIZE && maze[i+1][j] == Cell_Status::OPEN) {
		maze[i+1][j] = Cell_Status::USED;
		mazeSolver(maze, i+1, j);
		if (maze[i + 1][j] != Cell_Status::FAILED) {
			maze[i+1][j] = Cell_Status::OPEN;
		}
	}
		
	maze[i][j] = Cell_Status::FAILED;

	//check if down is available

}

void print(Cell_Status maze[ROW_SIZE][COL_SIZE]) {
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COL_SIZE; j++) {
			if (maze[i][j] == Cell_Status::OPEN) {
				std::cout << " " << "|";
			}
			else if(maze[i][j] == Cell_Status::USED) {
				std::cout << "X" << "|";
			}
			else if (maze[i][j] == Cell_Status::FAILED) {
				std::cout << "F" << "|";
			}
			else
			{
				std::cout << "B" << "|";
			}
			

		}
		std::cout << std::endl;
	}

}
