#pragma once

#include <string>

class Book
{
public:
	Book();
	~Book();
	

private:
	int isbn;
	std::string title;
	std::string author;
	int pages;
	int yearReleased;
	std::string publisher;
	int edition;

};

