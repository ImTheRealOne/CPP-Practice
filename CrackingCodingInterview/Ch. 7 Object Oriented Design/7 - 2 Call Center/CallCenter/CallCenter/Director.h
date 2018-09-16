#pragma once
#include "Employee.h"
class Director :
	public Employee
{
public:
	Director();
	~Director();
	inline virtual void handleCall(const int level);
	Director( std::string newTitle) { employeeLevel = 3; title = newTitle; };

private:
	Director* parent;
};

void Director::handleCall(const int level) {
	if (employeeLevel == level) {
		std::cout <<title << " handled call" << std::endl;
	}
	else
	{
		std::cout << "no one can help you :(" << std::endl;
	}
}


