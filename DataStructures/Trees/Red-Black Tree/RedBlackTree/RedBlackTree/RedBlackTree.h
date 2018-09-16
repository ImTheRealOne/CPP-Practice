#pragma once
#include "RedBlackNode.h"
#include <iostream>
class RedBlackTree
{
public:
	RedBlackTree();
	~RedBlackTree();
	void setRoot(RedBlackNode * newRoot);
	void leftRotate(RedBlackNode * node);
	void rightRotate(RedBlackNode * node);
	void insert(int newValue);
	void insert_FixUP(RedBlackNode * node);
	void print();
	void print(RedBlackNode * node);
	void transPlant(RedBlackNode * u, RedBlackNode * v);
	void RB_Tree_Delete(int);
	void deleteNode(RedBlackNode * targetNode);
	void deleteNode_Fix_Up(RedBlackNode * node);
	RedBlackNode * getMin(RedBlackNode * node);
	RedBlackNode * findNode(int target, RedBlackNode * node);
private:
	 RedBlackNode * root;
	 RedBlackNode * sentinelNullLeafPtr;
};

