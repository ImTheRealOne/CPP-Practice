#pragma once

#include "stdafx.h"

class Ant
{
public:
	Ant(int newI, int newJ);
	~Ant();
	
	void turn(COLOR color);
	void moveForward();

	int getiPosition() {
		return i;
	}
	int getjPosition() {
		return j;
	}

	void printAnt() {
		std::cout << "[*]";
	}
	void printDirection();
	void printPosition();
	
	void testTurn();
	void testMoveForward();
private:
	int i;
	int j;
	DIRECTION direction;
};

