#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

void Character::moveTowardsOtherHero(Character* otherHero) {
	if (!moveXCoord(otherHero->getX()) && !moveYCoord(otherHero->getY())) {
		moveToRandomGrid();
	}

	changed();
	oldX = x;
	oldY = y;
	//notify mediator to update map
}

void Character::changed() {
	mediator->characterChanged(this);
}



bool Character::moveXCoord(const int otherX) {
	bool moved = false;
	oldX = x;
	if (otherX-x < 1) {
		x--;
		moved = true;
	}
	else if(otherX-x > 1)
	{
		x++;
		moved = true;
	}
	return moved;
}

bool Character::moveYCoord(const int otherY) {
	bool moved = false;
	oldY = y;
	if (otherY - y < 1) {
		if(y>ROWSIZE)
			y--;
		moved = true;
	}
	else if (otherY - y > 1)
	{
		if (y < ROWSIZE)
			y++;
		moved = true;
	}
	return moved;
}

void Character::moveToRandomGrid() {
	srand(time(NULL));
	oldX = x;
	oldY = y;
	x = rand() % ROWSIZE-1;
	y = rand() % ROWSIZE - 1;
}

int Character::getX() const {
	return x;
}

int Character::getY() const {
	return y;
}

int Character::getOldX() const {
	return oldX;
}

int Character::getOldY() const {
	return oldY;
}