// PermutationWIthDups.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

void permutationNoDupsHelper(const std::string & string);
void permWithoutDups(std::string currString,int i, std::string result);
void permutationDupsHelper(const std::string & string, std::map < std::string, int> & solutinSet);
void permuationDups(std::string currString, int i, std::string result, std::map < std::string, int> & solutinSet);
std::string removeDups(const std::string & string);


int main()
{
	std::string string = "att";
	std::string stringNoDups;
	std::map<std::string, int> solutionSet;

	stringNoDups = removeDups(string);
	
	//std::cout << stringNoDups << std::endl;

	permutationNoDupsHelper(stringNoDups);



	permutationDupsHelper(string, solutionSet);

	std::map<std::string, int>::iterator it;
	std::cout << std::endl << std::endl;
	for (it = solutionSet.begin(); it != solutionSet.end(); it++) {
		std::cout << it->first << "  :  " << it->second << std::endl;
	}

	system("pause");
    return 0;
}

std::string removeDups(const std::string & string) {
	std::string result = "";

	for (int i = 0; i < string.size(); i++) {
		if (result.find(string.at(i)) == std::string::npos) {
			result += (string.at(i));
		}
	}

	return result;
}
void permWithoutDups(std::string currString,int i, std::string result) {
	if (!currString.empty()) {
		result += currString.at(i);
		currString.erase(i, 1);
	}
	if (currString.empty()) {
		std::cout << result << std::endl;
	}
	for (int j = 0; j < currString.size(); j++) {
		permWithoutDups(currString, j, result);
	}

}

void permutationNoDupsHelper(const std::string & string) {
	for (int i = 0; i < string.size(); i++) {
		permWithoutDups(string,i, "");
	}

}


void permutationDupsHelper(const std::string & string, std::map<std::string, int> &solutionSet) {
	for (int i = 0; i < string.size(); i++) {

		permuationDups(string, i, "", solutionSet);
	}

}

void permuationDups(std::string currString, int i, std::string result, std::map<std::string, int> &solutionSet) {
	if (!currString.empty()) {
		result += currString.at(i);
		currString.erase(i, 1);
	}
	if (currString.empty()) {
		std::map<std::string, int>::iterator it;
		it = solutionSet.find(result);
		if (it == solutionSet.end()) {
			solutionSet.emplace(result, 1);
		}
		else
		{
			solutionSet[result] +=  1;
		}
	}
	for (int j = 0; j < currString.size(); j++) {
		permuationDups(currString, j, result, solutionSet);
	}

}