#include "Troop.h"
#include <cmath>

Troop::Troop(string name, int numberOfTroops, vector<Weapon*> * weapon, Country * country) :
    Entity(name, "Ground Infantry", numberOfTroops, 3, weapon, country) {
	this->HPScalling = 3;
	this->HP = this->HP* this->HPScalling;
    }


int Troop::getCarryingCapacity() {
    return this->getAmount();
}

Entity * Troop::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Troop(name, numberOfTroops, weapon, this->country);
}

int Troop::weaknesses(int damage, Weapon& weapon) {
    int potentialDamage = damage;
    if (weapon.getType() == ANTI_TANK) {
	potentialDamage = this->HP/damage;
    }
    return potentialDamage;
}

int Troop::getTerrainHandling() {
    return 3;
}
