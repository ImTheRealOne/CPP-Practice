#pragma once
#include <string>

enum VEHICLETYPE
{
	MOTORCYCLE,BUS,CAR
};

class Vehicle
{
public:
	Vehicle();
	Vehicle(VEHICLETYPE newVehicleType) : vehicleType(newVehicleType) {};
	~Vehicle();
private:
	std::string license;
	VEHICLETYPE vehicleType;
};

