// IteratorExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include "Iterator.h"
#include "ListIterator.h"
#include <iostream>
#include "IteratorPtr.h"

void PrintElements(Iterator<int> & i);
int main()
{

	List<int> * list = new List<int>(10);
	

	for (int i = 0; i < 9; i++) {
		list->Append(i);
	}
	list->Prepend(2);
	list->Print();
	list->Remove(8);
	list->Print();
	list->Remove(0);
	list->Print();
	list->RemoveFirst();
	list->Print();
	list->RemoveLast();
	list->Print();

	//ListIterator<int> forward(list);

	//Iterator<int>* iterator = list->CreateIterator();

	IteratorPtr<int> iterator(list->CreateIterator());

	PrintElements(*iterator);
	system("pause");
    return 0;
}

void PrintElements(Iterator<int > & i) {
	for (i.First(); !i.IsDone(); i.Next()) {
		std::cout << i.CurrentItem() << "  ";
	}
}

