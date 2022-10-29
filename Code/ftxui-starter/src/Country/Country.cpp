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
    population = 0;
    economy = 0;
    morale = 0;
    resources = 0;
    research = 0;
    aggressiveness = 0;
    goalRating = 0;
    numSpies = 0;
    generatePersonalityMatrix();
}

std::string Country::getName()
{
    return "";
}

void Country::generatePersonalityMatrix()
{
    this->personalityMatrix << 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
}