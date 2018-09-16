#include "Main.h"
#include "LinkedList.h"
#include <iostream>

Main::Main()
{
}


Main::~Main()
{
}

int main() {
	LinkedList list;
	for (int i = 0; i < 10; i++)
	{
		list.addToTail(i);
	}

	list.print();

	Node* node;
	int k = 3;
	int i = 0;
	node = list.returnKthELement(list.getHead(), k, i);

	

	system("pause");
	return 0;

}
