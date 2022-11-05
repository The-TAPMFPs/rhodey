#include "Entity.h"
#include <iostream>

Entity::Entity(string name, string type, int HP, int Damage,
	vector<Weapon*> * weapon, Country * country) {
    this->name = name;
    this->type = type;
    this->HP = HP;
    this->Damage = Damage;
    this->defending = false;
    this->weapons = weapon;
    this->uuid = uuid::generateUUID();
    this->country = country;
}

Entity::~Entity() {
    int initial = this->weapons->size();
    for (int count = 0; count < initial; count++) {
	delete this->weapons->at(this->weapons->size()-1);
	this->weapons->pop_back();
    }
    delete this->weapons;
}

void Entity::attack(Entity & defender) {
    if (this->HP <= 0) {
	return;
    }
    int totalDamage = 0;
    totalDamage = (this->Damage*this->getAmount())/this->weapons->size();
    for (int count = 0; count < this->weapons->size(); count++) {
	defender.defend(totalDamage, * this->weapons->at(count));
    }
}

void Entity::update() {
    this->HP = this->HP - this->DamageDone;
    this->DamageDone = 0;
}

void Entity::defend(int damage, Weapon &weapon) {
    int potentialDamage = damage;
    if (this->getAndSetDefense()) {
	potentialDamage = potentialDamage*0.7;
    }
    potentialDamage = potentialDamage/this->HPScalling;
    potentialDamage = this->weaknesses(potentialDamage, weapon);
    this->DamageDone = potentialDamage;
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

int Entity::getAmount() {
    return this->HP/this->HPScalling;
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
