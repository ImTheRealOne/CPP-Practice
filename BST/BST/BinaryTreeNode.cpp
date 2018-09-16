#ifndef BINARYTREENODE_CPP
#define BINARYTREENODE_CPP



#include "BinaryTreeNode.h"



template <class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
	data = 0;
	left = nullptr;
	right = nullptr;
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(T newData)
{
	data = newData;
	left = nullptr;
	right = nullptr;
}

template <class T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
	

		std::cout << "node destruct : " << this->getData()<<"   ";

	delete left;
	delete right;
	left = nullptr;
	right = nullptr;

		
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const BinaryTreeNode<T>& otherNode) 
{
	this->setData(otherNode.getData());
	this->setLeft(otherNode.getLeft());
	this->setRight(otherNode.getRight());
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode( BinaryTreeNode<T>*&  otherNode)
{
	this->setData(otherNode->getData());
	this->setLeft(otherNode->getLeft());
	this->setRight(otherNode->getRight());
}



template <class T>
T BinaryTreeNode<T>::getData() const {

	return this->data;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getParent() const {
	return parent;
}

template <class T>
void BinaryTreeNode<T>::setParent(BinaryTreeNode<T>* newParentNode) {
	parent = newParentNode;
}

template <class T>
void BinaryTreeNode<T>::setData(T newData) {

	data = newData;
}

template<class T>
void BinaryTreeNode<T>::setLeft(BinaryTreeNode<T>* newLeft) {
	left = newLeft;
}

template<class T>
void BinaryTreeNode<T>::setRight(BinaryTreeNode<T>* newRight) {
	right = newRight;
}

template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeft() const {
	if(left)
		return left;
	else
		return nullptr;
}

template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRight() const {
	if(right)
		return right;
	else
		return nullptr;
}

template<class T>
void BinaryTreeNode<T>::print()
{
	std::cout << this->data;
}

#endif // !BINARYTREENODE_CPP
