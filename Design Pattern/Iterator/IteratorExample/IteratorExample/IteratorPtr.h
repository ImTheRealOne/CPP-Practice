#pragma once
#include "Iterator.h"


template <class Item>
class IteratorPtr
{
public:
	IteratorPtr(Iterator<Item>* i) : _i(i) {};
	~IteratorPtr() { delete _i; }
	
	Iterator<Item>* operator->() { return _i; }
	Iterator<Item>& operator*() { return *_i; }

private:
	IteratorPtr(const IteratorPtr&);
	IteratorPtr& operator= (const IteratorPtr&);


private:
	Iterator<Item>* _i;


};

