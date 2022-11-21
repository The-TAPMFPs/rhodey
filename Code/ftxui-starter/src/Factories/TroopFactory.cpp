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
    UnitFactory(name, num, con)
{
    _name = name;
    _num = num;
    _con = con;

        w1 =  new vector<Weapon *> {weapons->getWeapon(CLASS_SMG), weapons->getWeapon(CLASS_PISTOL)}; /**<Vector which contains a set of references to weapon objects>*/

        w2 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_PISTOL), weapons->getWeapon(CLASS_SNIPER)}; /**<Vector which contains a set of references to weapon objects>*/

        w3 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_SMG), weapons->getWeapon(CLASS_DUALBURETTE), weapons->getWeapon(CLASS_BAZOOKA)}; /**<Vector which contains a set of references to weapon objects>*/

        w4 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_PISTOL), weapons->getWeapon(CLASS_SNIPER), weapons->getWeapon(CLASS_BAZOOKA)}; /**<Vector which contains a set of references to weapon objects>*/

        w5 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_DUALBURETTE), weapons->getWeapon(CLASS_SNIPER50), weapons->getWeapon(CLASS_AK47)}; /**<Vector which contains a set of references to weapon objects>*/

        w6 = new vector<Weapon *> {weapons->getWeapon(CLASS_AK47), weapons->getWeapon(CLASS_DUALBURETTE), weapons->getWeapon(CLASS_BAZOOKA), weapons->getWeapon(CLASS_SNIPER50)}; /**<Vector which contains a set of references to weapon objects>*/

}
/**
 * @fn ~TroopFactory()
 * @brief The Destructor of the TroopFactory class.
 */
TroopFactory::~TroopFactory(){
    delete w1;
    delete w2;
    delete w3;
    delete w4;
    delete w5;
    delete w6;
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
    Troop * e;
    if(_con->getResearch() < 0.2){
        e = new Troop(_name, _num, w1, _con);
            w1 =  new vector<Weapon *> {weapons->getWeapon(CLASS_SMG), weapons->getWeapon(CLASS_PISTOL)}; /**<Vector which contains a set of references to weapon objects>*/

	    convert << _num << " troops with SMGs and Pistols were recruited.";
        temp = convert.str();
        Logger::log(temp);
	    w1 =  new vector<Weapon *> {weapons->getWeapon(CLASS_SMG), weapons->getWeapon(CLASS_PISTOL)}; /**<Vector which contains a set of references to weapon objects>*/

    }
    else if(_con->getResearch() < 0.5){
        e = new Troop(_name, _num, w2, _con);
            w2 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_PISTOL), weapons->getWeapon(CLASS_SNIPER)}; /**<Vector which contains a set of references to weapon objects>*/

        convert << _num << " troops with ARs, Pistols and Snipers were recruited.";
        temp = convert.str();
        Logger::log(temp);
	    w2 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_PISTOL), weapons->getWeapon(CLASS_SNIPER)}; /**<Vector which contains a set of references to weapon objects>*/

    }
    else if(_con->getResearch() < 0.8){
        switch(i){
            case 1:
                e = new Troop(_name, _num, w3, _con);
                    w3 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_SMG), weapons->getWeapon(CLASS_DUALBURETTE), weapons->getWeapon(CLASS_BAZOOKA)}; /**<Vector which contains a set of references to weapon objects>*/

                convert << _num << " troops with ARs, SMGs, Dual Burettes and Bazookas were recruited.";
                temp = convert.str();
                Logger::log(temp);
                    w3 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_SMG), weapons->getWeapon(CLASS_DUALBURETTE), weapons->getWeapon(CLASS_BAZOOKA)}; /**<Vector which contains a set of references to weapon objects>*/

                break;
            case 2:
                e = new Troop(_name, _num, w4, _con);
                    w4 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_PISTOL), weapons->getWeapon(CLASS_SNIPER), weapons->getWeapon(CLASS_BAZOOKA)}; /**<Vector which contains a set of references to weapon objects>*/

                convert << _num << " troops with ARs, SMGs, Snipers and Bazookas were recruited.";
                temp = convert.str();
                Logger::log(temp);
                    w4 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_PISTOL), weapons->getWeapon(CLASS_SNIPER), weapons->getWeapon(CLASS_BAZOOKA)}; /**<Vector which contains a set of references to weapon objects>*/

                break;
        }
    }
    else if(_con->getResearch() <= 1){
        switch(i){
            case 1:
                e = new Troop(_name, _num, w5, _con);
                    w5 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_DUALBURETTE), weapons->getWeapon(CLASS_SNIPER50), weapons->getWeapon(CLASS_AK47)}; /**<Vector which contains a set of references to weapon objects>*/

		        convert << _num << " troops with ARs, Dual Burettes, Sniper50s and AK47s were recruited.";
                temp = convert.str();
                Logger::log(temp);
                    w5 = new vector<Weapon *> {weapons->getWeapon(CLASS_AR), weapons->getWeapon(CLASS_DUALBURETTE), weapons->getWeapon(CLASS_SNIPER50), weapons->getWeapon(CLASS_AK47)}; /**<Vector which contains a set of references to weapon objects>*/

                break;
            case 2:
                e = new Troop(_name, _num, w6, _con);
                    w6 = new vector<Weapon *> {weapons->getWeapon(CLASS_AK47), weapons->getWeapon(CLASS_DUALBURETTE), weapons->getWeapon(CLASS_BAZOOKA), weapons->getWeapon(CLASS_SNIPER50)}; /**<Vector which contains a set of references to weapon objects>*/

                convert << _num << " troops with AK47s, Dual Burettes, Bazooka and Sniper50s were recruited.";
                temp = convert.str();
                Logger::log(temp);
                    w6 = new vector<Weapon *> {weapons->getWeapon(CLASS_AK47), weapons->getWeapon(CLASS_DUALBURETTE), weapons->getWeapon(CLASS_BAZOOKA), weapons->getWeapon(CLASS_SNIPER50)}; /**<Vector which contains a set of references to weapon objects>*/

                break;
        }
    }
    this->_con->getMap()->getOccupancyTable()->addEntity(e, this->_con->getCapital());
    return e;
}


