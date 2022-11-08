#include "NarrativeDirector.h"

NarrativeDirector::NarrativeDirector(Alliance* teamA, Alliance* teamB)
    : teamA(teamA), teamB(teamB)
{}

Narrative NarrativeDirector::makeEconomicNarrative()
{
    NarrativeBuilder* builder = new EconomicNarrativeBuilder();
    executeStandardMake(builder);
    Narrative res = builder->getResult();
    delete builder;

    return res;
}

Narrative NarrativeDirector::makeTerritorialNarrative()
{
    NarrativeBuilder* builder = new TerritorialNarrativeBuilder();
    executeStandardMake(builder);
    Narrative res = builder->getResult();
    delete builder;

    return res;
}

Narrative NarrativeDirector::makeRevengeNarrative()
{
    NarrativeBuilder* builder = new RevengeNarrativeBuilder();
    executeStandardMake(builder);
    Narrative res = builder->getResult();
    delete builder;

    return res;
}

Narrative NarrativeDirector::makeReligiouslNarrative()
{
    NarrativeBuilder* builder = new ReligiousNarrativeBuilder();
    executeStandardMake(builder);
    Narrative res = builder->getResult();
    delete builder;

    return res;
}

Narrative NarrativeDirector::makePoliticalNarrative()
{
    NarrativeBuilder* builder = new PoliticalNarrativeBuilder();
    executeStandardMake(builder);
    Narrative res = builder->getResult();
    delete builder;

    return res;
}

void NarrativeDirector::executeStandardMake(NarrativeBuilder* builder)
{
    std::vector<Country*> teamAMembers = teamA->getMembers();
    std::vector<Country*> teamBMembers = teamB->getMembers();

    std::vector<std::string> countriesA;
    std::vector<std::string> countriesB;

    for(auto a = teamAMembers.begin(); a != teamAMembers.end(); a++) {
        countriesA.push_back((*a)->getName());
    }

    for(auto b = teamBMembers.begin(); b != teamBMembers.end(); b++) {
        countriesB.push_back((*b)->getName());
    }

    builder->reset();
    builder->setDispute(countriesA, countriesB);
    builder->setConflict(countriesA, countriesB);
    builder->setHostilities(countriesA, countriesB);
    builder->setPostWar(countriesA, countriesB);
    builder->setDisputeSettled(countriesA, countriesB);
}