#pragma once
#include "Entities/Entity.h"
#include <string>
#include <vector>
#include "../Entities/WeaponTemplateMethod/Weapon.h"
#include "../logger.h"
#include "../Country/Country.h"


class UnitFactory{
    protected:
        std::string _name;
        int _num;
        Country * _con;
        vector<Weapon *> * w1;
        vector<Weapon *> * w2;
        vector<Weapon *> * w3;
        vector<Weapon *> * w4;
        vector<Weapon *> * w5;
        vector<Weapon *> * w6;
        Entity* e;
    public:
        virtual ~UnitFactory();
        virtual Entity* makeUnit() = 0;
        
        
};