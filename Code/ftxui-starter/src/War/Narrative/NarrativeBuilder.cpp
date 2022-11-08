#include "NarrativeBuilder.h"
/**
 * \file NarrativeBuilder.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 8 November 2022
 */
//Pick a random string from the provided vector
/**
 * \fn string NarrativeBuilder::pickRandom(std::vector<std::string> strings)
 * \brief function picks a random string inside the vector 
 * @param strings is a vector of strings 
 * \return returms a random string inside the vector for the NarrativeBuilder
*/
std::string NarrativeBuilder::pickRandom(std::vector<std::string> strings)
{
    return strings[uuid::randomInt(0, strings.size()-1)];
}
/**
 * \fn void NarrativeBuilder::reset()
 * \brief function resets the Narrative 
*/
void NarrativeBuilder::reset()
{
    this->product = Narrative();
}
/**
 * \fn Narrative NarrativeBuilder::getResult()
 * \brief function gets the result of the narrative
 * \return returns the product of the narrative
*/
Narrative NarrativeBuilder::getResult()
{
    return this->product;
}