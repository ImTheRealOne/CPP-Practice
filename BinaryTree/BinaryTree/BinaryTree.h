#pragma once
#include "BinaryTreeNode.h"
#include <string>
#include <vector>
#include <queue>
#include <iostream>
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	BinaryTree(const BinaryTree &);
	void insert(int data);
	void remove();
	
	void print(BinaryTreeNode * );
	std::string itob(int num);
	BinaryTreeNode * getRoot();

private:
	BinaryTreeNode * root;
	int size = 0;
};

