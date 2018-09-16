#pragma once
#include "ParkingLevel.h"
#include <vector>
class ParkingStructure
{
public:
	ParkingStructure() {

		for (int i = 0; i < 2; i++) {
			parkingLevels.push_back(new ParkingLevel(5, 5));
			parkingLevels.at(i)->initializeParkingLevel();
		}
		
	};
	
	~ParkingStructure();

	void printStructure() {
		for (int i = 0; i < parkingLevels.size(); i++) {
			std::cout << "level : " << i << std::endl;
			parkingLevels.at(i)->print();

			std::cout << std::endl;
		}
	}



private:
	std::vector<ParkingLevel* > parkingLevels;


};

