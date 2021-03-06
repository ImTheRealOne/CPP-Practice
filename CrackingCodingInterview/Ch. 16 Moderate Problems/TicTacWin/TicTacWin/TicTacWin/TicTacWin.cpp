// TicTacWin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <regex>
#include <iostream>

std::regex	 winningOset [] = { std::regex(".O..O..O."),
								std::regex("O..O..O.."),
								std::regex("..O..O..O"),
								std::regex("OOO......"),
								std::regex("...OOO..."),
								std::regex("......OOO"),
								std::regex("O...O...O"),
								std::regex("..O.O.O..") };

std::regex winningXset [] = { std::regex(".X..X..X."),
							std::regex("X..X..X.."),
							std::regex("..X..X..X"),
							std::regex("XXX......"),
							std::regex("...XXX..."),
							std::regex("......XXX"),
							std::regex("X...X...X"),
							std::regex("..X.X.X..") };



int main()
{
	std::string playBoard = {"OOOXXOOXX"};

	for (auto& walkerRegEx : winningOset) {
		if (std::regex_match(playBoard, walkerRegEx)) {
			std::cout << "O wins" << std::endl;
		}
	}
	
	for (auto& walkerRegEx : winningXset) {
		if (std::regex_match(playBoard, walkerRegEx)) {
			std::cout << "X wins" << std::endl;
		}
	}
	system("pause");

    return 0;
}

