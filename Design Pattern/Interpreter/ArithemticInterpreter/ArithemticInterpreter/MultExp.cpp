#include "stdafx.h"
#include "MultExp.h"


MultExp::MultExp(ArithmeticExp* op1, ArithmeticExp* op2)
{
	_operand1 = op1;
	_operand2 = op2;
}


MultExp::~MultExp()
{
	delete _operand1;
	delete _operand2;
}


int MultExp::Evaluate(Context& aContext) {
	return _operand1->Evaluate(aContext) *
		_operand2->Evaluate(aContext);
}

ArithmeticExp* MultExp::Copy() const {
	return new MultExp(_operand1->Copy(), _operand2->Copy());
}

ArithmeticExp* MultExp::Replace(const char* name, ArithmeticExp& exp) {
	return new MultExp(_operand1->Replace(name, exp),
		_operand2->Replace(name, exp));
}



