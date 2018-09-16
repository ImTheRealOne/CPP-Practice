#pragma once
#include "MediatorAbstract.h"
#include "Character.h"
#include "Map.h"

class Mediator : public MediatorAbstract
{
public:
	Mediator();
	~Mediator();
	
	virtual void createMediator(Character* newHeroA, Character* newHeroB, Map* newMap);

	virtual void mapChanged(Map* map);
	virtual void characterChanged(Character* hero);
	virtual void update();

private:
	Character* heroA;
	Character* heroB;
	Map* map;
};

