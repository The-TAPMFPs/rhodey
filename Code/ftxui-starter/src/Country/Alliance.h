//An Alliance is simply a named group of countries.
//Coutries within an Alliance work together to defeat the opponent Alliance.
#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Country.h"

class Country;

class Alliance {
    private:
		std::string name;
		bool teamA = false;
		std::vector<Country *> members;
		static int first;

    public:
		Alliance(std::string name, bool teamA = false);
		void add(Country*);
		void print();
		bool isTeamA() {return teamA;}
};

