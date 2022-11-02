#pragma once
#include "Entities/Entity.h"
#include <string>

class UnitFactory{
    protected:
        std::string _name;
        int _num;
    public:
        virtual ~UnitFactory();
        virtual Entity* makeUnit() = 0;
        
        
};