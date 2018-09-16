#include "stdafx.h"
#include "Consumer.h"


Consumer::Consumer()
{
	buffer =  new std::vector<int>();
	bufferLimit = 0;
}

Consumer::Consumer(std::vector<int> * newBuffer, volatile int * newBufferLimit, std::mutex * newMutex) {
	buffer = newBuffer;
	bufferLimit = newBufferLimit;
	consumerSemaphore = newMutex;
}

Consumer::~Consumer()
{
}

void Consumer::consume() {
	while (true) {
		//std::cout << std::endl << "buff limit : " << *bufferLimit;
		if (*bufferLimit > 0) {
			consumerSemaphore->lock(); 
			(*bufferLimit)--;
			std::cout << std::endl << "consumer consumed : " << *buffer->begin() << std::endl;

			buffer->erase(buffer->begin());
			consumerSemaphore->unlock();
		}
		else
		{
		}

	}

}
