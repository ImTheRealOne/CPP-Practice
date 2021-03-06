// ArithemticInterpreter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ArithmeticExp.h"
#include "Context.h"
#include "VariableExp.h"
#include "AddExp.h"
#include <iostream>
int main()
{
	ArithmeticExp* expression;
	Context context;
	
	VariableExp* x = new VariableExp("X");
	VariableExp* y = new VariableExp("Y");

	expression = new AddExp(x, y);

	context.Assign(x, 9);
	context.Assign(y, 1);

	int result = expression->Evaluate(context);

	std::cout << result << std::endl;

	system("pause");
    return 0;
}



