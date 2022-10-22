#pragma once
#include <string>
#include <vector>
#include "GroundVehicle.h"

using namespace std;

class Tank :public GroundVehicle{
    public:
    Tank();
     void attack();
     void d();
     void transport();
    Entity* clone();

};