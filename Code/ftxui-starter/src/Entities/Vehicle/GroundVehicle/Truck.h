#pragma once
#include "GroundVehicle.h"

using namespace std;

class Truck :public GroundVehicle{
    protected:
	Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon);
    public:
    Truck(string name, int numberOfTroops, vector<Weapon *> * weapons,
	    Country * country);
};
