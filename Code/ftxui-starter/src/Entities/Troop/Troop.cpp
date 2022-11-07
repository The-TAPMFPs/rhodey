#include "Troop.h"

Troop::Troop(string name, int numberOfTroops, vector<Weapon*> * weapon, Country * country) :
    Entity(name, "Ground Infantry", numberOfTroops, 3, weapon, country) {
	this->HPScalling = 3;
	this->HP = this->HP* this->HPScalling;
    }


int Troop::getCarryingCapacity() {
    return 1;
}

Entity * Troop::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Troop(name, numberOfTroops, weapon, this->country);
}

int Troop::weaknesses(int damage, Weapon& weapon) {
    int potentialDamage = damage * log10(damage* weapon.getDamage());
    if (weapon.getType() == "AntiVehicle") {
	potentialDamage = this->HP/damage;
    }
    return potentialDamage;
}

int Troop::getTerrainHandling() {
    return 3;
}
