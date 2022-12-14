#pragma once
#include "../Entity.h"

using namespace std;

class Vehicle : protected Entity{
    protected:
    int capacity=0;
    virtual Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)=0;
public:
    Vehicle(string name, int numberOfTroops, int HP, int Damage,
	    vector<Weapon*> * weapon, Country * country, std::string type);
    int getCarryingCapacity();
    int getTerrainHandling();
    virtual bool isVehicle() {return true;}
};
