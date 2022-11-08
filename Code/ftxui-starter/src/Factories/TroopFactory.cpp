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
    w1 =  new vector<Weapon *> {new SMG(), new Pistol()}; /**<Vector which contains a set of references to weapon objects>*/
    w2 = new vector<Weapon *> {new AR(), new Pistol(), new Sniper()}; /**<Vector which contains a set of references to weapon objects>*/
    w3 = new vector<Weapon *> {new AR(), new SMG(), new DualBurette(), new Bazooka()}; /**<Vector which contains a set of references to weapon objects>*/
    w4 = new vector<Weapon *> {new AR(), new Pistol(), new Sniper(), new Bazooka()}; /**<Vector which contains a set of references to weapon objects>*/
    w5 = new vector<Weapon *> {new AR(), new DualBurette(), new Sniper50(), new AK47()}; /**<Vector which contains a set of references to weapon objects>*/
    w6 = new vector<Weapon *> {new AK47(), new DualBurette(), new Bazooka(), new Sniper50()}; /**<Vector which contains a set of references to weapon objects>*/
}
/**
 * @fn ~TroopFactory()
 * @brief The Destructor of the TroopFactory class.
 */
TroopFactory::~TroopFactory(){
    for (int count = 0; count < w1->size(); count) {
	delete w1->at(w1->size()-1);
	w1->pop_back();
    }
    delete w1;

    for (int count = 0; count < w2->size(); count) {
	delete w2->at(w2->size()-1);
	w2->pop_back();
    }
    delete w2;
    for (int count = 0; count < w3->size(); count) {
	delete w3->at(w3->size()-1);
	w3->pop_back();
    }
    delete w4;
    for (int count = 0; count < w4->size(); count) {
	delete w4->at(w4->size()-1);
	w4->pop_back();
    }
    delete w4;
    for (int count = 0; count < w5->size(); count) {
	delete w5->at(w5->size()-1);
	w5->pop_back();
    }
    delete w5;
    for (int count = 0; count < w6->size(); count) {
	delete w6->at(w6->size()-1);
	w6->pop_back();
    }
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
        w1 =  new vector<Weapon *> {new SMG(), new Pistol()};
	    convert << _num << " troops with SMGs and Pistols were recruited.";
        temp = convert.str();
        Logger::log(temp);
	w1 =  new vector<Weapon *> {new SMG(), new Pistol()};
    }
    else if(_con->getResearch() < 0.5){
        e = new Troop(_name, _num, w2, _con);
        w2 = new vector<Weapon *> {new AR(), new Pistol(), new Sniper()};
        convert << _num << " troops with ARs, Pistols and Snipers were recruited.";
        temp = convert.str();
        Logger::log(temp);
	w2 = new vector<Weapon *> {new AR(), new Pistol(), new Sniper()};
    }
    else if(_con->getResearch() < 0.8){
        switch(i){
            case 1:
                e = new Troop(_name, _num, w3, _con);
                w3 = new vector<Weapon *> {new AR(), new SMG(), new DualBurette(), new Bazooka()};
                convert << _num << " troops with ARs, SMGs, Dual Burettes and Bazookas were recruited.";
                temp = convert.str();
                Logger::log(temp);
                w3 = new vector<Weapon *> {new AR(), new SMG(), new DualBurette(), new Bazooka()};
                break;
            case 2:
                e = new Troop(_name, _num, w4, _con);
                w4 = new vector<Weapon *> {new AR(), new Pistol(), new Sniper(), new Bazooka()};
                convert << _num << " troops with ARs, SMGs, Snipers and Bazookas were recruited.";
                temp = convert.str();
                Logger::log(temp);
                w4 = new vector<Weapon *> {new AR(), new Pistol(), new Sniper(), new Bazooka()};
                break;
        }
    }
    else if(_con->getResearch() <= 1){
        switch(i){
            case 1:
                e = new Troop(_name, _num, w5, _con);
                w5 = new vector<Weapon *> {new AR(), new DualBurette(), new Sniper50(), new AK47()};
		        convert << _num << " troops with ARs, Dual Burettes, Sniper50s and AK47s were recruited.";
                temp = convert.str();
                Logger::log(temp);
                w5 = new vector<Weapon *> {new AR(), new DualBurette(), new Sniper50(), new AK47()};
                break;
            case 2:
                e = new Troop(_name, _num, w6, _con);
                w6 = new vector<Weapon *> {new AK47(), new DualBurette(), new Bazooka(), new Sniper50()};
                convert << _num << " troops with AK47s, Dual Burettes, Bazooka and Sniper50s were recruited.";
                temp = convert.str();
                Logger::log(temp);
                w6 = new vector<Weapon *> {new AK47(), new DualBurette(), new Sniper50(), new Bazooka()};
                break;
        }
    }
    this->_con->getMap()->getOccupancyTable()->addEntity(e, this->_con->getCapital());
    return e;
}


