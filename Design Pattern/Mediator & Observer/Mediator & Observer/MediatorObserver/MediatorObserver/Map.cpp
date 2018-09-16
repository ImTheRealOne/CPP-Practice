#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	arrayMap = new char*[COLSIZE];
	for (int i = 0; i < ROWSIZE; i++) {
		arrayMap[i] = new char[ROWSIZE];
	}

}


Map::~Map()
{
}

void Map::initializeMap() {
	for (int i = 0; i < ROWSIZE; i++) {
		for (int j = 0; j < COLSIZE; j++) {
			arrayMap[i][j] = ' ';
		}
	}
}

void Map::clearSpot(const int i, const int j) {
	arrayMap[i][j] = ' ';
}

void Map::updateHero(const int i, const int j) {
	arrayMap[i][j] = 'X';
}

void Map::printMap() {
	for (int i = 0; i < ROWSIZE; i++) {
		for (int j = 0; j < COLSIZE; j++) {
			std::cout << arrayMap[i][j] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}