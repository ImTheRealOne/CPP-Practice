// FlattenLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include <iostream>
#include <vector>

Node* flattenList(const std::vector<Node* > &nodeVector);
void recursiveFlattenList(Node* NodePtr, std::vector<Node* > &nodeVector);

void priorityAddNode(Node* currNode, std::vector<Node*> &nodeVector);

int main()
{
	Node* node5 = new Node(9);
	Node* node7 = new Node(7);
	Node* node8 = new Node(8);
	Node* node30 = new Node(30);
	Node* node10 = new Node(10);
	Node* node20 = new Node(20);
	
	node5->setDownNode(node7);
	node7->setDownNode(node8);
	node8->setDownNode(node30);
	node5->setRightNode(node10);
	node10->setDownNode(node20);

	std::vector<Node* > nodeVector;
	Node* newNodeHead;
	Node* nodeVectorPtr;
	recursiveFlattenList(node5, nodeVector);
	
	newNodeHead = flattenList(nodeVector);
	nodeVectorPtr = newNodeHead;
	
	while (nodeVectorPtr) {
		std::cout << nodeVectorPtr->getData() << " ";
		nodeVectorPtr = nodeVectorPtr->getRightNode();
	}



	system("pause");
    return 0;
}

void recursiveFlattenList(Node* currNode, std::vector<Node* > &nodeVector) {
		priorityAddNode(currNode, nodeVector);
	if (currNode->getState() == NODESTATE::DOWNANDRIGHT) {
		recursiveFlattenList(currNode->getRightNode(), nodeVector);
		recursiveFlattenList(currNode->getDownNode(), nodeVector);
	}
	else if (currNode->getState() == NODESTATE::DOWNONLY) {
		recursiveFlattenList(currNode->getDownNode(), nodeVector);
	}
	else if (currNode->getState() == NODESTATE::RIGHTONLY) {
		recursiveFlattenList(currNode->getRightNode(), nodeVector);
	}


}

void priorityAddNode(Node* currNode,std::vector<Node*> &nodeVector) {
	bool added = false;
	if (nodeVector.empty()) {
		nodeVector.push_back(currNode);
	}
	else
	{
		int vectorSize = nodeVector.size();
		for (int i = 0; i < vectorSize && !added; i++) {
			if (nodeVector.at(i)->getData() > currNode->getData()) {
				std::vector<Node* >::iterator iterator = nodeVector.begin();
				nodeVector.insert(iterator + i, currNode);
				added = true;
			}
		}
	}
	if (!added) {
		nodeVector.push_back(currNode);
	}
}

Node* flattenList(const std::vector<Node*> &nodeVector) {
	Node* nodeHeadPtr = nullptr;
	Node* currNodePtr;
	std::vector<Node* > newVector;
	if (nodeVector.size() > 0) {
		currNodePtr = nodeVector.at(0);
		nodeHeadPtr = currNodePtr;
		currNodePtr->setRightNode(nullptr);
		currNodePtr->setDownNode(nullptr);
		for (int i = 1; i < nodeVector.size(); i++) {
			currNodePtr->setRightNode(nodeVector.at(i));
			currNodePtr = currNodePtr->getRightNode();
		}
		nodeVector.at(nodeVector.size() - 1)->setRightNode(nullptr);
	}
	return nodeHeadPtr;
}



