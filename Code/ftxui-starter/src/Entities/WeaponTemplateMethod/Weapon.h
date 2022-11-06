#pragma once
#include <string>

using namespace std;

enum WEAPON_TYPE {SMALL_ARMS, TANK_ROUND, ANTI_TANK, ANTI_AIR, CANNON, HIGH_CAL, BOMB, ROCKET};

class Weapon {
 protected:
  string WeaponName;
  int damage = 0;
  WEAPON_TYPE WeaponType;

 public:
  Weapon(int damage, string weaponName);
  int getDamage();
  WEAPON_TYPE getType();
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

class TestWeapon : public Weapon {
    public:
	TestWeapon();
};

class DualBurette : public Weapon{
    public:
	DualBurette();
};

class AK47 : public Weapon{
    public:
	AK47();
};
