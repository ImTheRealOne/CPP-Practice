#include "Main.h"
#include <iostream>



Main::Main()
{
}


Main::~Main()
{
}

BinaryTreeNode * commonAncestor( BinaryTreeNode a, BinaryTreeNode b);

void containsRoot(BinaryTreeNode * Tree1RootNode, BinaryTreeNode * Tree2RootNode);

bool compareSubTree(BinaryTreeNode * T1Node, BinaryTreeNode * T2Node);

int main()
{
	BinaryTree Tree;

	Tree.insert(6);
	Tree.insert(10);
	Tree.insert(14);
	Tree.insert(8);
	Tree.insert(3);
	Tree.insert(5);
	Tree.insert(7);
	Tree.insert(10);

	Tree.print(Tree.getRoot());

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	BinaryTree Tree2;

	Tree2.insert(6);
	Tree2.insert(10);
	Tree2.insert(13);

	Tree2.print(Tree2.getRoot());

	containsRoot(Tree.getRoot(), Tree2.getRoot());

	system("pause");
	return 0;

	
}

BinaryTreeNode * commonAncestor( BinaryTreeNode a, BinaryTreeNode b) {


	return nullptr;
}

void containsRoot(BinaryTreeNode * T1Node, BinaryTreeNode * searchNode) {
	if (T1Node->getData() != searchNode->getData()) {
		if (T1Node->getLeft())
			containsRoot(T1Node->getLeft(), searchNode);
		if (T1Node->getRight())
			containsRoot(T1Node->getRight(), searchNode);
	}
	if (T1Node->getData() == searchNode->getData()) {
		if (compareSubTree(T1Node, searchNode))
			std::cout << "Yes" << std::endl;
		else
			std::cout << "NO";
	}
}


bool compareSubTree(BinaryTreeNode * T1Node, BinaryTreeNode * T2Node){
	if (!T1Node && !T2Node)
		return true;
	else if (!T2Node)
		return true;
	else if(!T1Node)
		return false;
	if (T1Node->getData() != T2Node->getData())
		return false;
	else if (T1Node->getData() == T2Node->getData()) {
		return compareSubTree(T1Node->getLeft(), T2Node->getLeft()) && 
						compareSubTree(T1Node->getRight(), T2Node->getRight());
	}

}
