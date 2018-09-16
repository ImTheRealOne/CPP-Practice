#pragma once
#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "Iterator.h"
#include "List.h"


template <class Item>
class ListIterator : public Iterator<Item>
{
public:
	ListIterator();
	ListIterator(const List<Item>* aList);
	~ListIterator();

	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual Item CurrentItem() const;

private:
	const List<Item>* _list;
	long _current;
};


template<class Item>
ListIterator<Item>::ListIterator()
{
}

template<class Item>
ListIterator<Item>::ListIterator(const List<Item>* aList)
{
	_list = aList;
	_current = 0;
}


template<class Item>
ListIterator<Item>::~ListIterator()
{
	delete _list;
}

template<class Item>
void ListIterator<Item>::First() {
	_current = 0;
}

template<class Item>
void ListIterator<Item>::Next() {
	_current++;
}

template<class Item>
bool ListIterator<Item>::IsDone() const {
	return _current >= _list->Count();
}



template<class Item>
Item ListIterator<Item>::CurrentItem() const {
	if (IsDone()) {
		//throw "IteratorOutOfBounds";
	}
	return _list->Get(_current);
}



#endif // !LISTITERATOR_H


