#pragma once
#include <string>
#include <vector>
#include "Vehicle.h"

using namespace std;

class WaterVehicle :public Vehicle{
    public:
    WaterVehicle();
    virtual void attack();
    virtual void d();
    virtual void transport();
    Entity* clone();

};