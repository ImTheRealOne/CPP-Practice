#pragma once
#include "ParkingSpot.h"
#include <random>
#include <time.h>

class ParkingLevel
{
public:
	ParkingLevel();
	ParkingLevel(const int ROWSIZE, const int COLSIZE) :
	rowSize(ROWSIZE), colSize(COLSIZE) { level = new ParkingSpot*[COLSIZE];
															for (int i = 0; i < COLSIZE; i++) {
																level[i] = new ParkingSpot[ROWSIZE];
															}
														}
	~ParkingLevel() {
		for (int i = 0; i < colSize; i++) {
			delete[] level[i];
		}
		delete[] level;
	}

	void initializeParkingLevel() {
		srand(time(NULL));

		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				int vehicleType = rand() % 3;
				level[i][j] = ParkingSpot(i, j, VEHICLETYPE(vehicleType));
			}
		}
	}

	void print() {
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				level[i][j].printGeneralInfo();
				std::cout << "|";
			}
			std::cout << std::endl;
		}
	}

private:
	ParkingSpot ** level;
	int rowSize;
	int colSize;
	int openSpots;
	int closeSpots;



};

