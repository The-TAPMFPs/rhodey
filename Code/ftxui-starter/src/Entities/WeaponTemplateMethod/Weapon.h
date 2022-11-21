#pragma once
#include <string>

using namespace std;

enum WEAPON_TYPE {SMALL_ARMS, TANK_ROUND, ANTI_TANK, ANTI_AIR, CANNON, HIGH_CAL, BOMB, ROCKET};

/*! \enum WEAPON_NAME *
 *  Name of a weapon used to get a flyweight weapon from the flyweight factory.
 */
enum WEAPON_NAME{
    CLASS_BAZOOKA,
    CLASS_SNIPER,
    CLASS_SNIPER50,
    CLASS_PISTOL,
    CLASS_AR,
    CLASS_SMG,
    CLASS_DUALBURETTE,
    CLASS_AK47,
    CLASS_TORPEDO,
    CLASS_MISSILE,
    CLASS_BOMB,
    CLASS_CANNON,
    CLASS_MG160
};

class WeaponFlyweightFactory;

class Weapon {
    friend WeaponFlyweightFactory;
    protected:
      string WeaponName;
      int damage = 0;
      WEAPON_TYPE WeaponType;
      Weapon(int damage, string weaponName);
    public:
      virtual ~Weapon();
      int getDamage();
      WEAPON_TYPE getType();
      string getName();
      virtual void outputFlair()=0;
};

class Bazooka : protected Weapon {
    friend WeaponFlyweightFactory;
    protected:
	Bazooka();
    public:
	virtual void outputFlair() override;
};

class Sniper : protected Weapon{
    friend WeaponFlyweightFactory;
    protected:
	Sniper();
    public:
	virtual void outputFlair() override;
};

class Sniper50 : protected Weapon{
    friend WeaponFlyweightFactory;
    protected:
	Sniper50();
    public:
	virtual void outputFlair() override;
};

class Pistol : protected Weapon{
    friend WeaponFlyweightFactory;
    protected:
	Pistol();
    public:
	virtual void outputFlair() override;
};

class AR : protected Weapon{
    friend WeaponFlyweightFactory;
    protected:
	AR();
    public:
	virtual void outputFlair() override;
};

class SMG : protected Weapon{
    friend WeaponFlyweightFactory;
    protected:
	SMG();
    public:
	virtual void outputFlair() override;
};

class DualBurette : protected Weapon{
    friend WeaponFlyweightFactory;
    protected:
	DualBurette();
    public:
	virtual void outputFlair() override;
};

class AK47 : protected Weapon{
    friend WeaponFlyweightFactory;
    protected:
	AK47();
    public:
	virtual void outputFlair() override;
};

class Torpedo:protected Weapon{
    friend WeaponFlyweightFactory;
    protected:
	Torpedo();
    public:
	virtual void outputFlair() override;
};

class Missile:protected Weapon{
    friend WeaponFlyweightFactory;
    protected:
	Missile();
    public:
	virtual void outputFlair() override;
};

class Bomb:protected Weapon{
    friend WeaponFlyweightFactory;
    protected:
	Bomb();
    public:
	virtual void outputFlair() override;
};
class Cannon:protected Weapon{
    friend WeaponFlyweightFactory;
    protected:
	Cannon();
    public:
	virtual void outputFlair() override;
};
class Mg160:protected Weapon{
    friend WeaponFlyweightFactory;
    protected:
	Mg160();
    public:
	virtual void outputFlair() override;
};

class TestWeapon : public Weapon {
    friend WeaponFlyweightFactory;
    public:
	TestWeapon();
	virtual void outputFlair() override;
};

class TankCannon : protected Weapon {
    friend WeaponFlyweightFactory;
    protected:
	TankCannon();
    public:
	virtual void outputFlair() override;
};

class TestBomb : public Weapon {
    friend WeaponFlyweightFactory;
    public:
	TestBomb();
	virtual void outputFlair() override;
};
