#include "Weapon.h"
#include <math.h>

int Weapon::getDamage() {return this->damage;}
string Weapon::getName() {return this->WeaponName;}
WEAPON_TYPE Weapon::getType() {return this->WeaponType;}

Weapon::Weapon(int damage, std::string name) {
    this->damage = damage;
    this->WeaponName = name;
}
Bazooka::Bazooka() : Weapon(0, "Bazooka") {
    this->damage = 90 + rand( )%100;  // DO RANDOM DAMAGE GENERATION
    this->WeaponType = ANTI_TANK;
  }
Sniper::Sniper(): Weapon(0,"Sniper"){
    this->damage=85+rand()%100;
    this->WeaponType = SMALL_ARMS;
}
Sniper50::Sniper50(): Weapon(0,"Sniper50"){
    this->damage=90 + rand( )%100;
    this->WeaponType = HIGH_CAL;
}
Pistol::Pistol(): Weapon(0,"Pistol"){
    this->damage=5+rand()%15;
    this->WeaponType = SMALL_ARMS;
}
AR::AR():Weapon(0,"AR"){
    this->damage=15+rand()%30;
    this->WeaponType = SMALL_ARMS;
}
SMG::SMG():Weapon(0,"SMG"){
    this->damage=10+rand()%25;
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
