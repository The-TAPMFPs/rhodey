#pragma once
#include "Entities/Entity.h"
#include <string>
#include <vector>
#include "WeaponTemplateMethod/Weapon.h"

class UnitFactory{
    protected:
        std::string _name;
        int _num;
        vector<Weapon *> * w1;
        vector<Weapon *> * w2;
        vector<Weapon *> * w3;
        vector<Weapon *> * w4;
        vector<Weapon *> * w5;
        Entity* e;
    public:
        virtual ~UnitFactory();
        virtual Entity* makeUnit() = 0;
        
        
};