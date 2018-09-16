#include "Main.h"

#include "BST.h"


Main::Main()
{
}


Main::~Main()
{
}

std::vector<std::vector<BinaryTreeNode<int>*>*> createLinkedListIterative(BinaryTreeNode<int>* root);
int main() {
	BST<int>* tree = new BST<int>();
	//tree->insert(3);
	//tree->insert(5);
	//tree->insert(1);

	////std::cout << "this is root " << std::to_string(tree->getRoot()->getData()) << std::endl;

	//tree->inOrderPrint(tree->getRoot());
	//std::cout << std::endl;
	//std::cout << std::endl;

	//tree->remove(3, tree->getRoot());
	//tree->inOrderPrint(tree->getRoot());
	//std::cout << std::endl;

	//tree->insert(2);
	//tree->insert(4);

	//tree->inOrderPrint(tree->getRoot());

	//std::cout << std::endl;
	//std::cout << std::endl;
	//std::cout<<tree->postOrderPrint(tree->getRoot());

	tree->insert(7);
	tree->insert(5);
	tree->insert(1);
	tree->insert(4);
	tree->insert(6);
	tree->insert(9);
	tree->insert(8);
	tree->insert(10);
	tree->insert(2);

	std::vector<std::vector<BinaryTreeNode<int>*>*> vec = createLinkedListIterative(tree->getRoot());

	for (int i = 0; i < vec.size(); i++) {
		std::cout << "level " << i << ": ";
		for (int j = 0; j < vec.at(i)->size(); j++) {
			std::cout << vec.at(i)->at(j)->getData() << ",  ";
		}
		std::cout << std::endl;
	}

	



	if (tree->isBalanced(tree->getRoot()))
	{

		std::cout << "tree is bal" << std::endl;
	}
	else
	{
		std::cout << "tree is not bal" << std::endl;
	}
	system("pause");

}

std::vector<std::vector<BinaryTreeNode<int>*>*> createLinkedListIterative(BinaryTreeNode<int>* root) {


	std::vector<std::vector<BinaryTreeNode<int>*>*> *resultList = new std::vector<std::vector<BinaryTreeNode<int>*>*>();
	std::vector<BinaryTreeNode<int>*> *currentLevel = new std::vector<BinaryTreeNode<int>*>();

	if (root)
		currentLevel->push_back(root);

	while (!currentLevel->empty()) {
		resultList->push_back(currentLevel);
		std::vector<BinaryTreeNode<int>*> *parentLevel = currentLevel;
		currentLevel = new std::vector<BinaryTreeNode<int>*>();
		for (BinaryTreeNode<int>* node : *parentLevel) {
			if (node->getLeft() != nullptr) {
				currentLevel->push_back(node->getLeft());
			}
			if (node->getRight() != nullptr) {
				currentLevel->push_back(node->getRight());
			}
		}

	}
	return *resultList;
}