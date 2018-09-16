#pragma once

enum RedBlackNode_Color
{
	RED, BLACK
};

class RedBlackNode
{
public:
	RedBlackNode();
	RedBlackNode(int newKey, RedBlackNode * newParent, RedBlackNode_Color newColor , RedBlackNode * const nullLeafPtr);
	RedBlackNode(const RedBlackNode & otherNode);
	~RedBlackNode();
	int getKey();
	void setKey(int newKey);
	RedBlackNode * getParent();
	void setParent(RedBlackNode * newParent);

	RedBlackNode * getLeft();
	void setLeft(RedBlackNode * newLeft);

	RedBlackNode * getRight();
	void setRight(RedBlackNode * newRight);

	RedBlackNode_Color getColor();
	void setColor(RedBlackNode_Color newColor);

private:
	int key;
	RedBlackNode * parent;
	RedBlackNode * left;
	RedBlackNode * right;
	RedBlackNode_Color color;
};

