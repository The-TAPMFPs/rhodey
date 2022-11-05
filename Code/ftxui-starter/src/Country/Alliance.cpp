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
