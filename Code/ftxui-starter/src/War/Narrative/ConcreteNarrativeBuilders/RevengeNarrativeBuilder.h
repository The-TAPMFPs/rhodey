#pragma once
#include "../NarrativeBuilder.h"

class RevengeNarrativeBuilder : public NarrativeBuilder {
    public:
        void setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB);
        void setHostilities(std::vector<std::string> countriesA, std::vector<std::string> countriesB);
        void setPostWar(std::vector<std::string> countriesA, std::vector<std::string> countriesB);
        void setDisputeSettled(std::vector<std::string> countriesA, std::vector<std::string> countriesB);
        void setConflict(std::vector<std::string> countriesA, std::vector<std::string> countriesB);
};