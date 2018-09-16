#include "Main.h"
#include <iostream>
#include <vector>


Main::Main()
{
}


Main::~Main()
{
}

int removeDups(std::vector<int> a ,int len);

int removeANum(std::vector<int>&a,  int target, int len);


int main() {

	std::vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(2); 
	a.push_back(2);
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);
	a.push_back(1);
	a.push_back(4);
	a.push_back(4);
	a.push_back(1);
	a.push_back(6);
	a.push_back(7);
	a.push_back(888);

	//std::cout << "Unique : " << removeDups(a, 14) << std::endl;
	//for (int i = 0; i < 14; i++) {
	//	std::cout << a[i] << "   ";
	//}
		
	removeANum(a, 1, 14);

	for (int i = 0; i < 14; i++) {
		std::cout << a[i] << "   ";
	}

	system("pause");
	return 0;
}

int removeANum(std::vector<int>& a,int target, int len) {
	int newLen = len;
	for (int i = 0, j = 0; i < len; i++) {
		if (a[i] == target) {
			newLen--;
		}
		else
		{
			a[j] = a[i];
			j++;
		}
	}
	return newLen;
}

int removeDups(std::vector<int> a, int len) {
	if(len < 2)
		return NULL;
	
	
	int newLen = len;
	int pos = 1;
	int i = 0;
	int j = 1;

	while (j < len) {

		if (a[i] != a[j]) {

		
			int temp = a[pos];
			a[pos] = a[j];
			 temp = a[pos];
			pos++;
			i++;
			j++;
		}
		else
		{
			while (j < len && a[i] == a[j]) {
				j++;
				newLen--;
			}
			 int temp = a[pos];
			a[pos] = a[j];
			
			i = j;
			j++;
			pos++;
		}
	}
	return newLen;

}