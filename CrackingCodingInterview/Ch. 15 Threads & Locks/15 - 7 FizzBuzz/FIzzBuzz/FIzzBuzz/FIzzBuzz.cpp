// FIzzBuzz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <mutex>
#include <iostream>
#include <string>

void checkFizz();
void checkBuzz();
void checkFizzBuzz();
void FizzBuzz();

bool fizzBuzz = false;
bool fizz = false;
bool buzz = false;
bool iterationDone = false;
bool finished = false;

std::condition_variable cv;
std::condition_variable cv_checkFizzBuzz;
std::condition_variable cv_FizzBuzzGen;
std::mutex lock;
std::mutex coutLock;

int num;
const int MAX = 20;

void FizzBuzzCheck(const int divisor, std::string output, int currentThread);
void FizzBuzzNumGen();

bool numberGenerated;
int updated = 0;


int main()
{
	/*std::thread startFizzBuzz(FizzBuzz);
	std::thread FizzBuzzThread(checkFizzBuzz);
	std::thread fizzThread(checkFizz);
	std::thread buzzThread(checkBuzz);
	

	
	startFizzBuzz.join();
	FizzBuzzThread.join();
	fizzThread.join();
	buzzThread.join();*/


	std::thread startFizzBuzz(FizzBuzzNumGen);
	std::thread FizzBuzzThread(FizzBuzzCheck, 15, "FizzBuzz", 0);
	std::thread fizzThread(FizzBuzzCheck, 3, "Fizz", 1);
	std::thread buzzThread(FizzBuzzCheck, 5, "Buzz", 2);

	startFizzBuzz.join();
	FizzBuzzThread.join();
	fizzThread.join();
	buzzThread.join(); 



	system("pause");
    return 0;
}

void FizzBuzzCheck(const int divisor,  std::string output, int currentThread) {
	while (num < MAX) {
		std::unique_lock<std::mutex> uniqueLock(lock, std::defer_lock);
		while (!uniqueLock.try_lock()) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		while (!numberGenerated) {
			cv_FizzBuzzGen.wait(uniqueLock);
		}
		
		std::cout << "updated : " << updated << "   currentTHread : " << currentThread << std::endl;
		while (updated != currentThread) {
			cv_checkFizzBuzz.wait(uniqueLock);
		}
		if (updated == currentThread) {
			if (num % divisor == 0) {
				coutLock.lock();
				std::cout << output;
				coutLock.unlock();
			}

			updated += 1;
			cv_checkFizzBuzz.notify_all();
		}
	}
	
}

void FizzBuzzNumGen() {
	std::unique_lock<std::mutex> uniqueLock(lock);

	for (int i = 1; i < MAX; i+=2) {
		num = i;
		coutLock.lock();
		std::cout << "Num : " << num << " ";
		coutLock.unlock();
		numberGenerated = true;
		cv_FizzBuzzGen.notify_all();
		while (updated < 2)
		{
			cv_checkFizzBuzz.wait(uniqueLock);
		}
		numberGenerated = false;
		updated = 0;
	}

}



void checkFizz() {
	while (!finished) {
		std::unique_lock<std::mutex> unique_lock(lock);
		while (!fizz) {
			cv.wait(unique_lock);
		}
		if (!iterationDone) {
			if (num % 3 == 0) {
				coutLock.lock();
				std::cout << "Fizz";
				coutLock.unlock();
			}
		}
		buzz = true;
		fizz = false;
		cv.notify_all();

	}

}

void checkBuzz() {
	while (!finished) {
		std::unique_lock<std::mutex> unique_lock(lock);
		while (!buzz) {
			cv.wait(unique_lock);
		}

		if (num % 5 == 0) {
			coutLock.lock();
			std::cout << "Buzz"; 
			coutLock.unlock();
		}
		std::cout << std::endl;
		iterationDone = true;
		buzz = false;
		cv.notify_all();
	}
	

}

void checkFizzBuzz() {
	while (!finished)
	{
		std::unique_lock<std::mutex> unique_lock(lock);
		while (!fizzBuzz) {
			cv.wait(unique_lock);
		}
		if (num % 15 == 0) {
			std::cout << "FizzBuzz" << std::endl;
			iterationDone = true;
			cv.notify_all();
		}
		else
		{
			fizz = true;
			cv.notify_all();
		}
		fizzBuzz = false;
		cv.notify_all();
	}
	
}

void FizzBuzz() {
	std::unique_lock<std::mutex> unique_lock(lock);

	for (int i = 1; i < 20; i += 2) {
		num = i;
		coutLock.lock();
		std::cout << "num : " << num << "  -  ";
		coutLock.unlock();
		fizzBuzz = true;
		cv.notify_all();
		while (!iterationDone) {
			cv.wait(unique_lock);
		}
		iterationDone = false;
		

	}
	finished = true;
	fizzBuzz = true;
	fizz = true;
	buzz = true;
	cv.notify_all();
}
