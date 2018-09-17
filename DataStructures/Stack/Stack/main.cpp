#include "main.h"
#include <iostream>
#include "Stack.h"

main::main()
{
}


main::~main()
{
}

int main() {

	int* intPtr;

	intPtr = nullptr;

	delete intPtr;
	system("pause");
	int number;
	number = NULL;

	//Stack<int> a(6);
	//Stack<int> b;
	//a.push(6);	
	//a.print();
	//std::cout << std::endl;
	//a.push(7);
	//a.print();
	//std::cout << std::endl;
	//a.pop();
	//a.print();


	Stack<char> a = *(new Stack<char>());

	a.setCap(5);

	a.push('t');
	a.push('a');
	a.push('c');

	a.pop();
	a.pop();
	a.pop();


	system("pause");
}