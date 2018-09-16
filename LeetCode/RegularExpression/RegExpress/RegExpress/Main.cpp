#include "Main.h"
#include <iostream>
#include <string>

Main::Main()
{
}


Main::~Main()
{
}

bool Equals(std::string one, std::string two);
void print(std::string one, std::string two);
int main()
{
	std::string one = "aa";
	std::string two = "a";
	
	print(one, two);

	one = "aabb";
	two = "aabb";
	print(one, two);

	one = "aaa";
	two = "aa";

	print(one, two);

	one = "aaa";
	two = "a*";
	print(one, two);

	one = "aa";
	two = ".*";
	print(one, two);

	one = "ab";
	two = ".*";
	print(one, two);

	one = "aab";
	two = "c*a*b";
	print(one, two);

	one = "acabcde";
	two = "ac.*e";
	print(one, two);

		
	system("pause");
	return 0;
}
void print(std::string one, std::string two) {
	if (Equals(one, two)) {
		std::cout << one << "   ==    " << two << "    :    " << "true" << std::endl;
	}
	else
	{
		std::cout << one << "   ==    " << two << "    :   " << "false" << std::endl;
	}

}
bool Equals(std::string one, std::string two) {

	while (one.length() >0 && two.length() >0) {
		
		char twoEndChar = two.at(two.length() - 1);
		char oneEndChar = one.at(one.length() - 1);
		if (twoEndChar == '*') {
			if (two.length() > 1) {
				if (two.at(two.length() - 2) == '.') {			//checking for .* 
					if (two.size() > 2) {
						std::size_t found = one.find(two.at(two.length() - 3));
						if ( found != std::string::npos	) {
							while (one.length() != found+1)
								one.pop_back();
						}
						else
						{
							return false;
						}

					
						two.pop_back();
						two.pop_back();
					}
					else
					{
						return true;
					}
				}
				else							// checking for repeated previous char of two
				{
					while (one.length() > 0 && two.at(two.length() - 2) == one.at(one.length()-1)) {
						
											one.pop_back();
										
					}
					two.pop_back();
					two.pop_back();
				}
			}

		}
		else if (twoEndChar == '.') {
			one.pop_back();
			two.pop_back();
		}
		else
		{
			if (oneEndChar == twoEndChar) {
				one.pop_back();
				two.pop_back();
			}
			else
			{
				return false;
			}
		}


	}
	if(two.length() > 0)
	{
		while (two.length() > 0 && two.back() == '*') {
			two.pop_back();
			if (two.empty())
				return false;
			two.pop_back();
		}
	}

		if (one.length() == two.length()) {
			return true;
		}

		


	
	return false;
}
