#include "PoliticalNarrativeBuilder.h"
/**
 * \file PoliticalNarrativeBuilder.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 8 November 2022
 */
/**
 * \fn void PoliticalNarrativeBuilder::setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
 * \brief the dispute reason between 2 countries/2 different alliances
 * \param countriesA the first country 
 * \param countriesB the second country
*/
void PoliticalNarrativeBuilder::setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.dispute = NarrativeBuilder::pickRandom({
        countriesA[0] + "'s conservative leader has come into power by calling for the downfall of " + countriesB[0] + 
        "'s liberal ways. This has not gone unnoticed and tensions are beggining to grow.",
    });
}
/**
 * \fn void PoliticalNarrativeBuilder::setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
 * \brief the Hostilities reason between 2 countries/2 different alliances
 * \param countriesA the first country 
 * \param countriesB the second country
*/
void PoliticalNarrativeBuilder::setHostilities(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.hostilities = NarrativeBuilder::pickRandom({
        countriesB[0] + " call " + countriesA[0] + " out for the what has been said against there country and the political ideologies that they hold" +
        countriesA[0] + " repoonse is further aggrevation of the situation, military forces begin to surface on both sides."
    });
}
/**
 * \fn void PoliticalNarrativeBuilder::setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
 * \brief the postwar narrative reason between 2 countries/2 different alliances
 * \param countriesA the first country 
 * \param countriesB the second country
*/
void PoliticalNarrativeBuilder::setPostWar(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.postWar = NarrativeBuilder::pickRandom({
        "Fighting has ceased for now, this war of political ideologies is one that will never end, and both " + countriesA[0] + " and " + countriesB[0] +
        "know it, talks of peace begin, unity is possible."
    });
}
/**
 * \fn void PoliticalNarrativeBuilder::setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
 * \brief the dispute settled narrative reason between 2 countries/2 different alliances
 * \param countriesA the first country 
 * \param countriesB the second country
*/
void PoliticalNarrativeBuilder::setDisputeSettled(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.disputeSettled = NarrativeBuilder::pickRandom({
        "The war is over " + countriesA[0] + " go home and so do " + countriesB[0] + " beliefs still stand, people never change, but the war is over." 
    });
}