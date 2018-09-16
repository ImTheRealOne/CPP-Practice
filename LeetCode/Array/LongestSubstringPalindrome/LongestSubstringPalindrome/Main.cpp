#include "Main.h"
#include <iostream>
#include <string>



Main::Main()
{
}


Main::~Main()
{
}

std::string longestSubstringPalindrom(std::string s);
std::string longestCommonSubstringBruteForce(std::string a, std::string b);
int main() {
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << " ";
	}

	std::string answer = longestCommonSubstringBruteForce("abcdef", "abcabcdef");
	std::cout << "longest : " << answer << std::endl;


	system("pause");

	return 0;
}

std::string longestSubstringPalindrom(std::string s) {
	std::string result;


	return result;
	
}

std::string longestCommonSubstringBruteForce(std::string a, std::string b) {
	std::string result;
	std::string tempResult;
	for (int i = 0; i < a.length(); i++) {
		
		for (int j = 0; j < b.length(); j++) {
			tempResult.clear();
			int k = i;
			int l = j;
			while (k < a.length() && l < b.length() && a.at(k) == b.at(l) ) {
				tempResult += a.at(k);
				k++;
				l++;
			}
			if (tempResult.length() > result.length())
				result = tempResult;
		}
		
	}

	return result;
}