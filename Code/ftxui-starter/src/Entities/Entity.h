#pragma once
#include <vector>
#include "./WeaponTemplateMethod/Weapon.h"
#include <bits/stdc++.h>
#include "../uuid.h"
using namespace std;

class Entity{

    protected:
	bool getAndSetDefense(); // gets current value of defense flag and then
				//   flips it.
	virtual Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)=0;
	virtual int weaknesses(int damage,Weapon & weapon)=0;
	void defend(int damage, Weapon & weapon); /// Do not use this method


	string name;
	string type;  // stores the type of entity
	bool defending; // shows if entity is in a defesive possition or not.
	int HP=0; // HP will represent the amount of entities in a group.
	int Damage=0; // The Damage of a entity is the basis of damage that it can
		      // inflict
	int DamageDone=0;
	int HPScalling = 1;
	vector<Weapon*> * weapons;
	int terrianHandling = 0;
	UUID uuid = "";
public:
	Entity(string name, string type, int HP, int Damage, vector<Weapon*> * weapon);
	virtual ~Entity();
	// Virtuals
	virtual int getCarryingCapacity()=0;
	virtual int getTerrainHandling()=0;

	/// Returns the specified Number of entities.

	void attack(Entity & defender);
	void assignWeapon(Weapon & weapon);
	int getAmount();
	bool getDefenseStatus() {return defending;}
	std::string getName() {return name;}
	UUID getUUID() {return uuid;}
	void update();

	Entity* split(int numberOfEntities);
};
