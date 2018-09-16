#pragma once
#include "Iterator.h"
template <class Item>
class AbstractList
{
public:
	AbstractList();
	~AbstractList();
	
	virtual Iterator<Item>* CreateIterator() const = 0;

	

};

template <class Item>
AbstractList<Item>::AbstractList()
{
}

template <class Item>
AbstractList<Item>::~AbstractList()
{
}