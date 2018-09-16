#include "Main.h"
#include <iostream>
#include <string>


Main::Main()
{
}


Main::~Main()
{
}

int recurSearch(std::string a [], std::string key, int lowBound, int upBound);

int main() {



	std::string a[14] = { "at", "", "", "", "ball", "", "",
							"car", "", "", "dad", "", "","tt" };

	std::cout <<"answer at : "<< recurSearch(a, "car", 0, sizeof(a) / sizeof(*a))<<std::endl;

	system("pause");
	return 0;
}

int recurSearch(std::string a[], std::string key, int lowBound, int upBound) {

	int result = -1;
	int result2 = -1;
	int mid = (upBound+lowBound) / 2;
	//check if mid is key
	if (a[mid] == key) {
		return mid;
	}
	//check if mid is out of bounds
	if (mid >= upBound || mid <= lowBound)
		return -1;
	else
	{
		//if mid is empty string check both sides
		if (a[mid].empty()) {
			//recurse both sides
			result = recurSearch(a, key, lowBound, mid-1);
			if(result == -1)
				result2 = recurSearch(a, key, mid+1, upBound);
		}
		//if mid is larger than key then target is in lower half
		else if (a[mid] > key) {
			result = recurSearch(a, key, lowBound, mid-1);
		}
		//if mid is smaller than key then target is in upper half
		else if (a[mid] < key) {
			result = recurSearch(a, key, mid+1, upBound);
		}
	}
	//check if result is target if not return result2
	if(result != -1)
		return result;
	else
	{
		return result2;
	}
}

