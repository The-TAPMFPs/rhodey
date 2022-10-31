#include "Troop.h"
#include <vector>
#include "../Entity.h"

Troop::Troop(string name, int numberOfTroops, vector<Weapon*> * weapon) :
    Entity(name, "Ground Infantry", numberOfTroops, 2, weapon) {
	this->HPScalling = 3;
	this->HP = this->HP* this->HPScalling;
    }


int Troop::getCarryingCapacity() {
    return 0;
}

void Troop::defend(int damage, Weapon & weapon) { }

Entity * Troop::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Troop(name, numberOfTroops, weapon);
}

int Troop::weaknesses(int damage, Weapon& weapon) {
    int potentialDamage =damage;
    if (weapon.getType() == "AntiVehicle") {
	potentialDamage = this->HP/damage;
    }
    return potentialDamage;
}

int Troop::getTerrainHandling() {
    return 0;
}
