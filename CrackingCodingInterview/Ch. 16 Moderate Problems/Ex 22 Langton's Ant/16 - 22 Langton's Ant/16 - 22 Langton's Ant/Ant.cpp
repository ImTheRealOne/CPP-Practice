#include "stdafx.h"
#include "Ant.h"


Ant::Ant(int newI, int newJ)
{
	i = newI;
	j = newJ;
	direction = DIRECTION::RIGHT;
}


Ant::~Ant()
{
}

void Ant::turn(COLOR color)
{
	if (color == COLOR::BLACK) {
		direction = (direction - 1) < 0? DIRECTION(3) : DIRECTION(direction - 1);
	}
	else
	{
		direction = DIRECTION((direction + 1) % 4);		
	}
	std::cout << " landed on " << ((color == COLOR::BLACK) ? "Black " : "white ");
	std::cout<< std::endl;
	std::cout << " now facing  : "; 
	printDirection();
}

void Ant::moveForward()
{
	if (direction == DIRECTION::RIGHT) {
		j += 1;
	}
	else if (direction == DIRECTION::DOWN) {
		i += 1;
	}
	else if (direction == DIRECTION::LEFT) {
		j -= 1;
	}
	else if (direction == DIRECTION::UP) {
		i -= 1;
	}
}

void Ant::testTurn() {
	COLOR color;
	std::cout << " test TURNING " << std::endl;
	std::cout << " all black " << std::endl;
	for (int i = 0; i < 9; i++) {
		printDirection();
		turn(COLOR::BLACK);
	}
	printDirection();
	std::cout << " all white " << std::endl;
	for (int i = 0; i < 9; i++) {
		printDirection();
		turn(COLOR::WHITE);
	}


}

void Ant::testMoveForward() {
	printPosition();
	for (int i = 0; i < 10; i++) {
		moveForward();
		turn(COLOR::BLACK);
		printPosition();
	}
	for (int i = 0; i < 10; i++) {
		moveForward();
		turn(COLOR::WHITE);
		printPosition();
	}

}

void Ant::printDirection() {
	switch (direction) {
	case DIRECTION::RIGHT:
		std::cout << " right ";
		break;
	case DIRECTION::DOWN:
		std::cout << " down ";
		break;
	case DIRECTION::LEFT:
		std::cout << " left ";
		break;
	case DIRECTION::UP:
		std::cout << " UP ";
		break;
	default:
		break;
	}
	std::cout << std::endl;
}

void Ant::printPosition() {
	
	std::cout << "ant - " << " i : " << i << "  j : " << j << "  ";
	printDirection();
}
