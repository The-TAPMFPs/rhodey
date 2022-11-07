#include "ReligiousNarrativeBuilder.h"

void ReligiousNarrativeBuilder::setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.dispute = NarrativeBuilder::pickRandom({
        "The conservative state of " + countriesA[0] + " is fed up of the liberal shenanigans of their neighbour, " + countriesB[0] + ". After weeks of group hostilities and riots, their respective militaries finally clash.",
    });
}

void ReligiousNarrativeBuilder::setHostilities(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.hostilities = NarrativeBuilder::pickRandom({
        ""
    });
}

void ReligiousNarrativeBuilder::setPostWar(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.postWar = NarrativeBuilder::pickRandom({
        ""
    });
}

void ReligiousNarrativeBuilder::setDisputeSettled(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.disputeSettled = NarrativeBuilder::pickRandom({
        ""
    });
}