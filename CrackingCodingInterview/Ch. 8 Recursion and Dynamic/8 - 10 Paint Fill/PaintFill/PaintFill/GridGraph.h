#pragma once
#include <vector>


enum COLOR
{
	RED, BLUE, BLACK, WHITE
};
struct GridNodeStruct
{
	int x;
	int y;
	COLOR color;
	std::vector<GridNodeStruct*> neighbors;

	GridNodeStruct(int newX, int newY, COLOR newColor) {
		this->x = newX;
		this->y = newY;
		this->color = newColor;

	};
};

class GridGraph
{
	std::vector<std::vector<GridNodeStruct>> nodes;
	COLOR ** gridPtr;
	int rowSize;
	int colSize;
public:
	GridGraph(COLOR * grid, int rowSize, int colSize);
	~GridGraph();
	void setGrid(COLOR** grid, int rowSize, int colSize);
	void initGraph();
	void initNeighbors();
	void addNeighbors(GridNodeStruct &node);
};

