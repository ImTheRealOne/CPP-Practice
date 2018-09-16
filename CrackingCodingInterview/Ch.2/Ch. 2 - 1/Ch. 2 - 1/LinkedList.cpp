#include "LinkedList.h"
#include <iostream>
#include <stdlib.h>
#include <unordered_set>

using std::shared_ptr;

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::LinkedList(Node* a) {
	if (a) {
		//head = a;
		head->data = a->data;
		head->next = a->next;
		length++;
	}
	while (a->next)
	{
		length++;
		a = a->next;
	}
}


LinkedList::~LinkedList()
{
	std::cout << "linked list delete" << std::endl;


	Node* currNode = this->head;
	Node* tempNode;
	
	while (currNode) {
		tempNode = currNode;
		std::cout << "deleting " << currNode->data<< std::endl;
		currNode = currNode->next;
		delete tempNode;
	}
	
	system("pause");
}
void LinkedList::addToTail(Node* newNode) {
	Node*curr;
	curr = head;

	if (!curr) {
		head = newNode;
	}
	else {
		while (curr->next)		{
			curr = curr->next;
		}
		curr->next = newNode;
	}
	length++;
}

void LinkedList::addToTail(std::shared_ptr<Node>* a) {
	Node* curr;
	curr = head;

	if (!curr) {

		head = (Node *) a;
	}
	else
	{
		while (curr->next)
		{
			curr = curr->next;
		}
		curr->next = (Node*)a;
	}
	length++;
}

void LinkedList::addToTail(int i) {
	Node* curr;
	curr = head;

	if (!curr) {
		
		head = new Node(i,nullptr);
	}
	else
	{
		while (curr->next)
		{
			curr = curr->next;
		}
		curr->next = new Node(i,nullptr);
	} 
	length++;

}

void LinkedList::print() {
	Node* temp;
	temp = head;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}	

void LinkedList::removeDup() {
	Node* prevNode;
	Node* currNode;

	std::unordered_set<int> set;
	int i = 0;
	if (head) {
		currNode = head;
		set.insert(currNode->data);
		i++;
	}
	else {
		return;
	}
	while (currNode->next) {
		prevNode = currNode;
		currNode = currNode->next;
		
			if (set.count(currNode->data)) {
				prevNode->next = currNode->next;
				length--;
				std::cout << "i : " << i;
			}
			else
			{
				set.insert(currNode->data);
			}
			i++;
	}
}

void LinkedList::removeDupNoBuff() {
	Node* currNode;
	Node* nextNode;
	if (head) {
		currNode = head;
	}
	else
	{
		return;
	}

	

	while (currNode) {
		nextNode = currNode;
		while (nextNode->next) {
			if (currNode->data == nextNode->next->data) {
				std::cout << "match " << std::endl;
				nextNode->next = nextNode->next->next;
				length--;
			}
			else
			{
				nextNode = nextNode->next;
			}
		}
		currNode = currNode->next;
	}
	
}
Node* LinkedList::returnKthELement(Node * nodePtr, int k , int& i)
{
	if (!nodePtr) {
		return NULL;
	}
	if (i == k) {
		return nodePtr;
	}
	else
	{
		i++;
		returnKthELement(nodePtr->next, k, i);
	}

	return NULL;
}

Node* LinkedList::getHead() {
	return head;
}

void LinkedList::setHead(Node newHead) {
	this->head->equals(newHead);
}

bool LinkedList::deleteMiddleNode(Node* mid) {
	if (mid == NULL || mid->next == NULL)
		return false;
	else {
		Node * next = mid->next;
		mid->data = next->data;
		mid->next = next->next;
		length--;
		return true;
	}
}

int LinkedList::getLength() {
	return length;
}



bool LinkedList::isPalindrome() {
	 
	return false;
}

bool LinkedList::isEqual(Node* one, Node* two) {

	return false;
}