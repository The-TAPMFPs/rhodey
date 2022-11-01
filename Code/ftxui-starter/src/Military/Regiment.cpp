#include "Regiment.h"
#include "math.h"
#include <algorithm>
#include <random>

Regiment::Regiment(std::string name) {
    this->name = name;
}

Regiment::Regiment(std::string name, vector<Entity*> * units) {
    this->name = name;
    this->units = units;
}


Regiment::~Regiment() {
    for (int count = 0; count < this->units->size(); count++) {
	delete this->units->at(this->units->size()-1);
	this->units->pop_back();
    }
    delete this->units;
}

void Regiment::addUnit(Entity * unit) {
    this->units->push_back(unit);
}

void Regiment::attack(Regiment *oposingRegiment) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(this->units->begin(), this->units->end(), generator);
    std::shuffle(oposingRegiment->units->begin(),
	    oposingRegiment->units->end(), generator);

    int mySize = this->units->size();
    int theirSize = oposingRegiment->units->size();
    int maxCount = max(mySize, theirSize);
    for (int count = 0; count < maxCount; count++) {
	/// This line is disgusting but all its doing is passing in the attacks
	this->units->at(count % mySize)->attack(
		*oposingRegiment->units->at(count % theirSize)
		);
    }
}

/// TODO
void Regiment::move(Region *region) {
    return;
}
