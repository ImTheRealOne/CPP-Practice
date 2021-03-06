// 16-12 XMLencoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

std::string readFromFile(std::string fileName);
bool writeToFile(std::string fileName);
std::string encodeString(std::string line);



int main()
{
	std::string encodedXML = readFromFile("test.xml");
	//writeToFile("test.xml");
	std::cout <<"solution "<< std::endl << encodedXML;
	system("pause");
    return 0;
}

std::string readFromFile(const std::string fileName)
{
	std::string result = "";
	std::fstream filestream;
	std::string line;
	filestream.open(fileName);

	if (filestream.is_open()) {
		while (std::getline(filestream, line)) {
			std::cout << line << std::endl;
			result += encodeString(line);
		}
	}
	else
	{
		result = "failed to open file";
	}

	return result;
}

bool writeToFile(std::string fileName)
{
	bool success = false;
	std::ofstream outputFileStream;
		
	outputFileStream.open(fileName, std::ios::app);

	if (outputFileStream.is_open()) {
		success = true;
	}
	else
	{
		success = false;
	}

	return success;
}

std::string encodeString(std::string line)
{
	std::vector<std::string> tags = {">", "family", "person", "firstName", "lastName", "state", "=\"" };
	std::vector<std::regex> regExpTags = { std::regex("^</\\*\\>"), std::regex("family"), std::regex("person") ,
				std::regex("firstName"), std::regex("lastName"), std::regex("state") };
	std::size_t found = 0;
	while (found != std::string::npos) {
		for (int i = 0; i < tags.size(); i++) {
			found = std::string::npos;
			found = line.find(tags.at(i));
			if (found != std::string::npos) {

				if (i == 0) {
					std::size_t prevGreaterThanIndex = line.rfind("</", found);
					
					line.replace(found, tags.at(i).length(), std::to_string(i) + " ");

					if(prevGreaterThanIndex != std::string::npos)
						line.replace(prevGreaterThanIndex, found-prevGreaterThanIndex , " ");
					else
					{
						prevGreaterThanIndex = line.rfind("<", found);
						line.replace(prevGreaterThanIndex, 1, " ");
					}
				}
				else if (i == 6) {
					std::size_t endQuotationIndex = 0;
					line.replace(found, 2, "");
					endQuotationIndex = line.find("\"", found + 1);
					line.replace(endQuotationIndex, 1, " ");
				}
				else {
					line.replace(found, tags.at(i).length(), std::to_string(i) + " ");
				}
			}
			std::cout << line << std::endl;
		}
	}

	return line;
}
