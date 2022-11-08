#pragma once
#include "../NarrativeBuilder.h"

class PoliticalNarrativeBuilder : public NarrativeBuilder {
    public:
        void setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB);
        void setHostilities(std::vector<std::string> countriesA, std::vector<std::string> countriesB);
        void setPostWar(std::vector<std::string> countriesA, std::vector<std::string> countriesB);
        void setDisputeSettled(std::vector<std::string> countriesA, std::vector<std::string> countriesB);
};