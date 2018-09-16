#pragma once
#include <iostream>
#include <vector>
#include <string>
class Main
{
public:
	Main();
	~Main();
};

void permutation(std::vector<int> arr, int size, std::vector<int> result, int length);
void print(std::vector<int> arr, int size);
std::string perm(std::vector<int> arr);

int main() {

	std::vector<int> arr = { 1,2,3 };
	std::vector<int>  result;
	permutation(arr, arr.size(), result, 0);
	//std::cout<<perm(arr);

	system("pause");
	return 0;
};

void permutation(std::vector<int> arr, int size, std::vector<int>  result, int length) {


	for (int i = 0; i < size; i++) {
		if (arr[i] != NULL) {
			int temp = arr[i];
			result.resize(length + 1);
			result[length] = arr[i];
			arr[i] = NULL;
			if(result.size() != size)
				permutation(arr, size, result, length + 1);
			arr[i] = temp;
		}
		if (result.size() == size) {
			print(result, result.size());
			return;
		}
	}
	
}

void print(std::vector<int> arr, int size) {
	std::cout << "[";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ",";
	}
	std::cout << "]";
}

std::string perm(std::vector<int> vec) {
	std::string res = "";
	int temp;

	for (int i = 0; i < vec.size(); ++i) {
		temp = vec.at(i);
		if (temp == -1)
			continue;
		else {
			res += std::to_string(temp) + ",";
			vec.at(i) = -1;
			res += perm(vec);
			vec.at(i) = temp;
		}
		res.pop_back();
		res += "\n";
	}
	std::cout << "res : " << res;
	return res;
	
}