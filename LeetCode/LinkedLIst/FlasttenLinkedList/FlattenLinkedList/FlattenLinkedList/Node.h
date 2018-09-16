#pragma once

enum NODESTATE
{

	DOWNANDRIGHT,DOWNONLY,RIGHTONLY

};

class Node
{
public:
	Node();
	Node(int newData) : data(newData) { rightNode = nullptr; downNode = nullptr; };
	Node(const Node& copyNode) {data = copyNode.getData(); }
	~Node();

	int getData() const { return data; }
	void setRightNode(Node* newRightNode) { rightNode = newRightNode;}
	void setDownNode(Node* newDownNode) { downNode = newDownNode; }
	Node* getRightNode() { return rightNode; }
	Node* getDownNode() { return downNode; }

	NODESTATE getState() {
		if (rightNode && downNode)
			return NODESTATE::DOWNANDRIGHT;
		else if (rightNode && !downNode)
			return NODESTATE::RIGHTONLY;
		else if (downNode && !rightNode)
			return NODESTATE::DOWNONLY;
	}

private:
	int data;
	Node* rightNode;
	Node* downNode;
};

