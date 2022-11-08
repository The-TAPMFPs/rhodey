#pragma once
#include <string>
#include "Narrative.h"
#include "../../uuid.h"

//This interface is responsible for constructing the main narrative that the war follows
class NarrativeBuilder {
    protected:
        Narrative product;
        static std::string pickRandom(std::vector<std::string> strings);

    public:
        virtual void setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB) = 0;
        virtual void setHostilities(std::vector<std::string> countriesA, std::vector<std::string> countriesB) = 0;
        //Conflict phase is determined by the simulation
        virtual void setPostWar(std::vector<std::string> countriesA, std::vector<std::string> countriesB) = 0;
        virtual void setDisputeSettled(std::vector<std::string> countriesA, std::vector<std::string> countriesB) = 0;
        void reset();
        Narrative getResult();
};