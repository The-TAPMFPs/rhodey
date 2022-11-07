#pragma once
#include "../Entity.h"

using namespace std;

class Troop : public Entity{
protected:
    virtual Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon);
    virtual int weaknesses(int damage, Weapon & weapon);
public:
    Troop(string name, int numberOfTroops, vector<Weapon*> * weapon,
	    Country * country);
    virtual int getCarryingCapacity();
    virtual int getTerrainHandling();
};
