#pragma once
#include "WaterVehicle.h"

using namespace std;

class Carrier :public WaterVehicle{
    protected:
	Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon);
    public:
    Carrier(string name, int numberOfTroops, vector<Weapon *> * weapons,
	    Country * country);

};
