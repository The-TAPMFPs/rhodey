//A WarPhase is a State for the main War object, which dictates which phase of war the simulation is currently in
#pragma once
#include "../War.h"
#include <vector>

class War;

enum phase {
    CONFLICT,
    DISPUTE,
    DISPUTE_SETTLED,
    HOSTILITIES,
    POST_WAR
};

class WarPhase {
    public:
        virtual void handleWarChange(War* war) = 0;
        virtual std::string getCurrentWarState() = 0;
        std::string thumbnail;
        phase warPhase;
};
