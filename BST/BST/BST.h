#pragma once
#ifndef BST_H
#define BST_H

#include "BinaryTreeNode.h"
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

template <class T>
class BST
{
protected:
	BinaryTreeNode< T>* root;

public:
	BST();
	BST(BinaryTreeNode <T>*);
	BST( BST&);
	
	~BST();
	void BSTDestructor(BinaryTreeNode <T>*);
	BinaryTreeNode <T>* getRoot();
	void setRoot(BinaryTreeNode <T>* newRoot);
	virtual void insert(T data);
	BinaryTreeNode<T>* remove(T data, BinaryTreeNode<T>*);
	BinaryTreeNode<T>* getMin(BinaryTreeNode<T>*);
	void inOrderPrint(BinaryTreeNode <T>*);

	std::string postOrderPrint(BinaryTreeNode <T>*);
	std::string preOrderPrint(BinaryTreeNode <T>*);

	int getDepth(BinaryTreeNode<T> *);
	bool isBalanced(BinaryTreeNode<T>*);
};



#include "BST.CPP"

#endif // !BST_H


