#include "Alliance.h"

Alliance::Alliance(std::string name) : name(name) {}

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

//For round-robin selection of a country from the alliance
Country* Alliance::getMemberModuloSize(int modIndex) {
    if(!this->members.empty())
    {
        return this->members[modIndex%this->members.size()];
    }
    return nullptr;
}