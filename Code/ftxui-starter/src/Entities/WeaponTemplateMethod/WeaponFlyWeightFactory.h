#include "Weapon.h"
#include <map>
#include <memory>


class WeaponFlyweightFactory {
    private:
	std::map<int, shared_ptr<Weapon>> cachedWeapons;
    public:
	WeaponFlyweightFactory();
	Weapon * getWeapon(WEAPON_NAME);
};
