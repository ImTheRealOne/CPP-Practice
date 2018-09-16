// doublylist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "DoublyLinkedList.h"

int main()
{
	Node<int> *node1 = new Node<int>(1);
	Node<int> *node2 = new Node<int>(2);
	Node<int> *node3 = new Node<int>(3);
	Node<int> *node4 = new Node<int>(4);
	Node<int> *node5 = new Node<int>(5);
	Node<int> *node6 = new Node<int>(6);
	Node<int> *node7 = new Node<int>(7);
	
	DoublyLinkedList<int> dlinkedlist;
	dlinkedlist.addToTail(node3);
	dlinkedlist.insertToHead(node2);
	dlinkedlist.print();
	dlinkedlist.addToTail(node1);
	dlinkedlist.moveToHead(node1);
	dlinkedlist.print();
	dlinkedlist.addToTail(node4);
	dlinkedlist.addToTail(node5);
	dlinkedlist.addToTail(node6);
	dlinkedlist.print();
	dlinkedlist.removeCurrNode(node6);
	dlinkedlist.print();
	dlinkedlist.removeCurrNode(node1);
	dlinkedlist.print();
	node1 = new Node<int>(1);
	dlinkedlist.insertToHead(node1);
	dlinkedlist.print();
	node6 = new Node<int>(6);
	dlinkedlist.addToTail(node6);
	dlinkedlist.print();






	system("pause");
    return 0;
}

