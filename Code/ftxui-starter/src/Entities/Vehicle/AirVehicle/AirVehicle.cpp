#include "AirVehicle.h"

AirVehicle::AirVehicle(string name, int numberOfTroops, int HP, int Damage,
	vector<Weapon*> * weapon, Country * country, std::string type) :
    Vehicle(name, numberOfTroops, HP, Damage, weapon, country, type){};

int AirVehicle::weaknesses(int damage,Weapon & weapon) {
    int totalDamage = damage;
    if (weapon.getType() == ANTI_AIR || weapon.getType() == CANNON) {
	totalDamage = totalDamage*1.2;
    }
    if (weapon.getType() == ROCKET) {
	totalDamage = totalDamage*1.4;
    }
    return totalDamage;
}
