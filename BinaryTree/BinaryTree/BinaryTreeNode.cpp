#include "BinaryTreeNode.h"



BinaryTreeNode::BinaryTreeNode()
{
	data = 0;
	left = nullptr;
	right = nullptr;
}


BinaryTreeNode::~BinaryTreeNode()
{
	delete left;
	delete right;
	
}

BinaryTreeNode::BinaryTreeNode(int newData)
{
	this->data = newData;
	this->left = nullptr;
	this->right = nullptr;
}

BinaryTreeNode::BinaryTreeNode(const BinaryTreeNode & copyNode)
{
	this->data = copyNode.data;
	this->right = copyNode.right;
	this->left = copyNode.left;
}

BinaryTreeNode * BinaryTreeNode::getLeft()
{
	return this->left;
}

BinaryTreeNode * BinaryTreeNode::getRight()
{
	return this->right;
}

BinaryTreeNode * BinaryTreeNode::getParent()
{
	return parent;
}

int BinaryTreeNode::getData()
{
	return this->data;
}

void BinaryTreeNode::setLeft(BinaryTreeNode * newLeft)
{
	this->left = newLeft;
}

void BinaryTreeNode::setRight(BinaryTreeNode * newRight)
{
	this->right = newRight;
}

void BinaryTreeNode::setParent(BinaryTreeNode * newParent)
{
	this->parent = newParent;
}

void BinaryTreeNode::setData(int newData)
{
	this->data = newData;
}

int BinaryTreeNode::getDepth(BinaryTreeNode* node)
{
	int depth = 0;
	while (node != nullptr) {
		node = node->getParent();
		depth++;
	}
	return depth;
}
