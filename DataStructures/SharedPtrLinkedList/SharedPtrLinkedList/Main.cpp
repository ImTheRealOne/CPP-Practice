#include "Main.h"
#include "SharedPtrLinkedList.h"
#include <iostream>

using std::cout;
using std::endl;
Main::Main()
{
}


Main::~Main()
{
}

int main() {
	SharedPtrLinkedList a,b;
	a.addToTail(3);
	a.addToTail(23);

	b.addToTail(2);
	
	cout << "a" << endl;

	std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> c (new SharedPtrLinkedList::SharedPtrNode(4));
	cout << "b" << endl;
	a.print();
	b.print();
	a.addToTail(c);
	cout << "c" << endl;
	b.addToTail(c);

	a.print();
	b.print();

	
	system("pause");
	return 0;
}

