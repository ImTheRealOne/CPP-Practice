#include "Main.h"
#include <iostream>
#include <map>
#include <string>
#include <random>
#include <vector>

Main::Main()
{
}


Main::~Main()
{
}

std::string sort(std::string a);
std::string qSort(std::string& a, int left, int right);
void swap(std::string & a, int left, int right);
int partition(std::string & a, int left, int right, int index);
void sortAnagram(std::string arr[], int size);

int main() {

	std::string arr [] = {"cat", "bat", "that", "act", "abt", "tab"};

	//sort("cat");
	sortAnagram(arr, sizeof(arr)/sizeof(*arr));

	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
		std::cout << arr[i] << "   ";
	}

	//std::map<std::string, std::string> kMap;

	//kMap.insert(std::pair<std::string, std::string>("abc", "1"));
	//kMap.insert(std::pair<std::string, std::string>("abc", "2"));


	system("pause");
	return 0;
}

void sortAnagram(std::string arr[], int size) {
	
	std::map<std::string, std::vector<std::string>> keyMap;

	for(int i = 0; i < size;i++){
		std::string key = sort(arr[i]);
		std::cout << "key : " << key << "   arr : " << arr[i] << std::endl;
		std::map < std::string, std::vector<std::string>>::iterator it = keyMap.find(key);
		if (it == keyMap.end()) {
			std::vector<std::string> a;
			a.push_back(arr[i]);
			keyMap.insert(std::pair<std::string, std::vector<std::string>>(key, a));
		}
		else
		{
			keyMap.at(key).push_back(arr[i]);
		}

	}
	int i = 0;
	for (auto x : keyMap) {
		for (int j = 0; j < x.second.size(); j++) {
			arr[i] = x.second.at(j);
			i++;
		}
	}

}




std::string sort(std::string a) {

	std::string result = qSort(a, 0, a.length()-1);
	//std::cout << "string : " << a;
	return a;
}

std::string qSort(std::string & a ,int left, int right) {
	if (left >= right)
		return a;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(left, right);
	int pivot = distribution(generator);


	int pos = partition(a, left, right, pivot);
	//print(*this->vectorPtr);
	qSort(a, left, pos - 1);
	qSort(a, pos + 1, right);

	return a;
}

void swap(std::string & a, int left, int right) {
	char temp = a.at(left);
	a.at(left) = a.at(right);
	a.at(right) = temp;
}


int partition(std::string & a, int left, int right, int index) {

	swap(a, index, right);
	int pos = left;
	for (int i = left; i < right; i++) {
		if (a.at(i) <= a.at(right)) {
			swap(a, i, pos);
			pos++;
		}
	}
	//print(*this->vectorPtr);
	//std::cout << "pos : " << vectorPtr->at(pos) << "     right   :   " << vectorPtr->at(right) << std::endl;
	swap(a, pos, right);
	//print(*this->vectorPtr);
	//std::cout << "pos : " << vectorPtr->at(pos) << "     right   :   " << vectorPtr->at(right) << std::endl;
	return pos;
}