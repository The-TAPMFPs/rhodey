#include "EconomicNarrativeBuilder.h"
/**
 * \file EconomicNarrativeBuilder.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 8 November 2022
 */

/**
 * \fn void EconomicNarrativeBuilder::setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
 * \brief the dispute reason between 2 countries/2 different alliances
 * \param countriesA the first country 
 * \param countriesB the second country
*/
void EconomicNarrativeBuilder::setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.dispute = NarrativeBuilder::pickRandom({
        "The gold mines of " + countriesA[0] + " have run dry! People are starving and options are running low",
        "They elect to attack, " + countriesB[0] + " a country known for its resources and wealth."
    });
}
/**
 * \fn void EconomicNarrativeBuilder::setHostilities(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
 * \brief the Hostilities between 2 countries/2 different alliances
 * \param countriesA the first country 
 * \param countriesB the second country
*/
void EconomicNarrativeBuilder::setHostilities(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.hostilities = NarrativeBuilder::pickRandom({
        "Hostilities are slow, " + countriesA[0] + " eye " + countriesB[0] + " like hyenas waiting for the ideal momement, both sides are preparing for war." 
    });
}
/**
 * \fn void EconomicNarrativeBuilder::setPostWar(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
 * \brief the postwar narrative between 2 countries/2 different alliances
 * \param countriesA the first country 
 * \param countriesB the second country
*/
void EconomicNarrativeBuilder::setPostWar(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.postWar = NarrativeBuilder::pickRandom({
        "Fighting has slowed, people are tired, there's no point in fighting for gold if you're going to die getting it." + countriesA[0] + 
        " has begun moving on from the idea of war."
    });
}
/**
 * \fn void EconomicNarrativeBuilder::setDisputeSettled(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
 * \brief the dispute settled narrative between 2 countries/2 different alliances
 * \param countriesA the first country 
 * \param countriesB the second country
*/
void EconomicNarrativeBuilder::setDisputeSettled(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.disputeSettled = NarrativeBuilder::pickRandom({
        "The war is over and although it was a war to try and gain more, both sides have lost so much " + countriesA[0] + " and " + countriesB[0] + 
        " all go home, hopefully the future will hold prosperity."
    });
}