#pragma once
#include <vector>
#include <utility>
#include <iostream>


class Node
{

public:
	Node();
	~Node();
	Node(int data);
	Node(int data, int weight);
	Node(const Node  &otherNode);

	void setData(int newData);
	int getData() const ;
	void setWeight(int newWeight);
	int getWeight() const;
	void setPrev(Node * prevNode);
	Node * getPrev();
	void addNeighbor(Node* newNeighbor, int cost);
	std::vector<std::pair<Node*, int>> * getNeighbor();


private:
	int data;
	int weight;
	Node * prev;
	std::vector<std::pair<Node*, int>> * neighbors;

};