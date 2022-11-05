#include "Weapon.h"
#include <math.h>

int Weapon::getDamage() {return this->damage;}
string Weapon::getName() {return this->WeaponName;}
string Weapon::getType() {return this->WeaponType;}

Weapon::Weapon(int damage, std::string name) {
    this->damage = damage;
    this->WeaponName = name;
    this->WeaponType = "";
}
