// CallinOrder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Foo.h"


int main()
{

	Foo foo;
	
	std::thread threadC(&Foo::third, &foo);
	std::thread threadB(&Foo::second, &foo);
	std::thread threadA(&Foo::first,&foo);
	threadC.join();
	threadB.join();
	threadA.join();

	system("pause");
    return 0;
}

