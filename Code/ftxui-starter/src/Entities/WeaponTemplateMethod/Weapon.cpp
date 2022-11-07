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
}
//research level 1
Pistol::Pistol(): Weapon(0,"Pistol"){
    this->damage=5+rand()%15;
    this->WeaponType = SMALL_ARMS;
}
//research level 2 (0.2>)
AR::AR():Weapon(0,"AR"){
    this->damage=15+rand()%30;
    this->WeaponType = SMALL_ARMS;
}
SMG::SMG():Weapon(0,"SMG"){
    this->damage=10+rand()%25;
    this->WeaponType = SMALL_ARMS;
}

Sniper::Sniper(): Weapon(0,"Sniper"){
    this->damage=85+rand()%100;
    this->WeaponType = SMALL_ARMS;
}
//research level 3(0.5>)
Bazooka::Bazooka() : Weapon(0, "Bazooka") {
    this->damage = 90 + rand( )%100;  // DO RANDOM DAMAGE GENERATION
    this->WeaponType = ANTI_TANK;
}

Sniper50::Sniper50(): Weapon(0,"Sniper50"){
    this->damage=90 + rand( )%100;
    this->WeaponType = HIGH_CAL;
}

DualBurette::DualBurette() : Weapon(0, "Dual"){
    this->damage=10+rand()%15;
    this->WeaponType = SMALL_ARMS;
}
//research level 4(0.8>)
AK47::AK47(): Weapon(0, "AK47"){
    this->damage=20 + rand( )%100;
    this->WeaponType = SMALL_ARMS;
}

Bomb::Bomb():Weapon(0,"Bomb"){
    this->damage=35+rand()%55;
    this->WeaponType = BOMB;
}
Cannon::Cannon():   Weapon(0,"Cannon"){
    this->damage=25+rand()%45;
    this->WeaponType = TANK_ROUND;
}
Torpedo::Torpedo(): Weapon(0,"Torpedo"){
    this->damage=45+rand()%75;
    this->WeaponType = BOMB;
}
Missile::Missile():Weapon(0,"Missile"){
    this->damage=40+rand()%65;
    this->WeaponType = ROCKET;
}

TestWeapon::TestWeapon():Weapon(10, "TestWeapon"){}
