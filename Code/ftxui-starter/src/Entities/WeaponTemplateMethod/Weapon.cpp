#include "Weapon.h"
#include <math.h>

int Weapon::getDamage() {return this->damage;}
string Weapon::getName() {return this->WeaponName;}
string Weapon::getType() {return this->WeaponType;}

Bazooka::Bazooka() : Weapon(0, "Bazooka") {
    this->damage = 90 + rand( )%100;  // DO RANDOM DAMAGE GENERATION
  }

Sniper::Sniper(): Weapon(0,"Sniper"){ //2nd
    this->damage=85+rand()%100;
}

Sniper50::Sniper50(): Weapon(0,"Sniper50"){ //1st
    this->damage=90 + rand( )%100;
}

Pistol::Pistol(): Weapon(0,"Pistol"){ //last
    this->damage=5+rand()%15;
}

AR::AR():Weapon(0,"AR"){ //3rd
    this->damage=15+rand()%30;
}

SMG::SMG():Weapon(0,"SMG"){ //4th
    this->damage=10+rand()%25;
}

