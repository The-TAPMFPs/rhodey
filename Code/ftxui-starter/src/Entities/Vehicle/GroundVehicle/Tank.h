#pragma once
#include "GroundVehicle.h"

using namespace std;

class Tank :public GroundVehicle{
    protected:
	Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon);
    int weaknesses(int damage, Weapon & weapon);
    public:
    Tank(string name, int numberOfTroops, vector<Weapon *> * weapons,
	    Country * country);

};
