#include "Main.h"
#include "Stack.h"


Main::Main()
{
}


Main::~Main()
{
}

template <class T>
void sortStack(Stack<T> &a);


int main() {
	Stack<int>* test = new Stack<int> (5);
	test->push(4);
	test->push(2);
	test->push(6);
	test->push(3);
	test->push(1);
	test->print();
	sortStack(*test);
	test->print();

	system("pause");
}

template <class T>
void sortStack(Stack<T> & a) {
	Stack<T>* tempStack = new Stack<T> (a.getCapacity());

	if (a.isEmpty()) {
		return;
	}
	T tempvalue = NULL;

	while (!a.isEmpty()) {
		tempvalue = a.peek();
		a.pop();
		while (!tempStack->isEmpty() && tempStack->peek() > tempvalue) {
			a.push(tempStack->peek());
			tempStack->pop();
		}
		tempStack->push(tempvalue);
	}
		while(!tempStack->isEmpty()) {
			a.push(tempStack->peek());
			tempStack->pop();
		}
	
	a.print();

}