// ReadFromStream.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct TreeNode
{
	int data;
	int numOfNodeLessThan;
	TreeNode * left;
	TreeNode * right;

	TreeNode() {
		data = 0;
		numOfNodeLessThan = 0;
		left = nullptr;
		right = nullptr;
	}

	TreeNode(const int &newData) {
		data = newData;
		numOfNodeLessThan = 0;
		left = nullptr;
		right = nullptr;
	}
	void setnumOfNodeLessThan(const int &newSize) {
		numOfNodeLessThan = newSize;
	}
	int getnumOfNodeLessThan() {
		return numOfNodeLessThan;
	}
	void setLeft(TreeNode * newLeft) {
		left = newLeft;
	}
	TreeNode * getLeft() {
		return left;
	}
	void setRight(TreeNode * newRight) {
		right = newRight;
	}
	TreeNode * getRight() {
		return right;
	}
	int getData() {
		return data;
	}
	void setData(const int &newData) {
		data = newData;
	}
};
class Tree {
	TreeNode * root;

public:
	Tree() {
		root = nullptr;
	}
	void setRoot(TreeNode * newRoot) {
		root = newRoot;
	}
	TreeNode * getRoot() {
		return root;
	}
	void inorderPrint(TreeNode * node) {
		if (node->getLeft()) {
			inorderPrint(node->getLeft());
		}
		std::cout << node->getData() << "  ";
		if (node->getRight()) {
			inorderPrint(node->getRight());
		}
	}

	void insert(TreeNode * insertNode) {
		insert(root, insertNode);
	}
	//return -1 if empty tree
	//return -2 if node is not found
	int getLessThanCount(TreeNode * node, const int & target) {
		int rank = 0;
		int tempNum = 0;
		if (!root)
			return (-1);
		else
		{
			if (node->getData() == target) {
				rank = node->getnumOfNodeLessThan();
				return rank;
			}
			if (node->getData() < target) {
				if (node->getRight()) {
					rank = node->getnumOfNodeLessThan()+1;
					tempNum = getLessThanCount(node->getRight(), target);
					if (tempNum != -2) {
						rank += tempNum;
					}
					else
					{
						rank = -2;
					}
					return rank;
				}
			}
			else
			{
				if (node->getLeft()) {
					tempNum = getLessThanCount(node->getLeft(), target);
					if (tempNum != -2) {
						rank += tempNum;
					}
					else
					{
						rank = -2;
					}
					return rank;
				}
			}
		}
		return (-2);
	}

	void insert(TreeNode * treeNode, TreeNode * insertNode) {

		if (!root) {
			root = insertNode;
		}
		else
		{
			if (treeNode->getData() < insertNode->getData()) {
				if (treeNode->getRight()) {
					insert(treeNode->getRight(), insertNode);
				}
				else
				{
					treeNode->setRight(insertNode);
				}
			}
			else
			{
				treeNode->setnumOfNodeLessThan(treeNode->getnumOfNodeLessThan() + 1);
				if (treeNode->getLeft()) {
					insert(treeNode->getLeft(), insertNode);
				}
				else
				{
					treeNode->setLeft(insertNode);
				}
			}
		}
	}

};




int findRank( Tree &t, const int &target) {
	int rank = 0;
	
	rank = t.getLessThanCount(t.getRoot(), target);

	
	 return rank;
}

int main()
{
	Tree t;
	TreeNode * rootNode = new TreeNode(5);
	TreeNode * node = new TreeNode(1);
	TreeNode * node1 = new TreeNode(4);
	TreeNode * node7 = new TreeNode(4);
	TreeNode * node2 = new TreeNode(5);
	TreeNode * node3 = new TreeNode(9);
	TreeNode * node4 = new TreeNode(7);
	TreeNode * node5 = new TreeNode(13);
	TreeNode * node6 = new TreeNode(3);



	t.insert(rootNode);
	t.insert(node);
	t.insert(node1);
	t.insert(node7);
	t.insert(node2);
	t.insert(node3);
	t.insert(node4);
	t.insert(node5);
	t.insert(node6);
	

	std::cout << " rank for 1:  " << findRank(t, 1) << std::endl;
	std::cout << " rank for 4:  " << findRank(t, 4) << std::endl;
	std::cout << " rank for 5:  " << findRank(t, 5) << std::endl;
	std::cout << " rank for 3:  " << findRank(t, 3) << std::endl;
	std::cout << " rank for 9:  " << findRank(t, 9) << std::endl;
	std::cout << " rank for 13:  " << findRank(t, 13) << std::endl;
	std::cout << " rank for 7:  " << findRank(t, 7) << std::endl;
	std::cout << " rank for 7:  " << findRank(t, 77) << std::endl;

	t.inorderPrint(t.getRoot());
	system("pause");
    return 0;
}

