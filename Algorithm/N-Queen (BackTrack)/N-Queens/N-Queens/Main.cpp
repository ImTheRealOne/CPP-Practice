#include "Main.h"
#include <iostream>
#include <vector>
#include <algorithm>

const int BOARD_SIZE = 4;

enum Board_Pieces
{
	QUEEN, EMPTY, INVALID
};

Main::Main()
{
}


Main::~Main()
{
}

void print(std::vector<std::vector<Board_Pieces>> board );
void nQueensHelper(std::vector<std::vector<Board_Pieces>> board);
void nQueensSolver(std::vector<std::vector<Board_Pieces>> board, int i, int j, int queenPieces);
std::vector<std::vector<Board_Pieces>> invalidateSpaces(std::vector<std::vector<Board_Pieces>>  board, int i, int j);
int main() {

	std::vector<std::vector<Board_Pieces>> board(BOARD_SIZE, std::vector<Board_Pieces>(BOARD_SIZE, Board_Pieces::EMPTY));
	
	
	nQueensHelper(board);
	


	system("pause");
	return 0;
}



void print(std::vector<std::vector<Board_Pieces>> board) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == Board_Pieces::EMPTY)
				std::cout << "  , ";
			else if (board[i][j] == Board_Pieces::QUEEN)
				std::cout << " Q, ";
			else if (board[i][j] == Board_Pieces::INVALID)
				std::cout << " X, ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl; std::cout << std::endl;
}

std::vector<std::vector<Board_Pieces>> invalidateSpaces(std::vector<std::vector<Board_Pieces>>  board, int x, int y)
{
	std::cout << "before" << std::endl;
	//print(board);
	if (board[x][y] == Board_Pieces::EMPTY) {
		board[x][y] = Board_Pieces::QUEEN;

	}

		
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[i][y] != Board_Pieces::QUEEN)
			board[i][y] = Board_Pieces::INVALID;
	}
	for (int j = 0; j < BOARD_SIZE; j++) {
		if (board[x][j] != Board_Pieces::QUEEN)
			board[x][j] = Board_Pieces::INVALID;
	}
	int smaller = (x < y) ? x : y;
	int j = y - smaller;
	int i = x - smaller;
	while(i < (BOARD_SIZE) && j < (BOARD_SIZE) && i>= 0 && j >= 0) {
		if (board[i][j] != Board_Pieces::QUEEN) {
			board[i][j] = Board_Pieces::INVALID;
		}
		i++;
		j++;
	}
	 i = x;
	 j = y;
	while (i < BOARD_SIZE && j < BOARD_SIZE && i>= 0 && j >= 0) {
		if (board[i][j] != Board_Pieces::QUEEN) {
			board[i][j] = Board_Pieces::INVALID;
		}
		i++;
		j--;
	}
	 i = x;
	 j = y;
	while (i < BOARD_SIZE && j < BOARD_SIZE && i >= 0 && j >= 0) {
		if (board[i][j] != Board_Pieces::QUEEN) {
			board[i][j] = Board_Pieces::INVALID;
		}
		i--;
		j++;
	}
	std::cout << "after" << std::endl;
	//print(board);
	return board;
	
}

void nQueensHelper(std::vector<std::vector<Board_Pieces>> board) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			nQueensSolver(board, i, j, 0);
		}
	}
}

void nQueensSolver(std::vector<std::vector<Board_Pieces>> board, int x, int y, int queenPieces) {
	if (queenPieces >= 4)
		std::cout << std::endl << "queen pcs : " << queenPieces << std::endl;

	
	for (int i = x; i < BOARD_SIZE; i++) {
		for (int j = y; j < BOARD_SIZE; j++) {
			
			if (board[i][j] == Board_Pieces::EMPTY) {
				std::cout << std::endl << " i : " << i << "  j : " << j << std::endl;
			//	print(board);
				std::cout << std::endl << std::endl;
				nQueensSolver(invalidateSpaces(board, i, j) , i , j+1 , queenPieces+1);
				
			} 
		
			
		}
		y = 0;
	}
	queenPieces--;
}

