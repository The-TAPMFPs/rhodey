#pragma once
#include "../Entities/Entity.h"
#include "../MapRegions/Region.h"
/**
A Branch is the base class for a type of branch of the military.
Different branches have different types of units that are specific to them.
  */
class Regiment {
    protected:
	std::string name;
	vector <Entity*> * units;
    public:
	Regiment(std::string name);
	Regiment(std::string name, vector<Entity*> * units);
	~Regiment();
	void move(Region * region); //TODO work with dino on this one.
	void addUnit(Entity * unit);
	void attack(Regiment * oposingRegiment);
};
