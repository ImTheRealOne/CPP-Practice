#include "Main.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <algorithm>

Main::Main()
{
}


Main::~Main()
{
}

const std::string fileName = "unsortedStringFile.txt";
const std::string sortedFileName = "sortedStringFile.txt";
void createAlphaBins();
void genUnsortedStringFile();
std::string genRandomWord();
void genUnsortedBins();
void saveToUnsortedBin(std::vector<std::string> stringVector, int file);
void sortBins();
void writeToFile(std::ofstream &ostream, std::ofstream::openmode mode, std::string errorMsg);
void combineSortedBins();

int main() {
	createAlphaBins();
	genUnsortedStringFile();
	genUnsortedBins();
	sortBins();
	combineSortedBins();

	system("pause");
	return 0;

}

void combineSortedBins() {
	std::ofstream sortedFileStream;
	sortedFileStream.open(sortedFileName);

	std::ifstream sortedBinStream;


	char alpha = 'a';
	std::string binFileName = "";
	std::string word;
	do {
		binFileName = "";
		binFileName += alpha;
		binFileName += ".txt";

		sortedBinStream.open(binFileName);
		while (std::getline(sortedBinStream, word)) {
			sortedFileStream << (word + "\n");
		}
		sortedBinStream.close();
		alpha++;
	} while (alpha <= 'z');
	sortedFileStream.close();
}

void createAlphaBins() {
	char alpha = 'a';
	std::string binFileName = "";
	std::ofstream ostream;
	do {
		binFileName = "";
		binFileName += alpha;
		binFileName += ".txt";

		ostream.open(binFileName, std::ofstream::trunc);
		ostream.close();
		alpha++;
	} while (alpha <= 'z');


}

void writeToFile(std::ofstream &ostream, std::ofstream::openmode mode, std::string errorMsg) {
	try {
		ostream.open(fileName, mode);
	}
	catch (std::ofstream::failure &writeErr) {
		std::cout << errorMsg << std::endl;
		return;
	
	}

}
/*
	functionName : genUnsortedStringFile
	purpose : generate a random unsorted string file

*/
void genUnsortedStringFile() {
	std::string s;
	std::ofstream textFile;
	try {
		textFile.open(fileName);
	}
	catch (std::ofstream::failure &writeErr) {
		std::cout << "Error opening file 'unsortedStringFile.txt' from genUnsortedStringFile" << std::endl;
		return;
	}
	for (int i = 0; i < 10000; i++) {
		if (textFile.is_open()) {
			s = genRandomWord();	
			textFile << (s + "\n");

		}

	}

	textFile.close();
}

/*
	functionName : genRandomWord
	purpose : generate a random word

*/

std::string genRandomWord() {
	int stringLen = rand() % 10;
	int letter;
	std::string s = "";
	for (int i = 0; i < stringLen; i++) {
		
		letter = (rand() % 26 + 97);
		//std::cout << "letter : " << letter << "   -   " << static_cast<char>(letter) << std::endl;
		s += (static_cast<char>(letter));
	}
	//std::cout << s << std::endl;
	return s;
}

/*



*/
void genUnsortedBins() {
	std::ifstream fileStream;
	try {
		fileStream.open(fileName);
	}
	catch (std::ifstream::failure &readERR) {
		std::cout << "Error opening file 'unsortedStringFile.txt' from genUnsortedBins" << std::endl;
		return;
	}

	std::vector<std::vector<std::string>> stringVectors(26);
	/*for (int i = 0; i < 25; i++) {
		std::vector<std::string> newvector;
		stringvectors.push_back(newvector);
	}*/
	std::string word = "";
	if (fileStream) {
		while (std::getline(fileStream, word)) {
			if (!word.empty()) {
				int a = static_cast<int>(word.at(0));
				stringVectors.at(static_cast<int>(word.at(0))-97).emplace_back(word);
				if (stringVectors.at(static_cast<int>(word.at(0)) - 97).size() >= 50) {
					saveToUnsortedBin(stringVectors.at(static_cast<int>(word.at(0)) - 97), static_cast<int>(word.at(0)));
					stringVectors.at(static_cast<int>(word.at(0)) - 97).clear();
				}
			}
		}
	}
	int file = 97;
	for (std::vector<std::vector<std::string>>::iterator it = stringVectors.begin(); it != stringVectors.end(); ++it) {
		saveToUnsortedBin(*it, file);
		file++;
	}
}

void saveToUnsortedBin(std::vector<std::string> stringVector, int file) {
	char c = static_cast<char>(file);
	std::string binFileName = "";
	binFileName += c;
	binFileName += ".txt";
	std::ofstream fileStream;
	try {
		fileStream.open(binFileName, std::ofstream::out | std::ofstream::app);
	}
	catch (std::ofstream::failure &writeErr) {
		std::cout << "Error opening file 'binFileName.txt' from saveToUnsortedBin" << std::endl;
		return;
	}
	if (fileStream) {
		for (std::vector<std::string>::iterator it = stringVector.begin(); it != stringVector.end(); ++it) {
			fileStream << (*it + "\n");
		}
	}
	fileStream.close();	
}

void sortBins() {
	std::ifstream ifStream;
	std::ofstream ofstream;
	char alpha = 'a';
	std::string word;
	std::string binFileName = "";
	std::vector<std::string> stringVector;
	do {
		binFileName = "";
		binFileName += alpha;
		binFileName += ".txt";
		try {
			ifStream.open(binFileName);
		}
		catch (std::ifstream::failure &readERR) {
			std::cout << "Error opening file 'binFileName.txt' from sortBins" << std::endl;
			return;
		}
		if (ifStream) {
			while (std::getline(ifStream, word)) {
				stringVector.emplace_back(word);

			}
			ifStream.close();
			ofstream.open(binFileName);
			std::sort(stringVector.begin(), stringVector.end());
			for (std::vector<std::string>::iterator it = stringVector.begin(); it != stringVector.end(); ++it) {
				ofstream << (*it + "\n");
			}
			ofstream.close();
			stringVector.clear();
		}

		alpha++;
	} while (alpha <= 'z');
	
}