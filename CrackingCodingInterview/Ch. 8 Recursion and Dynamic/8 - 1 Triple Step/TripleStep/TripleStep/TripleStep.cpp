// TripleStep.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int TripleStepBrute(int TotalSteps, int currStep);

int TripleStepBottomUp(int TotalSteps, int currStep);

int TripleStepMemoization(int TotaSteps, int currStep, int memoryArray[]);

int main()
{
	int result = 0;
	const int totalSteps = 6;
	int  memoryArray [(totalSteps+1)];
	for (int i = 1; i < 6; i++) {
		result = TripleStepMemoization(i, 0, memoryArray);
		std::cout << "result at " << i << " : "  << result << std::endl;
	}
	

	system("pause");
    return 0;
}

int TripleStepBrute(int TotalSteps, int currStep) {
	int numOfWay = 0;
	for (int i = 1; i <= 3; i++) {
		if (TotalSteps == currStep + i) {
			numOfWay += 1;
		}
		else if ((currStep + i) < TotalSteps) {
			numOfWay += TripleStepBrute(TotalSteps, currStep + i);

		}

	}

	return numOfWay;
}

int TripleStepBottomUp(int TotalSteps, int currStep) {
	int numOfWay = 0;
	if (currStep >= TotalSteps) {
		return numOfWay;
	}
	if (TotalSteps <= 3) {
		return TripleStepBrute(TotalSteps, 0);
	}
	else {
		numOfWay += TripleStepBottomUp(TotalSteps, currStep + 1);
		if (currStep >= TotalSteps - 3) {
			numOfWay += TripleStepBrute(currStep, 0);
		}
	
	}
	return numOfWay;
}

int TripleStepMemoization(int TotalSteps, int currStep, int memoryArray[]) {
	int tempNum = 0;
	for (int i = 1; i <= TotalSteps; i++) {
		if (TotalSteps <= 3) {
			memoryArray[i] = TripleStepBrute(i, 0);
		}
		else if( i > 3)
		{
			
			for (int j = i-1; j >= i - 3; j--) {
				tempNum += memoryArray[j];
			}
			memoryArray[i] = tempNum;
			tempNum = 0;
		}

	}
	return memoryArray[TotalSteps];
}