#include "Weapon.h"
#include "../Entity.h"
#include "../../logger.h"

int Weapon::getDamage() {return this->damage;}
string Weapon::getName() {return this->WeaponName;}
WEAPON_TYPE Weapon::getType() {return this->WeaponType;}

Weapon::Weapon(int damage, std::string name) {
    this->damage = damage;
    this->WeaponName = name;
}
//research level 1
Pistol::Pistol(): Weapon(0,"Pistol"){
    this->damage=5+rand()%15;
    this->WeaponType = SMALL_ARMS;
}

void Pistol::outputFlair() {
    std::stringstream out;
    out << "Pistols unleash a hail of 9 millimeter bullets that dart accross The Battle Field" << std::endl;
    Logger::log(out.str());
}

//research level 2 (0.2>)
AR::AR():Weapon(0,"AR"){
    this->damage=15+rand()%30;
    this->WeaponType = SMALL_ARMS;
}
void AR::outputFlair() {
    std::stringstream out;
    out << "The sound of Bullets Singing Over Heads Inbetween the" <<
	" Thunderous claps of Gunfire Rumbles Across the Battle Field as Assult rifles show their furry" << std::endl;
    Logger::log(out.str());
}
SMG::SMG():Weapon(0,"SMG"){
    this->damage=10+rand()%25;
    this->WeaponType = SMALL_ARMS;
}
void SMG::outputFlair() {
    std::stringstream out;
    out << "Sub Machine guns unleash a storm of bullets across The Battle Field. Cutting"
	<< " Down Everything in Their Path and adding it to their newly created soup of "
	<< "bone fragments, blood, and boddies." << std::endl;
    Logger::log(out.str());
}

Sniper::Sniper(): Weapon(0,"Sniper"){
    this->damage=85+rand()%100;
    this->WeaponType = SMALL_ARMS;
}
void Sniper::outputFlair() {
    std::stringstream out;
    out << "Deafening Roars are Heard inbetween short Moments of Silience, "
	<< " ocasionally followed by a buzz, a sqeltching sound, and finnaly"
	<< "the dull thud of a body." << std::endl;
    Logger::log(out.str());
}
//research level 3(0.5>)
Bazooka::Bazooka() : Weapon(0, "Bazooka") {
    this->damage = 90 + rand( )%100;  // DO RANDOM DAMAGE GENERATION
    this->WeaponType = ANTI_TANK;
}
void Bazooka::outputFlair() {
    std::stringstream out;
    out << "A flash, followed by sound of a rumble, followed by a roar instills dread accross the battle field"
	<< " as rockets make their way to their targets."<< std::endl;
    Logger::log(out.str());
}

Sniper50::Sniper50(): Weapon(0,"50 cal. Sniper"){
    this->damage=90 + rand( )%100;
    this->WeaponType = HIGH_CAL;
}
void Sniper50::outputFlair() {
    std::stringstream out;
    out << "Deafening Roars are Heard inbetween short Moments of Silience, "
	<< " ocasionally followed by a buzz, a sqeltching sound, and finnaly"
	<< "the dull thud of a body." << std::endl;
    Logger::log(out.str());
}

DualBurette::DualBurette() : Weapon(0, "Dual"){
    this->damage=10+rand()%15;
    this->WeaponType = SMALL_ARMS;
}
void DualBurette::outputFlair() {
    std::stringstream out;
    out << "Pistols unleash a hail of 9 millimeter bullets that dart accross The Battle Field" << std::endl;
    Logger::log(out.str());
}
//research level 4(0.8>)
AK47::AK47(): Weapon(0, "AK47"){
    this->damage=20 + rand( )%100;
    this->WeaponType = SMALL_ARMS;
}
void AK47::outputFlair() {
    std::stringstream out;
    out << "The sound of Bullets Singing Over Heads Inbetween the" <<
	" Thunderous claps of Gunfire Rumbles Across the Battle Field as Assult rifles show their furry" << std::endl;
    Logger::log(out.str());
}

Bomb::Bomb():Weapon(0,"Bomb"){
    this->damage=35+rand()%55;
    this->WeaponType = BOMB;
}
void Bomb::outputFlair() {
    std::stringstream out;
    out << "Shrill, hellish Whistles are heard followed by a booms as bombs unleash destruction, panic, and chaos." << std::endl;
    Logger::log(out.str());
}
Cannon::Cannon():   Weapon(0,"Cannon"){
    this->damage=25+rand()%45;
    this->WeaponType = TANK_ROUND;
}
void Cannon::outputFlair() {
    std::stringstream out;
    out << "The sound of explosions followed by real explosions rocks the battle field" << std::endl;
    Logger::log(out.str());
}
Torpedo::Torpedo(): Weapon(0,"Torpedo"){
    this->damage=45+rand()%75;
    this->WeaponType = BOMB;
}
void Torpedo::outputFlair() {
    std::stringstream out;
    out << "A massive explosion rocks the oceans out of nowhere." << std::endl;
    Logger::log(out.str());
}
Missile::Missile():Weapon(0,"Missile"){
    this->damage=40+rand()%65;
    this->WeaponType = ROCKET;
}
void Missile::outputFlair() {
    std::stringstream out;
    out << "A hellish scream strikes fear into the hearts and minds of all, followed by a the sound of anihilation." << std::endl;
    Logger::log(out.str());
}

TankCannon::TankCannon():Weapon(0,"Missile"){
    this->damage=40+rand()%65;
    this->WeaponType = ROCKET;
}
void TankCannon::outputFlair() {
    std::stringstream out;
    out << "A hellish scream strikes fear into the hearts and minds of all, followed by a the sound of anihilation." << std::endl;
    Logger::log(out.str());
}

TestWeapon::TestWeapon():Weapon(10, "TestWeapon"){}
void TestWeapon::outputFlair(){

}
TestBomb::TestBomb() : Weapon(30,"Test Bomb") {
    this->WeaponType = BOMB;
}
void TestBomb::outputFlair(){

}
