
#ifndef MINBINARYHEAP_CPP
#define MINBINARYHEAP_CPP


#include "MinBinaryHeap.h"


template <class T>
MinBinaryHeap<T>::MinBinaryHeap():BST()
{
	size = 0;
	root = nullptr;
}

template <class T>
MinBinaryHeap<T>::~MinBinaryHeap():~BST()
{
	
}

template <class T>
void MinBinaryHeap<T>::insert(T data) {
	size++;
	std::string location = itob(size);
	BinaryTreeNode<T> * newNode = new BinaryTreeNode<T>(data);
	BinaryTreeNode<T> * walker = root;
	if (size == 1) {
		root = newNode;
	}
	else
	{
		location = location.substr(1, location.size());
		for (auto& it : location) {
			if (it == '1') {
				if (walker->getRight()) {
					walker = walker->getRight();
				}
				else
				{
					newNode->setParent(walker);
					walker->setRight(newNode);
				}
				
			}
			else
			{
				if (walker->getLeft()) {
					walker = walker->getLeft();
				}
				else
				{
					newNode->setParent(walker);
					walker->setLeft(newNode);
				}
			}
		}
	}
	reheapifyUp(newNode);
}

template <class T>
void MinBinaryHeap<T>::reheapifyUp(BinaryTreeNode<T>* currNode) {
	if (currNode == root)
		return;
	BinaryTreeNode<T>* walker = currNode;
	while (walker != root && walker->getParent()->getData() > currNode->getData()) {
		T tempData = walker->getParent()->getData();
		walker->getParent()->setData(walker->getData());
		walker->setData(tempData);
		walker = walker->getParent();


	}
	
}

template <class T>
std::string MinBinaryHeap<T>::itob(int num) {
	std::string result = "";
	while (num > 0) {
		result += (num % 2 == 0) ? "0" : "1";
		num = num / 2;
	}
	 std::reverse(result.begin(), result.end());
	std::cout << "result : " << result << std::endl;
	return result;
}

#endif // !MINBINARYHEAP_CPP
