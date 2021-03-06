// 16-24 PairsWithSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>

//returns all unique paired indexes not unique solution
std::vector<std::pair<int, int>> pairsWithSum(int * arr,const int size, const int target);

int main()
{
	int arr[] = { 2,4,13,-4,5,0,2,-4,-4, 13 };
	std::vector<std::pair<int, int>> result;
	result = pairsWithSum(arr, sizeof(arr)/sizeof(*arr), 9);
	
	for (auto &it : result) {
		std::cout << "index : " << it.first <<" -> " << arr[it.first] << " , " << "index : " << it.second << " -> " << arr[it.second]<<std::endl;
	}

    return 0;
}

std::vector<std::pair<int, int>> pairsWithSum(int * arr,const int size, const int target) {
	std::map<int, std::vector<int>> solutionMap;
	std::map<int, std::vector<int>>::iterator solutionMapIt;
	std::vector<std::pair<int, int>> solutionSet;
	int key;
	for (int i = 0; i < size; i++) { 
		//key is the difference between the target and current element at index i
		key = target - arr[i];
		std::cout << "key : " << key << std::endl;
		//check if current element at index is a solution for any another index
		solutionMapIt = solutionMap.find(arr[i]);
		if (solutionMapIt == solutionMap.end()) {
			//if the index is not a solution for another index then add to the map
				//with the difference as key and the index of current element as value to guarantee unique pair indexes
			std::vector<int> vector= { i }; 
			solutionMap.insert(std::pair<int, std::vector<int> >(key, vector));
		}
		//if the curret element at index i is a solution for another index
		else
		{
			//then add all combination of index i to the other index that has current element as its solution
			for (auto &vectorIt : solutionMapIt->second) {
				std::pair<int, int> pairIndexes(i, vectorIt);
				solutionSet.push_back(pairIndexes);
			}
			//check if the difference is already part of the map 
			//if not add it to the map with index as value
			solutionMapIt = solutionMap.find(key);
			if (solutionMapIt == solutionMap.end()) {
				std::vector<int> vector = { i };
				solutionMap.insert(std::pair<int, std::vector<int>>(key, vector));
			}
			//if difference is already a known key then add index to the values
			else
			{
				solutionMapIt->second.push_back( i);
			}
		}

	}



	return solutionSet;
}