#ifndef GRAPH_CPP
#define GRAPH_CPP


#include "Graph.h"

template<class T>
Graph<T>::Graph()
{
	size = 0;
	nodes = new std::vector<T*>;
}

template<class T>
Graph<T>::~Graph()
{
	std::cout << "graph destructor" << std::endl;
	for (auto it : *nodes) {
		delete it;
	}
}

template<class T>
void Graph<T>::insert(T newData)
{
	std::cout << "insert newData" << std::endl;
	T* newNode = new T(newData);

	size++;
	nodes->push_back(newNode);

}

template<class T>
void Graph<T>::printNodes()
{
	if (nodes) {
		for (int i = 0; i < nodes->size(); i++) {
			std::cout << nodes->at(i)->getData();
			std::cout << "   { ";
			std::cout<<nodes->at(i)->printNeighbor();
				std::cout<< "}" << std::endl;
		}
	}
}




template<class T>
void Graph<T>::insertNode(T& newNode) {
	T* tempNode = new T(newNode.getData());
	tempNode->setChildren(newNode.getChildren());
	std::cout << "insert newnOde" << std::endl;
	if (!nodes)
		nodes = new std::vector<T*>;
	size++;
	nodes->push_back(tempNode);
}

template<class T>
bool Graph<T>::DFStack(T* root, T*searchNode) {
	std::stack<T*> stack;
	std::vector<T*> visited;
	stack.push(root);
	while (!stack.empty())
	{
		T* v = stack.top();
		if (v == searchNode) {
			return true;
		}
		stack.pop();
		if (std::find(visited.begin(), visited.end(), v) == visited.end()) {
			visited.push_back(v);
			if (v->getChildren()) {
				for (T* it : *(v->getChildren())) {
					if (std::find(visited.begin(), visited.end(), it) == visited.end()) {
						stack.push(it);
					}
						
				}
			}
			
		}
	}
	return false;
}

template<class T>
std::vector<T*>* Graph<T>::getNodes()
{

	return nodes;
}



template<class T>
bool Graph<T>::BFS(T* root, T* searchNode)
{
	std::vector<T*> visited;
	std::queue<T*> queue;
	T* previous = new T [size];

	queue.push(root);
	visited.push_back(root);

	while (!queue.empty()) {
		T* r = queue.front();
		queue.pop();
		if (r == searchNode) {
			return true;
		}
		for (T* it : (r->getNeighbor())) {
			
			if ((std::find(visited.begin(), visited.end(), it) == visited.end())) {
				visited.push_back(it);
				queue.push(it);
			}
		}

	}



	return false;
}

template<class T>
bool Graph<T>::DPS(T * root, T * searchNode)
{
	if (root == nullptr)
		return false;
	std::vector<T*> visited;
	if (searchNode == root)
		return true;
	
	return DPSearch(root, searchNode, visited);
}

template <class T>
bool Graph<T>::DPSearch(T* root, T* searchNode, std::vector<T*> visited) {
	if (root == nullptr)
		return false;
	visited.push_back(root);
	if (root == searchNode)
		return true;
	if (root->getChildren()) {
		for (T* it : *(root->getChildren())) {
			if ((std::find(visited.begin(), visited.end(), it) == visited.end())) {
				visited.push_back(it);
				return DPSearch(it, searchNode, visited);
			}

		}
	}
	
	return false;
}

template<class T>
bool contains(std::vector<Node<T>*> v, Node<T>* searchNode)
{
	for (auto it : v) {
		if (it == searchNode)
			return true;
	}
	return false;
}

#endif
