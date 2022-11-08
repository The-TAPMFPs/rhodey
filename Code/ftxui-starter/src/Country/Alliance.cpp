#include "Alliance.h"
/**
 * \file Alliance.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 7 November 2022
 */
/**
 * \fn Alliance::Alliance(std::string name, bool teamA)
 * \brief a constructor for creating new Alliance objects 
 * \param name the name of a particular alliance 
 * \param teamA a true or false value 
*/
Alliance::Alliance(std::string name, bool teamA) : name(name), teamA(teamA){}

/**
 * \fn void Alliance::add(Country* country)
 * \brief adds a country to a particular alliance 
 * \param country a pointer to the country that we want to add to an alliance  
*/
void Alliance::add(Country* country) {
    members.push_back(country);
    country->allies = this;
}
/**
 * \fn void Alliance::print()
 * \brief prints all the countries within an alliance 
*/
void Alliance::print() {
    std::cout << "Alliance: " << name << std::endl;
    std::cout << "======================" << std::endl;
    for (Country* country : members) {
        std::cout << country->getName() << std::endl;
    }
    std::cout << std::endl;
}
/**
 * \fn vector<Country*> Alliance::getMembers()
 * \brief gets the members of an alliance from the vector
 * \return returns the members of an alliance 
*/
std::vector<Country*> Alliance::getMembers()
{
    return this->members;
}

//Returns true if the specified country is a member
//of this alliance; false otherwise
/**
 * \fn bool Alliance::containsCountry(Country* country)
 * \brief a function that tells us if a certain country is within a alliance (true is yes, false if not)
 * @param country a pointer to the country that we want to see if its contained in the aliance
 * \return the names of the country 
*/
bool Alliance::containsCountry(Country* country)
{
    return std::find(members.begin(), members.end(), country) != members.end();
}
std::vector<std::string> Alliance::getAllianceNames() {
    std::vector<std::string> names;
    for (Country* country : members) {
        names.push_back(country->getName());
    }
    return names;
}

//For round-robin selection of a country from the alliance
/**
 * \fn Country* Alliance::getMemberModuloSize(int modIndex)
 * \brief allows for a round-robin approach to select a country from the alliance 
 * \param modIndex the index in which we want to mod at 
 * \return nullptr
*/
Country* Alliance::getMemberModuloSize(int modIndex) {
    if(!this->members.empty())
    {
        return this->members[modIndex%this->members.size()];
    }
    return nullptr;
}
