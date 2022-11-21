#include "Entity.h"
#include "../Country/Country.h"
#include <exception>
#include <iostream>

/**
  * @brief Initializes the Values for a Entity
  * @param name - Name of the Entity
  * @param type - The Entity Type
  * @param HP - The Amount HP that Each Entity has
  * @param Damage - The Amount of Base Damage that the entity should do.
  * @param weapon - A vector of different weapons that the entity owns.
  * @param country - The country that the entity is alligned with.
  * @return Entity *
*/
Entity::Entity(string name, string type, int HP, int Damage,
	vector<Weapon*> * weapon, Country * country) {
    this->name = name;
    this->type = type;
    this->HP = HP;
    this->Damage = Damage;
    this->defending = false;
    if (weapon == NULL) {
	this->weapons = new std::vector<Weapon *>;
    } else {
	this->weapons = weapon;
    }
    this->uuid = uuid::generateUUID();
    this->country = country;
}

/**
  * @brief destroys the Entity
*/
Entity::~Entity() {
    int initial = this->weapons->size();
    delete this->weapons;
}

/**
  * @brief Attacks the entity that is passed to this entity.
  * @param defender - The Entity that this class is going to attack.
  * @return void
*/
void Entity::attack(Entity & defender, bool testing) {
    if (this->HP <= 0) {
	return;
    }
    int totalDamage = 0;
    if (this->weapons->size() != 0) {
	totalDamage = (this->Damage*this->getAmount())/this->weapons->size();
    }
    for (auto itr = this->country->getCountriesBeingSpiedOn()->begin();
	    itr != this->country->getCountriesBeingSpiedOn()->end(); ++itr) {
	if (long(itr->first) == long(this->country)) {
	    totalDamage = totalDamage*(log(itr->second+70)/log(70));
	}
    }
    for (int count = 0; count < this->weapons->size(); count++) {
	defender.defend(totalDamage, * this->weapons->at(count),testing);
    }
}

/**
  * @brief Updates the HP of the entities.
  * @warning This function should be called after both sides of a battle have finnished all of their attacks.
  * @return void
*/
void Entity::update() {
    this->HP = this->HP - this->DamageDone;
    this->DamageDone = 0;
}

/**
  * @brief Defends against a attacker, calculates that damage taken and stores it.
  * @param damage - The incomming damage from the attacker.
  * @param weapon - The current weapon that the attacker is using to attack.
  * @warning This function is reserved for calling withing the attack method. It should not be called anywhere else.
  * @return void
*/
void Entity::defend(int damage, Weapon &weapon, bool testing) {
    int potentialDamage = damage;
    if (this->getAndSetDefense()) {
	potentialDamage = potentialDamage*0.7;
    }
    if (testing) {
	potentialDamage = potentialDamage*0.5;
    } else {
	potentialDamage = potentialDamage*float(float(uuid::randomInt(300, 700))/1000);
    }
    potentialDamage = potentialDamage*(std::log(weapon.getDamage())/std::log(20));
    potentialDamage = this->weaknesses(potentialDamage, weapon);
    this->DamageDone = potentialDamage;
}

/**
  * @brief Stores and returns the current value of the defending flag and then flips it.
  * @warning This function is reserved for calling withing the attack method. It should not be called anywhere else.
  * @return Previous value of defense flag.
*/
bool Entity::getAndSetDefense() {
    bool currentValue = this->defending;
    if (this->defending == true) {
	this->defending = false;
    } else {
	this->defending = true;
    }
    return currentValue;
}

/**
  * @brief Adds a weapon to a entity.
  * @param weapon - New Weapon to Add to a Entity.
  * @return void
*/
void Entity::assignWeapon(Weapon &weapon) {
    this->weapons->push_back(&(weapon));
}

/**
  * @brief Stores and returns the current value of the defending flag and then flips it.
  * @param weapon - New Weapon to Add to a Entity.
  * @return Previous value of defense flag.
*/
Entity * Entity::split(int numberOfEntities) {
    if (numberOfEntities*this->HPScalling > this->HP) {
	return nullptr;
    }

    int numberOfWeaponsToTransfer = int (this->weapons->size() *
	    double (double (numberOfEntities)*HPScalling)/(double(this->HP)));
    if (numberOfWeaponsToTransfer > this->weapons->size()) {
	numberOfWeaponsToTransfer = this->weapons->size();
    }
    vector<Weapon *> * newWeapons = new vector<Weapon*>;
    for (int count = 0; count < numberOfWeaponsToTransfer; count++) {
	newWeapons->push_back(this->weapons->back());
	this->weapons->pop_back();
    }

    Entity * toReturn = this->splitType(this->name, numberOfEntities, newWeapons);
    this->HP = this->HP - numberOfEntities*this->HPScalling;
    return toReturn;
}

/**
  * @brief Stores and returns the current value of the defending flag and then flips it.
  * @throws WrongType - The entities that you are trying to merge into one are of different types.
  * @return Previous value of defense flag.
*/
void Entity::absorb(Entity *entity) {
    // merge checks
    if ((long int) entity == (long int) this) {
	throw SameEntity();
    } else if (long(entity->getCountry()) != long(this->country)) {
	throw DifferentAlliances();
    }
    if (entity->getType() == this->type) {
	this->HP = this->HP + entity->HP;
	entity->HP = 0;
	for (auto itr = entity->weapons->begin(); itr != entity->weapons->end(); ++itr) {
	    this->weapons->push_back(*itr);
	}
	for (int count = 0; count < entity->weapons->size(); count++) {
	    entity->weapons->pop_back();
	}
    } else {
	throw WrongType();
    }
}

int Entity::getAmount() {
    if (HP > 0 && HP <= HPScalling) {
	return 1;
    }
    return HP/HPScalling;
}
