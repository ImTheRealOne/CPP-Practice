// Parens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

void validParensPerm(std::stack<char> stack, int nPairs, int numOfOpen, int numOfClose);
void getValidParens(int nPairs);
void printStack(std::stack<char> stack);

int PAIRS = 3;
int main()
{
	getValidParens(PAIRS);

	system("pause");
    return 0;
}

void getValidParens(int nPairs) {
	std::stack<char> stack;
	if (nPairs <= 0) {
		return;

	}
	validParensPerm(stack, nPairs, 0, 0);
}

void validParensPerm(std::stack<char> stack, int nPairs, int numOfOpen, int numOfClose) {
	if (stack.size() >= PAIRS * 2) {
		printStack(stack);
		return;
	}
	if (numOfOpen < nPairs) {
		stack.push('(');
		validParensPerm(stack, nPairs, numOfOpen+1, numOfClose);
		stack.pop();
	}

	if (numOfOpen > numOfClose ) {
		stack.push(')');
		validParensPerm(stack, nPairs, numOfOpen, numOfClose+1);
	}
}

void printStack(std::stack<char> stack) {
	std::cout << std::endl;
	std::stack<char> tempStack;
	while (!stack.empty()) {
		tempStack.push(stack.top());
		stack.pop();
	}

	while (!tempStack.empty()) {
		std::cout << tempStack.top();
		tempStack.pop();
	}
	std::cout << std::endl;
}