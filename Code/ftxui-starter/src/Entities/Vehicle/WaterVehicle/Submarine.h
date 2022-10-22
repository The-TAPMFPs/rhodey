#pragma once
#include <string>
#include <vector>
#include "WaterVehicle.h"

using namespace std;

class Submarine :public WaterVehicle{
    public:
    Submarine();
     void attack();
     void d();
     void transport();
    Entity* clone();

};