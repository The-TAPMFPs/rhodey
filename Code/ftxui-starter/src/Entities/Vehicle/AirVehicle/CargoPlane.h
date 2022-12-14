#pragma once
#include "AirVehicle.h"

using namespace std;

class CargoPlane :public AirVehicle{
    protected:
	Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon);
    public:
    CargoPlane(string name, int numberOfTroops, vector<Weapon *> * weapons,
	    Country * country);

};
