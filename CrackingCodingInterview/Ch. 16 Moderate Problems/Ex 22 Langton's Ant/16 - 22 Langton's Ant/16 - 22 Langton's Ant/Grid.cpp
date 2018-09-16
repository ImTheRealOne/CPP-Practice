#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
{
}


Grid::Grid(int gridHeight, int gridWidth)
{
	ant = new Ant(10, 10);

	if (gridHeight > grid.size()) {
		for (int i = grid.size(); i < gridHeight; i++) {
			grid.emplace_back(std::vector<Square>());
			if (gridWidth > grid.at(i).size()) {
				for (int j = grid.at(i).size(); j < gridWidth; j++) {
					grid.at(i).emplace_back(Square(i, j));
				}
			}
		}
	}
}

Grid::~Grid()
{
	
}
