#include "WaterVehicle.h"

WaterVehicle::WaterVehicle(string name, int numberOfTroops, int HP, int Damage,
	vector<Weapon*> * weapon, Country * country, std::string type) :
    Vehicle(name, numberOfTroops, HP, Damage, weapon, country, type){};

int WaterVehicle::weaknesses(int damage,Weapon & weapon) {
    int totalDamage = damage;
    if (weapon.getType() == BOMB) {
	totalDamage = totalDamage*2;
    }
    if (weapon.getType() == ROCKET) {
	totalDamage = totalDamage*1.4;
    }
    if (weapon.getType() == CANNON) {
	totalDamage = totalDamage*1.4 + weapon.getDamage();
    }
    return totalDamage;
}
