#pragma once
#include <iostream>
#include "Vehicle.h"



class ParkingSpot
{
public:
	ParkingSpot();
	ParkingSpot(int newX, int newY, VEHICLETYPE newParkingType) :
		x(newX), y(newY), parkingType(newParkingType) {
		available = true;
		paid = false;
		cost = 0;
	};
	~ParkingSpot();

	int getX() const { return x; }
	int getY() const { return y; }
	VEHICLETYPE getType() const { return parkingType; }
	bool getAvailablity() const { return available; }
	bool getPaid() const { return paid; }
	double getCost() const { return cost; }

	void printSpecificInfo() {
		std::cout << "Parking : " << x << " , " << y << std::endl;
		std::cout << "Parking Type : " << printParkingType() << std::endl;
		std::cout << "Availability : " << (available ? "yes" : "no") << std::endl;
		std::cout << "cost : " << cost << std::endl;
	}

	void printGeneralInfo() {
		std::cout <<printParkingType();
		std::cout << (available ? "y" : "n");
	}

	std::string printParkingType() {
		if (parkingType == VEHICLETYPE::BUS) {
			return "B" ;
		}
		else if (parkingType == VEHICLETYPE::CAR) {
			return "C";
		}
		else
		{
			return "M";
		}
	}

	ParkingSpot& operator= (const ParkingSpot& otherParkingSpot) {
		if (this != &otherParkingSpot) {
			x = otherParkingSpot.getX();
			y = otherParkingSpot.getY();
			parkingType = otherParkingSpot.getType();
			available = otherParkingSpot.getAvailablity();
			cost = otherParkingSpot.getCost();
			paid = otherParkingSpot.getPaid();
		}
		return *this;
	}

	


private:
	int x;
	int y;
	VEHICLETYPE parkingType;
	bool available;
	double cost;
	bool paid;
	


};

