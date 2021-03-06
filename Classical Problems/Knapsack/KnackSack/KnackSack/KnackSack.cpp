// KnackSack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


const int ROWSIZE = 5;
const int COLSIZE = 6;
const int NUMOFITEMS = 4;
int knapsackMatrix[ROWSIZE][COLSIZE];

struct items
{
	int value;
	int weight;
	items() {
		value = 0;
		weight = 0;
	}
	items(int newValue, int newWeight) {
		value = newValue;
		weight = newWeight;
	};
	int getValue() {
		return value;
	};
	int getWeight() {
		return weight;
	};
};

items itemsArray[NUMOFITEMS];


void initKnapSackMatrix();
void printMatrix();
int max(const int & one, const int & two);

int MFKnapSack(const int &itemNum, const int &capacity);

int main()
{
	initKnapSackMatrix();
	printMatrix();
	items item0(0,0);
	items item1(12, 2);
	items item2(10, 1);
	items item3(20, 3);
	items item4(15, 2);

	itemsArray[0] = item0;
	itemsArray[1] = item1;
	itemsArray[2] = item2;
	itemsArray[3] = item3;
	itemsArray[4] = item4;

	MFKnapSack(ROWSIZE-1, COLSIZE-1);

	printMatrix();
	
	system("pause");
    return 0;
}

int max(const int & one, const int & two) {

	return((one > two) ? one : two);
}

void initKnapSackMatrix() {
	for (int i = 0; i < ROWSIZE; i++) {
		for (int j = 0; j < COLSIZE; j++) {
			if (i == 0 || j == 0) {
				knapsackMatrix[i][j] = 0;
			}
			else
			{
				knapsackMatrix[i][j] = -1;
			}
		}
	}
}

void printMatrix() {
	for (int i = 0; i < ROWSIZE; i++) {
		for (int j = 0; j < COLSIZE; j++) {
			std::cout << knapsackMatrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int MFKnapSack(const int &itemNum, const int &capacity) {
	int value = -1;
	if (knapsackMatrix[itemNum][capacity] < 0) {
		if (capacity < itemsArray[itemNum].getWeight()) {
			value = MFKnapSack(itemNum - 1,capacity);
		}
		else
		{
			value = max(MFKnapSack(itemNum - 1,capacity),
				itemsArray[itemNum].getValue() +
				MFKnapSack(itemNum - 1,capacity - itemsArray[itemNum].getWeight()));
		}
		knapsackMatrix[itemNum][capacity] = value;
		printMatrix();
	}
	return knapsackMatrix[itemNum][capacity];
}