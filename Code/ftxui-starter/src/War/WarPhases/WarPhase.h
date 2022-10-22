//A WarPhase is a State for the main War object, which dictates which phase of war the simulation is currently in
#pragma once
#include "../War.h"

class WarPhase {
    protected:
        War* _war;
    public:
        WarPhase();
        virtual ~WarPhase(){};
        
        void set_war(War* war){
            _war = war;
        }

        virtual void handleWarPhase() = 0; //State pattern `handle()`
};
