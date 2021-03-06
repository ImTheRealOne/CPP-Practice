// CallCenter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Respondent.h"
#include "Director.h"
#include "Manager.h"
#include <random>
#include <time.h>

int main()
{
	Director topDog = *new Director("Director of El Monte");
	Manager midDog = *new Manager(&topDog, "Manager of North El Monte Branch");
	Respondent bottomDog = *new Respondent(&midDog, "Scrub of North El Monte Branch");

	srand(time(NULL));
	int callLevel;
	for (int i = 0; i < 10; i++) {
		callLevel = rand() % 4 + 1;
		bottomDog.handleCall(callLevel);

	}

	system("pause");
    return 0;
}

