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
  virtual void outputFlair()=0;
};

class Bazooka : public Weapon {
    public:
  Bazooka();
  virtual void outputFlair() override;
};

class Sniper : public Weapon{
    public:
    Sniper();
  virtual void outputFlair() override;
};

class Sniper50 : public Weapon{
    public:
	virtual void outputFlair() override;
    Sniper50();
};

class Pistol : public Weapon{
    public:
	virtual void outputFlair() override;
    Pistol();
};

class AR : public Weapon{
    public:
	virtual void outputFlair() override;
    AR();
};

class SMG : public Weapon{
    public:
	virtual void outputFlair() override;
    SMG();
};

class DualBurette : public Weapon{
    public:
	virtual void outputFlair() override;
    DualBurette();
};

class AK47 : public Weapon{
    public:
	virtual void outputFlair() override;
    AK47();
};

class Torpedo:public Weapon{
    public:
	virtual void outputFlair() override;
    Torpedo();
};

class Missile:public Weapon{
    public:
	virtual void outputFlair() override;
    Missile();
};

class Bomb:public Weapon{
    public:
	virtual void outputFlair() override;
    Bomb();
};
class Cannon:public Weapon{
    public:
	virtual void outputFlair() override;
    Cannon();
};
class Mg160:public Weapon{
    public:
	virtual void outputFlair() override;
    Mg160();
};

class TestWeapon : public Weapon {
    public:
	virtual void outputFlair() override;
	TestWeapon();
};

class TankCannon : public Weapon {
    public:
	virtual void outputFlair() override;
	TankCannon();
};

class TestBomb : public Weapon {
    public:
	virtual void outputFlair() override;
	TestBomb();
};
