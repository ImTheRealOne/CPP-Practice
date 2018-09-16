#include "Main.h"
#include <iostream>
#include "LinkedList.h"
#include "Node.h"



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
	Node* temp;
	temp = new Node(5, nullptr);

	for (int i = 0; i < list.getLength(); i++)
	{
		list.deleteMiddleNode(temp);
	}

	list.print();

	
	system("pause");

	return 0;
}