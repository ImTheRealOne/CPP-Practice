#pragma once
#ifndef VARIABLE_H
#define VARIABLE_H


#include "ArithmeticExp.h"
#include "Context.h"
class VariableExp : public ArithmeticExp
{
public:
	VariableExp(const char*);
	virtual ~VariableExp();
	
	virtual int Evaluate(Context & aContext);
	virtual ArithmeticExp* Replace(const char*, ArithmeticExp&);
	virtual ArithmeticExp* Copy() const;
	char* getName();
private:
	char* _name;
};



#endif // !VARIABLE_H

