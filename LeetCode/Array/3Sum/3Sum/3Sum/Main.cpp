#include "Main.h"
#include <iostream>
#include <vector>


Main::Main()
{
}


Main::~Main()
{
}

std::vector<std::vector<int>> threeSum(int [], int);

int main() {
	int size = 0;
	int  array[] = { -1, 0, 1, 2, -1, -4 };
	std::vector<std::vector<int>> answer;
	size = (sizeof(array) / sizeof(*array));
	if ( size > 3) {
		answer = threeSum(array, size);
		for (auto &it : answer) {
			std::cout << " { ";
			for (auto& it2 : it) {
				std::cout << it2 << " , ";
			}
			std::cout << "  } " << std::endl;
		}
	}
	else
	{
		std::cout << "array too small, 3 element minimum" << std::endl;
	}

	system("pause");
	return 0;
}

std::vector<std::vector<int>> threeSum(int array[], int size) {
	std::vector<std::vector<int>> result;
	for (int i = 0; i <  size - 2; i++) {
		for (int j = i+1; j < size - 1; j++) {
			for (int k = j+1; k < size; k++) {
				std::cout << " i : " << i << "  j  :   " << j << "  k  :  " << k << std::endl;
				if (array[i] + array[j] + array[k] == 0) {
					std::vector<int> aSolution = *new std::vector<int>();
					aSolution.push_back(array[i]);
					aSolution.push_back(array[j]);
					aSolution.push_back(array[k]);
					result.push_back(aSolution);
				}

			}

		}

	}

	return result;
}