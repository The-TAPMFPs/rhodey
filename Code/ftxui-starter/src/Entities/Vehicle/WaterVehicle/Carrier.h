#pragma once
#include <string>
#include <vector>
#include "WaterVehicle.h"

using namespace std;

class Carrier :public WaterVehicle{
    public:
    Carrier();
     void attack();
     void d();
     void transport();
    Entity* clone();

};