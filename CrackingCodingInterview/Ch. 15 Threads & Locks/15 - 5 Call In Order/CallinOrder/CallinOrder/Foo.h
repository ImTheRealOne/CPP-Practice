#pragma once
class Foo
{
public:
	Foo();
	~Foo();
	void first();
	void second();
	void third();
private:
	std::mutex lock;
	std::condition_variable cv;
	bool secondFunc;
	bool thirdFunc;
};

