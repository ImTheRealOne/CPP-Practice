// 16 - 18 Pattern Matching.cpp : Defines the entry point for the console application. 
/*
Pattern Matching : You are given two strings, pattern and value.The pattern string consists of
just the letters a and b, describing a pattern within a string.For example, the string catcatgocatgo
matches the pattern aabab(where cat is a and go is b).It also matches patterns like a, ab, and b.
Write a method to determine if value matches pattern.

Author : Min Yu

*/
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

std::string patternMatch(std::string string, std::string pattern);

std::pair<std::string, std::string> findAB(std::string string);


std::string stringToPattern(std::string substring, std::string subValue, std::string string);

bool matchStringAB(std::string a, std::string b, std::string string, std::string pattern);

int main()
{
	std::cout<<patternMatch("catcatgocatgo", "aabab")<<std::endl;;
	std::cout << patternMatch("catcatgocatgo", "a") << std::endl;
	std::cout << patternMatch("catcatgocatgo", "ab") << std::endl;
	std::cout << patternMatch("catcatgocatgo", "b") << std::endl;
	
	system("pause");
    return 0;
}

//passes two strings for pattern matching 
std::string patternMatch(std::string string, std::string pattern)
{
	std::string a;
	std::string b;
	std::string result = string + " matches " + pattern + " = " + "false";
	 
	if (string.empty()) {
		result = "empty string";
	}
	if (pattern.empty()) {
		result = "empty pattern";
	}

	std::size_t stringPos;
	std::string tempString = string;
	std::map<std::string, int> stringSubSetMap;
	//create a map of all possible keys of a or b
	for (int i = 0; i < tempString.size()+1; i++) {
		tempString = string;
		a = tempString.substr(0, i);
		stringSubSetMap[a] = 1;
		b = tempString.substr(i, tempString.size());
		stringSubSetMap[b] = 1;
		

	}

	//iterate all combination of keys for a and b for comparison
	for (auto element1 = stringSubSetMap.begin(); element1 != stringSubSetMap.end(); element1++) {
		for (auto element2 = std::next(element1); element2 != stringSubSetMap.end(); element2++) {
			if (matchStringAB(element1->first, element2->first,string, pattern)) {
				result = string + " matches " + pattern + " = " + "true";
				break;
			}
			
		}
	}

	return result;
}


std::string stringToPattern(std::string substring,std::string subValue, std::string string)
{
	if (substring.empty()) {
		return string;
	}
	std::size_t pos;
	pos = string.find(substring);
	while (pos != std::string::npos) {
		string.replace(pos, substring.size(), subValue);
		pos = string.find(substring);
	}
	std::cout << string << std::endl;
	return string;
}


//build the string from pattern if at any point the strings no longer equals break out
bool matchStringAB(std::string a, std::string b, std::string string, std::string pattern)
{
	bool match = false;
	std::string patternToString;

	for (int i = 0; i < pattern.size(); i++) {
		if (pattern.at(i) == 'a') {
			patternToString.append(a);
		}
		else if (pattern.at(i) == 'b')
		{
			patternToString.append(b);
		}
		if (!string.compare(0,patternToString.size(),patternToString)) {
			match = false;
			break;
		}
	}
	if (patternToString == string) {
		match = true;
	}

	return match;
}
