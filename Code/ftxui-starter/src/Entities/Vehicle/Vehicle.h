#pragma once
#include "../Entity.h"

using namespace std;

class Vehicle :public Entity{
protected:
    int capacity=0;
    virtual Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)=0;
public:
    Vehicle(string name, int numberOfTroops, int HP, int Damage, vector<Weapon*> * weapon);
    virtual void defend(int damage, Weapon & weapon)=0;
    virtual int getCarryingCapacity();
    virtual int getTerrainHandling();
};
