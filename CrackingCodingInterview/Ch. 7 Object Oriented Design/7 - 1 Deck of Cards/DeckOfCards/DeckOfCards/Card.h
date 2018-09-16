#pragma once
#include <iostream>
enum SUIT
{
	SPADES, HEARTS, CLOVER, DIAMOND
};
enum COLOR
{
	RED, BLACK
};
class Card
{
public:
	Card();
	Card(int newRank, SUIT newSuit, COLOR newColor) : rank(newRank), suit(newSuit), color(newColor) {};
	~Card(); 
	int getRank() const { return rank; }
	SUIT getSuit() const { return suit; }
	COLOR getColor() const { return color; }
	void printCard();
private:
	int rank;
	SUIT suit;
	COLOR color;
};

