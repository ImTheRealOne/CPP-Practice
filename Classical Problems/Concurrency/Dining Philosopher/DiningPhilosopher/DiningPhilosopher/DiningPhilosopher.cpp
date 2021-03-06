// DiningPhilosopher.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include <string>
#include <chrono>

const int NUM_OF_PHILOSOPHER = 5;
const int NUM_OF_FORKS = NUM_OF_PHILOSOPHER;

std::mutex coutMutex;

void initializeChopSticks(std::vector<std::mutex *> * chopStickVector);
void eat(std::vector<std::mutex *> * chopStickVector, std::string philosopher);
void ctciEat(std::vector<std::mutex *> * chopStickVector, int philosopher);
int main()
{
	std::vector<std::mutex *> * chopsticks = new std::vector<std::mutex *> (NUM_OF_FORKS);
	std::vector<std::thread> philosophers(NUM_OF_PHILOSOPHER);
	
	/*std::thread thread1(eat, "1");
	std::thread thread2(eat, "2");
	std::thread thread3(eat, "3");
	std::thread thread4(eat, "4");
	std::thread thread5(eat, "5");

	philosophers.push_back(std::move(thread1));
	philosophers.push_back(std::move(thread2));
	philosophers.push_back(std::move(thread3));
	philosophers.push_back(std::move(thread4));
	philosophers.push_back(std::move(thread5));*/

	initializeChopSticks(chopsticks);

	for (int i = 0; i < NUM_OF_PHILOSOPHER; i++) {
		philosophers[i] = std::thread (ctciEat,chopsticks, i);
		
		//philosophers.emplace_back(std::move(std::thread(eat, chopsticks, std::to_string(i)))); 
			//oringinal main thread finish first?
	}

	for (int i = 0; i < NUM_OF_PHILOSOPHER; i++) {
		if (philosophers.at(i).joinable()) {
			philosophers.at(i).join();
		}
	}

	system("pause");
    return 0;
}
void initializeChopSticks(std::vector<std::mutex *> * chopSticksVector) {
	for (int i = 0; i < chopSticksVector->size(); i++) {
		chopSticksVector->at(i) = new std::mutex;
	}
}

void eat(std::vector<std::mutex *> * chopStickVector, std::string philosopher) {
	int timesEat = 0;
	bool hasFork1 = false;
	int fork1Index = 0;
	while (timesEat < 5) {
		//pick up a single fork from 1 to 4
		if (!hasFork1) {
			std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
			for (int i = 0; i < chopStickVector->size() - 1; i++) {
				if (chopStickVector->at(i)->try_lock()) {
					hasFork1 = true;
					fork1Index = i;
					break;
				}
			}
		}
		if (hasFork1) {
			if (chopStickVector->at(chopStickVector->size() - 1)->try_lock()) {
				hasFork1 = false;
				timesEat++;
				coutMutex.lock();
				std::cout << std::endl <<" philosopher " << philosopher << " is eating for the " << timesEat << " time" << std::endl;
				coutMutex.unlock();
				chopStickVector->at(fork1Index)->unlock();
				chopStickVector->at(chopStickVector->size() - 1)->unlock();
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
			}
		}

	}
};


void ctciEat(std::vector<std::mutex *> * chopStickVector, int philosopher) {
	int prev;
	int timesEat = 0;
	int left = (philosopher - 1 > 0) ? philosopher - 1 : NUM_OF_PHILOSOPHER - 1;
	int right = (philosopher + 1 < NUM_OF_PHILOSOPHER - 1) ? philosopher + 1 : 0;
	while (timesEat < 5) {
		if (chopStickVector->at(left)->try_lock()) {
			if (chopStickVector->at(right)->try_lock()) {
				timesEat++;
				coutMutex.lock();
				std::cout << std::endl << " philosopher " << philosopher << " is eating for the " << timesEat << " time" << std::endl;
				coutMutex.unlock();
				chopStickVector->at(right)->unlock();
				chopStickVector->at(left)->unlock();
			}
			else
			{
				chopStickVector->at(left)->unlock();
				
			}
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}


	}
	

}