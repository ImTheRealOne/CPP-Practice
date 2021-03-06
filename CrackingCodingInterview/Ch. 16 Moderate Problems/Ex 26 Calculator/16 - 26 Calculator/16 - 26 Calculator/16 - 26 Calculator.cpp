// 16 - 26 Calculator.cpp : Defines the entry point for the console application.
/*
Calculator: Given an arithmetic equation consisting of positive integers, +, -, * and / (no parentheses).
compute the result.

*/
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>


double calculator(std::string equation);

std::string operate(std::string equation, char a, char b);

std::string operation(std::string equation);

void testOperation();

std::string validEquation(std::string equation);

int main()
{
	try {
		std::cout << calculator("2*3+5/6*3+15.5")<<std::endl;
	}
	catch (const char * exceptionMsg) {
		std::cout << exceptionMsg;
	}
	system("pause");
    return 0;
}

double calculator(std::string equation) {
	double result = -1;
	if (equation.empty()) {
		throw "empty equation";
	}
	equation = validEquation(equation);
	try {
		std::string afterMulDiv = operate(equation, '*', '/');
		std::string afterAddSub = operate(afterMulDiv, '+', '+');
		result = std::stod(afterAddSub);
	}
	catch (const char* e) {
		std::cout << e;
	}


	return result;
}

void testOperation()
{
	std::string test1 = "3.5+4.1";
	std::cout << operation(test1);
	std::cout<<std::endl;
	std::string test2 = "1.1*1.1";
	std::cout << operation(test2);
	std::cout << std::endl;
	std::string test3 = "1.5/.5";
	std::cout << operation(test3);
	std::cout << std::endl;
	std::string test4 = "6.5-.6";
	std::cout << operation(test4);
	std::cout << std::endl;
}
//ensures there's not two consecutive operations
//there's no negative numbers initially
std::string validEquation(std::string equation)
{
	if (equation.empty()) {
		throw "empty equation";
	}
	char startChar = equation.at(0);
	char endChar = equation.at(equation.size() - 1);
	if (startChar == '+' || startChar == '-' || startChar == '*' || startChar == '/') {
		throw "invalid equation";
	}
	if (endChar == '+' || endChar == '-' || endChar == '*' || endChar == '/') {
		throw "invalid equation";
	}
	for (int i = 0; i < equation.size(); i++) {
		char currentChar = equation.at(i);
		if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
			if (i + 1 < equation.size()) {
				char nextChar = equation.at(i + 1);
				if (nextChar == '+' || nextChar == '-' || nextChar == '*' || nextChar == '/') {
					throw "invalid equation";
				}
			}
			//replace all minus with addition of the negative number
			if (currentChar == '-') {
				equation.replace(i, 1, "+");
				equation.insert(i + 1, "-");
				i += 1;
			}
		}
		//remove spaces
		else if (currentChar == ' ') {
			equation.replace(i, 1, "");
			i -= 1;
		}

	}


	return equation;
}

std::string operate(std::string equation, char a, char b)
{	
	std::stack<char> equStack;
	std::string tempEquation = equation;
	std::string subEquation = "";
	//early return if there's no multiply and divide
	//or if there is no addition
	std::size_t foundOperation = equation.find(a);
	if (foundOperation == std::string::npos) {
		foundOperation = equation.find(b);
		if (foundOperation == std::string::npos)
			return equation;
	}
	//push char into stack until there's an operation to perform
	for (int i = 0; i < tempEquation.size(); i++) {
		if (tempEquation.at(i) != a && tempEquation.at(i) != b) {
			equStack.push(tempEquation.at(i));

		}
		else
		{	//operation is found now pop from the stack until stack is empty or the beginning of sub equation
			subEquation = "";
			while (!equStack.empty() && (equStack.top() != '*'  && equStack.top() != '/' && equStack.top() != '+'))
			{
				char c = equStack.top();
				subEquation.insert(0,1, c);
				equStack.pop();
			}
			subEquation += tempEquation.at(i);
			for (int j = i+1; j < tempEquation.size() && (tempEquation.at(j) != '*' 
				&& tempEquation.at(j) != '/' && tempEquation.at(j) != '+' ); j++) {
			
					subEquation += tempEquation.at(j);
				
			}
			//solve subequation
			//std::cout << " subequation : " << subEquation << std::endl;
			std::string subResult = operation(subEquation);
			//std::cout << " subResult : " << subResult << std::endl;
			std::size_t subEquationIndex = tempEquation.find(subEquation);
			tempEquation.replace(subEquationIndex, subEquation.size(), "");
			tempEquation.insert(subEquationIndex, subResult);
			//std::cout << " tempEquation : " << tempEquation << std::endl;
			//empty the stack to reread the equation
			while (!equStack.empty()) {
				equStack.pop();
			}
			i = -1;
		}



	}


	return tempEquation;
}

std::string addsub(std::string equation)
{
	return std::string();
}
//parse the an equation and return the result
std::string operation(std::string equation)
{
	std::size_t operationIndex = -1;
	std::string operandA;
	std::string operandB;
	
	double result = - 999;
	operationIndex = equation.find('*');
	if (operationIndex != std::string::npos) {
		operandA = equation.substr(0, operationIndex);
		operandB = equation.substr(operationIndex+1, equation.size() - 1);
		result = std::stod(operandA) * std::stod(operandB);
		return std::to_string(result);
	}
	operationIndex = equation.find('/');
	if (operationIndex != std::string::npos) {
		operandA = equation.substr(0, operationIndex);
		operandB = equation.substr(operationIndex+1, equation.size() - 1);
		result = std::stod(operandA) / std::stod(operandB);
		return std::to_string(result);
	}
	operationIndex = equation.find('+');
	if (operationIndex != std::string::npos) {
		operandA = equation.substr(0, operationIndex);
		operandB = equation.substr(operationIndex+1, equation.size() - 1);
		result = std::stod(operandA) + std::stod(operandB);
		return std::to_string(result);
	}

	return std::to_string(result);;
}



