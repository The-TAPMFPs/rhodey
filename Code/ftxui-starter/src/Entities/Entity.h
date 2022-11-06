#pragma once
#include <string>
#include <vector>
#include "./WeaponTemplateMethod/Weapon.h"
#include "../uuid.h"
using namespace std;

class Country;

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
	Country * country;
public:
	Entity(string name, string type, int HP, int Damage,
		vector<Weapon*> * weapon, Country * country);
	virtual ~Entity();
	/**
	  @returns Returns the amout of additional Entities that this entitiy can transport
	*/
	virtual int getCarryingCapacity()=0;
	/**
	  @returns Returns the entities ability to traverse terrain
	*/
	virtual int getTerrainHandling()=0;


	void attack(Entity & defender);
	void assignWeapon(Weapon & weapon);
	/**
	  Updates the HP of the entities.
	  @warning This function should be called after both sides of a battle have finnished all of their attacks.
	*/
	void update();

	/**
	  Gets the current amount of entities.
	  @returns Amount of entities
	*/
	int getAmount() {return HP/HPScalling;}
	/**
	  @returns Returns the Country with which this entity is alligned.
	*/
	Country * getCountry() {return country;}
	/**
	  Gets the status of if a group is in defensive mode or not.
	  @returns Defensive status
	*/
	bool getDefenseStatus() {return defending;}
	/**
	  @returns Name of the Entity.
	*/
	std::string getName() {return name;}
	/**
	  @returns UUID of the Entity
	*/
	UUID getUUID() {return uuid;}

	/**
	  @returns Returns the Type of the current entity. (Troop, Tank, etc.)
	*/
	string getType() {return type;}

	Entity* split(int numberOfEntities);
	void absorb(Entity * entity);
};

struct WrongType : public exception {
   const char * what () const throw () {
      return "The Entitys that you are trying to merge are of different types.";
   }
};
