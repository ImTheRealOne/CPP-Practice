#pragma once
#ifndef CONTEXT_H
#define CONTEXT_H

#include "VariableExp.h"
#include <map>
#include "ArithmeticExp.h"
class VariableExp;
class Context
{
public:
	Context();
	~Context();

	int Lookup( char*) const;
	void Assign(VariableExp *, int);

private:
	std::map<char *, int> * map;
};

#endif // !CONTEXT_H