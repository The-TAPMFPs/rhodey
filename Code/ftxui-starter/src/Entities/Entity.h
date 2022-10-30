#pragma once
#include <string>
#include <vector>
#include "./WeaponTemplateMethod/Weapon.h"
using namespace std;

class Entity{

    protected:
	string name;
	string type;  // stores the type of entity
	bool defending; // shows if entity is in a defesive possition or not.
	int HP=0; // HP will represent the amount of entities in a group.
	int Damage=0; // The Damage of a entity is the basis of damage that it can
		      // inflict
	vector<Weapon*> weapons;

    public:
	Entity(string name, string type, int HP, int Damage);
	void attack(Entity & defender);
	virtual void defend(int damage, Weapon & weapon)=0;
	void assignWeapon(Weapon & weapon);
	bool getAndSetDefense(); // gets current value of defense flag and then
				//   flips it.
	virtual bool transport()=0;
	virtual bool transport(Entity &)=0;
	virtual Entity* split()=0;
};
