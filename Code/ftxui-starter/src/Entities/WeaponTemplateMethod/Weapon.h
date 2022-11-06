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

class DualBurette : public Weapon{
    public:
    DualBurette();
};

class AK47 : public Weapon{
    public:
    AK47();
};

class Torpedo:public Weapon{
    public:
    Torpedo();
};

class Missile:public Weapon{
    public:
    Missile();
};

class Bomb:public Weapon{
    public:
    Bomb();
};
class Cannon:public Weapon{
    public:
    Cannon();
};
class Mg160:public Weapon{
    Mg160();
};

class TestWeapon : public Weapon {
    public:
	TestWeapon();
};
