// 16 - 22 Langton's Ant.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
static int lowerBoundI = 999;
static int lowerBoundJ = 999;
static int upperBoundI = -999;
static int upperBoundJ = -999;
static int border = 10;

std::string printColor(COLOR color);

void kMovesV1(Grid &grid, const int kMoves);

Ant createAnt();

void checkBounds(int i, int j);

std::map<std::pair<int, int>, COLOR> kMovesV2(Ant &ant, const int kMoves);
COLOR flipColor(COLOR color);

int main()
{
	srand(time(NULL));

	Grid grid(0,0);
	
	//kMoves(grid, 10);

	Ant ant = createAnt();

	std::map<std::pair<int, int>, COLOR> moves = kMovesV2(ant, 4);
	ant.printPosition();
	for (std::map<std::pair<int, int>, COLOR>::iterator it = moves.begin();
		it != moves.end(); it++) {
		std::cout << " i : " << it->first.first << " , " << it->first.second << " : "  << printColor(it->second) << std::endl;

	}

	std::cout << " lower i : " << lowerBoundI <<std::endl;
	std::cout << " lower j : " << lowerBoundJ << std::endl;
	std::cout << " upper i : " << upperBoundI << std::endl;
	std::cout << " upper i : " << upperBoundJ << std::endl;
	grid.createGrid(moves, ant);
	grid.printGrid();

	system("pause");
    return 0;
}

std::string printColor(COLOR color) {
	if (color == COLOR::BLACK) {
		return "black";
	}
	else
		return "white";
}

void kMovesV1(Grid &grid, const int kMoves) {
	grid.printGrid();
	std::cout << std::endl;
	for (int i = 0; i < kMoves; i++) {
		std::cout << " Move : " << i << std::endl;
		grid.start();
		grid.printGrid();
		std::cout << std::endl;
	}
}

Ant createAnt()
{
	int antX = rand() % 100;
	int antY = rand() % 100;
	Ant ant(antX, antY);
	checkBounds(antX, antY);
	return ant;
}

void checkBounds(int i, int j)
{
	if (i > upperBoundI) {
		upperBoundI = i;
	}
	if (i < lowerBoundI) {
		lowerBoundI = i;
	}
	if (j > upperBoundJ) {
		upperBoundJ= j;
	}
	if (j < lowerBoundJ) {
		lowerBoundJ = j;
	}
}

std::map<std::pair<int, int>, COLOR> kMovesV2(Ant &ant, const int kMoves)
{
	std::map<std::pair<int, int>, COLOR> moves;
	std::pair<int, int> intCoordXY(ant.getiPosition(), ant.getjPosition());
	COLOR color = COLOR(rand() % 2);
	moves.insert(std::make_pair(intCoordXY, color));
	for (int i = 0; i < kMoves; i++) {
		checkBounds(intCoordXY.first, intCoordXY.second);
		ant.turn(moves.at(intCoordXY));
		moves.at(intCoordXY) = flipColor(moves.at(intCoordXY));
		ant.moveForward();
		std::map<std::pair<int, int>, COLOR>::iterator mapIt;
		mapIt = moves.find(std::pair<int, int>(ant.getiPosition(), ant.getjPosition()));
		if (mapIt == moves.end()) {
			intCoordXY = std::pair<int, int>(ant.getiPosition(), ant.getjPosition());
			color = COLOR(rand() % 2);
			moves.insert(std::make_pair(intCoordXY, color));

		}
	}

	return moves;
}

COLOR flipColor(COLOR color) {
	return (color == COLOR::BLACK) ? COLOR::WHITE : COLOR::BLACK;
}