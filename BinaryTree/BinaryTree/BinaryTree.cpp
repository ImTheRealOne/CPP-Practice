#include "BinaryTree.h"


BinaryTree::BinaryTree()
{
	this->root = nullptr;
	size = 0;
}


BinaryTree::~BinaryTree()
{
	delete root;
}

BinaryTree::BinaryTree(const BinaryTree & copyTree)
{

}

void BinaryTree::insert(int data)
{
	size++;
	std::string location = itob(size);
	BinaryTreeNode * newNode = new BinaryTreeNode(data);
	BinaryTreeNode * walker = root;
	if (size == 1) {
		root = newNode;
	}
	else
	{
		location = location.substr(1, location.size());
		for (auto& it : location) {
			if (it == '1') {
				if (walker->getRight()) {
					walker = walker->getRight();
				}
				else
				{
					newNode->setParent(walker);
					walker->setRight(newNode);
				}

			}
			else
			{
				if (walker->getLeft()) {
					walker = walker->getLeft();
				}
				else
				{
					newNode->setParent(walker);
					walker->setLeft(newNode);
				}
			}
		}
	}
}



void BinaryTree::print(BinaryTreeNode * node)
{
	if (!node)
		return;
	std::cout<<node->getData() << " " ;
	print(node->getLeft());
	print(node->getRight());

}

std::string BinaryTree::itob(int num) {
	std::string result = "";
	while (num > 0) {
		result += (num % 2 == 0) ? "0" : "1";
		num = num / 2;
	}
	std::reverse(result.begin(), result.end());
	return result;
}

BinaryTreeNode * BinaryTree::getRoot()
{
	return root;
}

