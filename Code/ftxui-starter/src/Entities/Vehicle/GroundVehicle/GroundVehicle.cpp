#include "GroundVehicle.h"

GroundVehicle::GroundVehicle(string name, int numberOfTroops, int HP, int Damage,
	vector<Weapon*> * weapon, Country * country, std::string type) :
    Vehicle(name, numberOfTroops, HP, Damage, weapon, country, type){};

int GroundVehicle::weaknesses(int damage,Weapon & weapon) {
    int totalDamage = damage;
    if (weapon.getType() == "anti-tank") {
	totalDamage = totalDamage*2;
    }
    if (weapon.getType() == "missile") {
	totalDamage = totalDamage*1.4;
    }
    if (weapon.getType() == "bomb") {
	totalDamage = totalDamage*1.4 + weapon.getDamage();
    }
    return totalDamage;
}
