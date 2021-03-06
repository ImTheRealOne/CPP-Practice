// Coins.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>


const int QUARTER = 25;
const int NICKEL = 5;
const int PENNY = 1;
const int DIME = 10;
int totalCalls = 0;

void coinSolSetNaiveRecur(int n, int quarters, int dimes, int nickels, int pennies, std::map<std::string, int> & solutionSet);
int makeChange(int amount, int  denoms[], int index);
int makeChange(int amount);

const int size = 3;


int main()
{
	int nCents = 56;
	int solutionCount = 0;
	int redundantCount = 0;

	std::map<std::string, int> solutionSet;

	//coinSolSetNaiveRecur(nCents, 0, 0, 0, 0, solutionSet);
	
	for (auto x : solutionSet) {
		solutionCount += 1;
		redundantCount += x.second;
		std::cout << x.first << " : " << x.second << std::endl;
	}
	
	std::cout << std::endl << "unique Solution : " << makeChange(25) << std::endl;
	std::cout << "redudant Count : " << redundantCount - solutionCount << std::endl;
	std::cout << "total calls : " << totalCalls << std::endl;

	system("pause");
    return 0;
}

void coinSolSetInter(std::map<std::string, int > & solutionSet) {
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			
		}
	}
}

void coinSolSetRecur(int n, int quarters, int dimes, int , int pennies, std::map<std::string, int> &solutionSet) {

}

void coinSolSetNaiveRecur(int n, int quarters, int dimes, int nickels, int pennies, std::map<std::string, int> &solutionSet) {
	totalCalls++;
	if (n == 0) {
		//convert to string

		std::string solution = "";
		

		solution = std::to_string(quarters) + ":" + std::to_string(dimes) + ":" +
						std::to_string(nickels) + ":" + std::to_string(pennies);

		std::map<std::string, int>::iterator it;
		it = solutionSet.find(solution);
		if (it == solutionSet.end()) {
			solutionSet[solution] = 1;
		}
		else
		{
			solutionSet[solution] += 1;
		}
	}
	else
	{
		if (n - 25 >= 0) {
			coinSolSetNaiveRecur(n - 25, quarters + 1, dimes, nickels, pennies, solutionSet);
		}
		if (n - 10 >= 0) {
			coinSolSetNaiveRecur(n - 10, quarters, dimes + 1, nickels, pennies, solutionSet);
		}
		if (n - 5 >= 0) {
			coinSolSetNaiveRecur(n - 5, quarters, dimes, nickels + 1, pennies, solutionSet);
		}
		if (n - 1 >= 0) {
			coinSolSetNaiveRecur(n - 1, quarters, dimes, nickels, pennies + 1, solutionSet);
		}
	}
}

int makeChange(int amount, int denoms[], int index) {
	if (index >= size)
		return 1;
	int denomAmt = denoms[index];
	int ways = 0;
	for (int i = 0; i * denomAmt <= amount; i++) {
		int amtRemaining = amount - i * denomAmt;
		ways += makeChange(amtRemaining, denoms, index + 1);

	}
	return ways;

}

int makeChange(int n) {
	int denoms[] = { 25, 10, 5, 1 };
	return makeChange(n, denoms, 0);
}