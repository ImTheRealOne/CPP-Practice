// DeckOfCards.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Deck.h"

int main()
{
	Deck deckOfCards;

	deckOfCards.printDeck();
	std::cout << std::endl;
	deckOfCards.shuffle();
	deckOfCards.printDeck();


	system("pause");
    return 0;

}

