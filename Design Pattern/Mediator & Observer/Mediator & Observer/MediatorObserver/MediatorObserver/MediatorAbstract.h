#pragma once

class Map;
class Character;
class MediatorAbstract
{
public:
	virtual ~MediatorAbstract();

	virtual void update();
	virtual void mapChanged(Map* map) = 0;
	virtual void characterChanged(Character* hero) = 0;

protected:
	MediatorAbstract();

};

