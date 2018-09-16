#include "main.h"
#include "LinkedList.h"
#include <iostream>


main::main()
{
}


main::~main()
{
}


int main() {
	LinkedList list;
	for (int i = 0; i < 10; i++)
	{
		list.addToTail(i / 2);
	}

	list.print();

	
	//list.removeDup();
	list.removeDupNoBuff();

	list.print();
	

	system("pause");
	return 0;
}