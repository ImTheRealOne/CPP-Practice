#include "stdafx.h"
#include "Mediator.h"


Mediator::Mediator()
{
}


Mediator::~Mediator()
{
}

void Mediator::createMediator(Character* newHeroA, Character* newHeroB, Map* newMap) {
	heroA = newHeroA;
	heroB = newHeroB;
	map = newMap;
	map->updateHero(heroA->getX(), heroA->getY());
	map->updateHero(heroB->getX(), heroB->getY());
}

void Mediator::characterChanged(Character* hero) {
	map->clearSpot(hero->getOldX(), hero->getOldY());
	map->updateHero(hero->getX(), hero->getY());
	map->printMap();
}

void Mediator::mapChanged(Map* map) {

}

void Mediator::update() {

}

void createLevel() {


}