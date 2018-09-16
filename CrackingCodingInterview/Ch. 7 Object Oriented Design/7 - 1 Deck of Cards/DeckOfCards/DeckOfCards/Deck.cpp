#include "stdafx.h"
#include "deck.h"


Deck::Deck()
{
	deck = new std::vector<Card>();
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; j++) {
			SUIT cardSuit = defineSuit(i);
			COLOR cardColor = defineColor(i);
			if (i > 10)
				deck->push_back(Card(10, cardSuit, cardColor));
			else
			{
			deck->push_back(Card(j, cardSuit, cardColor));

			}
		}
	}
}


Deck::~Deck()
{
	delete deck;
}

SUIT Deck::defineSuit(int cardPositoin) {
	
	int suitNum = cardPositoin % 4;

	switch ( suitNum)
	{
	case 0:
		return SUIT::SPADES;
		break;
	case 1:
		return SUIT::HEARTS;
		break;
	case 2:
		return SUIT::CLOVER;
		break;
	case 3:
		return SUIT::DIAMOND;
		break;
	default:
		break;
	}
}

COLOR Deck::defineColor(int cardPosition) {
	if (cardPosition % 2 == 0) {
		return COLOR::BLACK;
	}
	else
	{
		return COLOR::RED;
	}
}

void Deck::printDeck() {
	for (int i = 0; i < deck->size(); i++) {
		deck->at(i).printCard();
	}
}

void Deck::shuffle() {
	srand(time(NULL));
	std::vector<Card> * shuffledDeck = new std::vector<Card>();
	while (deck->size() > 0) {
		int cardIndex = rand() % deck->size();
		shuffledDeck->push_back(deck->at(cardIndex));
		deck->erase(deck->begin() + cardIndex, deck->begin() + cardIndex+ 1);
	}

	delete deck;
	deck = shuffledDeck;
}