#include "AirVehicle.h"

AirVehicle::AirVehicle(string name, int numberOfTroops, int HP, int Damage,
	vector<Weapon*> * weapon) :
    Vehicle(name, numberOfTroops, HP, Damage, weapon){};

int AirVehicle::weaknesses(int damage,Weapon & weapon) {
    int totalDamage = damage;
    if (weapon.getType() == "anti-air") {
	totalDamage = totalDamage*1.2;
    }
    if (weapon.getType() == "missile") {
	totalDamage = totalDamage*1.4;
    }
    return totalDamage;
}
