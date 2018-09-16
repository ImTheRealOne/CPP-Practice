#pragma once


class Map
{
public:
	Map();
	~Map();

	void initializeMap();
	void clearSpot(const int i, const int j);
	void updateHero(const int i, const int j);
	void printMap();

private:
	char** arrayMap;


};

