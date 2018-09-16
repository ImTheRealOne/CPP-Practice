#include "Main.h"
#include <iostream>
#include <SharedPtrLinkedList.h>


Main::Main()
{
}


Main::~Main()
{
}
void reverseNodesKGroupHelper(SharedPtrLinkedList& list, int k);
void swapNodes(std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> a,
					std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> b);
void reverseNodesKGroup(SharedPtrLinkedList list, int k);

SharedPtrLinkedList mergeTwoSortedList(SharedPtrLinkedList & a, SharedPtrLinkedList & b);

int main() {

	SharedPtrLinkedList list;
	list.addToTail(1);
	list.addToTail(4);
	list.addToTail(7);
	list.addToTail(9);
	list.addToTail(11);
	list.print();

	SharedPtrLinkedList list2;
	list2.addToTail(2);
	list2.addToTail(5);
	list2.addToTail(6);
	list2.addToTail(8);

	list2.print();


	SharedPtrLinkedList result = mergeTwoSortedList(list, list2);

	result.print();
	/*reverseNodesKGroupHelper(list, 3);
	list.print();
	reverseNodesKGroupHelper(list, 3);
	list.print();
	reverseNodesKGroupHelper(list, 2);
	list.print();
	reverseNodesKGroupHelper(list, 2);
	list.print();*/

	system("pause");
	return 0;
}

SharedPtrLinkedList mergeTwoSortedList(SharedPtrLinkedList& a, SharedPtrLinkedList& b) {
	SharedPtrLinkedList result;
	std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> walkerA;
 	std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> walkerB;
	std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> temp;

	if (a.empty())
		return b;
	else if (b.empty())
		return a;
	walkerA = a.getHead();
	walkerB = b.getHead();
	if (walkerA->getData() < walkerB->getData()) {
		result.setHead(walkerA);
		temp = walkerA;
		walkerA = walkerA->next;
		temp->next = nullptr;
	}
	else
	{
		
		result.setHead(walkerB);
		temp = walkerB;
		walkerB = walkerB->next;
		temp->next = nullptr;
		
	}

	
	while (walkerA && walkerB) {
		if (walkerA->getData() < walkerB->getData()) {
			temp = walkerA;
			result.addToTail(walkerA);
			walkerA = walkerA->next;
			temp->next = nullptr;
		}
		else
		{
			result.addToTail(walkerB);
			temp = walkerB;
			walkerB = walkerB->next;
			temp->next = nullptr;
		}
		
	}

	if(walkerA)
		result.addToTail(walkerA);

	else
	{
		result.addToTail(walkerB);
	}
	return result;
}

void reverseNodesKGroupHelper(SharedPtrLinkedList& list, int k) {
	if (list.empty()) {
		return;
	}
	if (k < 2) {
		return;
	}
	
	std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> walker = list.getHead();
	std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> endWalker = walker;
	bool firstRun = true;
	int l = 0;
	while (endWalker != nullptr) {
		int i;
		for (endWalker = walker, i = 0 ; i < k; i++) {
			if (i == 0)
				endWalker = walker;
			else if(endWalker->next)
				endWalker = endWalker->next;
			else {
				std::cout << "list not long enough" << std::endl;
				return;
			}
				
		}
		std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> prev = walker;
		std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> curr = prev->next;
		std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> next = curr->next;
		if (prev == list.getHead()) {
			list.setHead(curr);
		}

		for (int j = 0; j < k; j++ , l++) {	
			for (int m = j; m < k-1; m++) {
				prev = walker;
				curr = prev->next;
				next = curr->next;
				
				if (m == j && firstRun ) {
					curr->next = prev;
					prev->next = next;
					if (prev == list.getHead()) {

						list.setHead(curr);
					}
				}
				else
				{
					curr->next = next->next;
					prev->next = next;
					next->next = curr;
				}
				
			

				for (i = 0, walker = list.getHead(); i < l; i++) {
					if (walker->next)
						walker = walker->next;
				}
					list.print();
			}
		
			}
			walker = list.getHead();
			while (walker->next != endWalker->next) {
				walker = walker->next;

			}
		firstRun = false;
		}
	
		

		
}
	



void swapNodes(std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> currWalker,
				std::shared_ptr<SharedPtrLinkedList::SharedPtrNode> nextWalker) {


}

void reverseNodesKGroup(SharedPtrLinkedList list, int k) {

	



}