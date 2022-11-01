//A WarPhase is a State for the main War object, which dictates which phase of war the simulation is currently in
#pragma once
#include "../War.h"

class War;

class WarPhase {
    public:
        virtual void handleWarChange(War* war) = 0;
        virtual std::string getCurrentWarState() = 0;//TODO : Need to implement into ui that the state has changed
};
