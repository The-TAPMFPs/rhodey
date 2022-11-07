#pragma once
#include "../Vehicle.h"

using namespace std;

class WaterVehicle :public Vehicle{
    protected:
	virtual int weaknesses(int damage, Weapon & weapon);
    virtual Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)=0;
    public:
    WaterVehicle(string name, int numberOfTroops, int HP, int Damage,
	    vector<Weapon*> * weapon, Country * country, std::string type);

};
