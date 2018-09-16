#include "stdafx.h"
#include "VariableExp.h"


VariableExp::VariableExp(const char* name)
{
	_name = _strdup(name);
}


VariableExp::~VariableExp() {
	delete _name;
}

int VariableExp::Evaluate(Context& aContext) {
	return aContext.Lookup(_name);
}

ArithmeticExp * VariableExp::Copy() const
{
	return new VariableExp(_name);
}

ArithmeticExp * VariableExp::Replace(const char* name, ArithmeticExp& exp) {
	if (strcmp(name, _name) == 0) {
		return exp.Copy();
	}
	else
	{
		return new VariableExp(_name);
	}
}

char* VariableExp::getName() {
	return _name;
}