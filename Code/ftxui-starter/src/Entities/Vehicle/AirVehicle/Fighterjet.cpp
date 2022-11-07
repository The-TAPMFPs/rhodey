#include "Fighterjet.h"

/**
 * @file FighterJet.cpp
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn FighterJet(string name, int numberOfTroops, 
 vector<Weapon*>* weapons, Country * country)
 * @brief Construct a new Bomber:: Bomber object
 *  
 * @param name The name of the FighterJets. 
 * @param numberOfTroops The amount of FighterJets to make.
 * @param weapons The weapons that the FighterJets use.
 * @param country The Country that the FighterJets belong too.
 */
Fighterjet::Fighterjet(string name, int numberOfTroops,
	vector<Weapon *> * weapons, Country * country) : AirVehicle(name,
	    numberOfTroops, 200, 30, weapons, country, "Fighterjet") {
	this->terrianHandling = 100;
	this->capacity = 0;
    };
	
/**
 * @fn Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)
 * @brief Allows for the Fighterjet to be cloned
 * 
 * @return Entity * Fighterjet
 */
Entity * Fighterjet::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Fighterjet(name, numberOfTroops, weapon, this->country);
}
