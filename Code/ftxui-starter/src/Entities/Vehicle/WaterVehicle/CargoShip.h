#pragma once
#include "WaterVehicle.h"

using namespace std;

class CargoShip :public WaterVehicle{
    protected:
	Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon);
    public:
    CargoShip(string name, int numberOfTroops, vector<Weapon *> * weapons);

};
