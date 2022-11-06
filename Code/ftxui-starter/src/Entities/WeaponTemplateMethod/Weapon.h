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
    public:
  Bazooka();
};

class Sniper : public Weapon{
    public:
    Sniper();
};

class Sniper50 : public Weapon{
    public:
    Sniper50();
};

class Pistol : public Weapon{
    public:
    Pistol();
};

class AR : public Weapon{
    public:
    AR();
};

class SMG : public Weapon{
    public:
    SMG();
};

class Torpedo:public Weapon{
    Torpedo();
};

class Missile:public Weapon{
    Missile();
};

class Bomb:public Weapon{
    Bomb();
};
class Cannon:public Weapon{
    Cannon();
};
class Mg160:public Weapon{
    Mg160();
};

class TestWeapon : public Weapon {
    public:
	TestWeapon();
};
