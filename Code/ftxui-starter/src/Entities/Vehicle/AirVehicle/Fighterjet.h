#pragma once
#include "AirVehicle.h"

using namespace std;

class Fighterjet :public AirVehicle{
    protected:
	Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon);
    public:
    Fighterjet(string name, int numberOfTroops, vector<Weapon *> * weapons);
};
