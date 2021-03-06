// WordCount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

const std::string FILENAME = "C:\\Users\\ImTheRealOne\\Desktop\\C++ Practice\\CrackingCodingInterview\\Ch. 16 Moderate Problems\\Word Count\\WordCount\\test.txt";



int main()
{
	std::ifstream inFile;

	try {
		inFile.open(FILENAME);
	}
	catch (std::ifstream::failure e) {
		std::cout << " faled to open" << std::endl;

	}

	std::string word;
	char c = ' ';
	std::map<std::string, int> wordCounter;


	if (inFile.is_open()) {
		while (inFile.get(c)) {
			if (c == ' ') {
				std::cout << std::endl << "space found" << std::endl;
				if (wordCounter.count(word) == 0) {
					std::cout << "word not found" << std::endl;
					wordCounter.insert(std::pair<std::string, int>(word, 1));
				}
				else
				{
					wordCounter.at(word) = wordCounter.at(word) + 1;
					std::cout << "word found : " << wordCounter.at(word) << std::endl;
				}

				word = "";
			}
			else
			{
				std::cout << c;
				word += c;
			}
		}
	}
	else
	{
		std::cout << "file open failed" << std::endl;
	}
	
	
	if (!word.empty()) {
		wordCounter.insert(
			std::pair<std::string, int>(word, 1));
	}


	for (auto& x : wordCounter) {
		std::cout << x.first << " : " << x.second << std::endl;
	}

	inFile.close();
	system("pause");

    return 0;
}

