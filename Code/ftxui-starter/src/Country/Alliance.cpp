#include "Alliance.h"

int Alliance::first = 0;
Alliance::Alliance(std::string name) : name(name) {
    if (Alliance::first == 0) {
	this->playerr = true;
    }
    Alliance::first++;
}

void Alliance::add(Country* country) {
    members.push_back(country);
}

void Alliance::print() {
    std::cout << "Alliance: " << name << std::endl;
    std::cout << "======================" << std::endl;
    for (Country* country : members) {
        std::cout << country->getName() << std::endl;
    }
    std::cout << std::endl;
}

std::vector<std::string> Alliance::getAllianceNames() {
    std::vector<std::string> names;
    for (Country* country : members) {
        names.push_back(country->getName());
    }
    return names;
}

std::vector<Country*>* Alliance::getMembers() {
    return &members;
}
