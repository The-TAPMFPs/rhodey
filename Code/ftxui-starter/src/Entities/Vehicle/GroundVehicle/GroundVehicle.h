#pragma once
#include "../Vehicle.h"

using namespace std;

class GroundVehicle :public Vehicle{
    protected:
	virtual int weaknesses(int damage, Weapon & weapon);
    public:
    GroundVehicle(string name, int numberOfTroops, int HP, int Damage, vector<Weapon*> * weapon);

};
