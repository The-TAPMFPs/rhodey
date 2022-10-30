#pragma once
#include <string>
#include <vector>
#include "Vehicle.h"

using namespace std;

class GroundVehicle :public Vehicle{
    public:
    GroundVehicle();
    virtual void attack();
    virtual void defend();
    virtual void transport();
    virtual Entity* clone();//return pointer to entity

};