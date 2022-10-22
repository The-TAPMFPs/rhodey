#pragma once
#include <string>
#include <vector>
#include "Weapon.h"
using namespace std;

class Entity{
    
    private:
    string name;
    int HP=0;
    int Damage=0;
    vector<Weapon*> weapons;

    public:
    Entity();
    virtual void attack()=0;
    virtual void defend()=0;
    virtual void transport()=0;
    virtual Entity* clone()=0;




};