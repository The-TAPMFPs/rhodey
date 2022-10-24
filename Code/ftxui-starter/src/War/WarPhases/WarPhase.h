//A WarPhase is a State for the main War object, which dictates which phase of war the simulation is currently in
#pragma once
#include "../War.h"

class War;

class WarPhase {
    protected:
        War* _war;
    public:
        virtual ~WarPhase(){};
        void set_war(War* war);
        virtual void DoSomething() = 0;//TODO : Need to implement into ui that the state has changed
};
