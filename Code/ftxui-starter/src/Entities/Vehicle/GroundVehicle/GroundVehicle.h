#pragma once
#include "../Vehicle.h"

using namespace std;

class GroundVehicle :public Vehicle{
    protected:
	int weaknesses(int damage, Weapon & weapon);
    virtual Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)=0;
    public:
    GroundVehicle(string name, int numberOfTroops, int HP, int Damage, vector<Weapon*> * weapon);

};
