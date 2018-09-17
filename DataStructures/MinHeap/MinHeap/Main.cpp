#include "Main.h"
#include <iostream>
#include "ArrayMinHeap.h"


Main::Main()
{
}


Main::~Main()
{
}

int main() {

	MinBinaryHeap<int> * heap = new MinBinaryHeap<int>();

	//heap->insert(5);
	//heap->insert(7);
	//heap->insert(10);
	//heap->insert(2);
	//heap->inOrderPrint(heap->getRoot());

	ArrayMinHeap<BinaryTreeNode<int>> *k = new ArrayMinHeap<BinaryTreeNode<int>>();

	for (int i = 4; i > 0; i--)
	{
		k->insert(i);
	}

	k->Print();
	system("pause");

	return 0;
}