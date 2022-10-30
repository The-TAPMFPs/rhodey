#pragma once
#include <string>

using namespace std;

class Weapon {
 protected:
  string WeaponName;
  int damage = 0;
  string WeaponType;

 public:
  Weapon(int damage, string weaponName);
  int getDamage();
  string getType();
  string getName();
};
class Bazooka : public Weapon {
  Bazooka();
};

class Sniper : public Weapon{
    Sniper();
};

class Sniper50 : public Weapon{
    Sniper50();
};

class Pistol : public Weapon{
    Pistol();
};

class AR : public Weapon{
    AR();
};

class SMG : public Weapon{
    SMG();
};
