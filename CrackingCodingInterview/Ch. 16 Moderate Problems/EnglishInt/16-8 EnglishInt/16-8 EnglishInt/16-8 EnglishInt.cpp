// 16-8 EnglishInt.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

std::string englishIntStringBuilder(const int number);
std::string threePlaceBuilder(const int number);
std::string teensStringBuild(const int number);
std::string onesStringBuilder(const int number);
std::string tensStringBuilder(const int number);
std::string hundredsStringBuilder(const int number);
std::string thousandsStringBuilder(const int number);
std::string millionsStringBuilder(const int number);

int main()
{

	/*for (int i = 0; i < 100; i++) {
		std::cout<<englishIntStringBuilder(i)<<std::endl;

	}*/
	std::cout << englishIntStringBuilder(1000303) << std::endl;
	std::cout << englishIntStringBuilder(-11111113) << std::endl;
	std::cout << englishIntStringBuilder(-120123113) << std::endl;
	std::cout << englishIntStringBuilder(-100030000) << std::endl;

	system("pause");
    return 0;
}

std::string englishIntStringBuilder(const int number)
{
	std::string result = "";
	
	int tempNum = number;
	
	if (tempNum < 0) {
		result += "negative ";
		tempNum *= -1;
	}
	/*
	if (tempNum >= 1000) {
		int thousandthPlace = tempNum / 1000;
		if (thousandthPlace >= 100) {
			result += hundredsStringBuilder(thousandthPlace);
			thousandthPlace = thousandthPlace % 100;
		}
		if (thousandthPlace <= 19 && thousandthPlace >= 10) {
			result += teensStringBuild(thousandthPlace);
		}
		else
		{
			result += tensStringBuilder(thousandthPlace / 10);
			if (thousandthPlace % 10 != 0)
				result += onesStringBuilder(thousandthPlace % 10);
		}
		tempNum = tempNum % 1000;
		result += " thousand ";
	}
	if (tempNum >= 100) {
		result += hundredsStringBuilder(tempNum / 100);
		tempNum = tempNum % 100;
	}
	if (tempNum >= 0) {
		if (tempNum <= 19 && tempNum >= 10) {
			result += teensStringBuild(tempNum);
		}
		else
		{
			result += tensStringBuilder(tempNum / 10);
			if(tempNum % 10 != 0)
				result += onesStringBuilder(tempNum % 10);
		}
	}

	*/
	if (tempNum <= 999999999 && tempNum >= 1000000) {
		result += millionsStringBuilder(tempNum / 1000000);
		tempNum = tempNum % 1000000;
	}

	if (tempNum <= 999999 && tempNum >= 1000) {
		result += ", " + thousandsStringBuilder(tempNum / 1000);
		tempNum = tempNum % 1000;
	}
	if (tempNum <= 999 && tempNum >= 1){
		result += ", " + hundredsStringBuilder(tempNum);
	}

	return result;
}

std::string threePlaceBuilder(const int number) {
	std::string result = "";
	bool andFlag = 0;
	int tempNum = number;
	if (tempNum >= 100) {
		result += hundredsStringBuilder(tempNum / 100) + " hundred ";
		tempNum = tempNum % 100;
		andFlag = true;
	}
	if (tempNum >= 0) {
		if (tempNum <= 19 && tempNum >= 10) {
			result += teensStringBuild(tempNum);
		}
		else
		{
			result += tensStringBuilder(tempNum / 10);
			if (tempNum % 10 != 0)
				result += (andFlag) ? " and " : "";
				result += onesStringBuilder(tempNum % 10);
		}
	}
	return result;
}

std::string teensStringBuild(const int number) {
	std::string result = "";
	switch (number) {
		case 10:
			result = " ten ";
			break;
		case 11 :
			result = " eleven ";
			break;
		case 12 :
			result = " twelve ";
			break;
		case 13 :
			result = " thirteen ";
			break;
		case 14 :
			result = " fourteen ";
			break;
		case 15 : 
			result = " fifteen ";
			break;
		case 16 : 
			result = " sixteen ";
			break;
		case 17 : 
			result = " seventeen ";
			break;
		case 18 :
			result = " eighteen ";
			break;
		case 19 :
			result = " nineteen ";
			break;
		default :
			break;
	}

	return result;
}

std::string onesStringBuilder(const int number)
{
	std::string result = "";
	switch (number)
	{
		case 0:
			result = " zero ";
			break;
		case 1:
			result = " one ";
			break;
		case 2:
			result = " two ";
			break;
		case 3:
			result = " three ";
			break;
		case 4:
			result = " four ";
			break;
		case 5:
			result = " five ";
			break;
		case 6:
			result = " six ";
			break;
		case 7:
			result = " seven ";
			break;
		case 8:
			result = " eight ";
			break;
		case 9:
			result = " nine ";
			break;
		
	default:
		break;
	}
	return result;
}

std::string tensStringBuilder(const int number) {
	std::string result = "";

	switch ( number)
	{
		case 2:
			result = " twenty ";
			break;
		case 3:
			result = " thirty ";
			break;
		case 4:
			result = " fourty ";
			break;
		case 5:
			result = " fifty ";
			break;
		case 6:
			result = " sixty ";
			break;
		case 7:
			result = " seventy ";
			break;
		case 8:
			result = " eighty ";
			break;
		case 9:
			result = " ninety ";
			break;
	default:
		break;
	}
	return result;
}

std::string hundredsStringBuilder(const int number)
{
	std::string result = "";
	result += threePlaceBuilder(number);

	return result;
}

std::string thousandsStringBuilder(const int number)
{
	std::string result = "";
	result += threePlaceBuilder(number );
	
	return result + " thousand";
}

std::string millionsStringBuilder(const int number)
{
	std::string result;
	result += threePlaceBuilder(number);

	return result + " million";
}
