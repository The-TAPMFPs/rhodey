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
    return this->name;
}

void Country::generatePersonalityMatrix()
{
    Eigen::MatrixXd pm(6, 18);

    pm <<
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;

    this->personalityMatrix = pm;
}

std::vector<std::string> Country::getFormattedStats() {
    return std::vector<std::string> {
        "Population: " + std::to_string(population),
        "Economy: " + std::to_string(economy),
        "Morale: " + std::to_string(morale),
        "Resources: " + std::to_string(resources),
        "Research: " + std::to_string(research),
        "Aggressiveness: " + std::to_string(aggressiveness),
        "Goal Rating: " + std::to_string(goalRating),
        "Number of Spies: " + std::to_string(numSpies)
    };
}