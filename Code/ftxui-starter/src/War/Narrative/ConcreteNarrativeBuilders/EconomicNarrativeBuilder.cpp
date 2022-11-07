#include "EconomicNarrativeBuilder.h"

void EconomicNarrativeBuilder::setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.dispute = NarrativeBuilder::pickRandom({
        countriesA[0] + " is in a poor financial situation " + countriesB[0] + " hundreds of years ago, now they want it back.",
        "The gold mines of " + countriesA[0] + " have run dry! They elect to attack their sworn rival state, " + countriesB[0] + "."
    });
}

void EconomicNarrativeBuilder::setHostilities(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.hostilities = NarrativeBuilder::pickRandom({
        ""
    });
}

void EconomicNarrativeBuilder::setPostWar(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.postWar = NarrativeBuilder::pickRandom({
        ""
    });
}

void EconomicNarrativeBuilder::setDisputeSettled(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.disputeSettled = NarrativeBuilder::pickRandom({
        ""
    });
}