#pragma once
#include "Card.h"
#include <vector>
#include <random>
#include <time.h>

class Deck
{
public:
	Deck();
	~Deck();
	SUIT defineSuit(int cardPosition);
	COLOR defineColor(int cardPosition);
	void printDeck();
	void shuffle();
	
private:
	std::vector<Card> * deck;
};

