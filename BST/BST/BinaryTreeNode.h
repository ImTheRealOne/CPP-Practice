#pragma once
#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H


#include <iostream>
#include <string>

template <class T>
class BinaryTreeNode
{
private:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
	BinaryTreeNode<T>* parent;
public:
	BinaryTreeNode();
	BinaryTreeNode(T);
	~BinaryTreeNode();
	BinaryTreeNode(const BinaryTreeNode<T>& );
	BinaryTreeNode(  BinaryTreeNode<T>* &);
	T getData() const;
	void setData(T);
	void setLeft(BinaryTreeNode<T>*);
	void setRight(BinaryTreeNode<T>*);
	void setParent(BinaryTreeNode<T>*);
	BinaryTreeNode<T>* getParent() const;
	BinaryTreeNode<T>* getLeft() const;
	BinaryTreeNode<T>* getRight() const;
	void print();
	BinaryTreeNode<T> operator= (const BinaryTreeNode<T>& otherNode) {
		BinaryTreeNode<T> newNode;
		newNode.data = otherNode.getData();
		newNode.left = otherNode.getLeft();
		newNode.right = otherNode.getRight();
		return newNode;
	}
	bool operator > ( const BinaryTreeNode<T>& rhs) {
		return this->getData() > rhs.getData();
	}
	friend std::ostream& operator << (std::ostream& out, const BinaryTreeNode<T>& node) {
		out << node.data << " ";
		return out;
	};
};

#include "BinaryTreeNode.cpp"

#endif // !