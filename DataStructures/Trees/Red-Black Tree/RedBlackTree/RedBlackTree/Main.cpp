#include "Main.h"
#include <iostream>
#include "RedBlackTree.h"

Main::Main()
{
}


Main::~Main()
{
}

int main() {
	RedBlackTree rbTree;

	rbTree.insert(41);
	rbTree.insert(38);
	rbTree.insert(31);
	rbTree.insert(12);
	rbTree.insert(19);
	rbTree.insert(8);

	//rbTree.RB_Tree_Delete(12);

	rbTree.print();
	system("pause");
	return 0;
}