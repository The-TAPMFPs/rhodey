#include "Troop.h"
#include "Entities/Entity.h"

Troop::Troop(string name, string type, int HP, int Damage) :
    Entity(name, type, HP, Damage) {}


void Troop::transport() {
}

void Troop::defend(int damage, Weapon &weapon) {
    int potentialDamage = damage;
    if (this->getAndSetDefense()) {
	potentialDamage = potentialDamage/this->Damage;
    }

    if (weapon.getType() == "AntiVehicle") {
	potentialDamage = this->HP/damage;
    }

    this->HP = this->HP - potentialDamage;
}
