#pragma once
#include "ArithmeticExp.h"
class MultExp : public ArithmeticExp
{
public:
	MultExp(ArithmeticExp*, ArithmeticExp*);
	~MultExp();

	virtual int Evaluate(Context &);
	virtual ArithmeticExp* Replace(const char*, ArithmeticExp&);
	virtual ArithmeticExp* Copy() const;

private:
	ArithmeticExp * _operand1;
	ArithmeticExp* _operand2;
};

