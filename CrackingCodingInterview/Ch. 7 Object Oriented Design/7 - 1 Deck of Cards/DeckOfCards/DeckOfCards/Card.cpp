#include "stdafx.h"
#include "Card.h"


Card::Card()
{
}


Card::~Card()
{
}

void Card::printCard() {
	int cardRank = rank % 14;

	switch (cardRank)
	{
	case 1:
		std::cout << "A ";	
		break;
	case 11:
		std::cout << "J ";
		break;
	case 12:
		std::cout << "Q ";
		break;
	case 13:
		std::cout << "K ";
		break;
	default:
		std::cout << cardRank << " ";
		break;
	}
	const char *s;
	switch (suit)
	{
	case SUIT::SPADES:
		//std::cout << "Spades " ;
		std::cout << "\u2660" ;
		break;
	case SUIT::HEARTS:
		//std::cout << "Hearts ";
		std::cout << "\u2665";
		break;
	case SUIT::CLOVER:
		//std::cout << "Clover ";
		std::cout << "\u2663";
		break;
	case SUIT::DIAMOND:
		//std::cout << "Diamond ";
		std::cout << "\u2666";
		break;
	default:
		break;
	}

	switch (color)
	{
	case COLOR::BLACK:
		std::cout << "Black ";
		break;
	case COLOR::RED:
		std::cout << "Red ";
		break;
	default:
		break;
	}

	std::cout << std::endl;
}