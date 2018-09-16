#include "Main.h"
#include "LinkedList.h"
#include <iostream>

Main::Main()
{
}


Main::~Main()
{
}
Node addTwoListRev(Node * a, Node * b, int carry);
int main() {

	LinkedList one, two;
	one.addToTail(7);
	one.addToTail(1);
	one.addToTail(6);

	two.addToTail(5);
	two.addToTail(9);
	two.addToTail(2);
	two.addToTail(4);

	std::cout << "one : "; one.print();
	std::cout << std::endl;

	std::cout << "two : ";
	two.print();
	std::cout << std::endl;

	Node* newHead = new Node();
	newHead->equals(addTwoListRev(one.getHead(), two.getHead(), 0));
	if (newHead) {
		std::cout << "newhead : " << newHead->data<< std::endl;
 

	}	
	LinkedList newList;
	newList.setHead(*newHead);
	

	newList.print();
	system("pause");
	return 0;
}

Node addTwoListRev(Node * a, Node * b, int carry) {
	if (a == NULL && b == NULL && carry == 0)
		return Node(NULL, nullptr);
	int value = carry;
	carry = 0;
	if (a != NULL)
		value += a->data;
	if (b != NULL)
		value += b->data;
	Node* temp = new Node();
	temp->data = value % 10;
	Node * next = new Node();
	//std::cout << "temp : " << temp->data << std::endl;

	value >= 10 ? carry = 1 : carry = 0;

	next->equals(addTwoListRev(a == NULL ? NULL : a->next,
		b == NULL ? NULL : b->next, carry));
	if (next) {
		//std::cout <<"next : " << next->data<< std::endl;
	}
	temp->next = next;
	if (temp) {
		//std::cout << "temp after : " << temp->data << std::endl;
	}
	return *temp;

}