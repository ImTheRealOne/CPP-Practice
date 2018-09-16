


#pragma once
#include <map>
#include "DoublyLinkedList.h"
#include <iostream>
class Cache
{
private:
	int size;
	std::map<int ,Node<int *> *> cache;
	DoublyLinkedList<int*> lastUsedList;
public:
	Cache();
	Cache(int newSize);
	~Cache();
	Node<int *> * getValue(int key);
	void add(int key, int * address);
	void printList();
	void printCacheMap();
};

