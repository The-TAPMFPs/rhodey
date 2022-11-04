#pragma once
#include <string>

using namespace std;

class Weapon {
 protected:
  string WeaponName;
  int damage = 0;
  string WeaponType;

 public:
  Weapon(int damage, string weaponName);
  int getDamage();
  string getType();
  string getName();
};