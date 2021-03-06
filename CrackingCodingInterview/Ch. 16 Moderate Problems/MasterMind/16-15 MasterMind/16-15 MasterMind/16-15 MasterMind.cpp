// 16-15 MasterMind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

enum GridColor
{
	RED,YELLOW,GREEN,BLUE
};

std::pair<int, int> masterMind(std::vector<GridColor> guess, std::vector<GridColor> solution);

int main()
{
	std::vector<GridColor> guess{ RED, GREEN, RED, GREEN };
	std::vector<GridColor> solution{ YELLOW, GREEN, BLUE, RED };

	masterMind(guess, solution);


	system("pause");
    return 0;
}

std::pair<int, int> masterMind(std::vector<GridColor> guess, std::vector<GridColor> solution) {
	int hit = 0;
	int pseudoHit = 0;
	// 0 = red, 1 = yellow, 2 = green, 3 = blue
	int solutionSet[4] = { 0,0,0,0 };
	int guessSet[4] = { 0,0,0,0 };

	for (int i = 0; i < guess.size(); i++) {
		if (solution.at(i) == guess.at(i)) {
			hit++;
		}
		else
		{
			int temp = guess.at(i);
			solutionSet[solution.at(i)] +=  1;
			guessSet[guess.at(i)] += 1;

		}
	}

	for (int i = 0; i < 4; i++) {
		while (solutionSet[i] > 0 && guessSet[i] > 0) {
			pseudoHit++;
			solutionSet[i] -= 1;
			guessSet[i] -= 1;
		}
	}

	return std::pair<int, int>(hit, pseudoHit);
}