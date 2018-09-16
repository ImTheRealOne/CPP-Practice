#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "AbstractList.h"
template <class Item>
class List : public AbstractList<Item>
{
public:
	List(long size = DEFAULT_LIST_CAPACITY);
	List(List &);
	~List();
	List& operator= (const List&);

	virtual Iterator<Item>* CreateIterator() const;

	long Count() const;
	Item& Get(long index) const;
	Item& First() const;
	Item& Last() const;
	bool Includes(const Item&) const;

	void Append(const Item&);
	void Prepend(const Item&);
	void Resize();
	void Remove(const Item&);
	void RemoveLast();
	void RemoveFirst();
	void RemoveAll();

	void Print();

	Item& Top() const;
	void Push(const Item&);
	Item& Pop();

private:
	long _size;
	long _count;
	Item* _first;
	Item* _last;
	Item * _array;
};
template<class Item>
List<Item>::List(long size) {
	_array = new Item[size];
	_size = size;
	_count = 0;
}

template<class Item>
List<Item>::List(List & otherList) {
	Item * newArray[] = new Item[_size];
	for (int i = 0; i < _count; i++) {
		newArray[i] = _array[i];
	}

	delete _array;
	_array = newArray;

}

template<class Item>
List<Item>::~List() {
	delete  _array;
}

template<class Item>
List<Item>& List<Item>::operator=(const List<Item>& otherList) {
	Item * newList =  new Item[_size];
	for (int i = 0; i < _count; i++) {
		newList[i] = _array[i];
	}
	return *newList;
}

template <class Item>
Iterator<Item>* List<Item>::CreateIterator() const {
	return new ListIterator<Item>(this);
}

template<class Item>
long List<Item>::Count() const {
	return _count;
}

template<class Item>
Item& List<Item>::First() const {
	if(_count > 0)
		return _array[0];
	else
	{
		return nullptr;
	}
}

template<class Item>
Item& List<Item>::Get(long index) const {
	if(index < _count)
		return _array[index];
	else
	{
		
	}
}

template<class Item>
Item& List<Item>::Last() const {
	return _array[count];
}

template<class Item>
bool List<Item>::Includes(const Item& compareItem) const {
	for (int i = 0; i < _count; i++) {
		if (_array[i] == compareItem) {
			return true;
		}
	}
	return false;
}

template<class Item>
void List<Item>::Append(const Item& newItem) {
	if (_count+1 > _size) {
		//call resize;
	}
	_array[_count] = newItem;
	_count++;
	
}

template<class Item>
void List<Item>::Prepend(const Item& newItem) {
	if (_count+1 > _size) {
		//resize
	}

	Item * tempArray = new Item[_size];

	tempArray[0] = newItem;

	for (int i = 0; i < _count; i++) {
		tempArray[i + 1] = _array[i];
	}
	_count++;
	delete _array;

	_array = tempArray;
}

template <class Item>
void List<Item>::Remove(const Item& removeItem) {
	int i = 0;
	int j = 0;
	for (; i < _count; i++, j++) {
		
		if (_array[i] == removeItem) {
			j++;
			break;
		}
	}
	if (i != j) {
		for (; i < _count - 1; i++, j++) {
			_array[i] = _array[j];
		}
	}
	_count--;
}
template <class Item>
void List<Item>::RemoveFirst() {
	if (_count > 0) {
		for (int i = 0, j = 1; i < _count - 1; i++, j++) {
			_array[i] = _array[j];
		}
		_count--;
	}
	
}
template <class Item>
void List<Item>::RemoveLast() {
	if (_count > 0) {
		_count--;
	}
}

template <class Item>
void List<Item>::RemoveAll() {
	delete _array;
	_array = new Item[_size];

	_count = 0;
	
}

template<class Item>
void List<Item>::Print() {
	std::cout << std::endl;
	std::cout << "List -> size : " << _size << "   count : " << _count << std::endl;
	for (int i = 0; i < _count; i++) {
		std::cout << _array[i] << " ";
	}
	std::cout << std::endl << std::endl;
}
#endif // !LIST_H


