#include "WeaponFlyWeightFactory.h"
#include <memory>

WeaponFlyweightFactory::WeaponFlyweightFactory() {
}

Weapon * WeaponFlyweightFactory::getWeapon(WEAPON_NAME name) {
    if (cachedWeapons.find(name) == cachedWeapons.end()) {
	// TODO @Rec1dite was thinking of making this a command but the code
	//    would be pretty much just as ugly in the command class,
	//    what do you think?
	switch (name) {
	    case CLASS_BAZOOKA:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new Bazooka())});
		break;
	    case CLASS_SNIPER:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new Sniper())});
		break;
	    case CLASS_SNIPER50:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new Sniper50())});
		break;
	    case CLASS_PISTOL:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new Pistol())});
		break;
	    case CLASS_AR:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new AR())});
		break;
	    case CLASS_SMG:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new SMG())});
		break;
	    case CLASS_DUALBURETTE:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new DualBurette())});
		break;
	    case CLASS_AK47:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new AK47())});
		break;
	    case CLASS_TORPEDO:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new Torpedo())});
		break;
	    case CLASS_MISSILE:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new Missile())});
		break;
	    case CLASS_BOMB:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new Bomb())});
		break;
	    case CLASS_CANNON:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new Cannon())});
		break;
	    case CLASS_MG160:
		cachedWeapons.insert({name, shared_ptr<Weapon>((Weapon*) new Mg160())});
		break;
	    default:
		break;
	}
    }
    return cachedWeapons.at(name).get();
}
