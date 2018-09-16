#pragma once

#include "stdafx.h"

enum COLOR
{
	WHITE, BLACK, BLANK


};
enum DIRECTION
{
	RIGHT, DOWN, LEFT, UP
};
class Square
{
public:
	Square();
	Square(int newI, int newJ);
	~Square();
	int getI() {
		return i;
	}
	int getJ() {
		return j;
	}
	COLOR getColor() {
		return color;
	}
	void setColor(COLOR newColor) {
		color = newColor;
	}
	void flipColor();
	void testFlip() {
		for (int i = 0; i < 10; i++) {
			printSquareInfo();
			this->flipColor();
		}
	}
	void printSquareInfo() {
		std::cout << " i : " << i << " j : " << j;
		printColor();
		std::cout << std::endl;
	}
	void printColor() {
		if (color == COLOR::BLACK) {
			std::cout << " BLACK ";
		}
		else
		{
			std::cout << " WHITE ";
		}
	}
	void printSquare() {
		std::cout << "[";
		if (color == COLOR::BLACK) {
			std::cout << "B";
		}
		else if (color == COLOR::WHITE) {
			std::cout << "W";
		}
		else
		{
			std::cout << "k";
		}
		std::cout << "]";
	}
private:
	
	COLOR color;
	int i;
	int j;
};

