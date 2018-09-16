#pragma once

#include "ArithmeticExp.h"

class DivExp : public ArithmeticExp
{
public:
	DivExp(ArithmeticExp*, ArithmeticExp*);
	~DivExp();

	virtual int Evaluate(Context &);
	virtual ArithmeticExp* Replace(const char*, ArithmeticExp&);
	virtual ArithmeticExp* Copy() const;

private:
	ArithmeticExp * _operand1;
	ArithmeticExp* _operand2;
};

