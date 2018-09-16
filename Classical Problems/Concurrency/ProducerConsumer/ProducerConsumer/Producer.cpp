#include "stdafx.h"
#include "Producer.h"


Producer::Producer()
{
	buffer =  new std::vector<int>();
	bufferLimit = 0;
}

Producer::Producer(std::vector<int> * newBuffer,volatile int * newBufferLimit, std::mutex * newMutex) {
	buffer = newBuffer;
	bufferLimit = newBufferLimit;
	producerSemaphore = newMutex;
}

Producer::~Producer()
{

}

void Producer::setBuffer(std::vector<int>  * newBuffer) {
	buffer = newBuffer;
}

void Producer::produce() {
	int item;
	srand(time(NULL));
	while (true) {
		if (*bufferLimit < 10) {
			item = rand() % 100;
			producerSemaphore->lock();
			(*bufferLimit)++;
			buffer->push_back(item);
			std::cout << std::endl << "Producer produced : " << item << std::endl;
			producerSemaphore->unlock();
		}
		else
		{
		}
	}
}
