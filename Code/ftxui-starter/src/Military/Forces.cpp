#include "Forces.h"
#include <vector>
// Forces::Forces(std::string name) {
    // this->name = name;
// }

// Forces::Forces(std::string name, vector<Regiment *> * airForce,
	    // vector<Regiment *> * army, vector<Regiment *> * navy) {
    // this->name = name;
    // this->army = army;
    // this->airForce = airForce;
    // this->navy = navy;
// }

// Forces::~Forces() {
    // for (int count = 0; count < this->army->size(); count++) {
	// delete this->army->at(this->army->size()-1);
	// this->army->pop_back();
    // }

    // for (int count = 0; count < this->airForce->size(); count++) {
	// delete this->airForce->at(this->airForce->size()-1);
	// this->airForce->pop_back();
    // }

    // for (int count = 0; count < this->navy->size(); count++) {
	// delete this->navy->at(this->navy->size()-1);
	// this->navy->pop_back();
    // }
// }
// void Forces::addToArmy(Regiment * regiment) {
    // this->army->push_back(regiment);
// }
// void Forces::addToNavy(Regiment * regiment) {
    // this->airForce->push_back(regiment);
// }
// void Forces::addToAirForce(Regiment * regiment) {
    // this->navy->push_back(regiment);
// }

// void Forces::shuffle(vector<Regiment *> * current,
	// vector<Regiment *> * opposing) {
    // std::random_device rd;
    // std::mt19937 generator(rd());
    // std::shuffle(current->begin(), current->end(), generator);
    // std::shuffle(opposing->begin(),
	    // opposing->end(), generator);
// }

// void Forces::attack(vector<Regiment *> * current,
	// vector<Regiment *> * opposing) {
    // int currentSize = current->size();

    // for (int count = 0; count < currentSize; count++) {
	// current->at(count)->attack(opposing->at(count % currentSize));
    // }
// }

// void Forces::update() {
    // for (int count = 0; count < this->army->size(); count++) {
	// this->army->at(count)->update();
    // }
    // for (int count = 0; count < this->airForce->size(); count++) {
	// this->airForce->at(count)->update();
    // }
    // for (int count = 0; count < this->navy->size(); count++) {
	// this->navy->at(count)->update();
    // }
// }

// std::string Forces::battleTurn(Forces * opposing) {
    // std::string toReturn = "";

    // this->shuffle(this->army, opposing->army);
    // this->shuffle(this->navy, opposing->navy);
    // this->shuffle(this->airForce, opposing->airForce);

    // /// Attack Sequence
    // this->attack(this->airForce, opposing->airForce);
    // this->attack(this->airForce, opposing->navy);
    // this->attack(this->airForce, opposing->army);

    // this->attack(this->navy, opposing->navy);
    // this->attack(this->navy, opposing->airForce);

    // this->attack(this->army, opposing->army);


    // opposing->attack(opposing->airForce, this->airForce);
    // opposing->attack(opposing->airForce, this->navy);
    // opposing->attack(opposing->airForce, this->army);

    // opposing->attack(opposing->navy, this->navy);
    // opposing->attack(opposing->navy, this->airForce);

    // opposing->attack(opposing->army, this->army);

    // opposing->update();
    // this->update();

    // return toReturn;
// }
