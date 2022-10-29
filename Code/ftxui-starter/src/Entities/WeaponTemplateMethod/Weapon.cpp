#include "Weapon.h"
#include <math.h>

Bazooka::Bazooka() : Weapon(0, "Bazooka") {
    this->damage = 90 + rand( )%100;  // DO RANDOM DAMAGE GENERATION
  }

Sniper::Sniper(): Weapon(0,"Sniper"){
    this->damage=85+rand()%100;
}

Sniper50::Sniper50(): Weapon(0,"Sniper50"){
    this->damage=90 + rand( )%100;
}

Pistol::Pistol(): Weapon(0,"Pistol"){
    this->damage=5+rand()%15;
}

AR::AR():Weapon(0,"AR"){
    this->damage=15+rand()%30;
}

SMG::SMG():Weapon(0,"SMG"){
    this->damage=10+rand()%25;
}

