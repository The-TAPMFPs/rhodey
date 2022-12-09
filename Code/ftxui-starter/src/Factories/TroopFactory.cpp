#include "TroopFactory.h"
#include <sstream>
#include "Entities/WeaponTemplateMethod/Weapon.h"
#include "../MapRegions/Map.h"

/**
 * @file TroopFactory.cpp
 * @brief Construct a new Troop Factory object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022
 */

/**
 * @fn TroopFactory (std::string name, int num, Country * con)
 * @brief The constructor of the TroopFactory class.
 *
 * @param name Troop Name
 * @param num Amount of Troops
 * @param con Country of Troops
 */
TroopFactory::TroopFactory(std::string name, int num, Country * con) :
    UnitFactory(name, num, con) {
}
/**
 * @fn ~TroopFactory()
 * @brief The Destructor of the TroopFactory class.
 */
TroopFactory::~TroopFactory(){
}

/**
 * @fn Entity* makeUnit()
 * @brief Makes the specific units based on chance and research level
 *        and returns a reference to the new Entity that has been made.
 */

Entity* TroopFactory::makeUnit(){
    int i = rand() % 2 + 1; /**<A random number to decide what type of unit to make when the chance arises.>*/
    std::string temp; /**<A string to hold the message that the Vehicles were made.>*/
    std::stringstream convert; /**<A stringstream to concentate the intital message.>*/
    vector<Weapon *> * weaponVector;
    Troop * result;

    if(this->country->getResearch() < 0.2){
	weaponVector =  new vector<Weapon *> {weapons->getWeapon(CLASS_SMG), weapons->getWeapon(CLASS_PISTOL)}; /**<Vector which contains a set of references to weapon objects>*/
	result = new Troop(this->name, this->num, weaponVector, this->country);

	convert << this->num << " troops with SMGs and Pistols were recruited.";
    } else if(this->country->getResearch() < 0.5){
	weaponVector = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_PISTOL), weapons->getWeapon(CLASS_SNIPER)}; /**<Vector which contains a set of references to weapon objects>*/
       result = new Troop(this->name, this->num, weaponVector, this->country);

        convert << this->num << " troops with ARs, Pistols and Snipers were recruited.";
    } else if(this->country->getResearch() < 0.8){
       result = new Troop(this->name, this->num, w3, this->country);
	w3 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_SMG), weapons->getWeapon(CLASS_DUALBURETTE), weapons->getWeapon(CLASS_BAZOOKA)}; /**<Vector which contains a set of references to weapon objects>*/

	convert << this->num << " troops with ARs, SMGs, Dual Burettes and Bazookas were recruited.";
    } else if(this->country->getResearch() <= 1){
       result = new Troop(this->name, this->num, w5, this->country);
	w5 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_DUALBURETTE), weapons->getWeapon(CLASS_SNIPER50), weapons->getWeapon(CLASS_AK47)}; /**<Vector which contains a set of references to weapon objects>*/

	convert << this->num << " troops with ARs, Dual Burettes, Sniper50s and AK47s were recruited.";
    }

    temp = convert.str();
    Logger::log(temp);
    this->country->getMap()->getOccupancyTable()->addEntity(
	    result, this->country->getCapital());

    return result;
}


