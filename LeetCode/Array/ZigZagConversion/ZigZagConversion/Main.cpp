#include "Main.h"
#include <iostream>
#include <vector>
#include <string>


Main::Main()
{
}


Main::~Main()
{
}

std::string convert(std::string s, int row);

int main() {


	std::string a = convert("paypalishiring",4);
	std::cout << std::endl << "answer : " << a;
	system("pause");
	return 0;
}

std::string convert(std::string s, int row) {
	std::string result;
	std::vector<std::vector<char>> formattedText;
	bool down = true;
	for (int i = 0; i < row; i++) {
		formattedText.push_back(*new std::vector<char>);
	}
	int x = 0;
	for (int i = 0; i < s.length(); i++) {
		char k = s.at(i);
		formattedText.at(x).push_back(k);
		
		if (down) {
			x++;
			if (x == row) {
				x -= 2;
				down = !down;
			}
			
		}
		else
		{
			x--;
			if (x == 0) {
				down = !down;
			}
		}


	}
	for (auto& it : formattedText) {
		for (auto& it2 : it) {
			std::cout << it2 << " ";
			result += it2;
		}
		std::cout << std::endl;
	}


	return result;
}