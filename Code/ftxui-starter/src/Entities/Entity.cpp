#include "Entity.h"

Entity::Entity(string name, string type, int HP, int Damage, vector<Weapon*> * weapon) {
    this->name = name;
    this->type = type;
    this->HP = HP;
    this->Damage = Damage;
    this->defending = false;
    this->weapons = weapon;
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

    for (int count = 0; count < this->weapons->size(); count++) {
	defender.defend(totalDamage*damageModifier, * this->weapons->at(count));
    }
}

void Entity::defend(int damage, Weapon &weapon) {
    int potentialDamage = damage;
    if (this->getAndSetDefense()) {
	potentialDamage = potentialDamage/this->Damage;
    }
    potentialDamage = this->weaknesses(potentialDamage, weapon);
    this->HP = this->HP - potentialDamage;
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
    this->weapons->push_back(&(weapon));
}

Entity * Entity::split(int numberOfEntities) {
    if (numberOfEntities*3 > this->HP) {
	return nullptr;
    }

    int numberOfWeaponsToTransfer = int (this->weapons->size() *
	    double (double (numberOfEntities)*3)/(double(this->HP)));
    vector<Weapon *> * newWeapons = new vector<Weapon*>;
    for (int count = 0; count < numberOfEntities; count++) {
	newWeapons->push_back(this->weapons->back());
	this->weapons->pop_back();
    }

    Entity * toReturn = this->splitType(this->name, numberOfEntities, newWeapons);
    this->HP = this->HP - numberOfEntities*3;
    return toReturn;
}
