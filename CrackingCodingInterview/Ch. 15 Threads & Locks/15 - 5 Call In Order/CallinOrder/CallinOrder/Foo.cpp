#include "stdafx.h"
#include "Foo.h"


Foo::Foo()
{
	secondFunc = false;
	thirdFunc = false;
}


Foo::~Foo()
{
}

void Foo::first() {
	std::cout << "first " << std::endl;
	secondFunc = true;
	//std::this_thread::sleep_for(std::chrono::seconds(4));
	cv.notify_all();
	
}

void Foo::second() {
	std::unique_lock<std::mutex> uniqLock(lock);
	while (!secondFunc) {
		cv.wait(uniqLock);
	}
		std::cout << "second" << std::endl;
		thirdFunc = true;
		cv.notify_all();
}

void Foo::third() {
	std::unique_lock<std::mutex> uniqLock(lock);
	while (!thirdFunc) {
		cv.wait(uniqLock);
	}
		std::cout << "third" << std::endl;
}