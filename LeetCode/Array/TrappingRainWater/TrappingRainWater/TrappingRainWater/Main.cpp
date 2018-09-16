#include "Main.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

Main::Main()
{
}


Main::~Main()
{
}

int bruteForceCalculation(int a[], int size);
int stackCalculation(int a[], int size);

int trap(std::vector<int>& height)
{
	int ans = 0, current = 0;
	std::stack<int> st;
	while (current < height.size()) {
		while (!st.empty() && height[current] > height[st.top()]) {
			int top = st.top();
			st.pop();
			if (st.empty())
				break;
			int distance = current - st.top() - 1;
			int bounded_height = std::min(height[current], height[st.top()]) - height[top];
			ans += distance * bounded_height;
		}
		st.push(current++);
	}
	return ans;
}


int main() {

	int a [] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	std::vector<int> arr = { 0,1,0,2,1,0,1,3,2,1,2,1 };

	std::cout << "total Rain water : " << bruteForceCalculation(a, sizeof(a) / sizeof(*a)) << std::endl;
	std::cout << "total Rain water : " << trap(arr) << std::endl;


	system("pause");
	return 0;
}

int bruteForceCalculation(int a[], int size) {
	int totalRainWater = 0;
	int lowerBound = 0;
	int upperBound = 0;
	bool hasLower = false;

	int i = 0;
	int j = 0;
	//ignore beginning 0s
	while (a[i] == 0) {
		i++;
	}
	//iterate through the array
	while (i <= size-1) {
		hasLower = false;
			lowerBound = a[i];
			j = i+1;
			//iterate through the array looking checking for higher or equal level
			//use j to save the index
			//has lower is a flag to see if there was a higher or equal level
			while (j < size-1 && !hasLower) {
				if (a[j] >= a[i]) {
					hasLower = true;
				}
				j++;
			}
			//go back to the beginning index and add all the valleys
			//if has lower was set
			while (i < j-1 && hasLower) {
				totalRainWater += lowerBound - a[i];
				i++;
			}
			//if there was a higher or equal level to beginning level
			//then continue to the next index else skip that index
			if(hasLower)
				i = j-1;
			else
			{
				i++;
			}
	}
		


	return totalRainWater;
}

int stackCalculation(int a[], int size) {
	std::stack<int> stack;

	return 0;
}