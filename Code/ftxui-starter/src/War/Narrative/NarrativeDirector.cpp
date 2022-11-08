#include "NarrativeDirector.h"
/**
 * \file NarrativeDireector.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 8 November 2022
 */
/**
 * \fn NarrativeDirector::NarrativeDirector(Alliance* teamA, Alliance* teamB)
 * \brief Constrcutor that creates a new narrative director 
 * \param teamA a pointer to an alliance 
 * \param teamB a pointer to a 2nd different alliance 
*/
NarrativeDirector::NarrativeDirector(Alliance* teamA, Alliance* teamB)
    : teamA(teamA), teamB(teamB)
{}
/**
 * \fn Narrative NarrativeDirector::makeEconomicNarrative()
 * \brief this function makes the economic narrative 
 * \return return the the new EconomicNarrative 
*/
Narrative NarrativeDirector::makeEconomicNarrative()
{
    NarrativeBuilder* builder = new EconomicNarrativeBuilder();
    executeStandardMake(builder);
    Narrative res = builder->getResult();/**res is a variable that stores the newly made narrative by the builder */
    delete builder;

    return res;
}
/**
 * \fn Narrative NarrativeDirector::makeTerritorialNarrative()
 * \brief this function makes the TerritorialNarrative  
 * \return return the the new TerritorialNarrative 
*/
Narrative NarrativeDirector::makeTerritorialNarrative()
{
    NarrativeBuilder* builder = new TerritorialNarrativeBuilder();
    executeStandardMake(builder);
    Narrative res = builder->getResult();/**res is a variable that stores the newly made narrative by the builder */
    delete builder;

    return res;
}
/**
 * \fn Narrative NarrativeDirector::makeRevengeNarrative()
 * \brief this function makes the RevengeNarrative  
 * \return return the the new RevengeNarrative 
*/
Narrative NarrativeDirector::makeRevengeNarrative()
{
    NarrativeBuilder* builder = new RevengeNarrativeBuilder();
    executeStandardMake(builder);
    Narrative res = builder->getResult();/**res is a variable that stores the newly made narrative by the builder */
    delete builder;

    return res;
}
/**
 * \fn Narrative NarrativeDirector::makeReligiousNarrative()
 * \brief this function makes the ReligiousNarrative  
 * \return return the the new ReligiousNarrative 
*/
Narrative NarrativeDirector::makeReligiouslNarrative()
{
    NarrativeBuilder* builder = new ReligiousNarrativeBuilder();
    executeStandardMake(builder);
    Narrative res = builder->getResult();/**res is a variable that stores the newly made narrative by the builder */
    delete builder;

    return res;
}
/**
 * \fn Narrative NarrativeDirector::makePoliticalNarrative()
 * \brief this function makes the PoliticalNarrative  
 * \return return the the new PoliticalNarrative 
*/
Narrative NarrativeDirector::makePoliticalNarrative()
{
    NarrativeBuilder* builder = new PoliticalNarrativeBuilder();
    executeStandardMake(builder);
    Narrative res = builder->getResult();/**res is a variable that stores the newly made narrative by the builder */
    delete builder;

    return res;
}
/**
 * \fn void NarrativeDirector::executeStandardMake(NarrativeBuilder* builder)
 * \brief internal utility function
 * \param builder takes a pointer to a NarrativeBuilder and performs the standard steps 
*/
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
    builder->setHostilities(countriesA, countriesB);
    builder->setPostWar(countriesA, countriesB);
    builder->setDisputeSettled(countriesA, countriesB);
}