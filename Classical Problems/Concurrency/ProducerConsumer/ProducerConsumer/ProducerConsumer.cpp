// ProducerConsumer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include "Producer.h"
#include "Consumer.h"
#include <mutex>



int main()
{
	std::vector<int> buffer;
	std::mutex lock;
	static int bufferCount = 0;


	
	Producer p(&buffer, &bufferCount, &lock);
	Consumer * c = new Consumer(&buffer, &bufferCount, &lock);

	std::thread producerThread (&Producer::produce, p);
	std::thread consumerThread(&Consumer::consume, c);

	producerThread.join();
	consumerThread.join();

	system("pause");
    return 0;
}

