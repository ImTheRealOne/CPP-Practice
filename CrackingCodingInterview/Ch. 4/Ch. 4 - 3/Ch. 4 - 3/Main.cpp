#include "Main.h"
#include "Main.h"
#include <iostream>
#include "BST.h"
#include "BinaryTreeNode.h"
#include <vector>
#include <queue>
#include <memory>

Main::Main()
{
}


Main::~Main()
{
}

std::vector<BinaryTreeNode<int>> createLinkedListRecurse(
	BinaryTreeNode<int>* root);

void createLinkedListRecurse(
	BinaryTreeNode<int>* root, int depth, std::vector<BinaryTreeNode<int>>& linkedList);

std::vector<std::vector<BinaryTreeNode<int>*>*> createLinkedListIterative(BinaryTreeNode<int>* root);

int main() {
	BST<int> *tree = new BST<int>();
	tree->insert(5);
	tree->insert(3);
	tree->insert(7);
	tree->insert(1);
	tree->insert(4);
	tree->insert(6);
	tree->insert(8);

	//std::vector<BinaryTreeNode<int>> result = createLinkedListRecurse(tree->getRoot());
	std::vector<std::vector<BinaryTreeNode<int>*>*> result = createLinkedListIterative(tree->getRoot());


	/*for (int i = 0; i < result.size(); i++) {
		std::cout << "level  " << i << " : ";
		BinaryTreeNode<int> * ptr = &result.at(i);
		std::cout << ptr->getData() << " ";
		while (ptr->getRight()) {
			ptr = ptr->getRight();
			std::cout << ptr->getData() << " ";
		}
		std::cout << std::endl;
	}*/
	for (int i = 0; i < result.size(); i++) {
		std::cout << "level " << i << ": ";
		for (int j = 0; j < result.at(i)->size(); j++) {
			std::cout << result.at(i)->at(j)->getData() << ",  ";
		}
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}

std::vector<BinaryTreeNode<int>> createLinkedListRecurse(BinaryTreeNode<int>* root) {
	std::vector<BinaryTreeNode<int>> result;
		createLinkedListRecurse(root, 1, result);

	return result;
}

void createLinkedListRecurse(
	BinaryTreeNode<int>* root, int depth, std::vector<BinaryTreeNode<int>>& linkedList) {
	if (!root) return;
	if (linkedList.size() < depth)
		linkedList.push_back(*new BinaryTreeNode<int> (root->getData()));
	else {
		BinaryTreeNode<int> * currNode = &linkedList.at(depth-1);
		while (currNode->getRight())
		{
			currNode = currNode->getRight();
		}
		
		currNode->setRight(new BinaryTreeNode<int> (root->getData()));
	}
	if(root->getLeft())
		createLinkedListRecurse(root->getLeft(), depth + 1, linkedList);
	if (root->getRight())
		createLinkedListRecurse(root->getRight(), depth + 1, linkedList);

}

std::vector<std::vector<BinaryTreeNode<int>*>*> createLinkedListIterative(BinaryTreeNode<int>* root) {

	
	std::vector<std::vector<BinaryTreeNode<int>*>*> *resultList = new std::vector<std::vector<BinaryTreeNode<int>*>*>();
	std::vector<BinaryTreeNode<int>*>* currentLevel = new std::vector<BinaryTreeNode<int>*> ();

	if (root)
		currentLevel->push_back(new BinaryTreeNode<int>(*root));
	
	while (!currentLevel->empty()) {
		resultList->push_back(currentLevel);
		std::vector<BinaryTreeNode<int>*>* parentLevel = currentLevel;
		currentLevel = new std::vector<BinaryTreeNode<int>*>();
		for (int i = 0; i < parentLevel->size(); i++) {
			BinaryTreeNode<int> * node = (parentLevel->at(i));
			if (node->getLeft() != nullptr) {
				currentLevel->push_back((node->getLeft()));
			}
			if (node->getRight() != nullptr) {
				currentLevel->push_back((node->getRight()));
			}
			}
		}
		/*for (BinaryTreeNode<int> node:*parentLevel) {
			if (node.getLeft() != nullptr) {
				currentLevel->push_back(*new BinaryTreeNode<int>(*node.getLeft()));
			}
			if (node.getRight() != nullptr) {
				currentLevel->push_back(*new BinaryTreeNode<int>(*node.getRight()));
			}
		}

	}*/
	return *resultList;
}

//
//std::vector<std::vector<BinaryTreeNode<int>*>*> createLinkedListIterative(BinaryTreeNode<int>* root) {
//
//
//	std::vector<std::vector<BinaryTreeNode<int>*>*> *resultList = new std::vector<std::vector<BinaryTreeNode<int>*>*>();
//	std::vector<BinaryTreeNode<int>*> *currentLevel = new std::vector<BinaryTreeNode<int>*>();
//
//	if (root)
//		currentLevel->push_back(root);
//
//	while (!currentLevel->empty()) {
//		resultList->push_back(currentLevel);
//		std::vector<BinaryTreeNode<int>*> *parentLevel = currentLevel;
//		currentLevel = new std::vector<BinaryTreeNode<int>*>();
//		for (BinaryTreeNode<int>* node : *parentLevel) {
//			if (node->getLeft() != nullptr) {
//				currentLevel->push_back(node->getLeft());
//			}
//			if (node->getRight() != nullptr) {
//				currentLevel->push_back(node->getRight());
//			}
//		}
//
//	}
//	return *resultList;
//}
//
//
////print
//std::vector<std::vector<BinaryTreeNode<int>*>*> vec = createLinkedListIterative(tree.getRoot());
//
//for (int i = 0; i < vec.size(); i++) {
//	std::cout << "level " << i << ": ";
//	for (int j = 0; j < vec.at(i)->size(); j++) {
//		std::cout << vec.at(i)->at(j)->getData() << ",  ";
//	}
//	std::cout << std::endl;
//}