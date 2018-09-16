#include "RedBlackNode.h"



RedBlackNode::RedBlackNode()
{
	key = -1;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
	color = BLACK;
}

RedBlackNode::RedBlackNode(int newKey, RedBlackNode * newParent, RedBlackNode_Color newColor,  RedBlackNode* const nullLeafPtr) {
	this->key = newKey;
	parent = newParent;
	left = nullLeafPtr;
	right = nullLeafPtr;
	color = newColor;
}

RedBlackNode::RedBlackNode(const RedBlackNode & otherNode)
{
	this->key = otherNode.key;
	this->parent = otherNode.parent;
	this->left = otherNode.left;
	this->right = otherNode.right;
	this->color = otherNode.color;
}


RedBlackNode::~RedBlackNode()
{
	
	//delete left;
	//delete right;
}

int RedBlackNode::getKey() {
	return this->key;
}

void RedBlackNode::setKey(int newKey) {
	this->key = newKey;
}




RedBlackNode* RedBlackNode::getParent() {
	return this->parent;
}

RedBlackNode * RedBlackNode::getLeft()
{
	return left;
}

void RedBlackNode::setLeft(RedBlackNode * newLeft)
{
	this->left = newLeft;
}

RedBlackNode * RedBlackNode::getRight()
{
	return right;
}

void RedBlackNode::setRight(RedBlackNode * newRight)
{
	this->right = newRight;
}

RedBlackNode_Color RedBlackNode::getColor()
{
	return this->color;
}

void RedBlackNode::setColor(RedBlackNode_Color newColor)
{
	this->color = newColor;
}

void RedBlackNode::setParent(RedBlackNode * newParent) {
	this->parent = newParent;
}



