#pragma once
#include <string>
#include <vector>
#include "Entity.h"

using namespace std;

class Vehicle :public Entity{
    private:
    int capacity=0;
    public:
    Vehicle();
    virtual void attack();
    virtual void defend();
    virtual void transport();
    Entity* clone();

};