#pragma once
#include <memory>
#include <iostream>

using std::cout;
using std::endl;

class SharedPtrLinkedList
{
	
public:
	struct SharedPtrNode
	{
		int data;
		std::shared_ptr <SharedPtrNode> next;
		SharedPtrNode() {
			data = NULL;
			next = nullptr;
		}
		SharedPtrNode(const int &newData) {
			data = newData;
			next = nullptr;
		}
		~SharedPtrNode() {
			cout << "deleting Node" << endl;
		}

	};
	SharedPtrLinkedList();
	~SharedPtrLinkedList();
	void addToTail(const int & );
	void addToTail(const std::shared_ptr<SharedPtrNode> );
	void const print();
private:
	std::shared_ptr<SharedPtrNode> head;
	int size;
	std::shared_ptr<SharedPtrNode> tail;
};

