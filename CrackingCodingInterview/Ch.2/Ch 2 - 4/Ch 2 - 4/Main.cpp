#include "Main.h"
#include <iostream>
#include "LinkedList.h"


Main::Main()
{
}


Main::~Main()
{
}

int main() {
	LinkedList one;
	LinkedList two;

	one.addToTail(7);
	one.addToTail(1);
	one.addToTail(6);

	two.addToTail(5);
	two.addToTail(9);
	two.addToTail(2);



	system("pause");
	return 0;
}