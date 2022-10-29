#include "Entity.h"

Entity::Entity(string name, string type, int HP, int Damage) {
    this->name = name;
    this->type = type;
    this->HP = HP;
    this->Damage = Damage;
    this->defending = false;
}

void Entity::attack(Entity & defender) {
    if (this->HP <= 0) {
	return;
    }
    int totalDamage = 0;
    int damageModifier = 1;
    totalDamage = this->Damage;

    if (!this->getAndSetDefense()) {
	int damageModifier = 2;
    }

    for (int count = 0; count < this->weapons.size(); count++) {
	defender.defend(totalDamage*damageModifier, * this->weapons.at(count));
    }
}

bool Entity::getAndSetDefense() {
    bool currentValue = this->defending;
    if (this->defending == true) {
	this->defending = false;
    } else {
	this->defending = true;
    }
    return currentValue;
}

void Entity::assignWeapon(Weapon &weapon) {
    //TODO fix this when weapon class is finnished
    // this->weapons.push(weapon);
}
