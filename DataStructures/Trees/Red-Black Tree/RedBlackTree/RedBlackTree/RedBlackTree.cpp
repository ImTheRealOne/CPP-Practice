#include "RedBlackTree.h"



RedBlackTree::RedBlackTree()
{
	sentinelNullLeafPtr = new RedBlackNode(-1, sentinelNullLeafPtr, RedBlackNode_Color::BLACK, sentinelNullLeafPtr);
	root = sentinelNullLeafPtr;
}


RedBlackTree::~RedBlackTree()
{
	delete root;
}

void RedBlackTree::setRoot(RedBlackNode * newRoot) {
	this->root = newRoot;
}

void RedBlackTree::leftRotate(RedBlackNode * currNode) {
	RedBlackNode * rightNodeofCurrNode = currNode->getRight();
	//set currNode's right subtree to the left subtree of the right node
	//sever the pointers and reattached them to the proper parents
	currNode->setRight(rightNodeofCurrNode->getLeft());
	if (rightNodeofCurrNode->getLeft() != sentinelNullLeafPtr) {
		rightNodeofCurrNode->getLeft()->setParent(currNode);
	}
	rightNodeofCurrNode->setParent(currNode->getParent());

	//if the parent of curr node is root then set the new root to the right node of currNode
	//check if currNode is left or right child of parent then set the right subtree back to the parent node properly
	if (currNode->getParent() == sentinelNullLeafPtr) {
		setRoot(rightNodeofCurrNode);
	}
	else if (currNode == currNode->getParent()->getLeft()) {
		currNode->getParent()->setLeft(rightNodeofCurrNode);
	}
	else
	{
		currNode->getParent()->setRight(rightNodeofCurrNode);
	}
	rightNodeofCurrNode->setLeft(currNode);
	currNode->setParent(rightNodeofCurrNode);

}

void RedBlackTree::rightRotate(RedBlackNode * currNode) {
	//set currNode's left subtree to the right subtree of the left node
	//sever the pointers and reattached them to the proper parents
	RedBlackNode* leftNodeofCurrNode = currNode->getLeft();
	currNode->setLeft(leftNodeofCurrNode->getRight());
	if (leftNodeofCurrNode->getRight() != sentinelNullLeafPtr) {
		leftNodeofCurrNode->getRight()->setParent(currNode);
	}
	leftNodeofCurrNode->setParent(currNode->getParent());
	//if the parent of curr node is root then set the new root to the right node of currNode
	//check if currNode is left or right child of parent then set the right subtree back to the parent node properly
	if (currNode->getParent() == sentinelNullLeafPtr) {
		setRoot(leftNodeofCurrNode);
	}
	else if (currNode == currNode->getParent()->getRight()) {
		currNode->getParent()->setRight(leftNodeofCurrNode);
	}
	else {
		currNode->getParent()->setLeft(leftNodeofCurrNode);
	}
	leftNodeofCurrNode->setRight(currNode);
	currNode->setParent(leftNodeofCurrNode);
}

void RedBlackTree::insert(int newValue) {
	RedBlackNode * newNode = new RedBlackNode(newValue, sentinelNullLeafPtr, RedBlackNode_Color::RED, sentinelNullLeafPtr);
	RedBlackNode * parentOfWalker = sentinelNullLeafPtr;
	RedBlackNode * walker = root;
	//walk down the tree to the correct place to insert newNode
	while (walker != sentinelNullLeafPtr) {
		parentOfWalker = walker;
		if (newNode->getKey() < walker->getKey()) {
			walker = walker->getLeft();
		}
		else
		{
			walker = walker->getRight();
		}
	}
	
	newNode->setParent(parentOfWalker);
	if (parentOfWalker == sentinelNullLeafPtr) {
		setRoot(newNode);
	}
	else if (newNode->getKey() < parentOfWalker->getKey()) {
		parentOfWalker->setLeft(newNode);
	}
	else
	{
		parentOfWalker->setRight(newNode);
	}
	newNode->setLeft(sentinelNullLeafPtr);
	newNode->setRight(sentinelNullLeafPtr);
	newNode->setColor(RedBlackNode_Color::RED);
	insert_FixUP(newNode);
}

