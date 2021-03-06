// SmallestDifference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> smallestPair(std::vector<int> a, std::vector<int> b);

int main()
{
	std::vector<int> a{ 1, 3, 15, 11, 2 ,234};
	std::vector<int> b{ 23,127,235,19,8 };


	std::pair<int,int> result = smallestPair(a,b);

	std::cout << result.first << "  " << result.second << "  "<< abs(result.first - result.second) << std::endl;;

	system("pause");
    return 0;
}

std::pair<int, int> smallestPair(std::vector<int> a	, std::vector<int> b) {
	if (a.size() < 1 || b.size() < 1) {
		return std::pair<int, int>(-1, -1);
	}

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	std::vector<int>::iterator aIter = a.begin();
	std::vector<int>::iterator bIter = b.begin();

	int aPair = 0;
	int bPair = 0;
	int difference = 0;

		aPair = *aIter;
		bPair = *bIter;
		difference = abs(aPair - bPair);
	while (aIter != a.end() && bIter != b.end()) {
		if (abs((*aIter - *bIter) < difference)) {
			difference = abs(*aIter - *bIter);
		}
		std::cout << "aIter : " << *aIter << std::endl;
		std::cout << "bIter : " << *bIter << std::endl;
		if (*aIter < *bIter)
			aIter = aIter + 1;
		else
		{
			bIter = bIter + 1;
		}

		/*
		if (aIter+1 != a.end() && bIter+1 != b.end()) {
			std::cout << "aIter : " << *(aIter ) << std::endl;
			std::cout << "bIter : " << *(bIter) << std::endl;
			if (*(aIter + 1) > *(bIter + 1) ) {
				bIter = bIter + 1;
			}
			else 
			{
				aIter = aIter + 1;
			}

		}
		else if (aIter+1 == a.end() && bIter!= b.end()) {
			bIter = bIter +1;
		}
		else if(bIter+1 == b.end() && aIter != a.end())
		{
			aIter = aIter + 1;
		}
		if (aIter != a.end() && bIter != b.end()) {
			if (abs(*aIter - *bIter) < difference) {
				aPair = *aIter;
				bPair = *bIter;
				difference = abs(*aIter - *bIter);
			}
			else if(aIter == a.end())
			{
				if (abs(aPair - *bIter) < difference) {
					bPair = *bIter;
					difference = abs(aPair - *bIter);
				}
			}
			else if(bIter == b.end())
			{
				if (abs(bPair - *aIter) < difference) {
					aPair = *aIter;
					difference = abs(aPair - *bIter);
				}

			}
		}*/
	}
	
	return (std::pair<int, int>(*aIter, *bIter));
}