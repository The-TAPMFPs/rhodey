#pragma once

#include "../Country/Alliance.h"
#include "../MapRegions/Map.h"
#include "WarPhases/WarPhase.h"

class War {
    private:
        WarPhase* _warPhase;
        Alliance* teamA;
        Alliance* teamB;
        Map* map;
    public:
        War();
        War(WarPhase* warPhase);
        void TransitionTo(WarPhase* warPhase);
        ~War();
        void start();
};