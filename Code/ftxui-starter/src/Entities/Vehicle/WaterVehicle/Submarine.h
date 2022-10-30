#pragma once
#include "WaterVehicle.h"

using namespace std;

class Submarine :public WaterVehicle{
    protected:
	Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon);
    public:
    Submarine(string name, int numberOfTroops, vector<Weapon *> * weapons);

};
