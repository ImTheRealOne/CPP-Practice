#pragma once
#include <random>
#include <time.h>
#include "Mediator.h"
class Character
{
public:
	Character();
	Character(int newX, int newY, Mediator* newMediator) :
		x(newX), y(newY), mediator(newMediator),
		oldX(newX), oldY(newY) {};
	~Character();

	void moveTowardsOtherHero(Character* otherHero);
	bool moveXCoord(const int otherX);
	bool moveYCoord(const int otherY);
	void moveToRandomGrid();
	virtual void changed();

	int getX() const;
	int getY() const;
	int getOldX() const;
	int getOldY() const;
private:
	int x;
	int y;
	int oldX;
	int oldY;
	Mediator* mediator;
};

