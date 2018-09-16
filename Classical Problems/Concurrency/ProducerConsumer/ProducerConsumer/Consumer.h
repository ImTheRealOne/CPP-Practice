#pragma once
#include <vector>
#include <mutex>
#include <random>
#include <iostream>
class Consumer
{
public:
	Consumer();
	Consumer(std::vector<int> * newBuffer, volatile int * newBufferLimit, std::mutex *newMutex);
	~Consumer();

	void setBuffer(std::vector<int> * newBuffer);
	void consume();
private:
	std::vector<int> * buffer;
	volatile int * bufferLimit;
	std::mutex * consumerSemaphore;

};

