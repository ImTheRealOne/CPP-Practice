#pragma once
#include "Node.h"
#include <memory>
#include <iostream>

using std::shared_ptr;

class LinkedList
{
private:
	Node* head;
	int length;
public:
	LinkedList();
	LinkedList(Node*);
	~LinkedList();
	
	void setHead(Node);
	void addToTail(int);
	void addToTail(Node*);
	void addToTail(std::shared_ptr<Node>* a);
	void print();
	void removeDup();
	void removeDupNoBuff();
	Node * returnKthELement(Node*, int, int&);
	Node * getHead();
	bool deleteMiddleNode(Node*);
	int getLength();
	bool isEqual(Node*, Node*);
	bool isPalindrome();
};