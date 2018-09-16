#include "stdafx.h"
#include "SubExp.h"


SubExp::SubExp(ArithmeticExp* op1, ArithmeticExp* op2)
{
	_operand1 = op1;
	_operand2 = op2;
}


SubExp::~SubExp()
{
}

int SubExp::Evaluate(Context& aContext) {
	return _operand1->Evaluate(aContext) -
		_operand2->Evaluate(aContext);
}

ArithmeticExp* SubExp::Copy() const {
	return new SubExp(_operand1->Copy(), _operand2->Copy());
}

ArithmeticExp* SubExp::Replace(const char* name, ArithmeticExp& exp) {
	return new SubExp(_operand1->Replace(name, exp),
		_operand2->Replace(name, exp));
}

