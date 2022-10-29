#pragma once
#include <string>
#include <vector>
#include "WaterVehicle.h"

using namespace std;

class Warship :public WaterVehicle{
    public:
    Warship();
     void attack();
     void d();
     void transport();
    Entity* clone();

};