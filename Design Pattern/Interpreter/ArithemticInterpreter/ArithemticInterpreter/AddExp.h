#pragma once


#include "ArithmeticExp.h"

class AddExp : public ArithmeticExp
{
public:
	AddExp(ArithmeticExp*, ArithmeticExp*);
	~AddExp();

	virtual int Evaluate(Context &);
	virtual ArithmeticExp* Replace(const char*, ArithmeticExp&);
	virtual ArithmeticExp* Copy() const;

private:
	ArithmeticExp* _operand1;
	ArithmeticExp* _operand2;


};




