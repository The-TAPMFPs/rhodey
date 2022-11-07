#include "TroopFactory.h"
#include <sstream>

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
UnitFactory(name, num, con){
    _name = name;
    _num = num;
    _con = con;
    //level 1
    SMG* smg; /**<Reference to different weapon SMG object>*/
    Pistol* pis; /**<Reference to different weapon Pistol object>*/
    //level 2
    AR* ar; /**<Reference to different weapon AR object>*/
    Sniper* sni; /**<Reference to different weapon Sniper object>*/
    //level 3
    DualBurette* db; /**<Reference to different weapon DualBurette object>*/
    Bazooka* baz; /**<Reference to different weapon Bazooka object>*/
    //level 4
    Sniper50* s50; /**<Reference to different weapon Sniper50 object>*/
    AK47* ak; /**<Reference to different weapon AK47 object>*/
    w1 =  new vector<Weapon *> {smg, pis}; /**<Vector which contains a set of references to weapon objects>*/
    w2 = new vector<Weapon *> {ar, pis, sni}; /**<Vector which contains a set of references to weapon objects>*/
    w3 = new vector<Weapon *> {ar, smg, db, baz}; /**<Vector which contains a set of references to weapon objects>*/
    w4 = new vector<Weapon *> {ar, pis, sni, baz}; /**<Vector which contains a set of references to weapon objects>*/
    w5 = new vector<Weapon *> {ar, db, s50, ak}; /**<Vector which contains a set of references to weapon objects>*/
    w6 = new vector<Weapon *> {ak, db, baz, s50}; /**<Vector which contains a set of references to weapon objects>*/
}
/**
 * @fn ~TroopFactory()
 * @brief The Destructor of the TroopFactory class.
 */
TroopFactory::~TroopFactory(){}

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
	convert << _num << " troops with SMGs and Pistols were recruited.";
        temp = convert.str();
        Logger::log(temp);
    }
    else if(_con->getResearch() < 0.5){
        e = new Troop(_name, _num, w2, _con);
        convert << _num << " troops with ARs, Pistols and Snipers were recruited.";
        temp = convert.str();
        Logger::log(temp);
    }
    else if(_con->getResearch() < 0.8){
        switch(i){
            case 1:
                e = new Troop(_name, _num, w3, _con);
                convert << _num << " troops with ARs, SMGs, Dual Burettes and Bazookas were recruited.";
                temp = convert.str();
                Logger::log(temp);
                break;
            case 2:
                e = new Troop(_name, _num, w4, _con);
                convert << _num << " troops with ARs, SMGs, Snipers and Bazookas were recruited.";
                temp = convert.str();
                Logger::log(temp);
                break;
        }
    }
    else if(_con->getResearch() <= 1){
        switch(i){
            case 1:
                e = new Troop(_name, _num, w5, _con);
		        convert << _num << " troops with ARs, Dual Burettes, Sniper50s and AK47s were recruited.";
                temp = convert.str();
                Logger::log(temp);
                break;
            case 2:
                e = new Troop(_name, _num, w6, _con);
                convert << _num << " troops with AK47s, Dual Burettes, Bazooka and Sniper50s were recruited.";
                temp = convert.str();
                Logger::log(temp);
                break;
        }
    }
    return e;
}


