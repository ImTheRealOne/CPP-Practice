#ifndef MAIN_CPP
#define MAIN_CPP




#include "Main.h"
#include "Vector.h"


Main::Main()
{
}


Main::~Main()
{
}

int main(int argc, const char * argv[]) {
	Vector<int> driverVector;
	Vector<int> driverVector2;

	driverVector.insert(0, 3);
	driverVector.insert(0, 4);
	driverVector.print();
	driverVector.insert(0, 5);
	driverVector.print();
	driverVector.insert(2, 7);




	system("pause");
	return 0;
}

#endif // !MAIN_CPP

