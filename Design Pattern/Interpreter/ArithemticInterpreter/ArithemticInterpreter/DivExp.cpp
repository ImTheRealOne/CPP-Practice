#include "stdafx.h"
#include "DivExp.h"


DivExp::DivExp(ArithmeticExp* op1, ArithmeticExp* op2)
{
	_operand1 = op1;
	_operand2 = op2;
}


DivExp::~DivExp()
{
	delete _operand1;
	delete _operand2;
}


int DivExp::Evaluate(Context& aContext) {
	return _operand1->Evaluate(aContext) /
		_operand2->Evaluate(aContext);
}

ArithmeticExp* DivExp::Copy() const {
	return new DivExp(_operand1->Copy(), _operand2->Copy());
}

ArithmeticExp* DivExp::Replace(const char* name, ArithmeticExp& exp) {
	return new DivExp(_operand1->Replace(name, exp),
		_operand2->Replace(name, exp));
}



