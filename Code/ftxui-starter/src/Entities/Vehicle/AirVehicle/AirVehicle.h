#pragma once
#include "../Vehicle.h"

using namespace std;

class AirVehicle :protected Vehicle{
    protected:
	int weaknesses(int damage, Weapon & weapon);
	virtual Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)=0;
    public:
    AirVehicle(string name, int numberOfTroops, int HP, int Damage,
	    vector<Weapon*> * weapon, Country * country);
};
