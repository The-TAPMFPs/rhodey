#pragma once
#include <string>
#include <vector>
#include "../Entity.h"

using namespace std;

class Troop : public Entity{
    public:
    Troop(string name, string type, int HP, int Damage);
    virtual void attack(Entity & defender);
    virtual void defend(int damage, Weapon & weapon);
    void transport();
    virtual Entity* clone();

};