void RedBlackTree::insert_FixUP(RedBlackNode * node) {


	while (node->getParent()->getColor() == RedBlackNode_Color::RED) {
		if (node->getParent() == node->getParent()->getParent()->getLeft()) {
			RedBlackNode * rightNodeofGrandparent = node->getParent()->getParent()->getRight();
			if (rightNodeofGrandparent->getColor() == RedBlackNode_Color::RED) {
				node->getParent()->setColor(RedBlackNode_Color::BLACK);
				rightNodeofGrandparent->setColor(RedBlackNode_Color::BLACK);
				node->getParent()->getParent()->setColor(RedBlackNode_Color::RED);
				node = node->getParent()->getParent();
			}
			else {
				if (node == node->getParent()->getRight()) {
								node = node->getParent();
								leftRotate(node);
					}
				node->getParent()->setColor(RedBlackNode_Color::BLACK);
				node->getParent()->getParent()->setColor(RedBlackNode_Color::RED);
				rightRotate(node->getParent()->getParent());
			}
		}
		else {
			RedBlackNode * leftNodeofGrandParent = node->getParent()->getParent()->getLeft();
			if (leftNodeofGrandParent->getKey() == RED) {
				node->getParent()->setColor(RedBlackNode_Color::BLACK);
				leftNodeofGrandParent->setColor(RedBlackNode_Color::BLACK);
				node->getParent()->getParent()->setColor(RedBlackNode_Color::RED);
				node = node->getParent()->getParent();
			}
			else {
				if (node == node->getParent()->getRight()) {
					node = node->getParent();
					rightRotate(node);
				}
				node->getParent()->setColor(RedBlackNode_Color::BLACK);
				node->getParent()->getParent()->setColor(RedBlackNode_Color::RED);
				leftRotate(node->getParent()->getParent());
			}
		}
	}
	this->root->setColor(RedBlackNode_Color::BLACK);
}

void RedBlackTree::print() {
	print(this->root);
}

void RedBlackTree::print(RedBlackNode * node) {
	if (node->getLeft() != sentinelNullLeafPtr) {
		print(node->getLeft());
	}
	std::cout << " node : " << node->getKey() << " , ";
	((node->getColor() == RedBlackNode_Color::RED) ? std::cout << " RED   " : std::cout << " BLACK   ");

	if (node->getRight() != sentinelNullLeafPtr) {
		print(node->getRight());
	}
}

RedBlackNode * RedBlackTree::getMin(RedBlackNode * node) {
	if (node->getLeft()) {
		getMin(node);
	}
	return node;
}

RedBlackNode * RedBlackTree::findNode(int target, RedBlackNode * node) {
	if (node->getKey() == target) {
		return node;
	}
	else if (node->getKey() > target) {
		if (node->getLeft() != sentinelNullLeafPtr)
			findNode(target, node->getLeft());
		else
		{
			return sentinelNullLeafPtr;
		}
	}
	else
	{
		if (node->getRight() != sentinelNullLeafPtr)
			findNode(target, node->getRight());
		else
		{
			return sentinelNullLeafPtr;
		}
	}
}

void RedBlackTree::RB_Tree_Delete(int target) {
	deleteNode(findNode(target, this->root));
}

void RedBlackTree::transPlant(RedBlackNode * u, RedBlackNode * v) {
	if (u->getParent() == sentinelNullLeafPtr) {
		this->root = v;
	}
	else if (u == u->getParent()->getLeft()) {
		u->getParent()->setLeft(v);
	}
	else
	{
		u->getParent()->setRight(v);
		v->setParent(u->getParent());
	}
}

