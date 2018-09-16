#include "Main.h"
#include <iostream>
#include <string>

Main::Main()
{
}


Main::~Main()
{
}

int subStrBF(std::string a, std::string key);

int subStrSlidingWindow(std::string a, std::string key);

int main() {

	std::cout<< subStrSlidingWindow("ababadc", "abad");
	std::string a = "asdf";
	a.find("a");
	
	system("pause");
	return 0;
}

int subStrSlidingWindow(std::string a, std::string key) {

	int windowBegin = 0;
	int windowMid = 0;
	int windowEnd = 0;
	bool secondInstance = false;
	int pos = -1;
	if (a.empty() || key.empty())
		return pos;

	for (int i = 0; i < a.length(); i++) {
		if (a.at(i) == key.at(0)) {
			windowBegin = i;
			windowEnd = 0;

			while ((windowBegin + windowEnd) < a.length() && a.at(windowBegin+windowEnd) == key.at(windowEnd)){
				windowEnd++;
				if (windowEnd == key.length())
					return i;
				if (!secondInstance && a.at(windowBegin + windowEnd) == key.at(0)) {
					windowMid = windowBegin + windowEnd;
					secondInstance = true;
				}
			}
			if (secondInstance)
				i = windowMid-1;
			secondInstance = false;
			
		}

	}

	return pos;
}

int subStrBF(std::string a, std::string key) {
	int pos = -1;
	if (a.empty() || key.empty())
		return pos;
	for (int i = 0; i < a.length(); i++) {
		if (a.at(i) == key.at(0)) {
			int j = 0;
			while ((i+j) < a.length() && key.at(j) == a.at(j+i)) {
				j++;
				if (j == key.length()) {
					return i;
				}
			}
		}

	}

	return pos;
}