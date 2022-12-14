//An Alliance is simply a named group of countries.
//Coutries within an Alliance work together to defeat the opponent Alliance.
#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Country.h"
#include <algorithm>

class Country;

class Alliance {
    private:
		std::string name;
		bool teamA = false;
		std::vector<Country *> members;
		static int first;
		Alliance* enemyAlliance;

    public:
		Alliance(std::string name, bool teamA);
		void add(Country*);
		void print();
		void setEnemyAlliance(Alliance* enemyAlliance);
		std::vector<Country*> getMembers();
		bool isTeamA() {return teamA;}
		bool containsCountry(Country* country);
		std::vector<std::string> getAllianceNames();
		Country* getMemberModuloSize(int modIndex);
		Country* getIthCountry(int index);
		Alliance* getEnemyAlliance() {return enemyAlliance;}
		int numCountries() {return members.size();}
		std::string getName() {return name;}
};

