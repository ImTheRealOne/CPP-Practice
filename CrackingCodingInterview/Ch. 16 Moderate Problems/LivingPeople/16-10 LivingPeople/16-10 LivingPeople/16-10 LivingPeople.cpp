// 16-10 LivingPeople.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
#include <algorithm>

void generateList();

void openFile(std::vector<int> & birthYears, std::vector<int> & deathYears);
void print(const std::vector<int> &, const std::string);
std::pair<int, int> mostPplAlive(const std::vector<int> & birthYears, const std::vector<int> & deathYears);

int main()
{
	std::vector<int> birthYears;
	std::vector<int> deathYears;
	std::pair<int,int> result;
	//generateList();
	openFile(birthYears, deathYears);
	result = mostPplAlive(birthYears, deathYears);

	std::cout << "Year : " << result.second << " ---> Alive : " << result.first << std::endl;

	system("pause");
    return 0;
}

void generateList()
{
	std::ofstream filestream;
	int birthYear = 0;
	int deathYear = 0;

	srand(time(NULL));
	filestream.open("birthDeath.txt");
	if (filestream.is_open()) {
		for (int i = 0; i < 20; i++) {
			//filestream << i << " ";
			birthYear = rand() % 100 + 1900;
			deathYear = rand() % (2000-birthYear+1) + birthYear;

			filestream << birthYear << " " << deathYear << "\n";
		}
		filestream.close();
	}		
	else
	{
		std::cout << "can't open file" << std::endl;
	}

}

void openFile(std::vector<int> & birthYears, std::vector<int> & deathYears)
{
	std::string line;
	std::string input;
	std::string delimiter = " ";
	std::size_t start = 0, end = 0;
	int birth = 0, death = 0;
	int index;
	std::fstream fileStream;

	fileStream.open("birthDeath.txt");
	
	if (fileStream.is_open()) {
		while (getline(fileStream, line)) { 
			/*end = line.find(delimiter);
			index = std::stoi( line.substr(0, end));
			line.erase(0, end + delimiter.length()+1);*/
			end = line.find(delimiter);
			birth = std::stoi(line.substr(0, end+ delimiter.length()));
			birthYears.push_back(birth);
			line.erase(0, end+1);
			death = std::stoi(line.substr(0, line.length()));
			deathYears.push_back(death);
		}
	}
	else
	{
		std::cout << "unable to open file";
	}
	std::sort(birthYears.begin(), birthYears.end());
	std::sort(deathYears.begin(), deathYears.end());
}

void print(const std::vector<int>& vector, const std::string title)
{
	std::cout << title << std::endl;
	for (auto &walker : vector) {
		std::cout << walker << std::endl;
	}
}

std::pair<int,int> mostPplAlive(const std::vector<int>& birthYears, const std::vector<int>& deathYears)
{
	
	print(birthYears," birth");
	print(deathYears, "death ");
	if (birthYears.size() <= 0 || deathYears.size() <= 0) {
		return std::pair<int,int>(0,0);
	}
	std::vector<int> peopleAlive (100);
	int max = 0;
	int maxYear = 0;
	int birthIndex = 0, deathIndex = 0, currALive = 0;;
	int	prevBirthYear = birthYears.at(birthIndex);
	int prevDeathYear = deathYears.at(deathIndex);

	/*for (birthIndex, deathIndex; birthIndex < birthYears.size() && deathIndex < deathYears.size();) {
		if (deathYears.at(deathIndex) > birthYears.at(birthIndex)) {
			peopleAlive.at(birthIndex - 1900)++;
		}
	}*/

	while (birthIndex < birthYears.size() && deathIndex < deathYears.size()) {
		if (birthIndex < birthYears.size()) {

			if (deathYears.at(deathIndex) >= birthYears.at(birthIndex)) {
				if (birthYears.at(birthIndex) == prevBirthYear) {
					peopleAlive.at(prevBirthYear - 1900) += 1;
					currALive++;
					if (currALive > max) {
						max = currALive;
						maxYear = birthYears.at(birthIndex);
					}
				}
				else
				{
					peopleAlive.at(birthYears.at(birthIndex) - 1900) = currALive + 1;
					currALive++;
					if (currALive > max) {
						max = currALive;
						maxYear = birthYears.at(birthIndex);
					}
					prevBirthYear = birthYears.at(birthIndex);
				}
				birthIndex++;
			}
			else
			{
				currALive--;
				deathIndex++;
			}
		}
	}
	print(peopleAlive, " People aLIVE");
	return std::pair<int,int>(max,maxYear);
}
