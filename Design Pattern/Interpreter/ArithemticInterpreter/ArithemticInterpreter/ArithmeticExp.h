#pragma once
#ifndef ARITHMETICEXP_H
#define ARITHMETICEXP_H

class Context;
class ArithmeticExp
{
public:
	ArithmeticExp();
	virtual ~ArithmeticExp();

	virtual int Evaluate(Context &) = 0;
	virtual ArithmeticExp * Replace(const char*, ArithmeticExp &) = 0;
	virtual ArithmeticExp * Copy() const = 0;

};


#endif // !ARITHMETICEXP_H

