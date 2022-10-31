#pragma once
#include <vector>
#include "AirVehicle.h"

using namespace std;

class Bomber :public AirVehicle{
    protected:
	Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon);
    public:
    Bomber(string name, int numberOfTroops, vector<Weapon *> * weapons);
};
