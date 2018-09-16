#pragma once
#include <string>
#include <iostream>
class Employee
{
public:
	Employee();
	Employee(Employee* newSucessor) : successor(newSucessor) {};
	~Employee();

	inline virtual void handleCall(const int level);
private:
	Employee* successor;
protected:
	std::string title;
	int employeeLevel;
};

void Employee::handleCall(const int level) {
	if (successor != 0) {
		successor->handleCall(level);
	}

}