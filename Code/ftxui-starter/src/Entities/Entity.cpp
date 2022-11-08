#include "Entity.h"
#include <exception>
#include <iostream>

/**
 * @file Entity.cpp
 * @brief Construct a new Entity object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Entity(string name, string type, int HP, int Damage, vector<Weapon*> * weapon, Country * country)
 * @brief The constructor for the Entity class.
 * 
 * @param name The name of the Entity.
 * @param type The type of Entity.
 * @param HP The Health Points of the Entity.
 * @param Damage The base damage of the Entity.
 * @param weapon The Weapons that the entity has.
 * @param country The country that owns the entity.
 */
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

/**
 * @fn ~Entity
 * @brief The destructor of the Entity class. Deletes the object as well as the weapons vector.
 * 
 */
Entity::~Entity() {
    int initial = this->weapons->size();
    for (int count = 0; count < initial; count++) {
	delete this->weapons->at(this->weapons->size()-1);
	this->weapons->pop_back();
    }
    delete this->weapons;
}

/**
 * @fn void attack(Entity & defender)
 * @brief the attack function 
 * 
 * @param defender is the defender 
 */
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
/**
 * \fn void Entity::update()
 * \brief update function that updates the HP of an entity 
*/
void Entity::update() {
    this->HP = this->HP - this->DamageDone;
    this->DamageDone = 0;
}
/**
 * \fn void Entity::defend(int damage, Weapon &weapon)
 * \brief defend function that defends against an attack
 * \param damage the damage being dealt that we should dampen/make smaller since we are defending
 * \param weapon the weapon that is doing the damage
*/
void Entity::defend(int damage, Weapon &weapon) {
    int potentialDamage = damage;
    if (this->getAndSetDefense()) {
	potentialDamage = potentialDamage*0.7;
    }
    potentialDamage = potentialDamage/this->HPScalling;
    potentialDamage = this->weaknesses(potentialDamage, weapon);
    this->DamageDone = potentialDamage;
}
/**
 * \fn bool Entity::getAndSetDefense()
 * \brief function that determines if an entity is defending at a point in time 
 * \return the status of defending 
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
 * \fn void Entity::assignWeapon(Weapon &weapon)
 * \brief function that assigns a weapon to a particular entity
 * \param weapon the weapon thatll be assigned to an entity 
*/
void Entity::assignWeapon(Weapon &weapon) {
    this->weapons->push_back(&(weapon));
}
/**
 * \fn Entity * Entity::split(int numberOfEntities)
 * \brief function that clones an entity
 * \param numberOfEntities the number of entities we wish to clone
 * \return  
*/
Entity * Entity::split(int numberOfEntities) {
    if (numberOfEntities*3 > this->HP) {
	return nullptr;
    }

    int numberOfWeaponsToTransfer = int (this->weapons->size() *
	    double (double (numberOfEntities)*3)/(double(this->HP)));
    vector<Weapon *> * newWeapons = new vector<Weapon*>;
    for (int count = 0; count < numberOfWeaponsToTransfer; count++) {
	newWeapons->push_back(this->weapons->back());
	this->weapons->pop_back();
    }

    Entity * toReturn = this->splitType(this->name, numberOfEntities, newWeapons);
    this->HP = this->HP - numberOfEntities*3;
    return toReturn;
}

void Entity::absorb(Entity *entity) {
    if ((long int) entity == (long int) this) {
	return;
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
