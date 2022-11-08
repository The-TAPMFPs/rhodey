/**
 * \file Entity.h
 * \brief Entity Object Header File.
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \version 1.0
 * \date 6 November 2022
 */
#pragma once
#include <cmath>
#include <string>
#include <vector>
#include "./WeaponTemplateMethod/Weapon.h"
#include "../uuid.h"
using namespace std;


class Country;
/**
 * @brief The Entity class is the base Class for all types of Entities.
 */
class Entity{

    protected:
	bool getAndSetDefense(); // gets current value of defense flag and then
				//   flips it.
	virtual Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)=0;
	virtual int weaknesses(int damage,Weapon & weapon)=0;
	void defend(int damage, Weapon & weapon, bool testing = false); /// Do not use this method


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


	void attack(Entity & defender, bool testing = false);
	void assignWeapon(Weapon & weapon);
	void update();

	/**
	  Gets the current amount of entities.
	  @returns Amount of entities
	*/
	int getAmount();
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
	virtual bool isVehicle()=0;
};

struct WrongType : public exception {
   const char * what () const throw () {
      return "The Entitys that you are trying to merge are of different types.";
   }
};
struct SameEntity : public exception {
   const char * what () const throw () {
      return "The Entitys that you are trying to merge are the same entity.";
   }
};
struct DifferentAlliances : public exception {
   const char * what () const throw () {
      return "The Entitys that you are trying to merge are from different countries.";
   }
};
