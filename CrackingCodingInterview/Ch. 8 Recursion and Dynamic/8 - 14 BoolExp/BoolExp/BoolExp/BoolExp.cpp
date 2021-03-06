// BoolExp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stack>

bool xorOp(bool operand1, bool operand2);
bool andOp(bool operand1, bool operand2);
bool orOp(bool operand1, bool operatnd2);

bool evalBoolExp(const std::string &exp);

int countWays( std::string exp, bool wantedResult);

int countWaysHelper(std::string exp, bool wantedResult);

int main()
{
	std::string test = "0&0&0&1^1|0";
	
	std::cout << countWays(test, true) << std::endl;

	system("pause");
    return 0;
}

bool evalBoolExp(const std::string &exp) {
	bool operand1;
	bool operand2;

	operand1 = exp.at(0) - 48;
	operand2 = exp.at(2) - 48;

	char operation = static_cast<char>(exp.at(1));

	switch (operation)
	{
		case '&' :
			return andOp(operand1, operand2);
			break;
		case '^' :
			return xorOp(operand1, operand2);
			break;
		case '|' :
			return orOp(operand1, operand2);
			break;
		default:
			std::cout << "invalid operation"<<std::endl;
			break;
	}


	return false;
}

bool xorOp(bool operand1, bool operand2) {
	return operand1 ^ operand2;
}

bool andOp(bool operand1, bool operand2) {
	return operand1 & operand2;
}

bool orOp(bool operand1, bool operand2) {
	return operand1 | operand2;
}

int countWays(std::string exp, bool wantedResult) {
	int result = 0;
	if (exp.length() == 1) {
		std::cout << exp << std::endl << std::endl;
		return (exp.at(0)-48) == wantedResult;
	}
	else if(exp.length() >= 3)
	{
		for (int i = 0; i < exp.length() - 1; i += 2) {
			std::string partialString = exp.substr(i, 3);
			std::string tempString = exp;
			std::cout << tempString << std::endl;
			tempString.insert(i + 3, ")");
			tempString.insert(i, "(");
			bool tempBool = evalBoolExp(partialString);
			char tempChar = static_cast<char>(tempBool);
			std::cout << tempString << std::endl<<std::endl;
			std::size_t strIter;
			strIter = tempString.find("(");
			tempString.erase(strIter, 1);
			strIter = tempString.find(")");
			tempString.erase(strIter, 1);





			result += countWays(tempString.replace(i, 3, std::to_string(tempChar)), wantedResult);


		}
	}
	
	return result;
}
