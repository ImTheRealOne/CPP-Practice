// BitVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	Vector<int> driverVector;
	
	driverVector.insert(0, 3);

	driverVector.print();

	driverVector.insert(0, 4);
	driverVector.print();
	driverVector.insert(0, 5);
	driverVector.print();
	driverVector.insert(0, 6);
	driverVector.print();

	Vector<int> driver2Vector(driverVector);

	driver2Vector.print();


	system("pause");
    return 0;
}

