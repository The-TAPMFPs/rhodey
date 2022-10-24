#include "Country.h"

unsigned int Country::sizeOfArmy() //TODO: Calculate based off of troops
{
    return 0;
}
unsigned int Country::prowessInRegion(Region* region)
{
    return 0;
}

Country::Country(std::string name) : name(name) {
    int population = 0;
    double economy = 0;
    double morale = 0;
    double supplies = 0;
    double attrition = 0;
    double aggressiveness = 0;
}

std::string Country::getName()
{
    return "";
}