#pragma once
struct Node
{
	int data;
	Node * next;
public:
	Node();
	~Node();
	Node(int , Node*);
	void equals(const Node);
};

