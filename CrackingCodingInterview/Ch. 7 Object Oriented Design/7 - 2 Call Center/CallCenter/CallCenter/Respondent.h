#pragma once
#include "Employee.h"
class Respondent : public Employee
{
public:
	Respondent();
	~Respondent();
	
	inline virtual void handleCall(const int level);
	Respondent(Employee* newSucessor, std::string newTitle) : Employee(newSucessor) { employeeLevel = 1; title = newTitle; };

private:
	Respondent * parent;


};

void Respondent::handleCall(const int level) {
	if (level == employeeLevel) {
		std::cout <<title<< " handled call" << std::endl;
	}
	else
	{
		Employee::handleCall(level);
	}
}