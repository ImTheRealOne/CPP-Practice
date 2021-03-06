// MediatorObserver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Character.h"
#include "Map.h"
#include "Mediator.h"

int main()
{
	
	Mediator* level = new Mediator();
	Character* heroA = new Character(0, 0, level);
	Character* heroB = new Character(ROWSIZE-1, COLSIZE-1, level);
	Map* map = new Map();
	
	map->initializeMap();
	map->printMap();
	level->createMediator(heroA, heroB, map);


	for (int i = 0; i < 10; i++) {
		heroA->moveTowardsOtherHero(heroB);
	}



	




	
	system("pause");
    return 0;
}

