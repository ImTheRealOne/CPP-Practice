#include "stdafx.h"
#include "Cache.h"


Cache::Cache()
{
}

Cache::Cache(int newSize)
{
	size = newSize;
}




Cache::~Cache()
{
}

Node<int*>* Cache::getValue(int key)
{
	std::map<int, Node<int *> *>::iterator cacheMapIt;
	cacheMapIt = cache.find(key);
	if (cacheMapIt == cache.end()) {
		std::cout << "key doesn't exist"<<std::endl;
		return nullptr;
	}
	else
	{
		lastUsedList.moveToHead(cacheMapIt->second);
		return cacheMapIt->second;
	}
}

void Cache::add(int key, int * address)
{
	std::map<int, Node<int *> *>::iterator cacheIt;
	cacheIt = cache.find(key);
	//key already exist
	if (cacheIt != cache.end()) {
		lastUsedList.moveToHead(cacheIt->second);
	}
	//entry is new key
	else
	{	//check if last used key needs to be deleted
		//remove from cache map first before deleting from list
		if (cache.size() >= size) {
			cacheIt = cache.find(*lastUsedList.getTail()->getData());
			cache.erase(cacheIt);
			lastUsedList.removeCurrNode(lastUsedList.getTail());
			printList();
		}
		Node<int *> * nodePtr = new Node<int *>(address);
		lastUsedList.insertToHead(nodePtr);
		cache.insert(std::pair<int, Node<int * > * >(key, nodePtr));

	}
	std::cout << "inserted key : " << key << std::endl;
	printCacheMap();
	printList();

}

void Cache::printList()
{
	std::cout << "cache List :    ";
	for (Node<int *> * walker = lastUsedList.getHead(); walker; walker = walker->getNext()) {
		if (walker) {
			std::cout << *walker->getData() << " -> ";
		}
	}
	std::cout << std::endl;
}

void Cache::printCacheMap()
{
	std::map<int, Node<int *> *>::iterator cacheIt;
	std::cout << "cache Map :    ";
	for (cacheIt = cache.begin(); cacheIt != cache.end(); cacheIt++) {
		std::cout<<*cacheIt->second->getData();
		std::cout << " -> ";
	}
	std::cout << std::endl;
}


