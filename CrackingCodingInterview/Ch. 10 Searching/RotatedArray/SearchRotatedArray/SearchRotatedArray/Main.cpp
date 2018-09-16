#include "Main.h"
#include "Listy.h"
#include<iostream>

Main::Main()
{
}


Main::~Main()
{
}

int listySearch(Listy list, int target);
int searchRecursiveHelper(int a[], int target, int size);
int searchRecursive(Listy list, int target,  int upper, int lower);
int searchRotatedArray(int a [],int target , int size);
void rot_arr(int a[], int s, int r);
void swap(int a[], int x, int y);
int main() {
	int a[] = { 6,7, 0,1,2,3,4,5 };
	int size = 8;
	int b[] = { 10,20,40,60,90,110 };

	Listy list = *new Listy(b, sizeof(b) / sizeof(*b));
	int i = 0;
	while(list.getAt(i) != -99){
		if (i != listySearch(list, list.getAt(i)))
			std::cout << "F @ " << list.getAt(i) << std::endl;
		else
		{
			std::cout << "S @ " << list.getAt(i) << std::endl;
		}
		i++;
	}

	for (int i = 0; i < size; i++) {
		
		rot_arr(a, size, i);
		for (int j = 0; j < size; j++) {
			if (j != searchRotatedArray(a,a[j], size-1))
				std::cout << "f @ " << a[j] << std::endl;
		}
	}
	system("pause");
	return 0;
}

int listySearch(Listy list, int target) {
	int upper = -1;
	int lower = 0;
	int i = 0;
	while (upper == -1) {
		if (list.getAt(i) == target) {
			return i;
		}
		else if (list.getAt(i) == -99)
		{
			while (list.getAt(i) == -99) {
				
				i -= 1;
				upper = i;
			}
			break;
		}
		else if (list.getAt(i) < target) {
			lower = i;
		}
		else
		{
			upper = i;
			break;
		}

		i <<= 1;
		i++;
	}
		

	return searchRecursive(list, target, upper, lower);

}

int searchRecursive(Listy a, int target, int upperBound, int lowerBound) {
	int index = -99;
	bool leftRotation = false;
	bool rightRotation = false;
	if (a.getAt(upperBound) == target) return upperBound;
	if (a.getAt(lowerBound) == target) return lowerBound;
	if (upperBound - lowerBound < 1)
		return index;

	int searchIndex = (upperBound + lowerBound) / 2;
	leftRotation = a.getAt(lowerBound) > a.getAt(searchIndex) ? true : false;
	rightRotation = a.getAt(upperBound) < a.getAt(searchIndex) ? true : false;
	if (a.getAt(searchIndex) == target) {
		index = searchIndex;
		return index;
	}
	//a[search index] is smaller than target
	else if (a.getAt(searchIndex) < target)
	{

		//case 3 left rotation key is in upper half
		if (leftRotation) {
			if (a.getAt(upperBound)< target)
				upperBound = searchIndex;
			else
			{
				lowerBound = searchIndex;
			}
		}
		//case 4 right rotation key is in lower half
		else if (rightRotation) {
			if (a.getAt(upperBound) < target) {
				lowerBound = searchIndex;
			}
			else
			{
				upperBound = searchIndex;
			}
		}
		//case 2 no rotation key is in upper half
		else
		{
			lowerBound = searchIndex;
		}


	}
	//a[search index] is larger than target
	else
	{
		if (leftRotation) {
			if (a.getAt(upperBound)< target) {
				lowerBound = searchIndex;
			}
			else
			{
				upperBound = searchIndex;
			}
		}
		else if (rightRotation) {
			if (a.getAt(upperBound) < target) {
				upperBound = searchIndex;
			}
			else
			{
				lowerBound = searchIndex;
			}
		}
		else
		{
			upperBound = searchIndex;
		}


	}
	index = searchRecursive(a, target, upperBound, lowerBound);

	return index;
}


int searchRotatedArray(int a[], int target, int size) {
	int index = -99;

	int searchIndex = 0;
	int upperBound = size-1;
	int lowerBound = 0;
	bool leftRotation = false;
	bool rightRotation = false;
	int curr = 0;

	do {
		searchIndex = (upperBound + lowerBound) / 2;
		curr = a[searchIndex];
		leftRotation = a[lowerBound] > a[searchIndex] ? true : false;
		rightRotation = a[upperBound] < a[searchIndex] ? true : false;
		if (a[searchIndex] == target) {
			index = searchIndex;
			return index;
		}
		//a[search index] is smaller than target
		else if(a[searchIndex] < target)
		{
			
			//case 3 left rotation key is in upper half
			if (leftRotation) {
				if (a[upperBound] < target)
					upperBound = searchIndex;
				else
				{
					lowerBound = searchIndex;
				}
			}
			//case 4 right rotation key is in lower half
			else if (rightRotation) {
				if (a[upperBound] < target) {
					lowerBound = searchIndex;
				}
				else
				{
					upperBound = searchIndex;
				}
			}
			//case 2 no rotation key is in upper half
			else
			{
				lowerBound = searchIndex;
			}


		}
		//a[search index] is larger than target
		else
		{
			if (leftRotation) {
				if (a[upperBound] < target) {
					lowerBound = searchIndex;
				}
				else
				{
					upperBound = searchIndex;
				}
			}
			else if (rightRotation) {
				if (a[upperBound] < target) {
					upperBound = searchIndex;
				}
				else
				{
					lowerBound = searchIndex;
				}
			}
			else
			{
				upperBound = searchIndex;
			}
		

		}


	} while (upperBound - lowerBound > 1);
	
	
	if (a[upperBound] == target) return upperBound;
	if (a[lowerBound] == target) return lowerBound;

	return index;
}
void rot_arr(int a[], int s, int r) {
	int next = r, first = 0, last = s;

	while (first != next) {
		swap(a, first++, next++);
		if (next == last) next = r;
		else if (first == r) r = next;
	}
}

void swap(int a[], int x, int y) {
	int c = a[x];
	a[x] = a[y];
	a[y] = c;
}
