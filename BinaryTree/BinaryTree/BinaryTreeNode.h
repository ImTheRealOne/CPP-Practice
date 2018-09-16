#pragma once
class BinaryTreeNode
{
public:
	BinaryTreeNode();
	~BinaryTreeNode();

	BinaryTreeNode(int);
	BinaryTreeNode(const BinaryTreeNode &);
	BinaryTreeNode * getLeft();
	BinaryTreeNode * getRight();
	BinaryTreeNode * getParent();
	int getData();
	void setLeft(BinaryTreeNode *);
	void setRight(BinaryTreeNode *);
	void setParent(BinaryTreeNode *);
	void setData(int newData);
	int getDepth(BinaryTreeNode* );

private:
	int data;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
	BinaryTreeNode * parent;

};

