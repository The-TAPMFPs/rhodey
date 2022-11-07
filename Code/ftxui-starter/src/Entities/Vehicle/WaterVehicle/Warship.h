#pragma once
#include "WaterVehicle.h"

using namespace std;

class Warship :public WaterVehicle{
    protected:
	Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon);
    public:
    Warship(string name, int numberOfTroops, vector<Weapon *> * weapons,
	    Country * country);

};
