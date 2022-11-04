#include "Troop.h"

Troop::Troop(string name, int numberOfTroops, vector<Weapon*> * weapon) :
    Entity(name, "Ground Infantry", numberOfTroops, 3, weapon) {
	this->HPScalling = 3;
	this->HP = this->HP* this->HPScalling;
    }


int Troop::getCarryingCapacity() {
    return 0;
}

Entity * Troop::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Troop(name, numberOfTroops, weapon);
}

int Troop::weaknesses(int damage, Weapon& weapon) {
    int potentialDamage = damage * log10(damage* weapon.getDamage());
    if (weapon.getType() == "AntiVehicle") {
	potentialDamage = this->HP/damage;
    }
    return potentialDamage;
}

int Troop::getTerrainHandling() {
    return 0;
}
