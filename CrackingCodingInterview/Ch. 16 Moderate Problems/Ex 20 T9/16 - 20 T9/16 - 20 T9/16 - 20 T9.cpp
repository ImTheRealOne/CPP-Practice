// 16 - 20 T9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

bool readDictionary(const std::string fileName, std::map<int, std::vector<std::string>>& wordToT9Map);
int wordToT9(const std::string word);

int main()
{
	std::map<int, std::vector<std::string>> wordToT9Map;
	bool canReadDictioary = readDictionary("Dictionary.txt", wordToT9Map);
	if (canReadDictioary) {
		std::cout << "read from dictionary successful" << std::endl;
	}
	else
	{
		std::cout << " read failed ";
	}
	std::cout << "dictionary " << std::endl;
	

	std::map<int, std::vector<std::string>>::iterator it;
	for (it = wordToT9Map.begin(); it != wordToT9Map.end(); it++) {
		std::cout << "key : " << it->first << " , values : ";
		for (auto &vectorIt : it->second) {
			std::cout << vectorIt << " , ";
		}
		
		std::cout << std::endl;
	}

	it = wordToT9Map.begin();
	it = wordToT9Map.find(8733);
	if (it != wordToT9Map.end()) {
		std::cout << "key : " << it->first << " , values : ";
		for (auto &vectorIt : it->second) {
			std::cout << vectorIt << " , ";
		}
	}


	system("pause");
    return 0;
}

bool readDictionary(const std::string fileName, std::map<int,  std::vector<std::string>>& wordToT9Map)
{
	std::fstream fileStream;
	std::string line = "";
	int t9 = 0;

	fileStream.open(fileName);
	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			t9 = wordToT9(line);
			//wordToT9 returns -1 if line is empty string
			if (t9 != -1) {
				//checks if key and value was properly inserted
				//returns a false in 2nd argument if key already existed
				std::pair<std::map<int, std::vector<std::string>>::iterator, bool> insertResult =
					wordToT9Map.insert(std::map<int, std::vector<std::string>>::value_type(t9, std::vector<std::string> {line}));
				if (!insertResult.second) {
					std::cout << " key already existed " << std::endl;
					wordToT9Map[t9].push_back(line);
				}
				else
				{
					std::cout << t9  << " key created value :  "<< line << std::endl;
				}

			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

int wordToT9(const std::string word)
{
	std::string result = "";

	if (word.empty()) {
		return -1;
	}
	for (int i = 0; i < word.length(); i++) {

		if (word.at(i) >= 'a' && word.at(i) <= 'c') {
			result += "2";
		}
		else if (word.at(i) >= 'd' && word.at(i) <= 'f') {
			result += "3";
		}
		else if (word.at(i) >= 'g' && word.at(i) <= 'i') {
			result += "4";
		}
		else if (word.at(i) >= 'j' && word.at(i) <= 'l') {
			result += "5";
		}
		else if (word.at(i) >= 'm' && word.at(i) <= 'o') {
			result += "6";
		}
		else if (word.at(i) >= 'q' && word.at(i) <= 's') {
			result += "7";
		}
		else if (word.at(i) >= 't' && word.at(i) <= 'v') {
			result += "8";
		}
		else if (word.at(i) >= 'w' && word.at(i) <= 'z') {
			result += "9";
		}


	}


	return std::stoi(result);
}
