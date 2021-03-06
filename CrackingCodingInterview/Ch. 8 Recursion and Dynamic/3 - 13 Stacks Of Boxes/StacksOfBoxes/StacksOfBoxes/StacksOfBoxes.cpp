// StacksOfBoxes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>

#include <thread>
#include <mutex>


class X {
private:
	 int lastIdUsed;
public:
	static std::mutex lock;
	X(int data) :lastIdUsed(data) {};
	X(const X& otherX) {
		this->lastIdUsed = otherX.lastIdUsed;
	}
	void getNextId() {
		lock.lock();
		std::cout<< ++lastIdUsed<< "    ";
		lock.unlock();
	}
	int getInt() {
		return lastIdUsed;
	}
};

int recursiveCalls = 0;

struct box {
	int height;
	int depth;
	int width;

	box(int x, int y, int z) : width(x), height(y), depth(z) {}

	bool operator< (const box& rhs) {
		if (rhs.height > height && rhs.depth > depth && rhs.width > width) {
			return true;
		}
		return false;
	}

	void print() const {
		std::cout << std::endl;
		std::cout << "width : " << width << ", height : " << height << ", depth : " << depth << std::endl;
		std::cout<<std::endl;
	}
	
};


int main();

void insertBox(std::vector<box> & boxVector, const box & newBox);
void printVector(const std::vector<box> & boxVector);
void stackBoxesRecurse(const std::vector<box> & boxVector, int index, int &max, std::stack<box> boxStack,
	int runningHeight);

int main()
{
	box box6 = box(3, 2, 1);
	box box5 = box(6, 5, 4);
	box box4 = box(9 , 8, 7);
	box box3 = box(7, 8, 9);
	box box2 = box(4, 5, 6);
	box box1 = box(1, 2, 3);
	
	std::vector<box> boxVector;
	std::stack<box> boxStack;

	insertBox(boxVector, box1);
	insertBox(boxVector, box3);
	insertBox(boxVector, box2);
	insertBox(boxVector, box4);
	insertBox(boxVector, box5);
	insertBox(boxVector, box6);
	/*
	printVector(boxVector);
	int max = 0;
	stackBoxesRecurse(boxVector, 0, max, boxStack, 0);


	std::cout << "max : " << max << std::endl;
	std::cout << "recursive calls : " << recursiveCalls << std::endl;
	*/
	
	X testThread = *new X(42);



	std::thread first(&X::getNextId, testThread);

	std::thread second(&X::getNextId, testThread);

	first.join();
	second.join();
	std::cout << testThread.getInt() << std::endl;;

	testThread.getNextId();

	std::cout << testThread.getInt() << std::endl;

	system("pause");
    return 0;
}


void insertBox(std::vector<box> & boxVector, const box & newBox) {
	
	bool inserted = false;
	if (boxVector.empty()) {
		boxVector.push_back(newBox);
	}
	else
	{
		for (std::vector<box>::iterator it = boxVector.begin();
			it != boxVector.end(); it++) {
			if (*it <  newBox) {
				boxVector.insert(it, newBox);
				inserted = true;
				break;
			}
		}
		if (!inserted) {
			boxVector.push_back(newBox);
		}
	}

}

void printVector(const std::vector<box>& boxVector) {
	for (std::vector<box>::const_iterator it = boxVector.begin();
		it != boxVector.end(); it++) {
		it->print();
	}
}


void stackBoxesRecurse(const std::vector<box> & boxVector, int index, int &max, std::stack<box> boxStack,
						int runningHeight) {
	recursiveCalls++;
	if (index > boxVector.size()) {
		return;
	}
	if (boxStack.empty()) {
		boxStack.push(boxVector.at(index));
		runningHeight += boxVector.at(index).height;
		if (runningHeight > max) {
			max = runningHeight;
		}
		stackBoxesRecurse(boxVector, index +1, max, boxStack, runningHeight);
	}
	else
	{
		for (int i = index+1; i < boxVector.size(); i++) {
			if (boxVector.at(index).width < boxStack.top().width &&
				boxVector.at(index).depth < boxStack.top().depth) {
				boxStack.push(boxVector.at(i));
				runningHeight += boxVector.at(i).height;
				if (runningHeight > max) {
					max = runningHeight;
				}
			}
			stackBoxesRecurse(boxVector, i, max, boxStack, runningHeight);
		}
	}

}

