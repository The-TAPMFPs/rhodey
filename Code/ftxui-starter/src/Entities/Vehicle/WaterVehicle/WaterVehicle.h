#pragma once
#include "../Vehicle.h"

using namespace std;

class WaterVehicle :public Vehicle{
    protected:
	virtual int weaknesses(int damage, Weapon & weapon);
    public:
    WaterVehicle(string name, int numberOfTroops, int HP, int Damage, vector<Weapon*> * weapon);

};
