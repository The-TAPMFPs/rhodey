#include "Weapon.h"
#include <math.h>
/**
 *\fn int Weapon::getDamage()
 * \brief gets damage that the weapon will do 
 * \return returns the damage as an interger value 
 * 
*/

/**
 *\fn string Weapon::getName()
 * \brief gets the name of the weapon 
 * \return returns the name of a weapon as a string
 * 
*/

/**
 *\fn string Weapon::getType()
 * \brief gets type of weapon 
 * \return returns the weapon type as a string value 
 * 
*/
int Weapon::getDamage() {return this->damage;}
string Weapon::getName() {return this->WeaponName;}
string Weapon::getType() {return this->WeaponType;}
/**
 *\fn void Weapon::Weapon(int damage, std::string name)
 * \brief constructor that sets damage,WeaponName and WeaponType
 * 
*/
Weapon::Weapon(int damage, std::string name) {
    this->damage = damage;
    this->WeaponName = name;
    this->WeaponType = "";
}