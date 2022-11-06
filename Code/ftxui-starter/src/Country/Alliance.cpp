#include "Alliance.h"

Alliance::Alliance(std::string name, bool teamA) : name(name), teamA(teamA){}


void Alliance::add(Country* country) {
    members.push_back(country);
    country->allies = this;
}

void Alliance::print() {
    std::cout << "Alliance: " << name << std::endl;
    std::cout << "======================" << std::endl;
    for (Country* country : members) {
        std::cout << country->getName() << std::endl;
    }
    std::cout << std::endl;
}