void RedBlackTree::deleteNode(RedBlackNode * targetNode) {

	if (targetNode == sentinelNullLeafPtr) {
		std::cout << " target not in tree ";
		return;
	}
	RedBlackNode * tempNodePtr = targetNode;
	RedBlackNode * tempNodePtr2;
	RedBlackNode_Color tempNodePtr_color = tempNodePtr->getColor();
	
	if (targetNode->getLeft() == sentinelNullLeafPtr) {
		 tempNodePtr2 = targetNode->getRight();
		transPlant(targetNode, targetNode->getRight());
	}
	else if (targetNode->getRight() == sentinelNullLeafPtr) {
		tempNodePtr2 = targetNode->getLeft();
		transPlant(targetNode, targetNode->getLeft());
	}
	else
	{
		tempNodePtr = getMin(targetNode->getRight());
		tempNodePtr_color = tempNodePtr->getColor();
		 tempNodePtr2 = tempNodePtr->getRight();
		if (tempNodePtr->getParent() == targetNode) {
			tempNodePtr2->setParent(tempNodePtr);
		}
		else
		{
			transPlant(tempNodePtr, tempNodePtr->getRight());
			tempNodePtr->setRight(targetNode->getRight());
			tempNodePtr->getRight()->setParent(tempNodePtr);
		}
		transPlant(targetNode, tempNodePtr);
		tempNodePtr->setLeft(targetNode->getLeft());
		tempNodePtr->getLeft()->setParent(tempNodePtr);
		tempNodePtr->setColor(targetNode->getColor());
	}
	
	if (tempNodePtr_color == BLACK)
		deleteNode_Fix_Up(tempNodePtr2);
}

void RedBlackTree::deleteNode_Fix_Up(RedBlackNode * node) {
	RedBlackNode * tempNodePtr;
	while (node != this->root && node->getColor() == RedBlackNode_Color::BLACK) {
		if (node == node->getParent()->getLeft()) {
			tempNodePtr = node->getParent()->getRight();
			if (tempNodePtr->getColor() == RedBlackNode_Color::RED) {
				tempNodePtr->setColor(RedBlackNode_Color::BLACK);
				node->getParent()->setColor(RedBlackNode_Color::RED);
				leftRotate(node->getParent());
				tempNodePtr = node->getParent()->getRight();
			}
			if (tempNodePtr->getLeft()->getColor() == RedBlackNode_Color::BLACK
				&& tempNodePtr->getRight()->getColor() == RedBlackNode_Color::BLACK) {
				tempNodePtr->setColor(RedBlackNode_Color::RED);
				node = node->getParent();
			}
			else
			{
				if (tempNodePtr->getRight()->getColor() == RedBlackNode_Color::BLACK) {
					tempNodePtr->getLeft()->setColor(RedBlackNode_Color::BLACK);
					tempNodePtr->setColor(RedBlackNode_Color::RED);
					rightRotate(tempNodePtr);
					tempNodePtr = node->getParent()->getRight();
				}
				tempNodePtr->setColor(node->getParent()->getColor());
				node->getParent()->setColor(RedBlackNode_Color::BLACK);
				tempNodePtr->getRight()->setColor(RedBlackNode_Color::BLACK);
				leftRotate(node->getParent());
				node = this->root;
			}
		}
		else
		{
			tempNodePtr = node->getParent()->getLeft();
			if (tempNodePtr->getColor() == RedBlackNode_Color::RED) {
				tempNodePtr->setColor(RedBlackNode_Color::BLACK);
				node->getParent()->setColor(RedBlackNode_Color::RED);
				rightRotate(node->getParent());
				tempNodePtr = node->getParent()->getLeft();
			}
			if (tempNodePtr->getRight()->getColor() == RedBlackNode_Color::BLACK
				&& tempNodePtr->getLeft()->getColor() == RedBlackNode_Color::BLACK) {
				tempNodePtr->setColor(RedBlackNode_Color::RED);
				node = node->getParent();
			}
			else
			{
				if (tempNodePtr->getLeft()->getColor() == RedBlackNode_Color::BLACK) {
					tempNodePtr->getRight()->setColor(RedBlackNode_Color::BLACK);
					tempNodePtr->setColor(RedBlackNode_Color::RED);
					leftRotate(tempNodePtr);
					tempNodePtr = node->getParent()->getLeft();
				}
				tempNodePtr->setColor(node->getParent()->getColor());
				node->getParent()->setColor(RedBlackNode_Color::BLACK);
				tempNodePtr->getLeft()->setColor(RedBlackNode_Color::BLACK);
				rightRotate(node->getParent());
				node = this->root;
			}
		
		}
	}
	node->setColor(RedBlackNode_Color::BLACK);
}