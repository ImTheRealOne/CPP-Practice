	// Lamda Expression.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Country {
private:
	int population;
	std::string continentName;
	std::string countryName;
public:
	Country(int pop, std::string continent, std::string country) :
		population(pop), continentName(continent), countryName(country) {};

	int getPopulation() { return population; }
	std::string getContinent() { return continentName; }
	std::string getCountry() { return countryName; }


};

int getPopulation(std::vector<Country> countries, std::string continent);

int main()
{
	Country usa(3000, "North America", "usa");
	Country mexico(5000, "North America", "mexico");
	Country canada(2000, "North America", "canada");

	std::vector<Country> countries;
	countries.push_back(usa);
	countries.push_back(mexico);
	countries.push_back(canada);

	std::cout<<"total pop : " <<getPopulation(countries, "North America");

	system("pause");
    return 0;
}


int getPopulation(std::vector<Country> countries, std::string continent) {
	std::vector<Country>::iterator it = countries.begin();
	int pop = 0;
	std::for_each(countries.begin(), countries.end(), [continent, &pop](Country c) {
		if (c.getContinent() == continent) {
			pop += c.getPopulation();
		}
	});
	return pop;
}