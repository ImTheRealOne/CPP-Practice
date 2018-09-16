#include "stdafx.h"
#include "AddExp.h"


AddExp::AddExp(ArithmeticExp* op1, ArithmeticExp* op2)
{
	_operand1 = op1;
	_operand2 = op2;
}


AddExp::~AddExp()
{
	delete _operand1;
	delete _operand2;
}

int AddExp::Evaluate(Context& aContext) {
	return
		_operand1->Evaluate(aContext) +
		_operand2->Evaluate(aContext);
}

ArithmeticExp* AddExp::Copy() const {
	return new AddExp(_operand1->Copy(), _operand2->Copy());
}

ArithmeticExp* AddExp::Replace(const char* name, ArithmeticExp& exp) {
	return new AddExp(_operand1->Replace(name, exp),
		_operand2->Replace(name, exp));
}
