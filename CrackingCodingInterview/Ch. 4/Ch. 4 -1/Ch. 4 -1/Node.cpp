
#ifndef NODE_CPP
#define NODE_CPP


#include "Node.h"


template <class T>
Node<T>::Node()
{
	data = NULL;
	children = nullptr;
}

template<class T>
Node<T>::Node(T newData)
{
	data = newData;
	children = nullptr;
}



template <class T>
Node<T>::~Node()
{
	std::cout << "node destructor" << std::endl;
	delete children;
}

template<class T>
void Node<T>::addNeighbor( Node<T>* const newNeighbor )
{
	if (!this->children) {
		this->children = new std::vector<Node<T>*>;
	}


		this->children->push_back(newNeighbor);
}



template<class T>
std::string Node<T>::printNeighbor()
{
	std::string result;
	if (children) {
		

		for (int i = 0; i < children->size(); i++) {
			result += std::to_string(children->at(i)->getData()) + " ";
		}
	}
		
	
	return result;
}

template<class T>
T  const & Node<T>:: getData () const
{
	return T(data);
}

template<class T>
void Node<T>::setData(T newData)
{
	this->data = newData;
}

template<class T>
std::vector<Node<T>*>* const & Node<T>::getChildren() const
{
	return this->children;
}

template<class T>
void Node<T>::setChildren(std::vector<Node<T>*>* newChildren)
{
	this->children = newChildren;
}

#endif // !NODE_CPP


