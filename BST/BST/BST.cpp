#ifndef BST_CPP
#define BST_CPP
#include "BST.h"


template <class T>
BST<T>::BST()
{
	root = nullptr;
	
}

template<class T>
BST<T>::BST( BST & otherTree)
{
	root = otherTree.getRoot();
}

template <class T>
BST<T>::~BST()
{
	delete root;
	//BSTDestructor(root);
}

template<class T>
void BST<T>::BSTDestructor(BinaryTreeNode <T>* currNode)
{
	std::cout << "BST destructor" << std::endl;
	if (currNode != nullptr) {
		if (currNode->getLeft())
			BSTDestructor(currNode->getLeft());
		if (currNode->getRight())
			BSTDestructor(currNode->getRight());
		//std::cout << "curr NOde " << currNode->getData();
		if (currNode != nullptr) {
			delete currNode;
		}
		
		currNode = nullptr;
	}
	return;
}


template <class T>
BinaryTreeNode <T>* BST<T>::getRoot() {
	return root;
}

template<class T>
void BST<T>::setRoot(BinaryTreeNode <T>*  newRoot)
{
	root = (newRoot);
}

template <class T>
 void BST<T>::insert(T data) {
	 std::cout << "tree insert" << std::endl;
	BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(data);
	BinaryTreeNode<T>* walker = root;
	if (!root) {
		root = newNode;
	}
	while (walker) {
		if (walker->getData() > data) {
			if (walker->getLeft() ){
				walker = walker->getLeft();
			}
			else {
				walker->setLeft(newNode);
				return;
			}
			
		}
		else
		{
			if (walker->getRight()) {
				walker = walker->getRight();
			}
			else
			{
				walker->setRight(newNode);
				return;
			}
		}
	}

}

template <class T>
void BST<T>::inOrderPrint(BinaryTreeNode <T>* node) {
	if(!node)
		return;
	inOrderPrint(node->getLeft());
	std::cout << node->getData() << " ";
	inOrderPrint(node->getRight());

}


template <class T>
BinaryTreeNode<T>* BST<T>::remove(T target, BinaryTreeNode<T>* node) {
	if (!node)
		return node;
	if (node->getData() > target) {
		node->setLeft(remove(target, node->getLeft()));
	}
	else if (node->getData() < target) {
		node->setRight(remove(target, node->getRight()));
	}
	else
	{
		//node only has left child
		if (!node->getRight()) {		
			BinaryTreeNode<T>* tempNode = node->getLeft();
			delete node;
			return tempNode;
		}
		//node only has right child
		else if (!node->getLeft()) {
			BinaryTreeNode<T>* tempNode = node->getRight();
			delete node;
			return tempNode;
		}
		//node has two child
		BinaryTreeNode<T>* minNode = getMin(node->getRight());

		node->setData(minNode->getData());

		node->setRight(remove(minNode->getData(), node->getRight()));

	}
	return node;
}

template <class T>
BinaryTreeNode<T>* BST<T>::getMin(BinaryTreeNode<T>* node) {
	if (!node)
		return node;
	BinaryTreeNode<T>* walker = node;
	while (walker->getLeft()) {
		walker = walker->getLeft();
	}
	return walker;
}




template <class T>
std::string BST<T>::postOrderPrint(BinaryTreeNode <T>* node) {
	if (!node) 
		return "";

	return ("" + postOrderPrint(node->getLeft()) + postOrderPrint(node->getRight()) + std::to_string(node->getData()) +" ");
}

template <class T>
std::string  BST<T>::preOrderPrint(BinaryTreeNode <T>* node) {
	if (!node) 
		return "empty";

	return "" + std::to_string(node->getData())+ preOrderPrint(node->getRight()) + preOrderPrint(node->getLeft()) + " ";
}

template <class T>
int BST<T>::getDepth(BinaryTreeNode<T>* node) {

	if (!node)
		return 0;
	std::cout << " node " << node->getData() << std::endl;
	return std::max(1+getDepth(node->getLeft()), 1+getDepth(node->getRight()));
}

template<class T>
bool BST<T>::isBalanced(BinaryTreeNode<T>* node)
{
	if (!node)
		return true;
	if (std::abs(getDepth(node->getLeft()) - getDepth(node->getRight()) < 2))
		return true && isBalanced(node->getLeft()) && isBalanced(node->getRight());
	return false;
}


#endif // !BST_CPP

