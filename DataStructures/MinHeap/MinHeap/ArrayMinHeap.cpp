#ifndef ARRAYMINHEAP_CPP
#define ARRAYMINHEAP_CPP

#include "ArrayMinHeap.h"
template <class T>
ArrayMinHeap<T>::ArrayMinHeap()
{
	size = 0;
	heap = new std::vector<BinaryTreeNode<T>*>(0);
}



template <class T>
ArrayMinHeap<T>::~ArrayMinHeap()
{
	for (vector<T>::iterator it = heap->begin(); it != heap->end(); it++) {
		if (it) {
			delete it;
		}
	}
}

template<class T>
void ArrayMinHeap<T>::insert(T data)
{
	size++;
	heap->reserve(size);
	heap->resize(size);		//increase vector size
	BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(data);
	heap->at(size-1) = newNode;
	
	heapify();
}

template<class T>
void ArrayMinHeap<T>::heapify()
{
	for (int i = heap->size()-1; i >= 0; i--)
	{
		heapifyUp(i);
	}
}

template<class T>
void ArrayMinHeap<T>::heapifyUp(int index) {
	if (index == 0)
		return;
	int parent = index-1 / 2;

	if (heap->at(parent)->getData() > heap->at(index)->getData())
	{
		std::cout << " parent : " << heap->at(parent)->getData() << std::endl;
		std::cout << " index : " << heap->at(index)->getData() << std::endl;
		std::cout << std::endl;
		T data = heap->at(index)->getData();
		heap->at(index)->setData(heap->at(parent)->getData());
		heap->at(parent)->setData(data);
		
		Print();
		std::cout << std::endl;
		heapifyUp(parent);

		
	}



}

template <class T>
void ArrayMinHeap<T>::Print() {
	int j = heap->size();
	for (int i = 0; i <  j; i++) {
		( heap->at(i)->print());
		
	}
}

#endif // !ARRAYMINHEAP_CPP

