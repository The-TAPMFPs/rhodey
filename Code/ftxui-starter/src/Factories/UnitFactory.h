#pragma once
#include "Entities/Entity.h"
#include <string>
#include <memory>

class UnitFactory{
    protected:
        std::string _name;
        int _hp;
        int _num;
    public:
        virtual ~UnitFactory();
        virtual Entity* makeUnit() = 0;
        
        
};