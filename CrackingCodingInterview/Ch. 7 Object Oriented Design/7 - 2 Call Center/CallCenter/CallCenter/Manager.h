#pragma once
#include "Employee.h"
class Manager :
	public Employee
{
public:
	Manager();
	~Manager();

	inline virtual void handleCall(const int level);
	Manager(Employee* newSucessor, std::string newTitle) : Employee(newSucessor) { employeeLevel = 2; title = newTitle; };
private:
	Manager * parent;
};

void Manager::handleCall(const int level) {
	if (employeeLevel == level) {
		std::cout <<title<< " handled call" << std::endl;
	}
	else
	{
		Employee::handleCall(level);
	}
}
