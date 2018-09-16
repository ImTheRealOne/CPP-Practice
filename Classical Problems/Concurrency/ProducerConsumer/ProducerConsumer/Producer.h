#pragma once
#include <vector>
#include <mutex>
#include <random>
#include <iostream>
class Producer
{
public:
	Producer();
	Producer(std::vector<int> *  buffer, volatile int * bufferLmit, std::mutex * newMutex);
	~Producer();
	void produce();
	
	void setBuffer(std::vector<int> * buffer);
	std::vector<int> getBuffer();
private:
	std::vector<int> * buffer;
	std::mutex * producerSemaphore;
	volatile int * bufferLimit;

};

