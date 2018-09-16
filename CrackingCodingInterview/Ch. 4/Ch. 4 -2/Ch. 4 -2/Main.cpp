#include "Main.h"
#include <iostream>
#include "BinaryTreeNode.h"
#include "BST.h"
#include <random>
#include <algorithm>

Main::Main()
{
}


Main::~Main()
{
}

const int SIZE = 10;
BinaryTreeNode<int>* createBinTree(int arr[]);
BinaryTreeNode<int>* createBinTree(int arr[], int start, int end);
int main() {
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++) {
		arr[i] = i;
	}
	
	std::sort(std::begin(arr), std::end(arr));
	for (int i = 0; i < SIZE; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	BST<int> tree;
	BinaryTreeNode<int> * newRoot = new BinaryTreeNode<int>(* createBinTree(arr));
	tree.setRoot(newRoot);
	
	tree.inOrderPrint(tree.getRoot());
	
	system("pause");

	return 0;
}
BinaryTreeNode<int>* createBinTree(int arr[]) {
	
	return createBinTree( arr, 0, SIZE -1);
}


BinaryTreeNode<int>* createBinTree(int arr[], int start, int end) {
	if (end < start)
		return nullptr;
	int mid = (start + end) / 2;
	std::cout << "mid : " << mid << std::endl;
	BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(arr[mid]);
	std::cout << "set left";
	BinaryTreeNode<int>* tempNode =  (createBinTree(arr, start, mid - 1));
	
	newNode->setLeft(tempNode);
	std::cout << "set right";
	tempNode = (createBinTree(arr, mid+1, end));
	newNode->setRight(tempNode);
	return newNode;
}
