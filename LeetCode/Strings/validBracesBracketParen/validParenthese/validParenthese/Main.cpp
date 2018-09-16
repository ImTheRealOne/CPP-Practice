#include "Main.h"
#include <iostream>
#include <string>
#include <stack>


Main::Main()
{
}


Main::~Main()
{
}

void generateAllPermutationHelper(std::string a, int n, int left, int right, int& sol);
void generateAllPermutation(int n);
bool isValid(std::string input);
void print(std::string test);
int main() {
	
	//test cases for valid parenthese braces and brackets
	/*std::string test = "(){}[]";
	
	print(test);

	test = "({{}[]})";
	print(test);

	test = "(]";
	print(test);

	test = "([)]";
	print(test);*/
	
	generateAllPermutation(4);

	system("pause");
	return 0;
}

void generateAllPermutation(int n) {
	if (n <= 0) {

		std::cout << "n has to be greater than 0" << std::endl;
	}
	else
	{
		int a = 0;
		generateAllPermutationHelper("(", n, 1, 0,a );
	}

}

void generateAllPermutationHelper(std::string a,int n, int left, int right, int& sol) {
	if (left == n && right == n) {
		sol++;
		std::cout << a <<"   " << sol<< std::endl;

	}
	if (left < n) {
		generateAllPermutationHelper(a + "(", n, left+1, right, sol);
	
	}
	if (left > right) {
		generateAllPermutationHelper(a + ")", n, left, right+1, sol);
	}
	
	
}

void print(std::string test) {
	if (isValid(test)) {
		std::cout << test << " : valid" << std::endl;

	}

	else
	{
		std::cout << test << " : invalid" << std::endl;
	}
}

bool isValid(std::string input) {
	std::stack<char> charStack;

	if (input.empty()) {


		std::cout << "empty string";
		return true;
	}

	for (int i = 0; i < input.length(); i++) {
		if (input.at(i) == '(' || input.at(i) == '{' || input.at(i) == '[') {
			charStack.push(input.at(i));
		}
		else
		{
			if (input.at(i) == ')' && charStack.top() == '(') {
				charStack.pop();
			} 
			else if (input.at(i) == '}' &&  charStack.top() == '{') {
				charStack.pop();
			} 
			else if(input.at(i) == ']' && charStack.top() == '[') {
				charStack.pop();
			}
			else
			{
				return false;
			}
		}
	}
	
	if (charStack.empty())
		return true;


	return false;
}

