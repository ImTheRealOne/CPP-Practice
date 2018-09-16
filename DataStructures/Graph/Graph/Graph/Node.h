#pragma once
class Node
{
public:
	Node();
	Node(int newData) {
		this->data = newData;
	}
	~Node();

	Node(const Node &copyNode) { this->data = copyNode.data; }
	Node& operator= (const Node& otherNode);

	const int getData();
	void setData(const int &data);

private:
	int data;

};

