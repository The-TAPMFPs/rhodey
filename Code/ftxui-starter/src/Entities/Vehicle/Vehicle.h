#pragma once
#include <string>
#include <vector>
#include "Entity.h"

using namespace std;

class Vehicle :public Entity{
    public:
    Vehicle();
    virtual void attack();
    virtual void defend();
    virtual void transport();
    Entity* clone();

};