#include "Main.h"
#include <iostream>
#include <string>

Main::Main()
{
}


Main::~Main()
{
}

std::string stringMul(std::string num1, std::string num2);


int main() {
	std::string num1 = "0";
	std::string num2 = "010";

	std::string result = stringMul(num1, num2);

	std::cout << "result : " << result;

	system("pause");
	return 0;
}

std::string stringMul(std::string num1, std::string num2) {
	std::string result;
	int multiplicand = 0;
	int multiplier = 0;
	int product = 0;
	int firstDigit = 0;
	int secondDigit = 0;
	int carry;
	int k = 0;
	int tempNum = 0;

	std::reverse(num1.begin(), num1.end());
	std::reverse(num2.begin(), num2.end());
	result.resize(num1.length()+1 + num2.length()+1);
	//initialize the result string with 0s
	for (int i = 0; i < result.size(); i++) {
		result.at(i) = '0';
	}
	
	for (int i = 0; i < num1.length() ; i++) {
		int multiplicand = static_cast<int>(num1.at(i))-48;
		

			for (int j = 0; j < num2.length() ; j++) {
			

				multiplier = product = firstDigit = secondDigit = 0;
				int muliplier = static_cast<int>(num2[j])-48;
				
				product = multiplicand * muliplier;

				if (product >= 10) {
					secondDigit = product / 10;
					firstDigit = product % (10 * secondDigit);
				}
				else
				{
					firstDigit = product % 10;
				}
				if(result.at(i+j) == '0')
					result.at(i + j) = static_cast<char>(firstDigit) + 48;
				else
				{
					k = 0;
					tempNum = static_cast<int>(result.at(i + j + k)) - 48 + firstDigit;
					if (tempNum >= 10) {
						while (tempNum >= 10) {
							result.at(i + j) = static_cast<char>(tempNum % 10)+48;
							k++;
							result.at(i + j + k) = static_cast<char>(static_cast<int>(result.at(i + j + k))+1 - 48) + 48;
							tempNum = static_cast<int>(result.at(i + j + k)) - 48;
						}
					}
					else
					{
						result.at(i + j) = static_cast<char>(tempNum) + 48;
					}
				}
				if (secondDigit != 0) {
					if (result.at(i + j + 1) == '0')
						result.at(i + j + 1) = static_cast<char>(secondDigit)+48;
					else
					{
						k = 1;
						tempNum = static_cast<int>(result.at(i + j + k)) - 48 + secondDigit;
						if (tempNum >= 10) {
							while (tempNum >= 10) {
								result.at(i + j+k) = static_cast<char>(tempNum % 10) + 48;
								k++;
								result.at(i + j + k) = static_cast<char>(static_cast<int>(result.at(i + j + k))+1 - 48) + 48;
								tempNum = static_cast<int>(result.at(i + j + k)) - 48;
							}
						}
						else
						{
							result.at(i + j+k) = static_cast<char>(tempNum) + 48;
						}
					}
				}
				
					
			}

	}


	std::reverse(result.begin(), result.end());

	return result;
}


/*
					if (muliplier != 0) {
						if (product >= 10) {
							carry = product / 10;
							if (result.at(i + j+1) == NULL)
								result.at(i + j + 1) = static_cast<char>(carry)+48;
							else
							{
								int tempResult = static_cast<int>(result.at(i + j+1)) - 48 + carry;
								int k = 0;
								while (result.at(i+j+k) > 10) {


									k++;
								}
								
								
								
							}
							product = product % (carry * 10);
						}
					}
					if(result.at(i+j) == NULL)
						result.at(i + j) = static_cast<char>((product))+48;
					else
					{
						int tempResult = result.at(i + j)-48;
						result.at(i + j) = static_cast<char>(static_cast<int>(result.at(i + j))-48 + product)+48;
					}
				*/