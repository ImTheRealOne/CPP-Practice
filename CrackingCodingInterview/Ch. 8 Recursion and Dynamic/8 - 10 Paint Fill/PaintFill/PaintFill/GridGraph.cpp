#include "stdafx.h"
#include "GridGraph.h"


GridGraph::GridGraph(COLOR grid[][], int rowSize, int colSize)
{
	this->gridPtr = grid;
	this->rowSize = rowSize;
	this->colSize = colSize;
}


GridGraph::~GridGraph()
{
}

void GridGraph::initGraph() {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			GridNodeStruct * node = new GridNodeStruct(i, j, gridPtr[i][j]);
			
		}
	}

}

void GridGraph::initNeighbors() {
	for (int i = 0; i < nodes.size(); i++) {
		for (int j = 0; j < nodes.at(i).size(); j++) {
			addNeighbors(nodes.at(i).at(j));
		}
	}
}

void GridGraph::addNeighbors(GridNodeStruct &node){
	if (node.x - 1 >= 0) {
		GridNodeStruct * tempPtr = &nodes.at(node.x -1).at(node.y);
		node.neighbors.push_back(tempPtr);
	}
	if (node.x + 1 < rowSize) {
		GridNodeStruct * tempPtr = &nodes.at(node.x + 1).at(node.y);
		node.neighbors.push_back(tempPtr);
	}
	if (node.y - 1 >= 0) {
		GridNodeStruct * tempPtr = &nodes.at(node.x).at(node.y-1);
		node.neighbors.push_back(tempPtr);
	}
	if (node.y + 1 < colSize) {
		GridNodeStruct * tempPtr = &nodes.at(node.x).at(node.y+1);
		node.neighbors.push_back(tempPtr);
	}

}