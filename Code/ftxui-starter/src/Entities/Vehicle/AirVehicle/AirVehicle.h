#pragma once
#include "../Vehicle.h"

using namespace std;

class AirVehicle :public Vehicle{
    protected:
	virtual int weaknesses(int damage, Weapon & weapon);
    public:
    AirVehicle(string name, int numberOfTroops, int HP, int Damage, vector<Weapon*> * weapon);
};
