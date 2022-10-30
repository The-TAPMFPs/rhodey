#pragma once
#include <string>
#include <vector>
#include "Vehicle.h"

using namespace std;

class AirVehicle :public Vehicle{
    public:
    AirVehicle();
    virtual void attack();
    virtual void defend();
    virtual void transport();
    virtual Entity* clone();

};