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
		std::vector<Country *> members;

    public:
		Alliance(std::string name);
		void add(Country*);
		void print();
		std::vector<std::string> getAllianceNames();
		std::vector<Country *>* getMembers();
};