// 16 - 21 SumSwap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>

int getSumTotal(const std::vector<int> &arr);
std::pair<int, int> swapPairs(const std::vector<int> &arr1, const std::vector<int> &arr2);
std::set<std::pair<int, int>> swapPairsWithMap(const std::vector<int> &arr1, const std::vector<int> &arr2);

int main()
{
	std::vector<int> arr1 = { 4,1,2,1,1,2 };
	std::vector<int> arr2 = { 3,6,3,3 };

	std::pair<int, int> result = swapPairs(arr1, arr2);

	//std::cout << result.first << "  ,  " << result.second<<std::endl;

	std::set<std::pair<int, int>> solution;
	solution = swapPairsWithMap(arr1, arr2);

	for (auto &solutionIterator : solution) {
		std::cout << solutionIterator.first << "  ,  " << solutionIterator.second << std::endl;
	}

    return 0;
}

int getSumTotal(const std::vector<int> &arr)
{
	if (arr.empty()) {
		return -999;
	}

	int total = 0;

	for (int i = 0; i < arr.size(); i++) {
		total += arr[i];
	}

	return total;
}

std::pair<int, int> swapPairs(const std::vector<int> &arr1, const std::vector<int> &arr2)
{
	int pair1 = -999;
	int pair2 = -999;
	int sum1 = 0;
	int sum2 = 0;
	int difference1 = 0;
	int difference2 = 0;

	
	sum1 = getSumTotal(arr1);
	sum2 = getSumTotal(arr2);

	for (int i = 0; i < arr1.size(); i++) {
		difference1 = sum1 - arr1[i];
		difference2 = sum2 + arr1[i];
		for (int j = 0; j < arr2.size(); j++) {
			if (difference2 - arr2[j] == difference1 + arr2[j]) {
				pair1 = arr1[i];
				pair2 = arr2[j];
			}
		}
	}

	return std::pair<int, int>(pair1,pair2);
}

std::set<std::pair<int, int>> swapPairsWithMap(const std::vector<int> &arr1, const std::vector<int> &arr2)
{
	std::map<int, int> solutionSet;
	std::pair<int, int> pair(-1,-1);
	std::set<std::pair<int, int>> solution;
	int sum1 = -999;
	int sum2 = -999;
	
	if (arr1.empty() || arr2.empty()) {
		return solution;
	}

	sum1 = getSumTotal(arr1);
	sum2 = getSumTotal(arr2);

	int difference1 = 0;
	int difference2 = 0;

	for (int i = 0; i < arr1.size(); i++) {
		difference1 = sum1 - arr1[i];
		difference2 = sum2 + arr1[i];

		std::pair<std::map<int, int>::iterator, bool> insertResult =
			solutionSet.insert(std::map<int, int>::iterator::value_type((difference2 - difference1) / 2, arr1[i]));
	}
	std::map<int, int>::iterator solutionIterator;
	for (int i = 0; i < arr2.size(); i++) {
		solutionIterator = solutionSet.find(arr2[i]);
		if (solutionIterator != solutionSet.end()) {
			pair = std::pair<int, int>(solutionIterator->first, solutionIterator->second);
		}
		solution.insert(pair);
	}

	return solution;
}
