#pragma once
#include "ArithmeticExp.h"

class SubExp : ArithmeticExp
{
public:
	SubExp(ArithmeticExp*, ArithmeticExp*);
	~SubExp();

	virtual int Evaluate(Context &);
	virtual ArithmeticExp* Replace(const char*, ArithmeticExp&);
	virtual ArithmeticExp* Copy() const;

private:
	ArithmeticExp* _operand1;
	ArithmeticExp* _operand2;

};

