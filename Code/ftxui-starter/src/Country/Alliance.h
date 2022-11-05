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
		bool playerr = false;
		std::vector<Country *> members;

    public:
		static int first;
		Alliance(std::string name);
		void add(Country*);
		void print();
		bool isPlayer() {return playerr;}
};

