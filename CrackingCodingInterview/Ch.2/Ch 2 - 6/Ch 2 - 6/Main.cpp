#include "Main.h"
#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
Main::Main()
{
}



Main::~Main()
{
}

Node* ReverseAndCopy(Node* head);
bool isEqual(Node*, Node*);
bool isPalindrome(Node*);

int main() {
	LinkedList list;
	Stack reverseList;
	list.addToTail(1);
	list.addToTail(2);
	list.addToTail(3);
	list.addToTail(2);
	list.addToTail(1);
	
	list.print();
	
	reverseList.setTop(ReverseAndCopy(list.getHead()));
	reverseList.print();
	
	if (isEqual(list.getHead(), reverseList.getHead())) {
		std::cout << "Equals" << std::endl;
	}
	else
	{
		std::cout << "nope" << std::endl;


	}
	
	if (isPalindrome(list.getHead())) {
		std::cout << "palindrome" << std::endl;
	}
	else
	{
		std::cout << "not palindrome" << std::endl;


	}



	system("pause");

	return 0;
}

Node* ReverseAndCopy(Node* LinkedListNode) {
	Node* head = nullptr;
	if (LinkedListNode) {
		while (LinkedListNode) {
			Node* n = new Node(LinkedListNode->data, nullptr);
			n->next = head;
			head = n;
			LinkedListNode = LinkedListNode->next;

		}
	}
	return head;

}

bool isEqual(Node* one, Node* two) {
	while (one != NULL && two != NULL) {
		if (one->data != two->data)
			return false;
		one = one->next;
		two = two->next;
	}
	return one == NULL && two == NULL;
}

bool isPalindrome(Node* head) {
	Node* slow = head;
	Node* fast = head;

	Stack intStack;

	while (fast != NULL && fast->next != NULL) {
		intStack.push(slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast != NULL) {
		slow = slow->next;
	}
	while (slow != NULL) {
		int top = intStack.pop().data;
		if (top != slow->data) {
			return false;
		}
		slow = slow->next;
	}
	return true;
}