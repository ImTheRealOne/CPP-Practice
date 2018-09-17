#include "SharedPtrLinkedList.h"



SharedPtrLinkedList::SharedPtrLinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}


SharedPtrLinkedList::~SharedPtrLinkedList()
{
	
}

void SharedPtrLinkedList::addToTail(const int &  newData) {
	std::shared_ptr<SharedPtrNode> newNode(new SharedPtrNode(newData));
	if (!head) {
		head = std::move(newNode);
		tail = head;
	}
	else {
		std::shared_ptr<SharedPtrNode> curr (head);

		while (curr->next) {
			curr = curr->next;
		}
		curr->next = std::move(newNode);
		tail = curr;
	}
}

void SharedPtrLinkedList::addToTail(const std::shared_ptr<SharedPtrNode> newNode) {
	if (!head) {
		head = std::move(newNode);
		tail = head;
	}
	else {
		std::shared_ptr<SharedPtrNode> curr(head);
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = std::move(newNode);
		tail = curr->next;
	}

}

void const SharedPtrLinkedList::print() {
	std::shared_ptr<SharedPtrNode> curr(head);
	while (curr) {
		cout << " " << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}