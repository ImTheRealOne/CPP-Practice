#pragma once

#include "stdafx.h"
#include "Square.h"
#include "Ant.h"
#include <map>
extern int lowerBoundI;
extern int lowerBoundJ;
extern int upperBoundI;
extern int upperBoundJ;
extern int border;
class Grid
{
public:
	Grid();
	Grid(int gridHeight, int gridWidth);
	~Grid();

	void start() {
			ant->turn(grid.at(ant->getiPosition()).at(ant->getjPosition()).getColor());
			ant->moveForward();
			grid.at(ant->getiPosition()).at(ant->getjPosition()).flipColor();
	}

	void printGrid() {
		std::cout << "    ";
		for (int i = 0; i < grid.size(); i++) {
			std::cout << i + lowerBoundI - border/2 ;
			if(i < 10)
				std::cout << "  ";
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
		for (int i = 0; i < grid.size(); i++) {
			std::cout << i + lowerBoundJ - border / 2;
			if (i < 10) {
				 std::cout<< "   ";
			}
			else {
				std::cout  << "  ";
			}
			for (int j = 0; j < grid.at(i).size(); j++) {

				if (ant && i == ant->getiPosition() - lowerBoundI + border/2 && j == ant->getjPosition()-lowerBoundJ + border / 2) {
					ant->printAnt();
					std::cout << " ";
				}		
				else	{
					grid.at(i).at(j).printSquare();
					std::cout << " ";
				}
			}
			std::cout << std::endl;
		}
	}

	void createGrid(std::map<std::pair<int, int>, COLOR> movesMap , Ant &newAnt) {
		std::map<std::pair<int, int>, COLOR> ::iterator mapIt ;
		ant = &newAnt;
		for (int i = 0; i < border + upperBoundI - lowerBoundI; i++) {
			grid.emplace_back(std::vector<Square>());
			for (int j = 0; j < border + upperBoundJ - lowerBoundJ; j++) {
				grid.at(i).emplace_back(Square(i, j));
			}
		}
		printGrid();
		for (mapIt = movesMap.begin(); mapIt != movesMap.end(); mapIt++) {
			int y = mapIt->first.first-lowerBoundI + border / 2;
			int x = mapIt->first.second-lowerBoundJ + border / 2;
			grid.at(x).at(y).setColor(mapIt->second);
		}
		

	}

private:
	Ant * ant;
	std::vector<std::vector<Square>> grid;
};

