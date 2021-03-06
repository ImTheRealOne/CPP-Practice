// TowerOfHanoiRecur.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <iostream>
#include <vector>

const int NUMOFDISK = 4;

std::vector<std::stack<int>> createTower(int size);
std::stack<int> initializeRod(int size);
void printTower(std::vector<std::stack<int>> tower);
void iterativeSolverSimp(std::vector<std::stack<int>> & tower);
void recursionSolver(int n, std::stack<int> &source, std::stack<int> &target, std::stack<int> &aux);
void swap(std::stack<int> & a, std::stack<int> & b);
void printStack(std::stack<int> peg);

int main()
{
	std::vector<std::stack<int>> towerOfHanoi;

	std::stack<int> a;
	a.empty();

	towerOfHanoi = createTower(NUMOFDISK);

	printTower(towerOfHanoi);


	//iterativeSolverSimp(towerOfHanoi);

	recursionSolver(NUMOFDISK, towerOfHanoi.at(0), towerOfHanoi.at(2), towerOfHanoi.at(1));

	printTower(towerOfHanoi);

	system("pause");
    return 0;
}

std::vector<std::stack<int>> createTower(int size) {
	std::vector<std::stack<int>> tower = *new std::vector<std::stack<int>>();

	std::stack<int> rod1;
	std::stack<int> rod2;
	std::stack<int> rod3;

	rod1 = initializeRod(size);
	rod2 = initializeRod(0);
	rod3 = initializeRod(0);


	tower.push_back(rod1);
	tower.push_back(rod2);
	tower.push_back(rod3);



	return tower;
}

std::stack<int> initializeRod(int size) {
	std::stack<int> rod = *new std::stack<int>();

	for (int i = size; i > 0; i--) {
		rod.push(i);
	}

	return rod;
}

void printTower(std::vector<std::stack<int>> tower) {
	for (int i = 0; i < tower.size();i++)  {
		std::cout << "Rod " << i << ": ";
		while (!tower.at(i).empty())
		{
			std::cout << tower.at(i).top() << " ";
			tower.at(i).pop();
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void printStack(std::stack<int> peg) {

	std::cout << "Rod " << ": ";
	while (!peg.empty())
	{
		std::cout << peg.top() << " ";
		peg.pop();
	}
	std::cout << std::endl;
}



void iterativeSolverSimp(std::vector<std::stack<int>> & tower) {
	//n is odd
	if (NUMOFDISK % 2 == 1) {
		while (tower.at(2).size() < NUMOFDISK) {
				swap(tower.at(0), tower.at(2));
				printTower(tower);
			if (tower.at(2).size() >= NUMOFDISK) {
				break;
			}
			swap(tower.at(0), tower.at(1));
			printTower(tower);
			swap(tower.at(1), tower.at(2));
			printTower(tower);
			if (tower.at(2).size() >= NUMOFDISK) {
				break;
			}
		}
	}
	//n is even
	else
	{
		while (tower.at(2).size() < NUMOFDISK) {
			swap(tower.at(0), tower.at(1));
			printTower(tower);
			swap(tower.at(0), tower.at(2));
			printTower(tower);
			if (tower.at(2).size() >= NUMOFDISK) {
				break;
			}
			swap(tower.at(1), tower.at(2));
			printTower(tower);
			if (tower.at(2).size() >= NUMOFDISK) {
				break;
			}
		}
	}
	

}

void swap(std::stack<int> & a, std::stack<int> & b) {
	if (!a.empty() && !b.empty()) {
		//a top is bigger than b top;
		//push b top onto a
		if (a.top() > b.top()) {
			a.push(b.top());
			b.pop();
		}
		//b top is bigger than a top
		//push a top onto b
		else
		{
			b.push(a.top());
			a.pop();
		}
	}
	else
	{
		//a is empty push b top onto a
		if (a.empty() && !b.empty()) {
			a.push(b.top());
			b.pop();
		}
		//b is empty push a top onto b
		else if (!a.empty())
		{
			b.push(a.top());
			a.pop();
		}
	}
}

void recursionSolver(int n, std::stack<int>& source, std::stack<int> & target, std::stack<int> & aux) {
	if (n > 0) {
		recursionSolver(n - 1, source, aux, target);

		swap(source, target);

		printStack(source);
		printStack(aux);
		printStack(target);
		std::cout << std::endl;

		recursionSolver(n - 1, aux, target, source);
	}
}